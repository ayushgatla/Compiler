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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex(void);

typedef struct {
    int isInitialized;
    int isString;
    int num;
    char* str;
    
} var;

var vars[26] = {0};
int tempCount = 0;

char* newTemp() {
    char* temp = malloc(10);
    sprintf(temp, "t%d", tempCount++);
    return temp;
}
int labelCount = 0;

char* newLabel() {
    char* label = malloc(10);
    sprintf(label, "L%d", labelCount++);
    return label;
}
char* labelStack[100];
int top = -1;

void pushLabel(char* l) {
    labelStack[++top] = l;
}

char* popLabel() {
    return labelStack[top--];
}
char* IR[1000];
int irIndex = 0;

void emit(char* code) {
    IR[irIndex++] = strdup(code);
}

#line 120 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_STRING = 5,                     /* STRING  */
  YYSYMBOL_LT = 6,                         /* LT  */
  YYSYMBOL_GT = 7,                         /* GT  */
  YYSYMBOL_LE = 8,                         /* LE  */
  YYSYMBOL_GE = 9,                         /* GE  */
  YYSYMBOL_EQ = 10,                        /* EQ  */
  YYSYMBOL_NE = 11,                        /* NE  */
  YYSYMBOL_PRINT = 12,                     /* PRINT  */
  YYSYMBOL_SCAN = 13,                      /* SCAN  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_WHILE = 16,                     /* WHILE  */
  YYSYMBOL_RETURN = 17,                    /* RETURN  */
  YYSYMBOL_PLUS = 18,                      /* PLUS  */
  YYSYMBOL_MINUS = 19,                     /* MINUS  */
  YYSYMBOL_MUL = 20,                       /* MUL  */
  YYSYMBOL_DIV = 21,                       /* DIV  */
  YYSYMBOL_REM = 22,                       /* REM  */
  YYSYMBOL_ASSIGN = 23,                    /* ASSIGN  */
  YYSYMBOL_LPAREN = 24,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 25,                    /* RPAREN  */
  YYSYMBOL_SEMICOLON = 26,                 /* SEMICOLON  */
  YYSYMBOL_YYACCEPT = 27,                  /* $accept  */
  YYSYMBOL_program = 28,                   /* program  */
  YYSYMBOL_stmt_list = 29,                 /* stmt_list  */
  YYSYMBOL_stmt = 30,                      /* stmt  */
  YYSYMBOL_31_1 = 31,                      /* $@1  */
  YYSYMBOL_32_2 = 32,                      /* $@2  */
  YYSYMBOL_optional_else = 33,             /* optional_else  */
  YYSYMBOL_expr = 34,                      /* expr  */
  YYSYMBOL_term = 35,                      /* term  */
  YYSYMBOL_factor = 36                     /* factor  */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   100

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  27
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  10
/* YYNRULES -- Number of rules.  */
#define YYNRULES  30
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  59

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   281


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
      25,    26
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    89,    89,    94,    95,    99,   123,   151,   158,   179,
     189,   197,   188,   223,   224,   229,   245,   260,   270,   280,
     290,   300,   310,   321,   329,   345,   361,   377,   385,   398,
     421
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "ID", "STRING",
  "LT", "GT", "LE", "GE", "EQ", "NE", "PRINT", "SCAN", "IF", "ELSE",
  "WHILE", "RETURN", "PLUS", "MINUS", "MUL", "DIV", "REM", "ASSIGN",
  "LPAREN", "RPAREN", "SEMICOLON", "$accept", "program", "stmt_list",
  "stmt", "$@1", "$@2", "optional_else", "expr", "term", "factor", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-15)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       6,   -14,    -2,    23,    22,    29,     6,   -15,     1,   -15,
     -15,    25,     4,     5,    18,   -15,    33,     4,   -15,   -15,
      34,    26,   -15,    47,     4,     4,     4,     4,     4,     4,
       4,     4,   -15,     4,     4,     4,   -15,    67,   -15,   -15,
     -15,    18,    18,    18,    18,    18,    18,    18,    18,   -15,
     -15,   -15,   -15,     6,   -15,    15,     6,   -15,   -15
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     4,     0,    28,
      29,     0,     0,     0,    23,    27,     0,     0,     1,     3,
       0,     0,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     0,     0,     0,     9,     0,     6,     5,
      30,    18,    17,    20,    19,    22,    21,    15,    16,    24,
      25,    26,    10,     0,    11,    14,     0,    12,    13
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -15,   -15,   -15,    -6,   -15,   -15,   -15,     9,    69,     8
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,     7,    53,    55,    57,    13,    14,    15
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      19,     9,    10,    11,     9,    10,    20,     9,    10,     8,
       1,    24,    25,    26,    27,    28,    29,    21,     2,     3,
       4,    23,    12,    30,    31,    12,    37,    16,    12,    18,
      56,    32,    24,    25,    26,    27,    28,    29,    33,    34,
      35,    49,    50,    51,    30,    31,    17,    54,     0,     0,
      58,    22,    39,    24,    25,    26,    27,    28,    29,    36,
      38,     0,     0,     0,     0,    30,    31,     0,     0,     0,
       0,     0,    40,    24,    25,    26,    27,    28,    29,     0,
       0,     0,     0,     0,     0,    30,    31,     0,     0,     0,
       0,     0,    52,    41,    42,    43,    44,    45,    46,    47,
      48
};

