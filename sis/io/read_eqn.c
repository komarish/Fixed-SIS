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
   especially those whose name start with YY_ or EQN_yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with EQN_yy or YY, to avoid
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
#line 2 "read_eqn.y"

#include "sis.h"
#include "io_int.h"
#include <setjmp.h>
#include "config.h"

#if YYTEXT_POINTER
extern char *EQN_yytext;
#else
extern char EQN_yytext[];
#endif

static network_t *global_network;
static lsList po_list;

int EQN_yyerror();
#if 0 /* #ifndef FLEX_SCANNER */
#undef EQN_yywrap
static int input();
static int unput();
static int EQN_yywrap();
#endif

extern int equation_setup_string(char *);
extern int equation_setup_file(FILE *);

static void
do_assign(name, expr)
char *name;
node_t *expr;
{
    char errmsg[1024];
    node_t *node;

    node = read_find_or_create_node(global_network, name);
    if (node_function(node) != NODE_UNDEFINED) {
	(void) sprintf(errmsg, "Attempt to redefine '%s'\n", name);
	EQN_yyerror(errmsg);   /* never returns */
    }
    FREE(name);
    node_replace(node, expr);
}

static node_t *
do_sexpr_list(list, func)
array_t *list;
node_t *(*func)();
{
    int i;
    node_t *node, *node1, *node2;

    node1 = array_fetch(node_t *, list, 0);
    node = node_dup(node1);
    node_free(node1);
    for(i = 1; i < array_n(list); i++) {
	node1 = node;
	node2 = array_fetch(node_t *, list, i);
	node = (*func)(node1, node2);
	node_free(node1);
	node_free(node2);
    }
    array_free(list);
    return node;
}


#line 138 "y.tab.c"

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
extern int EQN_yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum EQN_yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    OPR_OR = 258,                  /* OPR_OR  */
    OPR_AND = 259,                 /* OPR_AND  */
    CONST_ZERO = 260,              /* CONST_ZERO  */
    CONST_ONE = 261,               /* CONST_ONE  */
    IDENTIFIER = 262,              /* IDENTIFIER  */
    OPR_XOR = 263,                 /* OPR_XOR  */
    OPR_XNOR = 264,                /* OPR_XNOR  */
    OPR_NOT = 265,                 /* OPR_NOT  */
    OPR_NOT_POST = 266,            /* OPR_NOT_POST  */
    NAME = 267,                    /* NAME  */
    INORDER = 268,                 /* INORDER  */
    OUTORDER = 269,                /* OUTORDER  */
    PASS = 270,                    /* PASS  */
    ASSIGN = 271,                  /* ASSIGN  */
    SEMI = 272,                    /* SEMI  */
    LPAREN = 273,                  /* LPAREN  */
    RPAREN = 274,                  /* RPAREN  */
    END = 275                      /* END  */
  };
  typedef enum EQN_yytokentype EQN_yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define OPR_OR 258
#define OPR_AND 259
#define CONST_ZERO 260
#define CONST_ONE 261
#define IDENTIFIER 262
#define OPR_XOR 263
#define OPR_XNOR 264
#define OPR_NOT 265
#define OPR_NOT_POST 266
#define NAME 267
#define INORDER 268
#define OUTORDER 269
#define PASS 270
#define ASSIGN 271
#define SEMI 272
#define LPAREN 273
#define RPAREN 274
#define END 275

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 69 "read_eqn.y"

    char *strval;
    node_t *node;
    array_t *array;

#line 237 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE EQN_yylval;


