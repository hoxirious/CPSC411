/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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

#line 144 "parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PLUS = 3,                       /* PLUS  */
  YYSYMBOL_ARRAY = 4,                      /* ARRAY  */
  YYSYMBOL_MULT = 5,                       /* MULT  */
  YYSYMBOL_MINUS = 6,                      /* MINUS  */
  YYSYMBOL_DIV = 7,                        /* DIV  */
  YYSYMBOL_O_PAREN = 8,                    /* O_PAREN  */
  YYSYMBOL_ERROR = 9,                      /* ERROR  */
  YYSYMBOL_C_PAREN = 10,                   /* C_PAREN  */
  YYSYMBOL_SEMICOLON = 11,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 12,                     /* COMMA  */
  YYSYMBOL_NOT_EQ = 13,                    /* NOT_EQ  */
  YYSYMBOL_ASSIGN = 14,                    /* ASSIGN  */
  YYSYMBOL_O_BRACKET = 15,                 /* O_BRACKET  */
  YYSYMBOL_C_BRACKET = 16,                 /* C_BRACKET  */
  YYSYMBOL_O_BRACE = 17,                   /* O_BRACE  */
  YYSYMBOL_C_BRACE = 18,                   /* C_BRACE  */
  YYSYMBOL_O_COMMENT = 19,                 /* O_COMMENT  */
  YYSYMBOL_C_COMMENT = 20,                 /* C_COMMENT  */
  YYSYMBOL_COLON = 21,                     /* COLON  */
  YYSYMBOL_INT = 22,                       /* INT  */
  YYSYMBOL_VOID = 23,                      /* VOID  */
  YYSYMBOL_LESSER = 24,                    /* LESSER  */
  YYSYMBOL_GREATER = 25,                   /* GREATER  */
  YYSYMBOL_LESSER_EQ = 26,                 /* LESSER_EQ  */
  YYSYMBOL_GREATER_EQ = 27,                /* GREATER_EQ  */
  YYSYMBOL_EQ = 28,                        /* EQ  */
  YYSYMBOL_ID = 29,                        /* ID  */
  YYSYMBOL_NUM = 30,                       /* NUM  */
  YYSYMBOL_WHILE = 31,                     /* WHILE  */
  YYSYMBOL_IF = 32,                        /* IF  */
  YYSYMBOL_ELSE = 33,                      /* ELSE  */
  YYSYMBOL_RETURN = 34,                    /* RETURN  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_program = 36,                   /* program  */
  YYSYMBOL_37_declaration_list = 37,       /* declaration-list  */
  YYSYMBOL_declaration = 38,               /* declaration  */
  YYSYMBOL_39_var_declaration = 39,        /* var-declaration  */
  YYSYMBOL_type = 40,                      /* type  */
  YYSYMBOL_41_fun_declaration = 41,        /* fun-declaration  */
  YYSYMBOL_42_param_list = 42,             /* param-list  */
  YYSYMBOL_param = 43,                     /* param  */
  YYSYMBOL_compound_stmt = 44,             /* compound_stmt  */
  YYSYMBOL_45_local_declarations = 45,     /* local-declarations  */
  YYSYMBOL_46_statement_list = 46,         /* statement-list  */
  YYSYMBOL_statement = 47,                 /* statement  */
  YYSYMBOL_expression_stmt = 48,           /* expression_stmt  */
  YYSYMBOL_selection_stmt = 49,            /* selection_stmt  */
  YYSYMBOL_iteration_stmt = 50,            /* iteration_stmt  */
  YYSYMBOL_return_stmt = 51,               /* return_stmt  */
  YYSYMBOL_expression = 52,                /* expression  */
  YYSYMBOL_var = 53,                       /* var  */
  YYSYMBOL_simple_expression = 54,         /* simple_expression  */
  YYSYMBOL_additive_expression = 55,       /* additive_expression  */
  YYSYMBOL_term = 56,                      /* term  */
  YYSYMBOL_factor = 57,                    /* factor  */
  YYSYMBOL_call = 58,                      /* call  */
  YYSYMBOL_args = 59,                      /* args  */
  YYSYMBOL_arg_list = 60                   /* arg_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   111

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  106

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   106,   106,   110,   112,   116,   116,   118,   121,   123,
     123,   125,   131,   132,   133,   135,   136,   138,   142,   142,
     144,   144,   146,   146,   147,   147,   148,   150,   152,   154,
     157,   160,   160,   163,   164,   166,   167,   169,   170,   171,
     172,   173,   174,   175,   177,   178,   179,   181,   182,   183,
     185,   186,   187,   188,   190,   192,   192,   194,   194
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PLUS", "ARRAY",
  "MULT", "MINUS", "DIV", "O_PAREN", "ERROR", "C_PAREN", "SEMICOLON",
  "COMMA", "NOT_EQ", "ASSIGN", "O_BRACKET", "C_BRACKET", "O_BRACE",
  "C_BRACE", "O_COMMENT", "C_COMMENT", "COLON", "INT", "VOID", "LESSER",
  "GREATER", "LESSER_EQ", "GREATER_EQ", "EQ", "ID", "NUM", "WHILE", "IF",
  "ELSE", "RETURN", "$accept", "program", "declaration-list",
  "declaration", "var-declaration", "type", "fun-declaration",
  "param-list", "param", "compound_stmt", "local-declarations",
  "statement-list", "statement", "expression_stmt", "selection_stmt",
  "iteration_stmt", "return_stmt", "expression", "var",
  "simple_expression", "additive_expression", "term", "factor", "call",
  "args", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-89)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-15)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -20,   -89,   -89,    49,   -89,   -20,   -89,    30,   -89,   -89,
     -89,    -2,    31,   -89,    46,    67,    50,    68,    69,    64,
      70,    65,    31,    72,    71,   -20,   -89,   -89,   -89,   -89,
     -20,    55,     2,   -89,    37,    27,    -7,   -89,    78,    80,
       9,   -89,    73,     2,   -89,   -89,   -89,   -89,    79,    75,
     -89,     1,    53,   -89,   -89,    82,    27,    27,    27,    27,
     -89,    83,   -89,   -89,   -89,    27,    27,    27,    27,    27,
      27,    27,    27,    27,    27,    27,   -89,    81,    85,   -89,
      84,    86,    87,   -89,   -89,   -89,    53,    53,    12,    12,
      12,    12,    12,    12,   -89,   -89,    27,   -89,   -89,     2,
       2,   -89,   -89,    66,     2,   -89
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,     0,     2,     4,     5,     0,     6,     1,
       3,     0,     0,     7,     0,    10,     0,     0,    13,     0,
      15,     0,     0,     0,     0,    19,    11,    12,     8,    16,
      19,     0,    21,    18,     0,     0,    35,    53,     0,     0,
       0,    23,     0,    21,    22,    24,    25,    26,     0,    51,
      34,    43,    46,    49,    52,     0,    56,     0,     0,     0,
      31,     0,    17,    20,    27,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    58,     0,    55,
       0,     0,     0,    32,    33,    51,    44,    45,    42,    37,
      38,    39,    40,    41,    48,    47,     0,    54,    36,     0,
       0,    57,    30,    28,     0,    29
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -89,   -89,    93,   -89,    21,    25,   -89,    88,   -89,    90,
      74,    58,   -88,   -89,   -89,   -89,   -89,   -35,    -4,   -89,
     -28,     6,     0,   -89,   -89,     7
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,    17,    18,    41,
      32,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    78,    79
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      55,    56,     1,     2,    66,    61,    12,    67,    57,    13,
      35,   102,   103,    14,    68,    66,   105,    35,    67,    25,
      60,    77,    80,    81,    82,    69,    70,    71,    72,    73,
      84,    36,    37,    38,    39,    35,    40,    16,    36,    37,
      88,    89,    90,    91,    92,    93,    30,    16,    13,     9,
      31,    30,    14,     1,    15,    31,    36,    37,    74,    11,
      75,    77,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    86,    87,    94,    95,    19,   -14,    21,    20,
      23,    22,    25,    28,    34,    24,    58,    29,    59,    65,
      64,    62,    76,    96,    83,    97,    99,   100,    10,   104,
      98,    63,     0,   101,    33,     0,     0,     0,     0,     0,
      27,    26
};

static const yytype_int8 yycheck[] =
{
      35,     8,    22,    23,     3,    40,     8,     6,    15,    11,
       8,    99,   100,    15,    13,     3,   104,     8,     6,    17,
      11,    56,    57,    58,    59,    24,    25,    26,    27,    28,
      65,    29,    30,    31,    32,     8,    34,    12,    29,    30,
      68,    69,    70,    71,    72,    73,    25,    22,    11,     0,
      25,    30,    15,    22,    23,    30,    29,    30,     5,    29,
       7,    96,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    66,    67,    74,    75,    30,    10,    10,    29,
      16,    12,    17,    11,    29,    15,     8,    16,     8,    14,
      11,    18,    10,    12,    11,    10,    10,    10,     5,    33,
      16,    43,    -1,    96,    30,    -1,    -1,    -1,    -1,    -1,
      22,    21
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    22,    23,    36,    37,    38,    39,    40,    41,     0,
      37,    29,     8,    11,    15,    23,    40,    42,    43,    30,
      29,    10,    12,    16,    15,    17,    44,    42,    11,    16,
      39,    40,    45,    45,    29,     8,    29,    30,    31,    32,
      34,    44,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    52,     8,    15,     8,     8,
      11,    52,    18,    46,    11,    14,     3,     6,    13,    24,
      25,    26,    27,    28,     5,     7,    10,    52,    59,    60,
      52,    52,    52,    11,    52,    53,    56,    56,    55,    55,
      55,    55,    55,    55,    57,    57,    12,    10,    16,    10,
      10,    60,    47,    47,    33,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    39,    39,    40,
      40,    41,    42,    42,    42,    43,    43,    44,    45,    45,
      46,    46,    47,    47,    47,    47,    47,    48,    49,    49,
      50,    51,    51,    52,    52,    53,    53,    54,    54,    54,
      54,    54,    54,    54,    55,    55,    55,    56,    56,    56,
      57,    57,    57,    57,    58,    59,    59,    60,    60
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       1,     6,     3,     1,     1,     2,     4,     4,     2,     0,
       2,     0,     1,     1,     1,     1,     1,     2,     5,     7,
       5,     2,     3,     3,     1,     1,     4,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     1,     1,     1,     4,     1,     0,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: declaration-list  */
