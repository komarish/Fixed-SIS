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
   especially those whose name start with YY_ or EQN_yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 113 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE EQN_yylval;


int EQN_yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
