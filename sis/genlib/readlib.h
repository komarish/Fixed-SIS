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
   especially those whose name start with YY_ or GENLIB_yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 117 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE GENLIB_yylval;


int GENLIB_yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