static const yytype_int8 yycheck[] =
{
       6,     3,     4,     5,     3,     4,     5,     3,     4,    23,
       4,     6,     7,     8,     9,    10,    11,     8,    12,    13,
      14,    12,    24,    18,    19,    24,    17,     4,    24,     0,
      15,    26,     6,     7,     8,     9,    10,    11,    20,    21,
      22,    33,    34,    35,    18,    19,    24,    53,    -1,    -1,
      56,    26,    26,     6,     7,     8,     9,    10,    11,    26,
      26,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,
      -1,    -1,    25,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,
      -1,    -1,    25,    24,    25,    26,    27,    28,    29,    30,
      31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    12,    13,    14,    28,    29,    30,    23,     3,
       4,     5,    24,    34,    35,    36,     4,    24,     0,    30,
       5,    34,    26,    34,     6,     7,     8,     9,    10,    11,
      18,    19,    26,    20,    21,    22,    26,    34,    26,    26,
      25,    35,    35,    35,    35,    35,    35,    35,    35,    36,
      36,    36,    25,    31,    30,    32,    15,    33,    30
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    27,    28,    29,    29,    30,    30,    30,    30,    30,
      31,    32,    30,    33,    33,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    35,    35,    35,    35,    36,    36,
      36
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     4,     4,     3,     3,     3,
       0,     0,     8,     2,     0,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     1,     1,     1,
       3
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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 5: /* stmt: ID ASSIGN expr SEMICOLON  */
#line 100 "parser.y"
       {

	    if(vars[(yyvsp[-3].id)].isInitialized) {
		if(vars[(yyvsp[-3].id)].isString != (yyvsp[-1].val).isString) {
		    printf("Type error: variable '%c' type mismatch\n", 'a' + (yyvsp[-3].id));
		    exit(1);
		}
	    }

	    vars[(yyvsp[-3].id)].isInitialized = 1;

	    if((yyvsp[-1].val).isString) {
		vars[(yyvsp[-3].id)].isString = 1;
		vars[(yyvsp[-3].id)].str = strdup((yyvsp[-1].val).str);
	    } else {
		vars[(yyvsp[-3].id)].isString = 0;
		vars[(yyvsp[-3].id)].num = (yyvsp[-1].val).num;
	    }
	    char buffer[100];
		sprintf(buffer, "%c = %s", 'a' + (yyvsp[-3].id), (yyvsp[-1].val).place);
		emit(buffer);
       }
#line 1200 "parser.tab.c"
    break;

  case 6: /* stmt: ID ASSIGN STRING SEMICOLON  */
#line 124 "parser.y"
        {
	    if(vars[(yyvsp[-3].id)].isInitialized && vars[(yyvsp[-3].id)].isString == 0) {
		printf("Type error: variable '%c' was int, cannot assign string\n", 'a' +(yyvsp[-3].id));
		exit(1);
	    }

	    vars[(yyvsp[-3].id)].isInitialized = 1;
	    vars[(yyvsp[-3].id)].isString = 1;
	    vars[(yyvsp[-3].id)].str = strdup((yyvsp[-1].str));
	    char* temp = newTemp();
char buffer1[200];
char* strval3 = (yyvsp[-1].str);
if(strval3[0] == '"') {
    char stripped[200];
    strncpy(stripped, strval3+1, strlen(strval3)-2);
    stripped[strlen(strval3)-2] = '\0';
    sprintf(buffer1, "%s = \"%s\"", temp, stripped);
} else {
    sprintf(buffer1, "%s = \"%s\"", temp, strval3);
}
emit(buffer1);

char buffer2[100];
sprintf(buffer2, "%c = %s", 'a' + (yyvsp[-3].id), temp);
emit(buffer2);
           }
#line 1231 "parser.tab.c"
    break;

  case 7: /* stmt: PRINT expr SEMICOLON  */
#line 152 "parser.y"
{
    char buffer[100];
    sprintf(buffer, "PRINT %s", (yyvsp[-1].val).place);
    emit(buffer);
}
#line 1241 "parser.tab.c"
    break;

  case 8: /* stmt: PRINT STRING SEMICOLON  */
#line 159 "parser.y"
{
    char* temp = newTemp();
    char buffer1[200];
    /* $2 may already have surrounding quotes from lexer — strip them */
    char* strval = (yyvsp[-1].str);
    if(strval[0] == '"') {
        char stripped[200];
        strncpy(stripped, strval+1, strlen(strval)-2);
        stripped[strlen(strval)-2] = '\0';
        sprintf(buffer1, "%s = \"%s\"", temp, stripped);
    } else {
        sprintf(buffer1, "%s = \"%s\"", temp, strval);
    }
    emit(buffer1);

    char buffer2[100];
    sprintf(buffer2, "PRINT %s", temp);
    emit(buffer2);
}
#line 1265 "parser.tab.c"
    break;

  case 9: /* stmt: SCAN ID SEMICOLON  */
#line 180 "parser.y"
{
    vars[(yyvsp[-1].id)].isInitialized = 1;
    vars[(yyvsp[-1].id)].isString = 0;   // assume input numeric for now

    char buffer[50];
    sprintf(buffer, "READ %c", 'a' + (yyvsp[-1].id));
    emit(buffer);
}
#line 1278 "parser.tab.c"
    break;

  case 10: /* $@1: %empty  */
#line 189 "parser.y"
    {
        char* elseLabel = newLabel();
        pushLabel(elseLabel);
        char buffer[100];
        sprintf(buffer, "ifFalse %s goto %s", (yyvsp[-1].val).place, elseLabel);
        emit(buffer);
    }
#line 1290 "parser.tab.c"
    break;

  case 11: /* $@2: %empty  */
#line 197 "parser.y"
    {
        char* endLabel = newLabel();
        pushLabel(endLabel);
        char buffer[100];
        sprintf(buffer, "goto %s", endLabel);
        emit(buffer);
        char buf2[100];
        sprintf(buf2, "%s:", labelStack[top-1]);
        emit(buf2);
    }
#line 1305 "parser.tab.c"
    break;

  case 12: /* stmt: IF LPAREN expr RPAREN $@1 stmt $@2 optional_else  */
#line 208 "parser.y"
    {
        char* endLabel = popLabel();
        popLabel();
        char buffer[100];
        sprintf(buffer, "%s:", endLabel);
        emit(buffer);
    }
#line 1317 "parser.tab.c"
    break;

  case 13: /* optional_else: ELSE stmt  */
#line 223 "parser.y"
                 { /* else body already parsed */ }
#line 1323 "parser.tab.c"
    break;

  case 14: /* optional_else: %empty  */
#line 224 "parser.y"
                 { /* no else — nothing to do */ }
#line 1329 "parser.tab.c"
    break;

  case 15: /* expr: expr PLUS term  */
#line 230 "parser.y"
        {
            if((yyvsp[-2].val).isString || (yyvsp[0].val).isString) {
                printf("Type error: cannot add string\n");
                exit(1);
            }
            (yyval.val).isString = 0;
		char* temp = newTemp();
		char buffer[100];
		sprintf(buffer, "%s = %s + %s", temp, (yyvsp[-2].val).place, (yyvsp[0].val).place);
		emit(buffer);

		(yyval.val).place = temp;
		(yyval.val).isString = 0;
        }
#line 1348 "parser.tab.c"
    break;

  case 16: /* expr: expr MINUS term  */
#line 246 "parser.y"
        {
            if((yyvsp[-2].val).isString || (yyvsp[0].val).isString) {
                printf("Type error: cannot subtract string\n");
                exit(1);
            }
            (yyval.val).isString = 0;
		char* temp = newTemp();
		char buffer[100];
		sprintf(buffer, "%s = %s - %s", temp, (yyvsp[-2].val).place, (yyvsp[0].val).place);
		emit(buffer);

		(yyval.val).place = temp;
		(yyval.val).isString = 0;
        }
#line 1367 "parser.tab.c"
    break;

  case 17: /* expr: expr GT term  */
#line 261 "parser.y"
{
    char* temp = newTemp();
    char buffer[100];
    sprintf(buffer, "%s = %s > %s", temp, (yyvsp[-2].val).place, (yyvsp[0].val).place);
    emit(buffer);

    (yyval.val).place = temp;
    (yyval.val).isString = 0;
}
#line 1381 "parser.tab.c"
    break;

  case 18: /* expr: expr LT term  */
#line 271 "parser.y"
{
    char* temp = newTemp();
    char buffer[100];
    sprintf(buffer, "%s = %s < %s", temp, (yyvsp[-2].val).place, (yyvsp[0].val).place);
    emit(buffer);

    (yyval.val).place = temp;
    (yyval.val).isString = 0;
}
#line 1395 "parser.tab.c"
    break;

  case 19: /* expr: expr GE term  */
#line 281 "parser.y"
{
    char* temp = newTemp();
    char buffer[100];
    sprintf(buffer, "%s = %s >= %s", temp, (yyvsp[-2].val).place, (yyvsp[0].val).place);
    emit(buffer);

    (yyval.val).place = temp;
    (yyval.val).isString = 0;
}
#line 1409 "parser.tab.c"
    break;

  case 20: /* expr: expr LE term  */
#line 291 "parser.y"
{
    char* temp = newTemp();
    char buffer[100];
    sprintf(buffer, "%s = %s <= %s", temp, (yyvsp[-2].val).place, (yyvsp[0].val).place);
    emit(buffer);

    (yyval.val).place = temp;
    (yyval.val).isString = 0;
}
#line 1423 "parser.tab.c"
    break;

  case 21: /* expr: expr NE term  */
#line 301 "parser.y"
{
    char* temp = newTemp();
    char buffer[100];
    sprintf(buffer, "%s = %s != %s", temp, (yyvsp[-2].val).place, (yyvsp[0].val).place);
    emit(buffer);

    (yyval.val).place = temp;
    (yyval.val).isString = 0;
}
#line 1437 "parser.tab.c"
    break;

  case 22: /* expr: expr EQ term  */
#line 311 "parser.y"
{
    char* temp = newTemp();
    char buffer[100];
    sprintf(buffer, "%s = %s == %s", temp, (yyvsp[-2].val).place, (yyvsp[0].val).place);
    emit(buffer);

    (yyval.val).place = temp;
    (yyval.val).isString = 0;
}
#line 1451 "parser.tab.c"
    break;

  case 23: /* expr: term  */
#line 322 "parser.y"
        {
            (yyval.val) = (yyvsp[0].val);
        }
#line 1459 "parser.tab.c"
    break;

  case 24: /* term: term MUL factor  */
#line 330 "parser.y"
        {
            if((yyvsp[-2].val).isString || (yyvsp[0].val).isString) {
                printf("Type error: cannot multiply string\n");
                exit(1);
            }
            (yyval.val).isString = 0;
		char* temp = newTemp();
		char buffer[100];
		sprintf(buffer, "%s = %s * %s", temp, (yyvsp[-2].val).place, (yyvsp[0].val).place);
		emit(buffer);

		(yyval.val).place = temp;
		(yyval.val).isString = 0;
        }
#line 1478 "parser.tab.c"
    break;

  case 25: /* term: term DIV factor  */
#line 346 "parser.y"
        {
            if((yyvsp[-2].val).isString || (yyvsp[0].val).isString) {
                printf("Type error: cannot divide string\n");
                exit(1);
            }
            (yyval.val).isString = 0;
	char* temp = newTemp();
	char buffer[100];
	sprintf(buffer, "%s = %s / %s", temp, (yyvsp[-2].val).place, (yyvsp[0].val).place);
	emit(buffer);

	(yyval.val).place = temp;
	(yyval.val).isString = 0;
        }
#line 1497 "parser.tab.c"
    break;

  case 26: /* term: term REM factor  */
#line 362 "parser.y"
{
    if((yyvsp[-2].val).isString || (yyvsp[0].val).isString) {
        printf("Type error: cannot mod string\n");
        exit(1);
    }

    char* temp = newTemp();
    char buffer[100];
    sprintf(buffer, "%s = %s %% %s", temp, (yyvsp[-2].val).place, (yyvsp[0].val).place);
    emit(buffer);

    (yyval.val).place = temp;
    (yyval.val).isString = 0;
}
#line 1516 "parser.tab.c"
    break;

  case 27: /* term: factor  */
#line 378 "parser.y"
        {
            (yyval.val) = (yyvsp[0].val);
        }
#line 1524 "parser.tab.c"
    break;

  case 28: /* factor: NUM  */
#line 386 "parser.y"
        {
            (yyval.val).isString = 0;
	    (yyval.val).num = (yyvsp[0].num);

		char* temp = newTemp();
		char buffer[100];
		sprintf(buffer, "%s = %d", temp, (yyvsp[0].num));
		emit(buffer);

		(yyval.val).place = temp;
        }
#line 1540 "parser.tab.c"
    break;

  case 29: /* factor: ID  */
#line 399 "parser.y"
        {
         if(!vars[(yyvsp[0].id)].isInitialized) {
		printf("Error: variable '%c' used before initialization\n", 'a' + (yyvsp[0].id));
		exit(1);
	    }

	    (yyval.val).isString = vars[(yyvsp[0].id)].isString;

	    if(vars[(yyvsp[0].id)].isString)
		(yyval.val).str = vars[(yyvsp[0].id)].str;
	    else
		(yyval.val).num = vars[(yyvsp[0].id)].num;

	    char* temp = newTemp();
	    char buffer[100];

	    sprintf(buffer, "%s = %c", temp, 'a' + (yyvsp[0].id));
	    emit(buffer);

	    (yyval.val).place = temp;
	 }
#line 1566 "parser.tab.c"
    break;

  case 30: /* factor: LPAREN expr RPAREN  */
#line 422 "parser.y"
        {
            (yyval.val) = (yyvsp[-1].val);
        }
#line 1574 "parser.tab.c"
    break;


#line 1578 "parser.tab.c"

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
      yyerror (YY_("syntax error"));
    }

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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 427 "parser.y"


