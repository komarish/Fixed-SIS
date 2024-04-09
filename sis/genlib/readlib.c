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
   especially those whose name start with YY_ or GENLIB_yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with GENLIB_yy or YY, to avoid
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
#line 2 "readlib.y"

/* file @(#)readlib.y	1.2                      */
/* last modified on 6/13/91 at 17:46:40   */
#include <setjmp.h>
#include "genlib_int.h"
#include "config.h"

#undef GENLIB_yywrap 
static int input();
static int unput();
static int GENLIB_yywrap();

FILE *gl_out_file;
#if YYTEXT_POINTER
extern char *GENLIB_yytext;
#else
extern char GENLIB_yytext[];
#endif

static int global_use_nor;
static function_t *global_fct;

extern int library_setup_string(char *);
extern int library_setup_file(FILE *, char *);


#line 98 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int GENLIB_yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum GENLIB_yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    OPR_OR = 258,                  /* OPR_OR  */
    OPR_AND = 259,                 /* OPR_AND  */
    CONST1 = 260,                  /* CONST1  */
    CONST0 = 261,                  /* CONST0  */
    IDENTIFIER = 262,              /* IDENTIFIER  */
    LPAREN = 263,                  /* LPAREN  */
    REAL = 264,                    /* REAL  */
    OPR_NOT = 265,                 /* OPR_NOT  */
    OPR_NOT_POST = 266,            /* OPR_NOT_POST  */
    GATE = 267,                    /* GATE  */
    PIN = 268,                     /* PIN  */
    SEMI = 269,                    /* SEMI  */
    ASSIGN = 270,                  /* ASSIGN  */
    RPAREN = 271,                  /* RPAREN  */
    LATCH = 272,                   /* LATCH  */
    CONTROL = 273,                 /* CONTROL  */
    CONSTRAINT = 274,              /* CONSTRAINT  */
    SEQ = 275                      /* SEQ  */
  };
  typedef enum GENLIB_yytokentype GENLIB_yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define OPR_OR 258
#define OPR_AND 259
#define CONST1 260
#define CONST0 261
#define IDENTIFIER 262
#define LPAREN 263
#define REAL 264
#define OPR_NOT 265
#define OPR_NOT_POST 266
#define GATE 267
#define PIN 268
#define SEMI 269
#define ASSIGN 270
#define RPAREN 271
#define LATCH 272
#define CONTROL 273
#define CONSTRAINT 274
#define SEQ 275

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 29 "readlib.y"

    tree_node_t *nodeval;
    char *strval;
    double realval; 
    pin_info_t *pinval;
    function_t *functionval;
    latch_info_t *latchval;
    constraint_info_t *constrval;

#line 201 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE GENLIB_yylval;


int GENLIB_yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum GENLIB_yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_OPR_OR = 3,                     /* OPR_OR  */
  YYSYMBOL_OPR_AND = 4,                    /* OPR_AND  */
  YYSYMBOL_CONST1 = 5,                     /* CONST1  */
  YYSYMBOL_CONST0 = 6,                     /* CONST0  */
  YYSYMBOL_IDENTIFIER = 7,                 /* IDENTIFIER  */
  YYSYMBOL_LPAREN = 8,                     /* LPAREN  */
  YYSYMBOL_REAL = 9,                       /* REAL  */
  YYSYMBOL_OPR_NOT = 10,                   /* OPR_NOT  */
  YYSYMBOL_OPR_NOT_POST = 11,              /* OPR_NOT_POST  */
  YYSYMBOL_GATE = 12,                      /* GATE  */
  YYSYMBOL_PIN = 13,                       /* PIN  */
  YYSYMBOL_SEMI = 14,                      /* SEMI  */
  YYSYMBOL_ASSIGN = 15,                    /* ASSIGN  */
  YYSYMBOL_RPAREN = 16,                    /* RPAREN  */
  YYSYMBOL_LATCH = 17,                     /* LATCH  */
  YYSYMBOL_CONTROL = 18,                   /* CONTROL  */
  YYSYMBOL_CONSTRAINT = 19,                /* CONSTRAINT  */
  YYSYMBOL_SEQ = 20,                       /* SEQ  */
  YYSYMBOL_YYACCEPT = 21,                  /* $accept  */
  YYSYMBOL_hack = 22,                      /* hack  */
  YYSYMBOL_gates = 23,                     /* gates  */
  YYSYMBOL_gate_info = 24,                 /* gate_info  */
  YYSYMBOL_pins = 25,                      /* pins  */
  YYSYMBOL_pin_info = 26,                  /* pin_info  */
  YYSYMBOL_pin_phase = 27,                 /* pin_phase  */
  YYSYMBOL_pin_name = 28,                  /* pin_name  */
  YYSYMBOL_function = 29,                  /* function  */
  YYSYMBOL_expr = 30,                      /* expr  */
  YYSYMBOL_name = 31,                      /* name  */
  YYSYMBOL_real = 32,                      /* real  */
  YYSYMBOL_clock = 33,                     /* clock  */
  YYSYMBOL_constraints = 34,               /* constraints  */
  YYSYMBOL_constraint = 35,                /* constraint  */
  YYSYMBOL_latch = 36,                     /* latch  */
  YYSYMBOL_type = 37                       /* type  */
};
typedef enum GENLIB_yysymbol_kind_t GENLIB_yysymbol_kind_t;




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
typedef __INT_LEAST8_TYPE__ GENLIB_yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t GENLIB_yytype_int8;
#else
typedef signed char GENLIB_yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ GENLIB_yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t GENLIB_yytype_int16;
#else
typedef short GENLIB_yytype_int16;
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
typedef __UINT_LEAST8_TYPE__ GENLIB_yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t GENLIB_yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char GENLIB_yytype_uint8;
#else
typedef short GENLIB_yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ GENLIB_yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t GENLIB_yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short GENLIB_yytype_uint16;
#else
typedef int GENLIB_yytype_uint16;
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
typedef GENLIB_yytype_int8 GENLIB_yy_state_t;