#line 106 "parser.y"
                             {
       parser_result = (yyvsp[0].decl);
       }
#line 1650 "parser.c"
    break;

  case 3: /* declaration-list: declaration declaration-list  */
#line 110 "parser.y"
                                               {
        (yyval.decl) = (yyvsp[-1].decl); (yyvsp[-1].decl)->next=(yyvsp[0].decl);
}
#line 1658 "parser.c"
    break;

  case 4: /* declaration-list: declaration  */
#line 112 "parser.y"
                 {
        (yyval.decl) = (yyvsp[0].decl);
        }
#line 1666 "parser.c"
    break;

  case 5: /* declaration: var-declaration  */
#line 116 "parser.y"
                             {(yyval.decl) = (yyvsp[0].decl);}
#line 1672 "parser.c"
    break;

  case 6: /* declaration: fun-declaration  */
#line 116 "parser.y"
                                                          {(yyval.decl) = (yyvsp[0].decl);}
#line 1678 "parser.c"
    break;

  case 7: /* var-declaration: type ID SEMICOLON  */
#line 118 "parser.y"
                                   {
            (yyval.decl) = createDecl(SIMPLE_DECL, (yyvsp[-1].id), 0, (yyvsp[-2].type), 0, 0, 0, yylineno);
        }
#line 1686 "parser.c"
    break;

  case 8: /* var-declaration: type ID O_BRACKET NUM C_BRACKET SEMICOLON  */
