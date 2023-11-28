/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PLUS = 258,                    /* PLUS  */
    ARRAY = 259,                   /* ARRAY  */
    MULT = 260,                    /* MULT  */
    MINUS = 261,                   /* MINUS  */
    DIV = 262,                     /* DIV  */
    O_PAREN = 263,                 /* O_PAREN  */
    ERROR = 264,                   /* ERROR  */
    C_PAREN = 265,                 /* C_PAREN  */
    SEMICOLON = 266,               /* SEMICOLON  */
    COMMA = 267,                   /* COMMA  */
    NOT_EQ = 268,                  /* NOT_EQ  */
    ASSIGN = 269,                  /* ASSIGN  */
    O_BRACKET = 270,               /* O_BRACKET  */
    C_BRACKET = 271,               /* C_BRACKET  */
    O_BRACE = 272,                 /* O_BRACE  */
    C_BRACE = 273,                 /* C_BRACE  */
    O_COMMENT = 274,               /* O_COMMENT  */
    C_COMMENT = 275,               /* C_COMMENT  */
    COLON = 276,                   /* COLON  */
    INT = 277,                     /* INT  */
    VOID = 278,                    /* VOID  */
    LESSER = 279,                  /* LESSER  */
    GREATER = 280,                 /* GREATER  */
    LESSER_EQ = 281,               /* LESSER_EQ  */
    GREATER_EQ = 282,              /* GREATER_EQ  */
    EQ = 283,                      /* EQ  */
    ID = 284,                      /* ID  */
    NUM = 285,                     /* NUM  */
    WHILE = 286,                   /* WHILE  */
    IF = 287,                      /* IF  */
    ELSE = 288,                    /* ELSE  */
    RETURN = 289                   /* RETURN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 77 "parser.y"

    struct decl *decl;
    struct expr *expr;
    struct stmt *stmt;
    struct type *type;
    struct var *var;
    struct param *param;
    char *id;
    int num;

#line 109 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_PARSER_H_INCLUDED  */
