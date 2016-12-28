/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 71 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* mylexer.cpp
* C++ source file generated from mylexer.l.
* 
* Date: 12/27/16
* Time: 20:50:39
* 
* ALex Version: 2.07
****************************************************************************/

#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\mylexer.l"

/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2016年11月16日, 星期三
****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include "myparser.h"
#include <iostream>
#include <cctype>
#include <stdlib.h>
#include <malloc.h>
#include <string>
#include <iomanip>

using namespace std;

extern int lineno;
string tokenString;

#line 61 "mylexer.cpp"
// repeated because of possible precompiled header
#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\mylexer.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYLEXERNAME::YYLEXERNAME()
{
	yytables();
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
}

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYLEXERNAME error then you have not declared
* the name of the lexical analyser. The easiest way to do this is to use a
* name declaration. This is placed in the declarations section of your Lex
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the lexer mylexer:
* 
* %name mylexer
* 
* For more information see help.
****************************************************************************/

// backwards compatability with lex
#ifdef input
int YYLEXERNAME::yyinput()
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
void YYLEXERNAME::yyoutput(int ch)
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
void YYLEXERNAME::yyunput(int ch)
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		// <warning: unreachable code> off
#endif
#endif

int YYLEXERNAME::yyaction(int action)
{
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 42 ".\\mylexer.l"
return MAIN;
#line 159 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 43 ".\\mylexer.l"
return '{';
#line 166 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 44 ".\\mylexer.l"
return '}';
#line 173 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 45 ".\\mylexer.l"
return IF;
#line 180 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 46 ".\\mylexer.l"
return ELSE;
#line 187 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 47 ".\\mylexer.l"
return WHILE;
#line 194 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 48 ".\\mylexer.l"
return FOR;
#line 201 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 49 ".\\mylexer.l"
return INT;
#line 208 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 50 ".\\mylexer.l"
return CHAR;
#line 215 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 51 ".\\mylexer.l"
return FLOAT;
#line 222 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 52 ".\\mylexer.l"
return INPUT;
#line 229 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 53 ".\\mylexer.l"
return OUTPUT;
#line 236 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 54 ".\\mylexer.l"
return ASSIGN;
#line 243 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 55 ".\\mylexer.l"
return _EQ;
#line 250 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 56 ".\\mylexer.l"
return _NE;
#line 257 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 57 ".\\mylexer.l"
return _LSH;
#line 264 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 58 ".\\mylexer.l"
return _RSH;
#line 271 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 59 ".\\mylexer.l"
return _OROR;
#line 278 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 60 ".\\mylexer.l"
return _ANDAND;
#line 285 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 61 ".\\mylexer.l"
return _NO;
#line 292 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 62 ".\\mylexer.l"
return _LT;
#line 299 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 63 ".\\mylexer.l"
return _GT;
#line 306 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 64 ".\\mylexer.l"
return _GE;
#line 313 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 65 ".\\mylexer.l"
return _LE;
#line 320 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 66 ".\\mylexer.l"
return _PLUS;
#line 327 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 67 ".\\mylexer.l"
return _MINUS;
#line 334 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 68 ".\\mylexer.l"
return _TIMES;
#line 341 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 69 ".\\mylexer.l"
return _OVER;
#line 348 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 70 ".\\mylexer.l"
return _MOD;
#line 355 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 71 ".\\mylexer.l"
return _INCRE;
#line 362 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 72 ".\\mylexer.l"
return _DECRE;
#line 369 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 73 ".\\mylexer.l"
return _AND;
#line 376 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 74 ".\\mylexer.l"
return _OR;
#line 383 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 75 ".\\mylexer.l"
return _XOR;
#line 390 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 76 ".\\mylexer.l"
return _NOT;
#line 397 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 77 ".\\mylexer.l"
return LPAREN;
#line 404 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 78 ".\\mylexer.l"
return RPAREN;
#line 411 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 79 ".\\mylexer.l"
return SEMI;
#line 418 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 80 ".\\mylexer.l"
return COMMA;
#line 425 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 81 ".\\mylexer.l"
tokenString=yytext;return CH;
#line 432 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 82 ".\\mylexer.l"
tokenString=yytext;return NUM;
#line 439 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 83 ".\\mylexer.l"
tokenString=yytext;return ID;
#line 446 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 84 ".\\mylexer.l"
lineno++;
#line 453 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 85 ".\\mylexer.l"

#line 460 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 86 ".\\mylexer.l"

#line 467 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 87 ".\\mylexer.l"
/* skip whitespace */
#line 474 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 88 ".\\mylexer.l"
return ERROR;
#line 481 "mylexer.cpp"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = yyfalse;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		// <warning: unreachable code> to the old state
#endif
#endif

void YYLEXERNAME::yytables()
{
	yystext_size = YYTEXT_SIZE;
	yysunput_size = YYUNPUT_SIZE;
	yytext_max = YYTEXT_MAX;
	yyunput_max = YYUNPUT_MAX;

	static const yymatch_t YYNEARFAR YYBASED_CODE match[] = {
		0
	};
	yymatch = match;

	yytransitionmax = 243;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 4, 1 },
		{ 5, 1 },
		{ 63, 42 },
		{ 34, 6 },
		{ 63, 42 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 48, 24 },
		{ 49, 24 },
		{ 52, 26 },
		{ 35, 8 },
		{ 54, 27 },
		{ 53, 26 },
		{ 56, 28 },
		{ 50, 24 },
		{ 4, 1 },
		{ 6, 1 },
		{ 4, 1 },
		{ 42, 62 },
		{ 55, 27 },
		{ 7, 1 },
		{ 8, 1 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 14, 1 },
		{ 15, 1 },
		{ 57, 29 },
		{ 16, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 74, 74 },
		{ 18, 1 },
		{ 19, 1 },
		{ 20, 1 },
		{ 21, 1 },
		{ 0, 74 },
		{ 58, 31 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 39, 16 },
		{ 43, 19 },
		{ 44, 19 },
		{ 23, 1 },
		{ 22, 1 },
		{ 40, 16 },
		{ 22, 1 },
		{ 22, 1 },
		{ 24, 1 },
		{ 22, 1 },
		{ 25, 1 },
		{ 26, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 27, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 28, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 29, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 30, 1 },
		{ 31, 1 },
		{ 32, 1 },
		{ 33, 1 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 46, 21 },
		{ 47, 21 },
		{ 59, 36 },
		{ 61, 39 },
		{ 0, 40 },
		{ 0, 41 },
		{ 0, 9 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 65, 48 },
		{ 66, 49 },
		{ 67, 50 },
		{ 68, 51 },
		{ 22, 87 },
		{ 69, 52 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 22, 87 },
		{ 4, 5 },
		{ 4, 5 },
		{ 41, 17 },
		{ 70, 53 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 71, 55 },
		{ 72, 56 },
		{ 73, 57 },
		{ 61, 60 },
		{ 75, 61 },
		{ 45, 20 },
		{ 37, 13 },
		{ 76, 65 },
		{ 77, 66 },
		{ 4, 5 },
		{ 78, 67 },
		{ 4, 5 },
		{ 64, 64 },
		{ 64, 64 },
		{ 64, 64 },
		{ 64, 64 },
		{ 64, 64 },
		{ 64, 64 },
		{ 64, 64 },
		{ 64, 64 },
		{ 64, 64 },
		{ 64, 64 },
		{ 79, 68 },
		{ 80, 69 },
		{ 81, 72 },
		{ 82, 73 },
		{ 38, 15 },
		{ 83, 77 },
		{ 84, 78 },
		{ 85, 80 },
		{ 86, 81 },
		{ 87, 82 },
		{ 88, 84 },
		{ 89, 86 },
		{ 51, 25 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ -3, -8, 0 },
		{ 1, 0, 0 },
		{ 0, 0, 47 },
		{ 5, 0, 46 },
		{ 0, 185, 43 },
		{ 0, -57, 20 },
		{ 0, 0, 29 },
		{ 0, -19, 32 },
		{ -36, 125, 47 },
		{ 0, 0, 36 },
		{ 0, 0, 37 },
		{ 0, 0, 27 },
		{ 0, 171, 25 },
		{ 0, 0, 39 },
		{ 0, 189, 26 },
		{ 0, 41, 28 },
		{ 62, 150, 41 },
		{ 0, 0, 38 },
		{ 0, 24, 21 },
		{ 0, 152, 13 },
		{ 0, 68, 22 },
		{ 87, 0, 42 },
		{ 0, 0, 34 },
		{ 87, -88, 42 },
		{ 87, 134, 42 },
		{ 87, -90, 42 },
		{ 87, -82, 42 },
		{ 87, -75, 42 },
		{ 87, -66, 42 },
		{ 0, 0, 2 },
		{ 0, -68, 33 },
		{ 0, 0, 3 },
		{ 0, 0, 35 },
		{ 0, 0, 15 },
		{ 0, 0, 19 },
		{ 0, 92, 0 },
		{ 0, 0, 30 },
		{ 0, 0, 31 },
		{ 74, 90, 0 },
		{ -40, 123, 44 },
		{ 62, 65, 0 },
		{ 64, -40, 0 },
		{ 0, 0, 16 },
		{ 0, 0, 24 },
		{ 0, 0, 14 },
		{ 0, 0, 23 },
		{ 0, 0, 17 },
		{ 87, 65, 42 },
		{ 87, 53, 42 },
		{ 87, 47, 42 },
		{ 87, 50, 42 },
		{ 87, 56, 42 },
		{ 87, 83, 42 },
		{ 87, 0, 4 },
		{ 87, 92, 42 },
		{ 87, 104, 42 },
		{ 87, 105, 42 },
		{ 0, 0, 18 },
		{ 0, 0, 40 },
		{ -60, 169, 0 },
		{ 74, 165, 0 },
		{ 0, -42, 41 },
		{ 64, 0, 0 },
		{ 0, 172, 41 },
		{ 87, 101, 42 },
		{ 87, 154, 42 },
		{ 87, 102, 42 },
		{ 87, 129, 42 },
		{ 87, 134, 42 },
		{ 87, 0, 7 },
		{ 87, 0, 8 },
		{ 87, 122, 42 },
		{ 87, 125, 42 },
		{ -60, 8, 0 },
		{ 0, 0, 45 },
		{ 87, 0, 9 },
		{ 0, 173, 0 },
		{ 87, 176, 42 },
		{ 87, 0, 5 },
		{ 87, 121, 42 },
		{ 87, 198, 42 },
		{ 87, 138, 42 },
		{ 0, 0, 11 },
		{ 0, 180, 0 },
		{ 87, 0, 10 },
		{ 0, 200, 0 },
		{ 0, 71, 6 },
		{ 0, 0, 12 },
		{ 0, 0, 1 }
	};
	yystate = state;

	static const yybackup_t YYNEARFAR YYBASED_CODE backup[] = {
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	yybackup = backup;
}
#line 90 ".\\mylexer.l"


/////////////////////////////////////////////////////////////////////////////
// programs section