#line 121 "parser.y"
                                                        {(yyval.decl) = createDecl(ARRAY_DECL, (yyvsp[-4].id), (yyvsp[-2].num), (yyvsp[-5].type), 0, 0, 0, yylineno);}
#line 1692 "parser.c"
    break;

  case 9: /* type: INT  */
#line 123 "parser.y"
          {(yyval.type) = createType(INT_TYPE, 0, 0);}
#line 1698 "parser.c"
    break;

  case 10: /* type: VOID  */
#line 123 "parser.y"
                                                    {(yyval.type) = createType(VOID_TYPE, 0, 0);}
#line 1704 "parser.c"
    break;

  case 11: /* fun-declaration: type ID O_PAREN param-list C_PAREN compound_stmt  */
#line 126 "parser.y"
{
    (yyval.decl) = createDecl(FUNCTION_DECL, (yyvsp[-4].id), 0, (yyvsp[-5].type), (yyvsp[-2].param), (yyvsp[0].stmt), 0, yylineno);
    (yyvsp[0].stmt)->parent = (yyval.decl);
}
#line 1713 "parser.c"
    break;

  case 12: /* param-list: param COMMA param-list  */
#line 131 "parser.y"
                                   { (yyval.param) = (yyvsp[-2].param); (yyvsp[-2].param)->next=(yyvsp[0].param);}
