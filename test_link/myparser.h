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
* myparser.h
* C++ header file generated from myparser.y.
* 
* Date: 12/27/16
* Time: 20:50:39
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _MYPARSER_H
#define _MYPARSER_H

#include <yycpars.h>

/////////////////////////////////////////////////////////////////////////////
// myparser

#ifndef YYEXPPARSER
#define YYEXPPARSER
#endif

class YYEXPPARSER YYFAR myparser : public _YL yyfparser {
public:
	myparser();
	virtual ~myparser();

protected:
	void yytables();
	virtual void yyaction(int action);
#ifdef YYDEBUG
	void YYFAR* yyattribute1(int index) const;
	void yyinitdebug(void YYFAR** p, int count) const;
#endif

	// attribute functions
	virtual void yystacktoval(int index);
	virtual void yyvaltostack(int index);
	virtual void yylvaltoval();
	virtual void yyvaltolval();
	virtual void yylvaltostack(int index);

	virtual void YYFAR* yynewattribute(int count);
	virtual void yydeleteattribute(void YYFAR* attribute);
	virtual void yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count);

public:
};

#ifndef YYPARSERNAME
#define YYPARSERNAME myparser
#endif

#line 29 ".\\myparser.y"

#ifndef YYSTYPE
#define YYSTYPE TreeNode *//定义为节点类型
#endif

#line 77 "myparser.h"
#define MAIN 257
#define IF 258
#define ELSE 259
#define WHILE 260
#define FOR 261
#define INT 262
#define CHAR 263
#define FLOAT 264
#define ID 265
#define NUM 266
#define CH 267
#define ASSIGN 268
#define _EQ 269
#define _NE 270
#define _LSH 271
#define _RSH 272
#define _NOT 273
#define _OR 274
#define _XOR 275
#define _AND 276
#define _LT 277
#define _LE 278
#define _GT 279
#define _GE 280
#define _PLUS 281
#define _MINUS 282
#define _TIMES 283
#define _OVER 284
#define _MOD 285
#define _INCRE 286
#define _DECRE 287
#define LPAREN 288
#define RPAREN 289
#define SEMI 290
#define COMMA 291
#define _ANDAND 292
#define _OROR 293
#define _NO 294
#define INPUT 295
#define OUTPUT 296
#define ERROR 297
#endif