void yyerror(const char *s) {
    printf("Syntax error: %s\n", s);
}
int main() {
    printf("Enter program:\n");
    yyparse();

    printf("\nGenerated IR:\n");
    FILE *fp = fopen("output.c", "w");

fprintf(fp, "#include <stdio.h>\n");
fprintf(fp, "int main() {\n");


for(int i = 0; i < 26; i++) {
    if(vars[i].isInitialized) {
        if(vars[i].isString)
            fprintf(fp, "char* %c;\n", 'a' + i);
        else
            fprintf(fp, "int %c;\n", 'a' + i);
    }
}


/* declare temps: string temps get char*, others get int */
for(int i = 0; i < tempCount; i++) {
    int isStrTemp = 0;
    char needle[20];
    sprintf(needle, "t%d = \"", i);
    for(int j = 0; j < irIndex; j++) {
        if(strncmp(IR[j], needle, strlen(needle)) == 0) {
            isStrTemp = 1; break;
        }
    }
    if(isStrTemp) fprintf(fp, "char* t%d;\n", i);
    else          fprintf(fp, "int t%d;\n", i);
}


for(int i = 0; i < irIndex; i++) {

    // READ
    if(strncmp(IR[i], "READ", 4) == 0) {
        char var;
        sscanf(IR[i], "READ %c", &var);
        fprintf(fp, "scanf(\"%%d\", &%c);\n", var);
    }

    // PRINT — detect string temp vs int temp
    else if(strncmp(IR[i], "PRINT", 5) == 0) {
        char var[20];
        sscanf(IR[i], "PRINT %s", var);
        /* check if this var is a string temp */
        int isStr = 0;
        char needle[30];
        sprintf(needle, "%s = \"", var);
        for(int j = 0; j < irIndex; j++) {
            if(strncmp(IR[j], needle, strlen(needle)) == 0) { isStr = 1; break; }
        }
        if(isStr) fprintf(fp, "printf(\"%%s\\n\", %s);\n", var);
        else      fprintf(fp, "printf(\"%%d\\n\", %s);\n", var);
    }

    // ifFalse → convert to valid C
    else if(strncmp(IR[i], "ifFalse", 7) == 0) {
        char cond[20], label[20];
        sscanf(IR[i], "ifFalse %s goto %s", cond, label);
        fprintf(fp, "if (!%s) goto %s;\n", cond, label);
    }

    // goto
    else if(strncmp(IR[i], "goto", 4) == 0) {
        char label[20];
        sscanf(IR[i], "goto %s", label);
        fprintf(fp, "goto %s;\n", label);
    }

    // label (ends with :)
    else if(strchr(IR[i], ':')) {
        fprintf(fp, "%s\n", IR[i]);
    }

    // normal assignment
    else {
        fprintf(fp, "%s;\n", IR[i]);
    }
}

fprintf(fp, "return 0;\n}");
fclose(fp);

printf("\nC code generated in output.c\n");

    return 0;
}