int EQN_yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum EQN_yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_OPR_OR = 3,                     /* OPR_OR  */
  YYSYMBOL_OPR_AND = 4,                    /* OPR_AND  */
  YYSYMBOL_CONST_ZERO = 5,                 /* CONST_ZERO  */
  YYSYMBOL_CONST_ONE = 6,                  /* CONST_ONE  */
  YYSYMBOL_IDENTIFIER = 7,                 /* IDENTIFIER  */
  YYSYMBOL_OPR_XOR = 8,                    /* OPR_XOR  */
  YYSYMBOL_OPR_XNOR = 9,                   /* OPR_XNOR  */
  YYSYMBOL_OPR_NOT = 10,                   /* OPR_NOT  */
  YYSYMBOL_OPR_NOT_POST = 11,              /* OPR_NOT_POST  */
  YYSYMBOL_NAME = 12,                      /* NAME  */
  YYSYMBOL_INORDER = 13,                   /* INORDER  */
  YYSYMBOL_OUTORDER = 14,                  /* OUTORDER  */
  YYSYMBOL_PASS = 15,                      /* PASS  */
  YYSYMBOL_ASSIGN = 16,                    /* ASSIGN  */
  YYSYMBOL_SEMI = 17,                      /* SEMI  */
  YYSYMBOL_LPAREN = 18,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 19,                    /* RPAREN  */
  YYSYMBOL_END = 20,                       /* END  */
  YYSYMBOL_YYACCEPT = 21,                  /* $accept  */
  YYSYMBOL_program = 22,                   /* program  */
  YYSYMBOL_prog = 23,                      /* prog  */
  YYSYMBOL_stat = 24,                      /* stat  */
  YYSYMBOL_expr = 25,                      /* expr  */
  YYSYMBOL_sexpr = 26,                     /* sexpr  */
  YYSYMBOL_sexpr_list = 27,                /* sexpr_list  */
  YYSYMBOL_identifier = 28,                /* identifier  */
  YYSYMBOL_input_list = 29,                /* input_list  */
  YYSYMBOL_output_list = 30                /* output_list  */
};
typedef enum EQN_yysymbol_kind_t EQN_yysymbol_kind_t;




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
typedef __INT_LEAST8_TYPE__ EQN_yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t EQN_yytype_int8;
#else
typedef signed char EQN_yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ EQN_yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t EQN_yytype_int16;
#else
typedef short EQN_yytype_int16;
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
typedef __UINT_LEAST8_TYPE__ EQN_yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t EQN_yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char EQN_yytype_uint8;
#else
typedef short EQN_yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ EQN_yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t EQN_yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short EQN_yytype_uint16;
#else
typedef int EQN_yytype_uint16;
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
typedef EQN_yytype_int8 EQN_yy_state_t;

/* State numbers in computations.  */
typedef int EQN_yy_state_fast_t;

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

/* Suppress an incorrect diagnostic about EQN_yylval being uninitialized.  */
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

#if !defined EQN_yyoverflow

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
#endif /* !defined EQN_yyoverflow */

