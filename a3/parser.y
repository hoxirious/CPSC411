%{
    // C code
    #include<stdio.h>
    #include"lex.yy.c"
    #include"ast.h"
    struct decl *parser_result = 0;
    struct SymbolTableStack table_stack = {.top = -1, .stack = NULL};

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
%token PLUS ARRAY MULT MINUS DIV O_PAREN ERROR C_PAREN SEMICOLON COMMA NOT_EQ ASSIGN O_BRACKET C_BRACKET O_BRACE C_BRACE O_COMMENT C_COMMENT COLON INT VOID LESSER GREATER LESSER_EQ GREATER_EQ EQ ID NUM WHILE IF ELSE RETURN
%locations
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

%locations
%%
// new grammar
program: declaration-list    {
       printf("Program start\n");
       parser_result = $1;
       }

declaration-list: declaration declaration-list {
        $$ = $1; $1->next=$2;
} | declaration  {
        $$ = $1;
        }

declaration: var-declaration {$$ = $1;} | fun-declaration {$$ = $1;}

var-declaration: type ID SEMICOLON {
            $$ = createDecl(SIMPLE_DECL, $2, 0, $1, 0, 0, 0, yylineno);
        }
            | type ID O_BRACKET NUM C_BRACKET SEMICOLON {$$ = createDecl(ARRAY_DECL, $2, $4, $1, 0, 0, 0, yylineno);}
type: INT {$$ = createType(INT_TYPE, 0, 0);} | VOID {$$ = createType(VOID_TYPE, 0, 0);}

fun-declaration: type ID O_PAREN param-list C_PAREN compound_stmt
{
    $$ = createDecl(FUNCTION_DECL, $2, 0, $1, $4, $6, 0, yylineno);
}

param-list: param COMMA param-list { $$ = $1; $1->next=$3;}
            | param { $$ = $1;}
            | VOID {$$ = createParam(VOID_PARAM,0,0,0, yylineno);}

param: type ID {$$ = createParam(SIMPLE_PARAM,$1, $2, 0,yylineno);}
     | type ID O_BRACKET C_BRACKET {$$ = createParam(ARRAY_PARAM, $1, $2, 0, yylineno);}

compound_stmt: O_BRACE local-declarations statement-list C_BRACE {
$$ = createStmt(COMPOUND_STMT, $2,0,0,0,$3, yylineno);
}

local-declarations: var-declaration local-declarations {$$ = $1; $1->next=$2;} |  {$$ = 0;}

statement-list: statement statement-list {$$ = $1; $1->next=$2;} | {$$ = 0;}

statement: expression_stmt {$$ = $1;} | compound_stmt {$$ = $1;} | selection_stmt {$$ = $1;} | iteration_stmt {$$ = $1;} | return_stmt {$$ = $1;}

expression_stmt: expression SEMICOLON { $$ = createStmt(EXPR_STMT, 0, $1, 0,0,0,yylineno);}

selection_stmt: IF O_PAREN expression C_PAREN statement {
                $$ = createStmt(SELECT_STMT, 0, $3, $5, 0,0, yylineno);}
              | IF O_PAREN expression C_PAREN statement ELSE statement {
                $$ = createStmt(SELECT_STMT, 0, $3, $5,$7,0, yylineno);}

iteration_stmt: WHILE O_PAREN expression C_PAREN statement {
              $$ = createStmt(ITER_STMT, 0, $3, $5,0,0, yylineno);}

return_stmt: RETURN SEMICOLON {$$ = createStmt(RETURN_STMT,0,0,0,0,0, yylineno);} | RETURN expression SEMICOLON {
           $$ = createStmt(RETURN_STMT, 0, $2,0,0,0, yylineno);}

expression: var ASSIGN expression {
          $$ = createExpr(ASSIGN_EXPR, $1, $3, 0, 0, yylineno);} | simple_expression {$$ = $1;}

var: ID {$$ = createExpr(VAR_EXPR, 0, 0,0, $1, yylineno);} | ID O_BRACE expression C_BRACE {$$ = createExpr(VAR_EXPR, 0,$3,0, $1, yylineno);}

simple_expression: additive_expression LESSER  additive_expression {$$ = createExpr(LESSER_EXPR, $1, $3, 0, 0, yylineno);}
                 | additive_expression GREATER additive_expression {$$ = createExpr(GREATER_EXPR, $1, $3,0, 0, yylineno);}
                 | additive_expression LESSER_EQ additive_expression {$$ = createExpr(LESSER_EQ_EXPR, $1, $3, 0, 0, yylineno);}
                 | additive_expression GREATER_EQ additive_expression {$$ = createExpr(GREATER_EQ_EXPR, $1, $3, 0, 0, yylineno);}
                 | additive_expression EQ additive_expression {$$ = createExpr(EQ_EXPR, $1, $3, 0, 0, yylineno);}
                 | additive_expression NOT_EQ additive_expression {$$ = createExpr(NOT_EQ_EXPR, $1, $3, 0, 0, yylineno);}
                 | additive_expression {$$ = $1;}

additive_expression: additive_expression PLUS term {$$ = createExpr(ADD_EXPR, $1, $3, 0,0, yylineno);}
                    | additive_expression MINUS term {$$ = createExpr(SUB_EXPR, $1, $3, 0,0, yylineno);}
                    | term {$$ = $1;}

term: term DIV factor   {$$ = createExpr(DIV_EXPR, $1, $3, 0,0, yylineno);}
    | term MULT factor  {$$ = createExpr(MULT_EXPR, $1, $3, 0,0, yylineno);}
    | factor    {$$ = $1;}

factor: O_PAREN expression C_PAREN {$$ = $2;}
      | var {$$ = $1;}
      | call {$$ = $1;}
      | NUM {$$ = createExpr(NUM_EXPR, 0, 0, $1,0, yylineno);}

call: ID O_PAREN args C_PAREN {$$ = createExpr(CALL_EXPR, 0,$3,0,$1, yylineno);}

args: arg_list {$$ = $1;} |  {$$ = 0;}

arg_list: expression COMMA arg_list {$$ = createExpr(ARG_EXPR,$1,0,0,0, yylineno); $1->right=$3;} | expression {$$ = createExpr(ARG_EXPR,$1,0,0,0, yylineno);}

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
        scope_enter(&table_stack);
        decl_resolve(&table_stack, parser_result);
        scope_exit(&table_stack);
        //printDecl(parser_result);
        printf("\nparsing successful");
    }else {
        result = yyerror("parsing failed");
    }

    return result;

}

int yyerror(char *msg){
    fprintf(stderr,"Error | Line: %d\n%s\n",yylineno,msg);
    return 1;
}