#line 1719 "parser.c"
    break;

  case 13: /* param-list: param  */
#line 132 "parser.y"
                    { (yyval.param) = (yyvsp[0].param);}
#line 1725 "parser.c"
    break;

  case 14: /* param-list: VOID  */
#line 133 "parser.y"
                   {(yyval.param) = createParam(VOID_PARAM,0,0,0, yylineno);}
#line 1731 "parser.c"
    break;

  case 15: /* param: type ID  */
#line 135 "parser.y"
               {(yyval.param) = createParam(SIMPLE_PARAM,(yyvsp[-1].type), (yyvsp[0].id), 0,yylineno);}
#line 1737 "parser.c"
    break;

  case 16: /* param: type ID O_BRACKET C_BRACKET  */
#line 136 "parser.y"
                                   {(yyval.param) = createParam(ARRAY_PARAM, (yyvsp[-3].type), (yyvsp[-2].id), 0, yylineno);}
#line 1743 "parser.c"
    break;

  case 17: /* compound_stmt: O_BRACE local-declarations statement-list C_BRACE  */
#line 138 "parser.y"
                                                                 {
(yyval.stmt) = createStmt(COMPOUND_STMT, (yyvsp[-2].decl),0,0,0,(yyvsp[-1].stmt), yylineno);
}
#line 1751 "parser.c"
    break;

  case 18: /* local-declarations: var-declaration local-declarations  */
#line 142 "parser.y"
                                                       {(yyval.decl) = (yyvsp[-1].decl); (yyvsp[-1].decl)->next=(yyvsp[0].decl);}
#line 1757 "parser.c"
    break;

  case 19: /* local-declarations: %empty  */
#line 142 "parser.y"
                                                                                  {(yyval.decl) = 0;}
#line 1763 "parser.c"
    break;

  case 20: /* statement-list: statement statement-list  */
#line 144 "parser.y"
                                         {(yyval.stmt) = (yyvsp[-1].stmt); (yyvsp[-1].stmt)->next=(yyvsp[0].stmt);}
#line 1769 "parser.c"
    break;

  case 21: /* statement-list: %empty  */
#line 144 "parser.y"
                                                                   {(yyval.stmt) = 0;}
#line 1775 "parser.c"
    break;

  case 22: /* statement: expression_stmt  */