/* State numbers in computations.  */
typedef int GENLIB_yy_state_fast_t;

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

/* Suppress an incorrect diagnostic about GENLIB_yylval being uninitialized.  */
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

#if !defined GENLIB_yyoverflow

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
#endif /* !defined GENLIB_yyoverflow */

#if (! defined GENLIB_yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union GENLIB_yyalloc
{
  GENLIB_yy_state_t GENLIB_yyss_alloc;
  YYSTYPE GENLIB_yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union GENLIB_yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (GENLIB_yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T GENLIB_yynewbytes;                                         \
        YYCOPY (&GENLIB_yyptr->Stack_alloc, Stack, GENLIB_yysize);                    \
        Stack = &GENLIB_yyptr->Stack_alloc;                                    \
        GENLIB_yynewbytes = GENLIB_yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        GENLIB_yyptr += GENLIB_yynewbytes / YYSIZEOF (*GENLIB_yyptr);                        \
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
          YYPTRDIFF_T GENLIB_yyi;                      \
          for (GENLIB_yyi = 0; GENLIB_yyi < (Count); GENLIB_yyi++)   \
            (Dst)[GENLIB_yyi] = (Src)[GENLIB_yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   93

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  21
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  33
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  71

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   275


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by GENLIB_yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (GENLIB_yysymbol_kind_t, GENLIB_yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by GENLIB_yylex.  */
static const GENLIB_yytype_int8 GENLIB_yytranslate[] =
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
      15,    16,    17,    18,    19,    20
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const GENLIB_yytype_uint8 GENLIB_yyrline[] =
{
       0,    57,    57,    58,    62,    63,    66,    71,    79,    80,
      84,    96,   109,   111,   115,   124,   132,   140,   148,   152,
     157,   162,   169,   175,   183,   186,   190,   195,   196,   211,
     212,   219,   229,   238
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (GENLIB_yysymbol_kind_t, GENLIB_yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *GENLIB_yysymbol_name (GENLIB_yysymbol_kind_t GENLIB_yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const GENLIB_yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "OPR_OR", "OPR_AND",
  "CONST1", "CONST0", "IDENTIFIER", "LPAREN", "REAL", "OPR_NOT",
  "OPR_NOT_POST", "GATE", "PIN", "SEMI", "ASSIGN", "RPAREN", "LATCH",
  "CONTROL", "CONSTRAINT", "SEQ", "$accept", "hack", "gates", "gate_info",
  "pins", "pin_info", "pin_phase", "pin_name", "function", "expr", "name",
  "real", "clock", "constraints", "constraint", "latch", "type", YY_NULLPTR
};

static const char *
GENLIB_yysymbol_name (GENLIB_yysymbol_kind_t GENLIB_yysymbol)
{
  return GENLIB_yytname[GENLIB_yysymbol];
}
#endif

#define YYPACT_NINF (-11)

#define GENLIB_yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define GENLIB_yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const GENLIB_yytype_int8 GENLIB_yypact[] =
{
      11,   -11,   -11,    13,    -7,   -11,    17,   -11,    11,    11,
     -11,    83,    26,    26,   -11,   -11,    83,    83,    65,   -11,
     -11,    11,    11,    20,   -11,    83,    83,   -11,   -11,    -8,
     -11,   -11,   -11,    76,    -8,    25,    -9,    10,   -11,    11,
      22,   -11,    11,   -11,    11,    11,   -11,    26,   -11,    34,
      26,    24,    26,   -11,   -11,    26,    10,   -11,    26,    26,
      26,    26,    26,    26,    26,    26,   -11,    26,    26,   -11,
     -11
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const GENLIB_yytype_int8 GENLIB_yydefact[] =
{
       4,    24,    25,     0,     2,     3,     0,     1,     0,     0,
       5,     0,     0,     0,    23,    22,     0,     0,     0,    21,
      26,     0,     0,     0,    19,     0,     0,    20,    14,    17,
       8,     8,    18,    15,    16,     6,     0,     0,     9,     0,
      27,    13,     0,    12,     0,     0,    29,     0,    11,     0,
       0,     7,     0,    33,    32,     0,     0,    30,     0,     0,
       0,     0,     0,     0,     0,     0,    31,     0,     0,    10,
      28
};

/* YYPGOTO[NTERM-NUM].  */
static const GENLIB_yytype_int8 GENLIB_yypgoto[] =
{
     -11,   -11,   -11,   -11,    16,   -11,   -11,    -6,    12,   -10,
       0,    -1,   -11,   -11,   -11,   -11,   -11
};

/* YYDEFGOTO[NTERM-NUM].  */
static const GENLIB_yytype_int8 GENLIB_yydefgoto[] =
{
       0,     3,     4,    10,    35,    38,    47,    42,     5,    29,
      19,    21,    46,    51,    57,    40,    54
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const GENLIB_yytype_int8 GENLIB_yytable[] =
{
       6,    18,    17,    27,    37,     8,    23,    24,    12,    13,
       9,    39,    22,     7,    41,    33,    34,     1,     1,     2,
       2,     6,     6,    25,    26,    14,    15,     1,    16,     2,
      17,    27,    11,    30,    31,    20,    32,    43,    37,    44,
      45,    53,    48,    56,    49,    50,    52,    36,     0,    55,
      60,    58,     0,     0,    59,     0,    43,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    25,    26,
      14,    15,     1,    16,     2,    17,    27,     0,     0,    28,
      26,    14,    15,     1,    16,     2,    17,    27,    14,    15,
       1,    16,     2,    17
};

static const GENLIB_yytype_int8 GENLIB_yycheck[] =
{
       0,    11,    10,    11,    13,    12,    16,    17,     8,     9,
      17,    20,    13,     0,     4,    25,    26,     7,     7,     9,
       9,    21,    22,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    15,    21,    22,     9,    16,    37,    13,    39,
      18,     7,    42,    19,    44,    45,    47,    31,    -1,    50,
      56,    52,    -1,    -1,    55,    -1,    56,    58,    59,    60,
      61,    62,    63,    64,    65,    -1,    67,    68,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    14,
       4,     5,     6,     7,     8,     9,    10,    11,     5,     6,
       7,     8,     9,    10
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const GENLIB_yytype_int8 GENLIB_yystos[] =
{
       0,     7,     9,    22,    23,    29,    31,     0,    12,    17,
      24,    15,    31,    31,     5,     6,     8,    10,    30,    31,
       9,    32,    32,    30,    30,     3,     4,    11,    14,    30,
      29,    29,    16,    30,    30,    25,    25,    13,    26,    20,
      36,     4,    28,    31,    31,    18,    33,    27,    31,    31,
      31,    34,    32,     7,    37,    32,    19,    35,    32,    32,
      28,    32,    32,    32,    32,    32,    32,    32,    32,    32,
      32
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const GENLIB_yytype_int8 GENLIB_yyr1[] =
{
       0,    21,    22,    22,    23,    23,    24,    24,    25,    25,
      26,    27,    28,    28,    29,    30,    30,    30,    30,    30,
      30,    30,    30,    30,    31,    31,    32,    33,    33,    34,
      34,    35,    36,    37
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const GENLIB_yytype_int8 GENLIB_yyr2[] =
{
       0,     2,     1,     1,     0,     2,     5,     8,     0,     2,
       9,     1,     1,     1,     4,     3,     3,     2,     3,     2,
       2,     1,     1,     1,     1,     1,     1,     0,     8,     0,
       2,     4,     4,     1
};


enum { YYENOMEM = -2 };

#define GENLIB_yyerrok         (GENLIB_yyerrstatus = 0)
#define GENLIB_yyclearin       (GENLIB_yychar = YYEMPTY)

#define YYACCEPT        goto GENLIB_yyacceptlab
#define YYABORT         goto GENLIB_yyabortlab
#define YYERROR         goto GENLIB_yyerrorlab
#define YYNOMEM         goto GENLIB_yyexhaustedlab


#define YYRECOVERING()  (!!GENLIB_yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (GENLIB_yychar == YYEMPTY)                                        \
      {                                                           \
        GENLIB_yychar = (Token);                                         \
        GENLIB_yylval = (Value);                                         \
        YYPOPSTACK (GENLIB_yylen);                                       \
        GENLIB_yystate = *GENLIB_yyssp;                                         \
        goto GENLIB_yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        GENLIB_yyerror (YY_("syntax error: cannot back up")); \
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
  if (GENLIB_yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (GENLIB_yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      GENLIB_yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
GENLIB_yy_symbol_value_print (FILE *GENLIB_yyo,
                       GENLIB_yysymbol_kind_t GENLIB_yykind, YYSTYPE const * const GENLIB_yyvaluep)
{
  FILE *GENLIB_yyoutput = GENLIB_yyo;
  YY_USE (GENLIB_yyoutput);
  if (!GENLIB_yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (GENLIB_yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
GENLIB_yy_symbol_print (FILE *GENLIB_yyo,
                 GENLIB_yysymbol_kind_t GENLIB_yykind, YYSTYPE const * const GENLIB_yyvaluep)
{
  YYFPRINTF (GENLIB_yyo, "%s %s (",
             GENLIB_yykind < YYNTOKENS ? "token" : "nterm", GENLIB_yysymbol_name (GENLIB_yykind));

  GENLIB_yy_symbol_value_print (GENLIB_yyo, GENLIB_yykind, GENLIB_yyvaluep);
  YYFPRINTF (GENLIB_yyo, ")");
}

/*------------------------------------------------------------------.
| GENLIB_yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
GENLIB_yy_stack_print (GENLIB_yy_state_t *GENLIB_yybottom, GENLIB_yy_state_t *GENLIB_yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; GENLIB_yybottom <= GENLIB_yytop; GENLIB_yybottom++)
    {
      int GENLIB_yybot = *GENLIB_yybottom;
      YYFPRINTF (stderr, " %d", GENLIB_yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (GENLIB_yydebug)                                                  \
    GENLIB_yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
GENLIB_yy_reduce_print (GENLIB_yy_state_t *GENLIB_yyssp, YYSTYPE *GENLIB_yyvsp,
                 int GENLIB_yyrule)
{
  int GENLIB_yylno = GENLIB_yyrline[GENLIB_yyrule];
  int GENLIB_yynrhs = GENLIB_yyr2[GENLIB_yyrule];
  int GENLIB_yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             GENLIB_yyrule - 1, GENLIB_yylno);
  /* The symbols being reduced.  */
  for (GENLIB_yyi = 0; GENLIB_yyi < GENLIB_yynrhs; GENLIB_yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", GENLIB_yyi + 1);
      GENLIB_yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+GENLIB_yyssp[GENLIB_yyi + 1 - GENLIB_yynrhs]),
                       &GENLIB_yyvsp[(GENLIB_yyi + 1) - (GENLIB_yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (GENLIB_yydebug)                          \
    GENLIB_yy_reduce_print (GENLIB_yyssp, GENLIB_yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int GENLIB_yydebug;
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
GENLIB_yydestruct (const char *GENLIB_yymsg,
            GENLIB_yysymbol_kind_t GENLIB_yykind, YYSTYPE *GENLIB_yyvaluep)
{
  YY_USE (GENLIB_yyvaluep);
  if (!GENLIB_yymsg)
    GENLIB_yymsg = "Deleting";
  YY_SYMBOL_PRINT (GENLIB_yymsg, GENLIB_yykind, GENLIB_yyvaluep, GENLIB_yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (GENLIB_yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int GENLIB_yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE GENLIB_yylval;
/* Number of syntax errors so far.  */
int GENLIB_yynerrs;




/*----------.
| GENLIB_yyparse.  |
`----------*/

int
GENLIB_yyparse (void)
{
    GENLIB_yy_state_fast_t GENLIB_yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int GENLIB_yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow GENLIB_yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T GENLIB_yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    GENLIB_yy_state_t GENLIB_yyssa[YYINITDEPTH];
    GENLIB_yy_state_t *GENLIB_yyss = GENLIB_yyssa;
    GENLIB_yy_state_t *GENLIB_yyssp = GENLIB_yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE GENLIB_yyvsa[YYINITDEPTH];
    YYSTYPE *GENLIB_yyvs = GENLIB_yyvsa;
    YYSTYPE *GENLIB_yyvsp = GENLIB_yyvs;

  int GENLIB_yyn;
  /* The return value of GENLIB_yyparse.  */
  int GENLIB_yyresult;
  /* Lookahead symbol kind.  */
  GENLIB_yysymbol_kind_t GENLIB_yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE GENLIB_yyval;



#define YYPOPSTACK(N)   (GENLIB_yyvsp -= (N), GENLIB_yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int GENLIB_yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  GENLIB_yychar = YYEMPTY; /* Cause a token to be read.  */

  goto GENLIB_yysetstate;


/*------------------------------------------------------------.
| GENLIB_yynewstate -- push a new state, which is found in GENLIB_yystate.  |
`------------------------------------------------------------*/
GENLIB_yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  GENLIB_yyssp++;


/*--------------------------------------------------------------------.
| GENLIB_yysetstate -- set current state (the top of the stack) to GENLIB_yystate.  |
`--------------------------------------------------------------------*/
GENLIB_yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", GENLIB_yystate));
  YY_ASSERT (0 <= GENLIB_yystate && GENLIB_yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *GENLIB_yyssp = YY_CAST (GENLIB_yy_state_t, GENLIB_yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (GENLIB_yyss, GENLIB_yyssp);

  if (GENLIB_yyss + GENLIB_yystacksize - 1 <= GENLIB_yyssp)
#if !defined GENLIB_yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T GENLIB_yysize = GENLIB_yyssp - GENLIB_yyss + 1;

# if defined GENLIB_yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        GENLIB_yy_state_t *GENLIB_yyss1 = GENLIB_yyss;
        YYSTYPE *GENLIB_yyvs1 = GENLIB_yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if GENLIB_yyoverflow is a macro.  */
        GENLIB_yyoverflow (YY_("memory exhausted"),
                    &GENLIB_yyss1, GENLIB_yysize * YYSIZEOF (*GENLIB_yyssp),
                    &GENLIB_yyvs1, GENLIB_yysize * YYSIZEOF (*GENLIB_yyvsp),
                    &GENLIB_yystacksize);
        GENLIB_yyss = GENLIB_yyss1;
        GENLIB_yyvs = GENLIB_yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= GENLIB_yystacksize)
        YYNOMEM;
      GENLIB_yystacksize *= 2;
      if (YYMAXDEPTH < GENLIB_yystacksize)
        GENLIB_yystacksize = YYMAXDEPTH;

      {
        GENLIB_yy_state_t *GENLIB_yyss1 = GENLIB_yyss;
        union GENLIB_yyalloc *GENLIB_yyptr =
          YY_CAST (union GENLIB_yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (GENLIB_yystacksize))));
        if (! GENLIB_yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (GENLIB_yyss_alloc, GENLIB_yyss);
        YYSTACK_RELOCATE (GENLIB_yyvs_alloc, GENLIB_yyvs);
#  undef YYSTACK_RELOCATE
        if (GENLIB_yyss1 != GENLIB_yyssa)
          YYSTACK_FREE (GENLIB_yyss1);
      }
# endif

      GENLIB_yyssp = GENLIB_yyss + GENLIB_yysize - 1;
      GENLIB_yyvsp = GENLIB_yyvs + GENLIB_yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, GENLIB_yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (GENLIB_yyss + GENLIB_yystacksize - 1 <= GENLIB_yyssp)
        YYABORT;
    }
#endif /* !defined GENLIB_yyoverflow && !defined YYSTACK_RELOCATE */


  if (GENLIB_yystate == YYFINAL)
    YYACCEPT;

  goto GENLIB_yybackup;


/*-----------.
| GENLIB_yybackup.  |
`-----------*/
GENLIB_yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  GENLIB_yyn = GENLIB_yypact[GENLIB_yystate];
  if (GENLIB_yypact_value_is_default (GENLIB_yyn))
    goto GENLIB_yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (GENLIB_yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      GENLIB_yychar = GENLIB_yylex ();
    }

  if (GENLIB_yychar <= YYEOF)
    {
      GENLIB_yychar = YYEOF;
      GENLIB_yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (GENLIB_yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      GENLIB_yychar = YYUNDEF;
      GENLIB_yytoken = YYSYMBOL_YYerror;
      goto GENLIB_yyerrlab1;
    }
  else
    {
      GENLIB_yytoken = YYTRANSLATE (GENLIB_yychar);
      YY_SYMBOL_PRINT ("Next token is", GENLIB_yytoken, &GENLIB_yylval, &GENLIB_yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  GENLIB_yyn += GENLIB_yytoken;
  if (GENLIB_yyn < 0 || YYLAST < GENLIB_yyn || GENLIB_yycheck[GENLIB_yyn] != GENLIB_yytoken)
    goto GENLIB_yydefault;
  GENLIB_yyn = GENLIB_yytable[GENLIB_yyn];
  if (GENLIB_yyn <= 0)
    {
      if (GENLIB_yytable_value_is_error (GENLIB_yyn))
        goto GENLIB_yyerrlab;
      GENLIB_yyn = -GENLIB_yyn;
      goto GENLIB_yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (GENLIB_yyerrstatus)
    GENLIB_yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", GENLIB_yytoken, &GENLIB_yylval, &GENLIB_yylloc);
  GENLIB_yystate = GENLIB_yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++GENLIB_yyvsp = GENLIB_yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  GENLIB_yychar = YYEMPTY;
  goto GENLIB_yynewstate;


/*-----------------------------------------------------------.
| GENLIB_yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
GENLIB_yydefault:
  GENLIB_yyn = GENLIB_yydefact[GENLIB_yystate];
  if (GENLIB_yyn == 0)
    goto GENLIB_yyerrlab;
  goto GENLIB_yyreduce;


/*-----------------------------.
| GENLIB_yyreduce -- do a reduction.  |
`-----------------------------*/
GENLIB_yyreduce:
  /* GENLIB_yyn is the number of a rule to reduce with.  */
  GENLIB_yylen = GENLIB_yyr2[GENLIB_yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  GENLIB_yyval = GENLIB_yyvsp[1-GENLIB_yylen];


  YY_REDUCE_PRINT (GENLIB_yyn);
  switch (GENLIB_yyn)
    {
  case 3: /* hack: function  */
#line 59 "readlib.y"
                    {global_fct = (GENLIB_yyvsp[0].functionval); }
#line 1259 "y.tab.c"
    break;

  case 6: /* gate_info: GATE name real function pins  */
#line 67 "readlib.y"
                    { 
			if (! gl_convert_gate_to_blif((GENLIB_yyvsp[-3].strval),(GENLIB_yyvsp[-2].realval),(GENLIB_yyvsp[-1].functionval),(GENLIB_yyvsp[0].pinval),global_use_nor))
			    GENLIB_yyerror(NIL(char));
		    }
#line 1268 "y.tab.c"
    break;

  case 7: /* gate_info: LATCH name real function pins latch clock constraints  */
#line 72 "readlib.y"
                    {
		      if (! gl_convert_latch_to_blif((GENLIB_yyvsp[-6].strval),(GENLIB_yyvsp[-5].realval),(GENLIB_yyvsp[-4].functionval),(GENLIB_yyvsp[-3].pinval),global_use_nor,(GENLIB_yyvsp[-2].latchval),(GENLIB_yyvsp[-1].pinval),(GENLIB_yyvsp[0].constrval)))
			GENLIB_yyerror(NIL(char));
		    }
#line 1277 "y.tab.c"
    break;

  case 8: /* pins: %empty  */
#line 79 "readlib.y"
                    { (GENLIB_yyval.pinval) = 0; }
#line 1283 "y.tab.c"
    break;

  case 9: /* pins: pins pin_info  */
#line 81 "readlib.y"
                    { (GENLIB_yyvsp[0].pinval)->next = (GENLIB_yyvsp[-1].pinval); (GENLIB_yyval.pinval) = (GENLIB_yyvsp[0].pinval);}
#line 1289 "y.tab.c"
    break;

  case 10: /* pin_info: PIN pin_name pin_phase real real real real real real  */
#line 85 "readlib.y"
                    {
			(GENLIB_yyval.pinval) = ALLOC(pin_info_t, 1);
			(GENLIB_yyval.pinval)->name = (GENLIB_yyvsp[-7].strval);
			(GENLIB_yyval.pinval)->phase = (GENLIB_yyvsp[-6].strval);
			(GENLIB_yyval.pinval)->value[0] = (GENLIB_yyvsp[-5].realval); (GENLIB_yyval.pinval)->value[1] = (GENLIB_yyvsp[-4].realval);
			(GENLIB_yyval.pinval)->value[2] = (GENLIB_yyvsp[-3].realval); (GENLIB_yyval.pinval)->value[3] = (GENLIB_yyvsp[-2].realval);
			(GENLIB_yyval.pinval)->value[4] = (GENLIB_yyvsp[-1].realval); (GENLIB_yyval.pinval)->value[5] = (GENLIB_yyvsp[0].realval);
			(GENLIB_yyval.pinval)->next = 0;
		    }
#line 1303 "y.tab.c"
    break;

  case 11: /* pin_phase: name  */
#line 97 "readlib.y"
                    {
			if (strcmp((GENLIB_yyvsp[0].strval), "INV") != 0) {
			    if (strcmp((GENLIB_yyvsp[0].strval), "NONINV") != 0) {
				if (strcmp((GENLIB_yyvsp[0].strval), "UNKNOWN") != 0) {
				    GENLIB_yyerror("bad pin phase");
				}
			    }
			}
			(GENLIB_yyval.strval) = (GENLIB_yyvsp[0].strval);
		    }
#line 1318 "y.tab.c"
    break;

  case 12: /* pin_name: name  */
#line 110 "readlib.y"
                    { (GENLIB_yyval.strval) = (GENLIB_yyvsp[0].strval); }
#line 1324 "y.tab.c"
    break;

  case 13: /* pin_name: OPR_AND  */
#line 112 "readlib.y"
                    { (GENLIB_yyval.strval) = util_strsav(GENLIB_yytext); }
#line 1330 "y.tab.c"
    break;

  case 14: /* function: name ASSIGN expr SEMI  */
#line 116 "readlib.y"
                    {
			(GENLIB_yyval.functionval) = ALLOC(function_t, 1);
			(GENLIB_yyval.functionval)->name = (GENLIB_yyvsp[-3].strval);
			(GENLIB_yyval.functionval)->tree = (GENLIB_yyvsp[-1].nodeval);
			(GENLIB_yyval.functionval)->next = 0;
		    }
#line 1341 "y.tab.c"
    break;

  case 15: /* expr: expr OPR_OR expr  */
#line 125 "readlib.y"
                    { 
			(GENLIB_yyval.nodeval) = gl_alloc_node(2);
			(GENLIB_yyval.nodeval)->phase = 1;
			(GENLIB_yyval.nodeval)->sons[0] = (GENLIB_yyvsp[-2].nodeval);
			(GENLIB_yyval.nodeval)->sons[1] = (GENLIB_yyvsp[0].nodeval);
			(GENLIB_yyval.nodeval)->type = OR_NODE;
		    }
#line 1353 "y.tab.c"
    break;

  case 16: /* expr: expr OPR_AND expr  */
#line 133 "readlib.y"
                    {
			(GENLIB_yyval.nodeval) = gl_alloc_node(2);
			(GENLIB_yyval.nodeval)->phase = 1;
			(GENLIB_yyval.nodeval)->sons[0] = (GENLIB_yyvsp[-2].nodeval);
			(GENLIB_yyval.nodeval)->sons[1] = (GENLIB_yyvsp[0].nodeval);
			(GENLIB_yyval.nodeval)->type = AND_NODE;
		    }
#line 1365 "y.tab.c"
    break;

  case 17: /* expr: expr expr  */
#line 141 "readlib.y"
                    {
			(GENLIB_yyval.nodeval) = gl_alloc_node(2);
			(GENLIB_yyval.nodeval)->phase = 1;
			(GENLIB_yyval.nodeval)->sons[0] = (GENLIB_yyvsp[-1].nodeval);
			(GENLIB_yyval.nodeval)->sons[1] = (GENLIB_yyvsp[0].nodeval);
			(GENLIB_yyval.nodeval)->type = AND_NODE;
		    }
#line 1377 "y.tab.c"
    break;

  case 18: /* expr: LPAREN expr RPAREN  */
#line 149 "readlib.y"
                    { 
			(GENLIB_yyval.nodeval) = (GENLIB_yyvsp[-1].nodeval); 
		    }
#line 1385 "y.tab.c"
    break;

  case 19: /* expr: OPR_NOT expr  */
#line 153 "readlib.y"
                    { 
			(GENLIB_yyval.nodeval) = (GENLIB_yyvsp[0].nodeval); 
			(GENLIB_yyval.nodeval)->phase = 0; 
		    }
#line 1394 "y.tab.c"
    break;

  case 20: /* expr: expr OPR_NOT_POST  */
#line 158 "readlib.y"
                    { 
			(GENLIB_yyval.nodeval) = (GENLIB_yyvsp[-1].nodeval); 
			(GENLIB_yyval.nodeval)->phase = 0; 
		    }
#line 1403 "y.tab.c"
    break;

  case 21: /* expr: name  */
#line 163 "readlib.y"
                    {
			(GENLIB_yyval.nodeval) = gl_alloc_leaf((GENLIB_yyvsp[0].strval));
			FREE((GENLIB_yyvsp[0].strval));
			(GENLIB_yyval.nodeval)->type = LEAF_NODE;	/* hack */
			(GENLIB_yyval.nodeval)->phase = 1;
		    }
#line 1414 "y.tab.c"
    break;

  case 22: /* expr: CONST0  */
#line 170 "readlib.y"
                    {
			(GENLIB_yyval.nodeval) = gl_alloc_leaf("0");
			(GENLIB_yyval.nodeval)->phase = 1;
			(GENLIB_yyval.nodeval)->type = ZERO_NODE;
		    }
#line 1424 "y.tab.c"
    break;

  case 23: /* expr: CONST1  */
#line 176 "readlib.y"
                    {
			(GENLIB_yyval.nodeval) = gl_alloc_leaf("1");
			(GENLIB_yyval.nodeval)->phase = 1;
			(GENLIB_yyval.nodeval)->type = ONE_NODE;
		    }
#line 1434 "y.tab.c"
    break;

  case 24: /* name: IDENTIFIER  */
#line 184 "readlib.y"
                    { (GENLIB_yyval.strval) = util_strsav(GENLIB_yytext); }
#line 1440 "y.tab.c"
    break;

  case 25: /* name: REAL  */
#line 187 "readlib.y"
                    { (GENLIB_yyval.strval) = util_strsav(GENLIB_yytext); }
#line 1446 "y.tab.c"
    break;

  case 26: /* real: REAL  */
#line 191 "readlib.y"
                    { (GENLIB_yyval.realval) = atof(GENLIB_yytext); }
#line 1452 "y.tab.c"
    break;

  case 27: /* clock: %empty  */
#line 195 "readlib.y"
                { (GENLIB_yyval.pinval) = 0;}
#line 1458 "y.tab.c"
    break;

  case 28: /* clock: CONTROL name real real real real real real  */
#line 197 "readlib.y"
                { (GENLIB_yyval.pinval) = ALLOC(pin_info_t, 1);
		  (GENLIB_yyval.pinval)->name = (GENLIB_yyvsp[-6].strval);
		  (GENLIB_yyval.pinval)->phase = util_strsav("UNKNOWN");
		  (GENLIB_yyval.pinval)->value[0] = (GENLIB_yyvsp[-5].realval);
		  (GENLIB_yyval.pinval)->value[1] = (GENLIB_yyvsp[-4].realval);
		  (GENLIB_yyval.pinval)->value[2] = (GENLIB_yyvsp[-3].realval);
		  (GENLIB_yyval.pinval)->value[3] = (GENLIB_yyvsp[-2].realval);
		  (GENLIB_yyval.pinval)->value[4] = (GENLIB_yyvsp[-1].realval);
		  (GENLIB_yyval.pinval)->value[5] = (GENLIB_yyvsp[0].realval);
		  (GENLIB_yyval.pinval)->next = 0;
		}
#line 1474 "y.tab.c"
    break;

  case 29: /* constraints: %empty  */
#line 211 "readlib.y"
                { (GENLIB_yyval.constrval) = 0; }
#line 1480 "y.tab.c"
    break;

  case 30: /* constraints: constraints constraint  */
#line 213 "readlib.y"
                {
		  (GENLIB_yyvsp[0].constrval)->next = (GENLIB_yyvsp[-1].constrval);
		  (GENLIB_yyval.constrval) = (GENLIB_yyvsp[0].constrval);
		}
#line 1489 "y.tab.c"
    break;

  case 31: /* constraint: CONSTRAINT pin_name real real  */
#line 220 "readlib.y"
                {
		  (GENLIB_yyval.constrval) = ALLOC(constraint_info_t, 1);
		  (GENLIB_yyval.constrval)->name = (GENLIB_yyvsp[-2].strval);
		  (GENLIB_yyval.constrval)->setup = (GENLIB_yyvsp[-1].realval);
		  (GENLIB_yyval.constrval)->hold = (GENLIB_yyvsp[0].realval);
		  (GENLIB_yyval.constrval)->next = 0;
		}
#line 1501 "y.tab.c"
    break;

  case 32: /* latch: SEQ name name type  */
#line 230 "readlib.y"
                { 
		  (GENLIB_yyval.latchval) = ALLOC(latch_info_t, 1);
		  (GENLIB_yyval.latchval)->in = (GENLIB_yyvsp[-2].strval);
		  (GENLIB_yyval.latchval)->out = (GENLIB_yyvsp[-1].strval);
		  (GENLIB_yyval.latchval)->type = (GENLIB_yyvsp[0].strval);
		}
#line 1512 "y.tab.c"
    break;

  case 33: /* type: IDENTIFIER  */
#line 239 "readlib.y"
                { 
		  if (strcmp(GENLIB_yytext, "RISING_EDGE") == 0) {
		    (GENLIB_yyval.strval) = util_strsav("re");
		  } else if (strcmp(GENLIB_yytext, "FALLING_EDGE") == 0) {
		    (GENLIB_yyval.strval) = util_strsav("fe");
		  } else if (strcmp(GENLIB_yytext, "ACTIVE_HIGH") == 0) {
		    (GENLIB_yyval.strval) = util_strsav("ah");
		  } else if (strcmp(GENLIB_yytext, "ACTIVE_LOW") == 0) {
		    (GENLIB_yyval.strval) = util_strsav("al");
		  } else if (strcmp(GENLIB_yytext, "ASYNCH") == 0) {
		    (GENLIB_yyval.strval) = util_strsav("as");
		  } else {
		    GENLIB_yyerror("latch type can only be re/fe/ah/al/as");
		  }
		}
#line 1532 "y.tab.c"
    break;


#line 1536 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter GENLIB_yychar, and that requires
     that GENLIB_yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of GENLIB_yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering GENLIB_yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (GENLIB_yysymbol_kind_t, GENLIB_yyr1[GENLIB_yyn]), &GENLIB_yyval, &GENLIB_yyloc);

  YYPOPSTACK (GENLIB_yylen);
  GENLIB_yylen = 0;

  *++GENLIB_yyvsp = GENLIB_yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int GENLIB_yylhs = GENLIB_yyr1[GENLIB_yyn] - YYNTOKENS;
    const int GENLIB_yyi = GENLIB_yypgoto[GENLIB_yylhs] + *GENLIB_yyssp;
    GENLIB_yystate = (0 <= GENLIB_yyi && GENLIB_yyi <= YYLAST && GENLIB_yycheck[GENLIB_yyi] == *GENLIB_yyssp
               ? GENLIB_yytable[GENLIB_yyi]
               : GENLIB_yydefgoto[GENLIB_yylhs]);
  }

  goto GENLIB_yynewstate;


/*--------------------------------------.
| GENLIB_yyerrlab -- here on detecting error.  |
`--------------------------------------*/
GENLIB_yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  GENLIB_yytoken = GENLIB_yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (GENLIB_yychar);
  /* If not already recovering from an error, report this error.  */
  if (!GENLIB_yyerrstatus)
    {
      ++GENLIB_yynerrs;
      GENLIB_yyerror (YY_("syntax error"));
    }

  if (GENLIB_yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (GENLIB_yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (GENLIB_yychar == YYEOF)
            YYABORT;
        }
      else
        {
          GENLIB_yydestruct ("Error: discarding",
                      GENLIB_yytoken, &GENLIB_yylval);
          GENLIB_yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto GENLIB_yyerrlab1;


/*---------------------------------------------------.
| GENLIB_yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
GENLIB_yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label GENLIB_yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++GENLIB_yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (GENLIB_yylen);
  GENLIB_yylen = 0;
  YY_STACK_PRINT (GENLIB_yyss, GENLIB_yyssp);
  GENLIB_yystate = *GENLIB_yyssp;
  goto GENLIB_yyerrlab1;


/*-------------------------------------------------------------.
| GENLIB_yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
GENLIB_yyerrlab1:
  GENLIB_yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      GENLIB_yyn = GENLIB_yypact[GENLIB_yystate];
      if (!GENLIB_yypact_value_is_default (GENLIB_yyn))
        {
          GENLIB_yyn += YYSYMBOL_YYerror;
          if (0 <= GENLIB_yyn && GENLIB_yyn <= YYLAST && GENLIB_yycheck[GENLIB_yyn] == YYSYMBOL_YYerror)
            {
              GENLIB_yyn = GENLIB_yytable[GENLIB_yyn];
              if (0 < GENLIB_yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (GENLIB_yyssp == GENLIB_yyss)
        YYABORT;


      GENLIB_yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (GENLIB_yystate), GENLIB_yyvsp);
      YYPOPSTACK (1);
      GENLIB_yystate = *GENLIB_yyssp;
      YY_STACK_PRINT (GENLIB_yyss, GENLIB_yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++GENLIB_yyvsp = GENLIB_yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (GENLIB_yyn), GENLIB_yyvsp, GENLIB_yylsp);

  GENLIB_yystate = GENLIB_yyn;
  goto GENLIB_yynewstate;


/*-------------------------------------.
| GENLIB_yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
GENLIB_yyacceptlab:
  GENLIB_yyresult = 0;
  goto GENLIB_yyreturnlab;


/*-----------------------------------.
| GENLIB_yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
GENLIB_yyabortlab:
  GENLIB_yyresult = 1;
  goto GENLIB_yyreturnlab;


/*-----------------------------------------------------------.
| GENLIB_yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
GENLIB_yyexhaustedlab:
  GENLIB_yyerror (YY_("memory exhausted"));
  GENLIB_yyresult = 2;
  goto GENLIB_yyreturnlab;


/*----------------------------------------------------------.
| GENLIB_yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
GENLIB_yyreturnlab:
  if (GENLIB_yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      GENLIB_yytoken = YYTRANSLATE (GENLIB_yychar);
      GENLIB_yydestruct ("Cleanup: discarding lookahead",
                  GENLIB_yytoken, &GENLIB_yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (GENLIB_yylen);
  YY_STACK_PRINT (GENLIB_yyss, GENLIB_yyssp);
  while (GENLIB_yyssp != GENLIB_yyss)
    {
      GENLIB_yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*GENLIB_yyssp), GENLIB_yyvsp);
      YYPOPSTACK (1);
    }
#ifndef GENLIB_yyoverflow
  if (GENLIB_yyss != GENLIB_yyssa)
    YYSTACK_FREE (GENLIB_yyss);
#endif

  return GENLIB_yyresult;
}

#line 256 "readlib.y"

static jmp_buf jmpbuf;

int
GENLIB_yyerror(errmsg)
char *errmsg;
{
    if (errmsg != 0) read_error(errmsg);
    longjmp(jmpbuf, 1);
}

int
gl_convert_genlib_to_blif(filename, use_nor)
char *filename;
int use_nor;
{
    FILE *fp;

    error_init();
    if ((fp = fopen(filename, "r")) == NULL) {
	perror(filename);
	return 0;
    }
    library_setup_file(fp, filename);
    gl_out_file = stdout;

    global_fct = 0;		/* not used here, just to check for error */
    global_use_nor = use_nor;

    if (setjmp(jmpbuf)) {
	return 0;
    } else {
	(void) GENLIB_yyparse();
	if (global_fct != 0) GENLIB_yyerror("syntax error");
	return 1;
    }
}

int
genlib_parse_library(infp, infilename, outfp, use_nor)
FILE *infp;
char *infilename;
FILE *outfp;
int use_nor;
{
    error_init();
    library_setup_file(infp, infilename);
    gl_out_file = outfp;
    global_fct = 0;		/* not used here, just to check for error */
    global_use_nor = use_nor;

    if (setjmp(jmpbuf)) {
	return 0;
    } else {
	(void) GENLIB_yyparse();
	if (global_fct != 0) GENLIB_yyerror("syntax error");
	return 1;
    }
}

int
gl_convert_expression_to_tree(string, tree, name)
char *string;
tree_node_t **tree;
char **name;
{
    error_init();
    global_fct = 0;
    library_setup_string(string);

    if (setjmp(jmpbuf)) {
	return 0;
    } else {
	(void) GENLIB_yyparse();
	if (global_fct == 0) GENLIB_yyerror("syntax error");
	*tree = global_fct->tree;
	*name = global_fct->name;
	return 1;
    }
}
