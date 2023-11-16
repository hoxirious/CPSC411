%{
    // C code
    #include<stdio.h>
    #include"lex.yy.c"
    #include"ast.h"
    struct decl *parser_result = 0;
    int yyerror(char *msg);

    // The grammar:
//  program -> declaration-list

//  declaration-list -> declaration-list declaration | declaration

//  declaration -> var-declaration | fun-declaration

//  var-declaration -> type ID ; | type-specifier ID [ NUM ] ;

//  type -> int | void

//  fun-declaration -> type ID ( params) compound-stmt

//  params -> param-list | void

//  param-list -> param-list , param | param

//  param -> type ID | type-specifier ID [ ]

//  compound-stmt -> { local-declarations statement-list }

//  local-declarations -> local-declarations var-declaration |

//  statement-list -> statement-list statement |

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
//  args -> arg-list |
//  arg-list -> arg-list , expression | expression
%}

%define parse.error verbose
%token PLUS ARRAY MULT MINUS DIV O_PAREN ERROR C_PAREN SEMICOLON COMMA NOT_EQ ASSIGN O_BRACE C_BRACE O_COMMENT C_COMMENT COLON INT VOID LESSER GREATER LESSER_EQ GREATER_EQ EQ ID NUM WHILE IF ELSE RETURN

%union {
    struct decl *decl;
    struct expr *expr;
    struct stmt *stmt;
    struct type *type;
    struct var *var;
    struct param *param;
    char *id;
    int num;
}
%type<decl> program declaration-list declaration var-declaration fun-declaration local-declarations

%type<stmt> compound_stmt statement-list statement  expression_stmt selection_stmt iteration_stmt return_stmt call

%type<id> ID

%type<num> NUM

%type<param> param-list param

%type<var> var

%type<type> type

%type<expr> expression simple_expression additive_expression term factor arg_list args
%%
// new grammar
program: declaration-list    {parser_result = $1;}

declaration-list: declaration declaration-list {$$ = $1; $1->next=$2;} | declaration  {$$ = $1;}

declaration: var-declaration {$$ = $1;} | fun-declaration {$$ = $1;}

var-declaration: type ID SEMICOLON {$$ = createDecl(SIMPLE_DECL, $2, 0, $1, 0, 0, 0);}
                | type ID O_BRACE NUM C_BRACE SEMICOLON {$$ = createDecl(ARRAY_DECL, $2, $4, $1, 0, 0, 0);}


type: INT {$$ = createType(INT_TYPE, 0, 0);} | VOID {$$ = createType(VOID_TYPE, 0, 0);}

fun-declaration: type ID O_PAREN param-list C_PAREN compound_stmt {$$ = createDecl(FUNCTION_DECL, $2, 0, $1, $4, $6, 0);}

param-list: param COMMA param-list {$$ = $1; $1->next=$3;}
            | param {$$ = $1;}
            | {$$ = 0;}

param: type ID {$$ = createParam(SIMPLE_PARAM,$1, $2, 0);} | type ID O_BRACE C_BRACE {$$ = createParam(ARRAY_PARAM, $1, $2, 0);}

compound_stmt: O_BRACE local-declarations statement-list C_BRACE {$$ = createStmt(COMPOUND_STMT, $2,0,0,0,$3);}

local-declarations: var-declaration local-declarations {$$ = $1; $1->next=$2;} |  {$$ = 0;}

statement-list: statement statement-list {$$ = $1; $1->next=$2;} | {$$ = 0;}

statement: expression_stmt {$$ = $1;} | compound_stmt {$$ = $1;} | selection_stmt {$$ = $1;} | iteration_stmt {$$ = $1;} | return_stmt {$$ = $1;}

expression_stmt: expression SEMICOLON {$$ = createStmt(EXPR_STMT, 0, $1, 0,0,0);}

selection_stmt: IF O_PAREN expression C_PAREN statement {$$ = createStmt(SELECT_STMT, 0, $3, $5, 0,0);}
              | IF O_PAREN expression C_PAREN statement ELSE statement {$$ = createStmt(SELECT_STMT, 0, $3, $5,$7,0);}

iteration_stmt: WHILE O_PAREN expression C_PAREN statement {$$ = createStmt(ITER_STMT, 0, $3, $5,0,0);}

return_stmt: RETURN SEMICOLON {$$ = createStmt(RETURN_STMT,0,0,0,0,0);} | RETURN expression SEMICOLON {$$ = createStmt(RETURN_STMT, 0, $2,0,0,0);}

expression: var ASSIGN expression {$$ = createExpr(ASSIGN_EXPR, $1, $3, 0, 0);} | simple_expression {$$ = $1;}

var: ID {$$ = createExpr(VAR_EXPR, 0, 0,0, $1);} | ID O_BRACE expression C_BRACE {$$ = createExpr(VAR_EXPR, 0,$3,0, $1);}

simple_expression: additive_expression LESSER  additive_expression {$$ = createExpr(LESSER_EXPR, $1, $3, 0, 0);}
                 | additive_expression GREATER additive_expression {$$ = createExpr(GREATER_EXPR, $1, $3,0, 0);}
                 | additive_expression LESSER_EQ additive_expression {$$ = createExpr(LESSER_EQ_EXPR, $1, $3, 0, 0);}
                 | additive_expression GREATER_EQ additive_expression {$$ = createExpr(GREATER_EQ_EXPR, $1, $3, 0, 0);}
                 | additive_expression EQ additive_expression {$$ = createExpr(EQ_EXPR, $1, $3, 0, 0);}
                 | additive_expression NOT_EQ additive_expression {$$ = createExpr(NOT_EQ_EXPR, $1, $3, 0, 0);}
                 | additive_expression {$$ = $1;}

additive_expression: additive_expression PLUS term {$$ = createExpr(ADD_EXPR, $1, $3, 0,0);}
                    | additive_expression MINUS term {$$ = createExpr(SUB_EXPR, $1, $3, 0,0);}
                    | term {$$ = $1;}

term: term DIV factor   {$$ = createExpr(DIV_EXPR, $1, $3, 0,0);}
    | term MULT factor  {$$ = createExpr(MULT_EXPR, $1, $3, 0,0);}
    | factor    {$$ = $1;}

factor: O_PAREN expression C_PAREN {$$ = $2;}
      | var {$$ = $1;}
      | call {$$ = $1;}
      | NUM {$$ = createExpr(NUM_EXPR, 0, 0, $1,0);}

call: ID O_PAREN args C_PAREN {$$ = createExpr(CALL_EXPR, 0,$3,0,$1);}

args: arg_list {$$ = $1;} |  {$$ = 0;}

arg_list: expression COMMA arg_list {$$ = createExpr(ARG_EXPR,$1,0,0,0); $1->right=$3;} | expression {$$ = createExpr(ARG_EXPR,$1,0,0,0);}

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