#line 146 "parser.y"
                           {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1781 "parser.c"
    break;

  case 23: /* statement: compound_stmt  */
#line 146 "parser.y"
                                                      {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1787 "parser.c"
    break;

  case 24: /* statement: selection_stmt  */
#line 147 "parser.y"
                          {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1793 "parser.c"
    break;

  case 25: /* statement: iteration_stmt  */
#line 147 "parser.y"
                                                      {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1799 "parser.c"
    break;

  case 26: /* statement: return_stmt  */
#line 148 "parser.y"
                     {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1805 "parser.c"
    break;

  case 27: /* expression_stmt: expression SEMICOLON  */
#line 150 "parser.y"
                                      { (yyval.stmt) = createStmt(EXPR_STMT, 0, (yyvsp[-1].expr), 0,0,0,yylineno);}
#line 1811 "parser.c"
    break;

  case 28: /* selection_stmt: IF O_PAREN expression C_PAREN statement  */
#line 152 "parser.y"
                                                        {
                (yyval.stmt) = createStmt(SELECT_STMT, 0, (yyvsp[-2].expr), (yyvsp[0].stmt), 0,0, yylineno);}
#line 1818 "parser.c"
    break;

  case 29: /* selection_stmt: IF O_PAREN expression C_PAREN statement ELSE statement  */
#line 154 "parser.y"
                                                                       {
                (yyval.stmt) = createStmt(SELECT_STMT, 0, (yyvsp[-4].expr), (yyvsp[-2].stmt),(yyvsp[0].stmt),0, yylineno);}
#line 1825 "parser.c"
    break;

  case 30: /* iteration_stmt: WHILE O_PAREN expression C_PAREN statement  */
#line 157 "parser.y"
                                                           {
              (yyval.stmt) = createStmt(ITER_STMT, 0, (yyvsp[-2].expr), (yyvsp[0].stmt),0,0, yylineno);}
#line 1832 "parser.c"
    break;

  case 31: /* return_stmt: RETURN SEMICOLON  */
#line 160 "parser.y"
                              {(yyval.stmt) = createStmt(RETURN_STMT,0,0,0,0,0, yylineno);}
#line 1838 "parser.c"
    break;

  case 32: /* return_stmt: RETURN expression SEMICOLON  */
#line 160 "parser.y"
                                                                                                                {
           (yyval.stmt) = createStmt(RETURN_STMT, 0, (yyvsp[-1].expr),0,0,0, yylineno);}
#line 1845 "parser.c"
    break;

  case 33: /* expression: var ASSIGN expression  */
#line 163 "parser.y"
                                  {
          (yyval.expr) = createExpr(ASSIGN_EXPR, (yyvsp[-2].var), (yyvsp[0].expr), 0, 0, yylineno);}
#line 1852 "parser.c"
    break;

  case 34: /* expression: simple_expression  */
#line 164 "parser.y"
                                                                                     {(yyval.expr) = (yyvsp[0].expr);}
#line 1858 "parser.c"
    break;

  case 35: /* var: ID  */
#line 166 "parser.y"
        {(yyval.var) = createExpr(VAR_EXPR, 0, 0,0, (yyvsp[0].id), yylineno);}
#line 1864 "parser.c"
    break;

  case 36: /* var: ID O_BRACKET expression C_BRACKET  */
#line 167 "parser.y"
                                       {(yyval.var) = createExpr(VAR_EXPR, 0,(yyvsp[-1].expr),0, (yyvsp[-3].id), yylineno);}
#line 1870 "parser.c"
    break;

  case 37: /* simple_expression: additive_expression LESSER additive_expression  */
#line 169 "parser.y"
                                                                   {(yyval.expr) = createExpr(LESSER_EXPR, (yyvsp[-2].expr), (yyvsp[0].expr), 0, 0, yylineno);}
#line 1876 "parser.c"
    break;

  case 38: /* simple_expression: additive_expression GREATER additive_expression  */
#line 170 "parser.y"
                                                                   {(yyval.expr) = createExpr(GREATER_EXPR, (yyvsp[-2].expr), (yyvsp[0].expr),0, 0, yylineno);}
#line 1882 "parser.c"
    break;

  case 39: /* simple_expression: additive_expression LESSER_EQ additive_expression  */
#line 171 "parser.y"
                                                                     {(yyval.expr) = createExpr(LESSER_EQ_EXPR, (yyvsp[-2].expr), (yyvsp[0].expr), 0, 0, yylineno);}
#line 1888 "parser.c"
    break;

  case 40: /* simple_expression: additive_expression GREATER_EQ additive_expression  */
#line 172 "parser.y"
                                                                      {(yyval.expr) = createExpr(GREATER_EQ_EXPR, (yyvsp[-2].expr), (yyvsp[0].expr), 0, 0, yylineno);}
#line 1894 "parser.c"
    break;

  case 41: /* simple_expression: additive_expression EQ additive_expression  */
#line 173 "parser.y"
                                                              {(yyval.expr) = createExpr(EQ_EXPR, (yyvsp[-2].expr), (yyvsp[0].expr), 0, 0, yylineno);}
#line 1900 "parser.c"
    break;

  case 42: /* simple_expression: additive_expression NOT_EQ additive_expression  */
#line 174 "parser.y"
                                                                  {(yyval.expr) = createExpr(NOT_EQ_EXPR, (yyvsp[-2].expr), (yyvsp[0].expr), 0, 0, yylineno);}
#line 1906 "parser.c"
    break;

  case 43: /* simple_expression: additive_expression  */
#line 175 "parser.y"
                                       {(yyval.expr) = (yyvsp[0].expr);}
#line 1912 "parser.c"
    break;

  case 44: /* additive_expression: additive_expression PLUS term  */
#line 177 "parser.y"
                                                   {(yyval.expr) = createExpr(ADD_EXPR, (yyvsp[-2].expr), (yyvsp[0].expr), 0,0, yylineno);}
#line 1918 "parser.c"
    break;

  case 45: /* additive_expression: additive_expression MINUS term  */
#line 178 "parser.y"
                                                     {(yyval.expr) = createExpr(SUB_EXPR, (yyvsp[-2].expr), (yyvsp[0].expr), 0,0, yylineno);}
#line 1924 "parser.c"
    break;

  case 46: /* additive_expression: term  */
#line 179 "parser.y"
                           {(yyval.expr) = (yyvsp[0].expr);}
#line 1930 "parser.c"
    break;

  case 47: /* term: term DIV factor  */
#line 181 "parser.y"
                        {(yyval.expr) = createExpr(DIV_EXPR, (yyvsp[-2].expr), (yyvsp[0].expr), 0,0, yylineno);}
#line 1936 "parser.c"
    break;

  case 48: /* term: term MULT factor  */
#line 182 "parser.y"
                        {(yyval.expr) = createExpr(MULT_EXPR, (yyvsp[-2].expr), (yyvsp[0].expr), 0,0, yylineno);}
#line 1942 "parser.c"
    break;

  case 49: /* term: factor  */
#line 183 "parser.y"
                {(yyval.expr) = (yyvsp[0].expr);}
#line 1948 "parser.c"
    break;

  case 50: /* factor: O_PAREN expression C_PAREN  */
#line 185 "parser.y"
                                   {(yyval.expr) = (yyvsp[-1].expr);}
#line 1954 "parser.c"
    break;

  case 51: /* factor: var  */
#line 186 "parser.y"
            {(yyval.expr) = (yyvsp[0].var);}
#line 1960 "parser.c"
    break;

  case 52: /* factor: call  */
#line 187 "parser.y"
             {(yyval.expr) = (yyvsp[0].stmt);}
#line 1966 "parser.c"
    break;

  case 53: /* factor: NUM  */
#line 188 "parser.y"
            {(yyval.expr) = createExpr(NUM_EXPR, 0, 0, (yyvsp[0].num),0, yylineno);}
#line 1972 "parser.c"
    break;

  case 54: /* call: ID O_PAREN args C_PAREN  */
#line 190 "parser.y"
                              {(yyval.stmt) = createExpr(CALL_EXPR, 0,(yyvsp[-1].expr),0,(yyvsp[-3].id), yylineno);}
#line 1978 "parser.c"
    break;

  case 55: /* args: arg_list  */
#line 192 "parser.y"
               {(yyval.expr) = (yyvsp[0].expr);}
#line 1984 "parser.c"
    break;

  case 56: /* args: %empty  */
#line 192 "parser.y"
                             {(yyval.expr) = 0;}
#line 1990 "parser.c"
    break;

  case 57: /* arg_list: expression COMMA arg_list  */
#line 194 "parser.y"
                                    {(yyval.expr) = createExpr(ARG_EXPR,(yyvsp[-2].expr),0,0,0, yylineno); (yyvsp[-2].expr)->right=(yyvsp[0].expr);}
#line 1996 "parser.c"
    break;

  case 58: /* arg_list: expression  */
#line 194 "parser.y"
                                                                                                               {(yyval.expr) = createExpr(ARG_EXPR,(yyvsp[0].expr),0,0,0, yylineno);}
#line 2002 "parser.c"
    break;


#line 2006 "parser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 196 "parser.y"


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
        scope_enter(&table_stack);
        decl_resolve(&table_stack, parser_result);
        scope_exit(&table_stack);
    }else {
        result = yyerror("parsing failed");
    }

    return result;

}

int yyerror(char *msg){
    fprintf(stderr,"Error | Line: %d\n%s\n",yylineno,msg);
    return 1;
}
