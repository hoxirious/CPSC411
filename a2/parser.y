%{
    // C code
    #include<stdio.h>
    #include"scanner.h"
    #include"ast.h"
    struct decl *parser_result = 0;
    int yyerror(char *msg);

    // The grammar:
//  program -> declaration-list

//  declaration-list -> declaration-list declaration | declaration

//  declaration -> var-declaration | fun-declaration

//  var-declaration -> type-specifier ID ; | type-specifier ID [ NUM ] ;

//  type-specifier -> int | void

//  fun-declaration -> type-specifier ID ( params) compound-stmt

//  params -> param-list | void

//  param-list -> param-list , param | param

//  param -> type-specifier ID | type-specifier ID [ ]

//  compound-stmt -> { local-declarations statement-list }

//  local-declarations -> local-declarations var-declaration | empty

//  statement-list -> statement-list statement | empty

//  statement -> expression-stmt | compound-stmt | selection-stmt

//  | iteration-stmt | return-stmt

//  expression-stmt -> expression ; | ;

//  selection-stmt -> if ( expression ) statement

//  | if ( expression ) statement else statement

//  iteration-stmt -> while ( expression ) statement

//  return-stmt -> return ; | return expression ;

//  expression -> var = expression | simple-expression

//  var -> ID | ID [ expression ]

//  simple-expression -> additive-expression relop additive-expression

//  | additive-expression

//  relop -> <= | < | > | >= | == |=

//  additive-expression -> additive-expression addop term | term

//  addop -> + | -

//  term -> term mulop factor | factor

//  mulop -> * | /

//  factor - ( expression ) | var | call | NUM
//  call -> ID ( args )
//  args -> arg-list | empty
//  arg-list -> arg-list , expression | expression
%}

%define parse.error verbose
%token PLUS ARRAY MULT MINUS DIV O_PAREN C_PAREN SEMICOLON COMMA NOT_EQ ASSIGN O_BRACE C_BRACE O_COMMENT C_COMMENT COLON INT VOID LESSER GREATER LESSER_EQ GREATER_EQ
%union {
    struct decl *decl;
    struct expr *expr;
    struct stmt *stmt;
    struct type *type;
    struct param *param;
    char *id;
    int num;
}
%type<decl> program declaration-list declaration var-declaration fun-declaration local-declarations

%type<stmt> compound_stmt statement-list statement  expression_stmt selection_stmt iteration_stmt return_stmt call

%type<id> ID

%type<num> NUM

//%type<param_list> param-list

%type<type> type_specifier

%type<expr> expression var simple_expression additive_expression relop term factor addop mulop arg_list args
%%
// new grammar
program: declaration-list    {parser_result = $1;}

declaration-list: declaration declaration-list {$$ = $1; $1->next=$2;} | declaration  {$$ = $1;}

declaration: var-declaration {$$ = $1;} | fun-declaration {$$ = $1;}

var-declaration: type-specifier ID SEMICOLON {$$ = createDecl(SIMPLE_DECL, $2, 0, $1, 0, 0, 0);} | type-specifier ID O_BRACE NUM C_BRACE SEMICOLON {$$ = createDecl(ARRAY_DECL, $2, $4, $1,0,0 0);}

type-specifier: INT {$$ = createType(INT_TYPE, 0, 0);} | VOID {$$ = createType(VOID_TYPE, 0, 0);}

fun-declaration: type-specifier ID O_PAREN params C_PAREN compound_stmt {$$ = createDecl(FUNCTION_DECL, $2, 0, $1, $4, $6);}

params: param-list {$$ = $1;} | VOID {$$ = createType(VOID_TYPE, 0, 0);}

param-list: param COMMA param_list {$$ = $1; $1->next=$3;} | param {$$ = $1;}

param: type-specifier ID {$$ = createParam(SIMPLE_PARAM,$1, $2, 0);} | type-specifier ID O_BRACE C_BRACE {$$ = createParam(ARRAY_PARAM, $1, $2, 0);}