#if (! defined EQN_yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union EQN_yyalloc
{
  EQN_yy_state_t EQN_yyss_alloc;
  YYSTYPE EQN_yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union EQN_yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (EQN_yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T EQN_yynewbytes;                                         \
        YYCOPY (&EQN_yyptr->Stack_alloc, Stack, EQN_yysize);                    \
        Stack = &EQN_yyptr->Stack_alloc;                                    \
        EQN_yynewbytes = EQN_yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        EQN_yyptr += EQN_yynewbytes / YYSIZEOF (*EQN_yyptr);                        \
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
          YYPTRDIFF_T EQN_yyi;                      \
          for (EQN_yyi = 0; EQN_yyi < (Count); EQN_yyi++)   \
            (Dst)[EQN_yyi] = (Src)[EQN_yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   139

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  21
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  10
/* YYNRULES -- Number of rules.  */
#define YYNRULES  39
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  70

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   275


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by EQN_yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (EQN_yysymbol_kind_t, EQN_yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by EQN_yylex.  */
static const EQN_yytype_int8 EQN_yytranslate[] =
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
static const EQN_yytype_uint8 EQN_yyrline[] =
{
       0,    86,    86,    87,    88,    89,    93,    94,    97,    98,
     104,   106,   108,   111,   116,   119,   122,   125,   128,   131,
     134,   137,   140,   143,   146,   156,   159,   162,   165,   168,
     171,   174,   177,   187,   192,   198,   203,   204,   221,   222
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (EQN_yysymbol_kind_t, EQN_yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *EQN_yysymbol_name (EQN_yysymbol_kind_t EQN_yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const EQN_yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "OPR_OR", "OPR_AND",
  "CONST_ZERO", "CONST_ONE", "IDENTIFIER", "OPR_XOR", "OPR_XNOR",
  "OPR_NOT", "OPR_NOT_POST", "NAME", "INORDER", "OUTORDER", "PASS",
  "ASSIGN", "SEMI", "LPAREN", "RPAREN", "END", "$accept", "program",
  "prog", "stat", "expr", "sexpr", "sexpr_list", "identifier",
  "input_list", "output_list", YY_NULLPTR
};

static const char *
EQN_yysymbol_name (EQN_yysymbol_kind_t EQN_yysymbol)
{
  return EQN_yytname[EQN_yysymbol];
}
#endif

#define YYPACT_NINF (-15)

#define EQN_yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-9)

#define EQN_yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const EQN_yytype_int16 EQN_yypact[] =
{
      95,   -15,   -15,   -15,   -14,   -12,   -11,   111,    10,    -6,
       5,   -15,    12,    17,   -15,   -15,    20,    20,    16,    22,
      20,    17,   -15,    13,    25,    27,    12,   -15,   113,   -15,
      17,    17,   129,   -15,    72,   -15,    87,   -15,   -15,    43,
      20,   -15,   -15,   -15,   -15,   113,   113,    63,   -15,   -15,
     -15,   -15,   -15,   -15,   -15,    44,   -15,    46,   113,   113,
     113,   113,   -15,    50,   -15,   -15,    78,    50,     8,     8
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const EQN_yytype_int8 EQN_yydefact[] =
{
       2,    28,    29,    35,     0,     0,     0,     0,     0,     3,
       0,     5,    32,     0,    36,    38,     0,     0,     0,     0,
       0,     0,     1,     0,     0,     0,     0,     6,     0,     9,
      10,    11,     0,    33,     0,    32,     0,    30,    31,     0,
       0,     4,     7,    21,    22,     0,     0,    12,    24,    37,
      39,    26,    34,    25,    27,     0,    20,     0,     0,     0,
       0,     0,    19,    16,    13,    23,    14,    15,    17,    18
};

/* YYPGOTO[NTERM-NUM].  */
static const EQN_yytype_int8 EQN_yypgoto[] =
{
     -15,   -15,   -15,    66,   -13,     3,    59,     0,   -15,   -15
};

/* YYDEFGOTO[NTERM-NUM].  */
static const EQN_yytype_int8 EQN_yydefgoto[] =
{
       0,     8,     9,    10,    63,    33,    34,    48,    30,    31
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const EQN_yytype_int8 EQN_yytable[] =
{
      12,     3,    13,    11,    14,    15,     4,     5,     6,    26,
      22,    -8,    23,    29,    24,    47,    35,    35,    45,    62,
      35,    40,    27,    39,     3,     1,     2,     3,    28,    21,
      49,    50,    56,    57,    35,    37,    35,    52,    32,    52,
      35,    38,    41,    55,    42,    66,    67,    68,    69,    58,
      59,    43,    44,     3,    60,    61,    45,    62,    60,    61,
      45,    62,    54,    64,    46,    65,    58,    59,    43,    44,
       3,    60,    61,    45,    62,    25,    36,     1,     2,     3,
       0,    46,    59,    43,    44,     3,    60,    61,    45,    62,
      32,    51,     1,     2,     3,     0,    46,     0,     0,     0,
       1,     2,     3,     0,     0,    32,    53,     4,     5,     6,
       0,     0,    -8,     7,    16,    17,    18,    19,    43,    44,
       3,    20,     0,    45,     0,     0,     0,    21,     0,     0,
       0,    46,    16,    17,    18,    19,     0,     0,     0,    20
};

static const EQN_yytype_int8 EQN_yycheck[] =
{
       0,     7,    16,     0,    16,    16,    12,    13,    14,     9,
       0,    17,    18,    13,    20,    28,    16,    17,    10,    11,
      20,    21,    17,    20,     7,     5,     6,     7,    16,    16,
      30,    31,    45,    46,    34,    19,    36,    34,    18,    36,
      40,    19,    17,    40,    17,    58,    59,    60,    61,     3,
       4,     5,     6,     7,     8,     9,    10,    11,     8,     9,
      10,    11,    19,    19,    18,    19,     3,     4,     5,     6,
       7,     8,     9,    10,    11,     9,    17,     5,     6,     7,
      -1,    18,     4,     5,     6,     7,     8,     9,    10,    11,
      18,    19,     5,     6,     7,    -1,    18,    -1,    -1,    -1,
       5,     6,     7,    -1,    -1,    18,    19,    12,    13,    14,
      -1,    -1,    17,    18,     3,     4,     5,     6,     5,     6,
       7,    10,    -1,    10,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    18,     3,     4,     5,     6,    -1,    -1,    -1,    10
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const EQN_yytype_int8 EQN_yystos[] =
{
       0,     5,     6,     7,    12,    13,    14,    18,    22,    23,
      24,    26,    28,    16,    16,    16,     3,     4,     5,     6,
      10,    16,     0,    18,    20,    24,    28,    17,    16,    28,
      29,    30,    18,    26,    27,    28,    27,    19,    19,    26,
      28,    17,    17,     5,     6,    10,    18,    25,    28,    28,
      28,    19,    26,    19,    19,    26,    25,    25,     3,     4,
       8,     9,    11,    25,    19,    19,    25,    25,    25,    25
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const EQN_yytype_int8 EQN_yyr1[] =
{
       0,    21,    22,    22,    22,    22,    23,    23,    24,    24,
      24,    24,    24,    24,    25,    25,    25,    25,    25,    25,
      25,    25,    25,    25,    25,    26,    26,    26,    26,    26,
      26,    26,    26,    27,    27,    28,    29,    29,    30,    30
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const EQN_yytype_int8 EQN_yyr2[] =
{
       0,     2,     0,     1,     3,     1,     2,     3,     0,     3,
       3,     3,     3,     5,     3,     3,     2,     3,     3,     2,
       2,     1,     1,     3,     1,     4,     4,     4,     1,     1,
       3,     3,     1,     1,     2,     1,     0,     2,     0,     2
};


enum { YYENOMEM = -2 };

#define EQN_yyerrok         (EQN_yyerrstatus = 0)
#define EQN_yyclearin       (EQN_yychar = YYEMPTY)

#define YYACCEPT        goto EQN_yyacceptlab
#define YYABORT         goto EQN_yyabortlab
#define YYERROR         goto EQN_yyerrorlab
#define YYNOMEM         goto EQN_yyexhaustedlab


#define YYRECOVERING()  (!!EQN_yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (EQN_yychar == YYEMPTY)                                        \
      {                                                           \
        EQN_yychar = (Token);                                         \
        EQN_yylval = (Value);                                         \
        YYPOPSTACK (EQN_yylen);                                       \
        EQN_yystate = *EQN_yyssp;                                         \
        goto EQN_yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        EQN_yyerror (YY_("syntax error: cannot back up")); \
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
  if (EQN_yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (EQN_yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      EQN_yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
EQN_yy_symbol_value_print (FILE *EQN_yyo,
                       EQN_yysymbol_kind_t EQN_yykind, YYSTYPE const * const EQN_yyvaluep)
{
  FILE *EQN_yyoutput = EQN_yyo;
  YY_USE (EQN_yyoutput);
  if (!EQN_yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (EQN_yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
EQN_yy_symbol_print (FILE *EQN_yyo,
                 EQN_yysymbol_kind_t EQN_yykind, YYSTYPE const * const EQN_yyvaluep)
{
  YYFPRINTF (EQN_yyo, "%s %s (",
             EQN_yykind < YYNTOKENS ? "token" : "nterm", EQN_yysymbol_name (EQN_yykind));

  EQN_yy_symbol_value_print (EQN_yyo, EQN_yykind, EQN_yyvaluep);
  YYFPRINTF (EQN_yyo, ")");
}

/*------------------------------------------------------------------.
| EQN_yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
EQN_yy_stack_print (EQN_yy_state_t *EQN_yybottom, EQN_yy_state_t *EQN_yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; EQN_yybottom <= EQN_yytop; EQN_yybottom++)
    {
      int EQN_yybot = *EQN_yybottom;
      YYFPRINTF (stderr, " %d", EQN_yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (EQN_yydebug)                                                  \
    EQN_yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
EQN_yy_reduce_print (EQN_yy_state_t *EQN_yyssp, YYSTYPE *EQN_yyvsp,
                 int EQN_yyrule)
{
  int EQN_yylno = EQN_yyrline[EQN_yyrule];
  int EQN_yynrhs = EQN_yyr2[EQN_yyrule];
  int EQN_yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             EQN_yyrule - 1, EQN_yylno);
  /* The symbols being reduced.  */
  for (EQN_yyi = 0; EQN_yyi < EQN_yynrhs; EQN_yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", EQN_yyi + 1);
      EQN_yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+EQN_yyssp[EQN_yyi + 1 - EQN_yynrhs]),
                       &EQN_yyvsp[(EQN_yyi + 1) - (EQN_yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (EQN_yydebug)                          \
    EQN_yy_reduce_print (EQN_yyssp, EQN_yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int EQN_yydebug;
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
EQN_yydestruct (const char *EQN_yymsg,
            EQN_yysymbol_kind_t EQN_yykind, YYSTYPE *EQN_yyvaluep)
{
  YY_USE (EQN_yyvaluep);
  if (!EQN_yymsg)
    EQN_yymsg = "Deleting";
  YY_SYMBOL_PRINT (EQN_yymsg, EQN_yykind, EQN_yyvaluep, EQN_yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (EQN_yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int EQN_yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE EQN_yylval;
/* Number of syntax errors so far.  */
int EQN_yynerrs;




/*----------.
| EQN_yyparse.  |
`----------*/

int
EQN_yyparse (void)
{
    EQN_yy_state_fast_t EQN_yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int EQN_yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow EQN_yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T EQN_yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    EQN_yy_state_t EQN_yyssa[YYINITDEPTH];
    EQN_yy_state_t *EQN_yyss = EQN_yyssa;
    EQN_yy_state_t *EQN_yyssp = EQN_yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE EQN_yyvsa[YYINITDEPTH];
    YYSTYPE *EQN_yyvs = EQN_yyvsa;
    YYSTYPE *EQN_yyvsp = EQN_yyvs;

  int EQN_yyn;
  /* The return value of EQN_yyparse.  */
  int EQN_yyresult;
  /* Lookahead symbol kind.  */
  EQN_yysymbol_kind_t EQN_yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE EQN_yyval;



#define YYPOPSTACK(N)   (EQN_yyvsp -= (N), EQN_yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int EQN_yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  EQN_yychar = YYEMPTY; /* Cause a token to be read.  */

  goto EQN_yysetstate;


/*------------------------------------------------------------.
| EQN_yynewstate -- push a new state, which is found in EQN_yystate.  |
`------------------------------------------------------------*/
EQN_yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  EQN_yyssp++;


/*--------------------------------------------------------------------.
| EQN_yysetstate -- set current state (the top of the stack) to EQN_yystate.  |
`--------------------------------------------------------------------*/
EQN_yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", EQN_yystate));
  YY_ASSERT (0 <= EQN_yystate && EQN_yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *EQN_yyssp = YY_CAST (EQN_yy_state_t, EQN_yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (EQN_yyss, EQN_yyssp);

  if (EQN_yyss + EQN_yystacksize - 1 <= EQN_yyssp)
#if !defined EQN_yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T EQN_yysize = EQN_yyssp - EQN_yyss + 1;

# if defined EQN_yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        EQN_yy_state_t *EQN_yyss1 = EQN_yyss;
        YYSTYPE *EQN_yyvs1 = EQN_yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if EQN_yyoverflow is a macro.  */
        EQN_yyoverflow (YY_("memory exhausted"),
                    &EQN_yyss1, EQN_yysize * YYSIZEOF (*EQN_yyssp),
                    &EQN_yyvs1, EQN_yysize * YYSIZEOF (*EQN_yyvsp),
                    &EQN_yystacksize);
        EQN_yyss = EQN_yyss1;
        EQN_yyvs = EQN_yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= EQN_yystacksize)
        YYNOMEM;
      EQN_yystacksize *= 2;
      if (YYMAXDEPTH < EQN_yystacksize)
        EQN_yystacksize = YYMAXDEPTH;

      {
        EQN_yy_state_t *EQN_yyss1 = EQN_yyss;
        union EQN_yyalloc *EQN_yyptr =
          YY_CAST (union EQN_yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (EQN_yystacksize))));
        if (! EQN_yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (EQN_yyss_alloc, EQN_yyss);
        YYSTACK_RELOCATE (EQN_yyvs_alloc, EQN_yyvs);
#  undef YYSTACK_RELOCATE
        if (EQN_yyss1 != EQN_yyssa)
          YYSTACK_FREE (EQN_yyss1);
      }
# endif

      EQN_yyssp = EQN_yyss + EQN_yysize - 1;
      EQN_yyvsp = EQN_yyvs + EQN_yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, EQN_yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (EQN_yyss + EQN_yystacksize - 1 <= EQN_yyssp)
        YYABORT;
    }
#endif /* !defined EQN_yyoverflow && !defined YYSTACK_RELOCATE */


  if (EQN_yystate == YYFINAL)
    YYACCEPT;

  goto EQN_yybackup;


/*-----------.
| EQN_yybackup.  |
`-----------*/
EQN_yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  EQN_yyn = EQN_yypact[EQN_yystate];
  if (EQN_yypact_value_is_default (EQN_yyn))
    goto EQN_yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (EQN_yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      EQN_yychar = EQN_yylex ();
    }

  if (EQN_yychar <= YYEOF)
    {
      EQN_yychar = YYEOF;
      EQN_yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (EQN_yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      EQN_yychar = YYUNDEF;
      EQN_yytoken = YYSYMBOL_YYerror;
      goto EQN_yyerrlab1;
    }
  else
    {
      EQN_yytoken = YYTRANSLATE (EQN_yychar);
      YY_SYMBOL_PRINT ("Next token is", EQN_yytoken, &EQN_yylval, &EQN_yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  EQN_yyn += EQN_yytoken;
  if (EQN_yyn < 0 || YYLAST < EQN_yyn || EQN_yycheck[EQN_yyn] != EQN_yytoken)
    goto EQN_yydefault;
  EQN_yyn = EQN_yytable[EQN_yyn];
  if (EQN_yyn <= 0)
    {
      if (EQN_yytable_value_is_error (EQN_yyn))
        goto EQN_yyerrlab;
      EQN_yyn = -EQN_yyn;
      goto EQN_yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (EQN_yyerrstatus)
    EQN_yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", EQN_yytoken, &EQN_yylval, &EQN_yylloc);
  EQN_yystate = EQN_yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++EQN_yyvsp = EQN_yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  EQN_yychar = YYEMPTY;
  goto EQN_yynewstate;


/*-----------------------------------------------------------.
| EQN_yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
EQN_yydefault:
  EQN_yyn = EQN_yydefact[EQN_yystate];
  if (EQN_yyn == 0)
    goto EQN_yyerrlab;
  goto EQN_yyreduce;


/*-----------------------------.
| EQN_yyreduce -- do a reduction.  |
`-----------------------------*/
EQN_yyreduce:
  /* EQN_yyn is the number of a rule to reduce with.  */
  EQN_yylen = EQN_yyr2[EQN_yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  EQN_yyval = EQN_yyvsp[1-EQN_yylen];


  YY_REDUCE_PRINT (EQN_yyn);
  switch (EQN_yyn)
    {
  case 5: /* program: sexpr  */
#line 90 "read_eqn.y"
                    { do_assign(util_strsav("SILLY"), (EQN_yyvsp[0].node)); }
#line 1291 "y.tab.c"
    break;

  case 9: /* stat: NAME ASSIGN identifier  */
#line 99 "read_eqn.y"
                    {
			network_set_name(global_network, (EQN_yyvsp[0].strval));
			FREE((EQN_yyvsp[0].strval));
		    }
#line 1300 "y.tab.c"
    break;

  case 12: /* stat: identifier ASSIGN expr  */
#line 109 "read_eqn.y"
                    { do_assign((EQN_yyvsp[-2].strval), (EQN_yyvsp[0].node)); }
#line 1306 "y.tab.c"
    break;

  case 13: /* stat: LPAREN ASSIGN identifier sexpr RPAREN  */
#line 112 "read_eqn.y"
                    { do_assign((EQN_yyvsp[-2].strval), (EQN_yyvsp[-1].node)); }
#line 1312 "y.tab.c"
    break;

  case 14: /* expr: expr OPR_OR expr  */
#line 117 "read_eqn.y"
                    { (EQN_yyval.node) = node_or((EQN_yyvsp[-2].node), (EQN_yyvsp[0].node)); node_free((EQN_yyvsp[-2].node)); node_free((EQN_yyvsp[0].node));}
#line 1318 "y.tab.c"
    break;

  case 15: /* expr: expr OPR_AND expr  */
#line 120 "read_eqn.y"
                    { (EQN_yyval.node) = node_and((EQN_yyvsp[-2].node), (EQN_yyvsp[0].node)); node_free((EQN_yyvsp[-2].node)); node_free((EQN_yyvsp[0].node));}
#line 1324 "y.tab.c"
    break;

  case 16: /* expr: expr expr  */
#line 123 "read_eqn.y"
                    { (EQN_yyval.node) = node_and((EQN_yyvsp[-1].node), (EQN_yyvsp[0].node)); node_free((EQN_yyvsp[-1].node)); node_free((EQN_yyvsp[0].node));}
#line 1330 "y.tab.c"
    break;

  case 17: /* expr: expr OPR_XOR expr  */
#line 126 "read_eqn.y"
                    { (EQN_yyval.node) = node_xor((EQN_yyvsp[-2].node), (EQN_yyvsp[0].node)); node_free((EQN_yyvsp[-2].node)); node_free((EQN_yyvsp[0].node));}
#line 1336 "y.tab.c"
    break;

  case 18: /* expr: expr OPR_XNOR expr  */
#line 129 "read_eqn.y"
                    { (EQN_yyval.node) = node_xnor((EQN_yyvsp[-2].node), (EQN_yyvsp[0].node)); node_free((EQN_yyvsp[-2].node)); node_free((EQN_yyvsp[0].node));}
#line 1342 "y.tab.c"
    break;

  case 19: /* expr: expr OPR_NOT_POST  */
#line 132 "read_eqn.y"
                    { (EQN_yyval.node) = node_not((EQN_yyvsp[-1].node)); node_free((EQN_yyvsp[-1].node)); }
#line 1348 "y.tab.c"
    break;

  case 20: /* expr: OPR_NOT expr  */
#line 135 "read_eqn.y"
                    { (EQN_yyval.node) = node_not((EQN_yyvsp[0].node)); node_free((EQN_yyvsp[0].node)); }
#line 1354 "y.tab.c"
    break;

  case 21: /* expr: CONST_ZERO  */
#line 138 "read_eqn.y"
                    { (EQN_yyval.node) = node_constant(0); }
#line 1360 "y.tab.c"
    break;

  case 22: /* expr: CONST_ONE  */
#line 141 "read_eqn.y"
                    { (EQN_yyval.node) = node_constant(1); }
#line 1366 "y.tab.c"
    break;

  case 23: /* expr: LPAREN expr RPAREN  */
#line 144 "read_eqn.y"
                    { (EQN_yyval.node) = (EQN_yyvsp[-1].node); }
#line 1372 "y.tab.c"
    break;

  case 24: /* expr: identifier  */
#line 147 "read_eqn.y"
                    {
			node_t *node;
			node = read_find_or_create_node(global_network, (EQN_yyvsp[0].strval));
			(EQN_yyval.node) = node_literal(node, 1);
			FREE((EQN_yyvsp[0].strval));
		    }
#line 1383 "y.tab.c"
    break;

  case 25: /* sexpr: LPAREN OPR_AND sexpr_list RPAREN  */
#line 157 "read_eqn.y"
                    { (EQN_yyval.node) = do_sexpr_list((EQN_yyvsp[-1].array), node_and); }
#line 1389 "y.tab.c"
    break;

  case 26: /* sexpr: LPAREN OPR_OR sexpr_list RPAREN  */
#line 160 "read_eqn.y"
                    { (EQN_yyval.node) = do_sexpr_list((EQN_yyvsp[-1].array), node_or); }
#line 1395 "y.tab.c"
    break;

  case 27: /* sexpr: LPAREN OPR_NOT sexpr RPAREN  */
#line 163 "read_eqn.y"
                    { (EQN_yyval.node) = node_not((EQN_yyvsp[-1].node)); node_free((EQN_yyvsp[-1].node)); }
#line 1401 "y.tab.c"
    break;

  case 28: /* sexpr: CONST_ZERO  */
#line 166 "read_eqn.y"
                    { (EQN_yyval.node) = node_constant(0); }
#line 1407 "y.tab.c"
    break;

  case 29: /* sexpr: CONST_ONE  */
#line 169 "read_eqn.y"
                    { (EQN_yyval.node) = node_constant(1); }
#line 1413 "y.tab.c"
    break;

  case 30: /* sexpr: LPAREN CONST_ZERO RPAREN  */
#line 172 "read_eqn.y"
                    { (EQN_yyval.node) = node_constant(0); }
#line 1419 "y.tab.c"
    break;

  case 31: /* sexpr: LPAREN CONST_ONE RPAREN  */
#line 175 "read_eqn.y"
                    { (EQN_yyval.node) = node_constant(1); }
#line 1425 "y.tab.c"
    break;

  case 32: /* sexpr: identifier  */
#line 178 "read_eqn.y"
                    {
			node_t *node;
			node = read_find_or_create_node(global_network, (EQN_yyvsp[0].strval));
			(EQN_yyval.node) = node_literal(node, 1);
			FREE((EQN_yyvsp[0].strval));
		    }
#line 1436 "y.tab.c"
    break;

  case 33: /* sexpr_list: sexpr  */
#line 188 "read_eqn.y"
                    {
			(EQN_yyval.array) = array_alloc(node_t *, 10);
			array_insert_last(node_t *, (EQN_yyval.array), (EQN_yyvsp[0].node));
		    }
#line 1445 "y.tab.c"
    break;

  case 34: /* sexpr_list: sexpr_list sexpr  */
#line 193 "read_eqn.y"
                    {
			array_insert_last(node_t *, (EQN_yyvsp[-1].array), (EQN_yyvsp[0].node));
		    }
#line 1453 "y.tab.c"
    break;

  case 35: /* identifier: IDENTIFIER  */
#line 199 "read_eqn.y"
                    { (EQN_yyval.strval) = util_strsav(EQN_yytext); }
#line 1459 "y.tab.c"
    break;

  case 37: /* input_list: input_list identifier  */
#line 205 "read_eqn.y"
                    {
			node_t *node;
			char errmsg[1024];
			node = read_find_or_create_node(global_network, (EQN_yyvsp[0].strval));
			if (node_function(node) != NODE_UNDEFINED) {
			    (void) sprintf(errmsg, 
				"Attempt to redefine '%s'\n", (EQN_yyvsp[0].strval));
			    EQN_yyerror(errmsg);   /* never returns */
			}
			network_change_node_type(global_network, 
							node, PRIMARY_INPUT);
			FREE((EQN_yyvsp[0].strval));
		    }
#line 1477 "y.tab.c"
    break;

  case 39: /* output_list: output_list identifier  */
#line 223 "read_eqn.y"
                    {
			node_t *node;
			node = read_find_or_create_node(global_network, (EQN_yyvsp[0].strval));
			LS_ASSERT(lsNewEnd(po_list, (lsGeneric) node, LS_NH));
			FREE((EQN_yyvsp[0].strval));
		    }
#line 1488 "y.tab.c"
    break;


#line 1492 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter EQN_yychar, and that requires
     that EQN_yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of EQN_yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering EQN_yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (EQN_yysymbol_kind_t, EQN_yyr1[EQN_yyn]), &EQN_yyval, &EQN_yyloc);

  YYPOPSTACK (EQN_yylen);
  EQN_yylen = 0;

  *++EQN_yyvsp = EQN_yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int EQN_yylhs = EQN_yyr1[EQN_yyn] - YYNTOKENS;
    const int EQN_yyi = EQN_yypgoto[EQN_yylhs] + *EQN_yyssp;
    EQN_yystate = (0 <= EQN_yyi && EQN_yyi <= YYLAST && EQN_yycheck[EQN_yyi] == *EQN_yyssp
               ? EQN_yytable[EQN_yyi]
               : EQN_yydefgoto[EQN_yylhs]);
  }

  goto EQN_yynewstate;


/*--------------------------------------.
| EQN_yyerrlab -- here on detecting error.  |
`--------------------------------------*/
EQN_yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  EQN_yytoken = EQN_yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (EQN_yychar);
  /* If not already recovering from an error, report this error.  */
  if (!EQN_yyerrstatus)
    {
      ++EQN_yynerrs;
      EQN_yyerror (YY_("syntax error"));
    }

  if (EQN_yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (EQN_yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (EQN_yychar == YYEOF)
            YYABORT;
        }
      else
        {
          EQN_yydestruct ("Error: discarding",
                      EQN_yytoken, &EQN_yylval);
          EQN_yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto EQN_yyerrlab1;


/*---------------------------------------------------.
| EQN_yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
EQN_yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label EQN_yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++EQN_yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (EQN_yylen);
  EQN_yylen = 0;
  YY_STACK_PRINT (EQN_yyss, EQN_yyssp);
  EQN_yystate = *EQN_yyssp;
  goto EQN_yyerrlab1;


/*-------------------------------------------------------------.
| EQN_yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
EQN_yyerrlab1:
  EQN_yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      EQN_yyn = EQN_yypact[EQN_yystate];
      if (!EQN_yypact_value_is_default (EQN_yyn))
        {
          EQN_yyn += YYSYMBOL_YYerror;
          if (0 <= EQN_yyn && EQN_yyn <= YYLAST && EQN_yycheck[EQN_yyn] == YYSYMBOL_YYerror)
            {
              EQN_yyn = EQN_yytable[EQN_yyn];
              if (0 < EQN_yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (EQN_yyssp == EQN_yyss)
        YYABORT;


      EQN_yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (EQN_yystate), EQN_yyvsp);
      YYPOPSTACK (1);
      EQN_yystate = *EQN_yyssp;
      YY_STACK_PRINT (EQN_yyss, EQN_yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++EQN_yyvsp = EQN_yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (EQN_yyn), EQN_yyvsp, EQN_yylsp);

  EQN_yystate = EQN_yyn;
  goto EQN_yynewstate;


/*-------------------------------------.
| EQN_yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
EQN_yyacceptlab:
  EQN_yyresult = 0;
  goto EQN_yyreturnlab;


/*-----------------------------------.
| EQN_yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
EQN_yyabortlab:
  EQN_yyresult = 1;
  goto EQN_yyreturnlab;


/*-----------------------------------------------------------.
| EQN_yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
EQN_yyexhaustedlab:
  EQN_yyerror (YY_("memory exhausted"));
  EQN_yyresult = 2;
  goto EQN_yyreturnlab;


/*----------------------------------------------------------.
| EQN_yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
EQN_yyreturnlab:
  if (EQN_yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      EQN_yytoken = YYTRANSLATE (EQN_yychar);
      EQN_yydestruct ("Cleanup: discarding lookahead",
                  EQN_yytoken, &EQN_yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (EQN_yylen);
  YY_STACK_PRINT (EQN_yyss, EQN_yyssp);
  while (EQN_yyssp != EQN_yyss)
    {
      EQN_yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*EQN_yyssp), EQN_yyvsp);
      YYPOPSTACK (1);
    }
#ifndef EQN_yyoverflow
  if (EQN_yyss != EQN_yyssa)
    YYSTACK_FREE (EQN_yyss);
#endif

  return EQN_yyresult;
}

#line 231 "read_eqn.y"


static jmp_buf jmpbuf;

int
EQN_yyerror(errmsg)
char *errmsg;
{
    read_error(errmsg);
    longjmp(jmpbuf, 1);
}


network_t *
read_eqn(fp)
FILE *fp;
{
    error_init();

    if (setjmp(jmpbuf)) {
	/* syntax error -- return from EQN_yyerror() */
	LS_ASSERT(lsDestroy(po_list, (void (*)()) 0));
	network_free(global_network);
	return 0;

    } else {
	global_network = network_alloc();
	read_filename_to_netname(global_network, read_filename);
	po_list = lsCreate();
	equation_setup_file(fp);
	(void) EQN_yyparse();

	if (!read_check_io_list(global_network, po_list)) {
	    network_free(global_network);
	    return 0;
	}
	read_hack_outputs(global_network, po_list);
	LS_ASSERT(lsDestroy(po_list, (void (*)()) 0));

	if (! network_is_acyclic(global_network)) {
	    network_free(global_network);
	    return 0;
	}

	return global_network;
    }
}

network_t *
read_eqn_string(s)
char *s;
{
    error_init();

    if (setjmp(jmpbuf)) {
	/* syntax error -- return from EQN_yyerror() */
	LS_ASSERT(lsDestroy(po_list, (void (*)()) 0));
	network_free(global_network);
	return 0;

    } else {
	global_network = network_alloc();
	po_list = lsCreate();
	equation_setup_string(s);
	(void) EQN_yyparse();

	if (!read_check_io_list(global_network, po_list)) {
	    network_free(global_network);
	    return 0;
	}
	read_hack_outputs(global_network, po_list);
	LS_ASSERT(lsDestroy(po_list, (void (*)()) 0));

	if (! network_is_acyclic(global_network)) {
	    network_free(global_network);
	    return 0;
	}

	return global_network;
    }
}
