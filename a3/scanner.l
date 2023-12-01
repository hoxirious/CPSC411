%{
    // C code (will be placed at the begining of the scanner.c)

    // The grammar:
    // Program -> Declaration_List
    // Declaration_List = Declaration_List Declaration | Declaration
    // Declaration -> ID : Type = Expr;
    // Type -> int | bool
    // Expr -> Expr + T | Expr - T | T
    // T -> T * F | T / F | F
    // F -> ( E ) | NUM


    // The grammar:
//  1: program -> declaration-list
//  2: declaration-list -> declaration-list declaration | declaration
//  3: declaration -> var-declaration | fun-declaration
//  4: var-declaration -> type-specifier ID ; | type-specifier ID [ NUM ] ;
//  5: type-specifier -> int | void
//  6: fun-declaration -> type-specifier ID ( params) compound-stmt
//  7: params -> param-list | void
//  8: param-list -> param-list , param | param
//  9: param -> type-specifier ID | type-specifier ID [ ]
//  10: compound-stmt -> { local-declarations statement-list }
//  11: local-declarations -> local-declarations var-declaration | empty
//  12: statement-list -> statement-list statement | empty
//  13: statement -> expression-stmt | compound-stmt | selection-stmt
//  | iteration-stmt | return-stmt
//  14: expression-stmt -> expression ; | ;
//  15: selection-stmt -> if ( expression ) statement
//  | if ( expression ) statement else statement16: iteration-stmt -> while ( expression ) statement
//  17: return-stmt -> return ; | return expression ;
//  18: expression -> var = expression | simple-expression
//  19: var -> ID | ID [ expression ]
//  20: simple-expression -> additive-expression relop additive-expression
//  | additive-expression
//  21: relop -> <= | < | > | >= | == |=
//  22: additive-expression -> additive-expression addop term | term
//  23: addop -> + | -
//  24: term -> term mulop factor | factor
//  25: mulop -> * | /
//  26: factor - ( expression ) | var | call | NUM
//  27: call -> ID ( args )
//  28: args -> arg-list | empty
//  29: arg-list -> arg-list , expression | expression

    #include "parser.h"
%}

DIGIT   [0-9]
LETTER [a-z|A-Z]
%option yylineno

%%
"+"     {return PLUS;}
"*"     {return MULT;}
"-"     {return MINUS;}
"/"     {return DIV;}
"("     {return O_PAREN;}
")"     {return C_PAREN;}
";"     {return SEMICOLON;}
","     {return COMMA;}
"!="    {return NOT_EQ;}
"="     {return ASSIGN;}
"=="    {return EQ;}
"{"     {return O_BRACE;}
"}"     {return C_BRACE;}
"["     {return O_BRACKET;}
"]"     {return C_BRACKET;}
"/*"    {return O_COMMENT;}
"*/"    {return C_COMMENT;}
":"     {return COLON;}
"int"   {return INT;}
"void"  {return VOID;}
"if"    {return IF;}
"else"  {return ELSE;}
"while" {return WHILE;}
"return" {return RETURN;}
"<"     {return LESSER;}
">"     {return GREATER;}
"<="    {return LESSER_EQ;}
">="    {return GREATER_EQ;}


{DIGIT}+    {yylval.num = atoi(yytext); return NUM;}
{LETTER}+   {yylval.id = strdup(yytext); return ID;}

(" "|\t|\n)     /* skip whitespaces */

.   {return ERROR;}
%%

// C code
// will be placed at the end of the scanner.c
int yywrap(){
    return 1;
}