compound_stmt: O_BRACE local-declarations statement-list C_BRACE {$$ = createStmt($2, $3);}

local-declarations: local-declarations var-declaration {$$ = $1; $1->next=$2;} | {$$ = 0;}

statement-list: statement-list statement {$$ = $1; $1->next=$2;} | {$$ = 0;}

statement: expression_stmt {$$ = $1;} | compound_stmt {$$ = $1;} | selection_stmt {$$ = $1;} | iteration_stmt {$$ = $1;} | return_stmt {$$ = $1;}

expression_stmt: expression SEMICOLON {$$ = createExprStmt($1);}

selection_stmt: IF O_PAREN expression C_PAREN statement {$$ = createIfStmt($3, $5, 0);} | IF O_PAREN expression C_PAREN statement ELSE statement {$$ = createIfStmt($3, $5, $7);}

iteration_stmt: WHILE O_PAREN expression C_PAREN statement {$$ = createWhileStmt($3, $5);}

return_stmt: RETURN SEMICOLON {$$ = createReturnStmt(0);} | RETURN expression SEMICOLON {$$ = createReturnStmt($2);}

expression: var ASSIGN expression {$$ = createExpr(ASSIGN_EXPR, $1, $3, 0);} | simple_expression {$$ = $1;}

var: ID {$$ = createVar($1, 0);} | ID O_BRACE expression C_BRACE {$$ = createVar($1, $3);}

simple_expression: additive_expression relop additive_expression {$$ = createExpr(REL_EXPR, $1, $3, $2);} | additive_expression {$$ = $1;}

relop: LESSER {$$ = createExpr(LESSER_EXPR, 0, 0, 0);} | GREATER {$$ = createExpr(GREATER_EXPR, 0, 0, 0);} | LESSER_EQ {$$ = createExpr(LESSER_EQ_EXPR, 0, 0, 0);} | GREATER_EQ {$$ = createExpr(GREATER_EQ_EXPR, 0, 0, 0);} | EQ {$$ = createExpr(EQ_EXPR, 0, 0, 0);} | NOT_EQ {$$ = createExpr(NOT_EQ_EXPR, 0, 0, 0);}

additive_expression: additive_expression addop term {$$ = createExpr(ADD_EXPR, $1, $3, $2);} | term {$$ = $1;}

addop: PLUS {$$ = createExpr(ADD_EXPR, 0, 0, 0);} | MINUS {$$ = createExpr(SUB_EXPR, 0, 0, 0);}

term: term mulop factor {$$ = createExpr(MULT_EXPR, $1, $3, $2);} | factor {$$ = $1;}

mulop: MULT {$$ = createExpr(MULT_EXPR, 0, 0, 0);} | DIV {$$ = createExpr(DIV_EXPR, 0, 0, 0);}

factor: O_PAREN expression C_PAREN {$$ = $2;} | var {$$ = $1;} | call {$$ = $1;} | NUM {$$ = createExpr(NUM_EXPR, 0, 0, $1);}

call: ID O_PAREN args C_PAREN {$$ = createCall($1, $3);}

args: arg_list {$$ = $1;} | {$$ = 0;}

arg_list: arg_list COMMA expression {$$ = $1; $1->next=$3;} | expression {$$ = $1;}

%%

// C code

int main(int argc, char **argv){
    if(argc > 1){
        yyin = fopen(argv[1], "r");
        if(!yyin){
            printf("error reading the file: %s\n", argv[1]);
            return 1;
        }
    }else {
        printf("usage: ./parser <filename>");
        return 1;
    }

    int result = yyparse();


    if(result == 0){
        printDecl(parser_result);
        printf("\nparsing successful");
    }else {
        printf("parsing failed");
    }

    return result;

}

int yyerror(char *msg){
    printf("parsing failed: %s\n", msg);
    return 1;
}
