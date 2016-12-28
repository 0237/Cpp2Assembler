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
* myparser.cpp
* C++ source file generated from myparser.y.
* 
* Date: 12/27/16
* Time: 20:50:39
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\myparser.y"

/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: 2016年11月16日, 星期三
****************************************************************************/

#include "mylexer.h"
#include "globals.h"
#include <fstream>
#include <string>

using namespace std;

char *savedName; /* for use in assignments */
static int savedLineNo;  /* ditto */
TreeNode * savedTree; /* stores syntax tree for later return */
int lineno;// 行号
//string t="t";
int tno;// 临时变量个数
extern string tokenString;

#line 62 "myparser.cpp"
// repeated because of possible precompiled header
#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\myparser.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYPARSERNAME::YYPARSERNAME()
{
	yytables();
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
}

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYPARSERNAME error then you have not declared
* the name of the parser. The easiest way to do this is to use a name
* declaration. This is placed in the declarations section of your YACC
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the parser myparser:
* 
* %name myparser
* 
* For more information see help.
****************************************************************************/

// yyattribute
#ifdef YYDEBUG
void YYFAR* YYPARSERNAME::yyattribute1(int index) const
{
	YYSTYPE YYFAR* p = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*(YYSTYPE YYFAR*)yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR*)yyattributestackptr)[yytop + (index)])
#endif

void YYPARSERNAME::yystacktoval(int index)
{
	yyassert(index >= 0);
	*(YYSTYPE YYFAR*)yyvalptr = ((YYSTYPE YYFAR*)yyattributestackptr)[index];
}

void YYPARSERNAME::yyvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltoval()
{
	*(YYSTYPE YYFAR*)yyvalptr = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYPARSERNAME::yyvaltolval()
{
	*(YYSTYPE YYFAR*)yylvalptr = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYFAR* YYPARSERNAME::yynewattribute(int count)
{
	yyassert(count >= 0);
	return new YYFAR YYSTYPE[count];
}

void YYPARSERNAME::yydeleteattribute(void YYFAR* attribute)
{
	delete[] (YYSTYPE YYFAR*)attribute;
}

void YYPARSERNAME::yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count)
{
	for (int i = 0; i < count; i++) {
		((YYSTYPE YYFAR*)dest)[i] = ((YYSTYPE YYFAR*)src)[i];
	}
}

#ifdef YYDEBUG
void YYPARSERNAME::yyinitdebug(void YYFAR** p, int count) const
{
	yyassert(p != NULL);
	yyassert(count >= 1);

	YYSTYPE YYFAR** p1 = (YYSTYPE YYFAR**)p;
	for (int i = 0; i < count; i++) {
		p1[i] = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

void YYPARSERNAME::yyaction(int action)
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 75 ".\\myparser.y"
 savedTree = newStmtNode(Maink);
				           savedTree->child[0] = yyattribute(2 - 2);
				         
#line 202 "myparser.cpp"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 79 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 3); 
#line 215 "myparser.cpp"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 82 ".\\myparser.y"
 YYSTYPE t = yyattribute(1 - 2);
                  if (t != NULL)
                  { while (t->sibling != NULL)
                      t = t->sibling;
                    t->sibling = yyattribute(2 - 2);
                    (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2); }
                  else (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 2);
                
#line 235 "myparser.cpp"
			}
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 90 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 248 "myparser.cpp"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 92 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 261 "myparser.cpp"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 93 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 274 "myparser.cpp"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 94 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 287 "myparser.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 95 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2); 
#line 300 "myparser.cpp"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 96 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2); 
#line 313 "myparser.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 97 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2); 
#line 326 "myparser.cpp"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 98 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2); 
#line 339 "myparser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 99 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2); 
#line 352 "myparser.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 100 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 365 "myparser.cpp"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 101 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = NULL; 
#line 378 "myparser.cpp"
			}
		}
		break;
	case 14:
		{
#line 102 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = NULL; 
#line 386 "myparser.cpp"
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 104 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 398 "myparser.cpp"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 105 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 411 "myparser.cpp"
			}
		}
		break;
	case 17:
		{
#line 106 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = NULL; 
#line 419 "myparser.cpp"
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 108 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 431 "myparser.cpp"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 109 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 444 "myparser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 112 ".\\myparser.y"
 YYSTYPE t = yyattribute(1 - 3);
                  if (t != NULL)
                  { while (t->sibling != NULL)
                      t = t->sibling;
                    t->sibling = yyattribute(3 - 3);
                    (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 3); }
                  else (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(3 - 3);
				        
#line 464 "myparser.cpp"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 120 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 477 "myparser.cpp"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 122 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); 
#line 490 "myparser.cpp"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 123 ".\\myparser.y"
  (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(IdK);
                    (*(YYSTYPE YYFAR*)yyvalptr)->attr.name = copyString("_"+tokenString);
                    if (st_lookup((*(YYSTYPE YYFAR*)yyvalptr)->attr.name) == -1)
                    {
                      st_insert((*(YYSTYPE YYFAR*)yyvalptr)->attr.name, (*(YYSTYPE YYFAR*)yyvalptr)->lineno, location++, (*(YYSTYPE YYFAR*)yyvalptr));
                    }
                    else
                    {
                      typeError((*(YYSTYPE YYFAR*)yyvalptr), "duplicate definition");
                    }
                 
#line 513 "myparser.cpp"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 136 ".\\myparser.y"
  
                   (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(Declarek);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 2);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(2 - 2);
                
#line 530 "myparser.cpp"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 142 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(Typek);
                    (*(YYSTYPE YYFAR*)yyvalptr)->type = Integer; 
#line 544 "myparser.cpp"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 144 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(Typek);
                    (*(YYSTYPE YYFAR*)yyvalptr)->type = Character; 
#line 558 "myparser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 146 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(Typek);
                    (*(YYSTYPE YYFAR*)yyvalptr)->type = Float; 
#line 572 "myparser.cpp"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 150 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(IfK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 7);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 7);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(7 - 7);
                 
#line 589 "myparser.cpp"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 156 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(IfK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 5);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 5);
                 
#line 605 "myparser.cpp"
			}
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[10];
			yyinitdebug((void YYFAR**)yya, 10);
#endif
			{
#line 162 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 9);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 9);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(7 - 9);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(9 - 9);
                 
#line 623 "myparser.cpp"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 170 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(WhileK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 5);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 5);
                 
#line 639 "myparser.cpp"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 175 ".\\myparser.y"
 savedName = copyString("_"+tokenString);
                   savedLineNo = lineno; 
                   
#line 654 "myparser.cpp"
			}
		}
		break;
	case 33:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 179 ".\\myparser.y"
 YYSTYPE t = newExpNode(IdK);
                   t->attr.name = savedName;
                    if (st_lookup(t->attr.name) == -1)
                      typeError(t, "not defined");
                    else
                    {
                      st_insert(t->attr.name, t->lineno, 0, t);
                    }
                   (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(AssignK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = t;
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(4 - 4);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.name = savedName;
                   (*(YYSTYPE YYFAR*)yyvalptr)->lineno = savedLineNo;
                 
#line 680 "myparser.cpp"
			}
		}
		break;
	case 34:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 195 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ReadK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(2 - 2);
                 
#line 695 "myparser.cpp"
			}
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 200 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(WriteK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(2 - 2);
                 
#line 710 "myparser.cpp"
			}
		}
		break;
	case 36:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 205 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = OROR;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 
#line 728 "myparser.cpp"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 212 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = ANDAND;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 
#line 746 "myparser.cpp"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 219 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = NE;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 
#line 764 "myparser.cpp"
			}
		}
		break;
	case 39:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 226 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = EQ;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 
#line 782 "myparser.cpp"
			}
		}
		break;
	case 40:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 233 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = LT;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 
#line 800 "myparser.cpp"
			}
		}
		break;
	case 41:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 240 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = GT;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 
#line 818 "myparser.cpp"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 247 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = GE;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 
#line 836 "myparser.cpp"
			}
		}
		break;
	case 43:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 254 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = LE;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 
#line 854 "myparser.cpp"
			}
		}
		break;
	case 44:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 261 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = LSH;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 
#line 872 "myparser.cpp"
			}
		}
		break;
	case 45:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 268 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = RSH;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 
#line 890 "myparser.cpp"
			}
		}
		break;
	case 46:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 275 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = PLUS;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 
#line 908 "myparser.cpp"
			}
		}
		break;
	case 47:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 282 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = MINUS;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 
#line 926 "myparser.cpp"
			}
		}
		break;
	case 48:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 289 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = TIMES;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 
#line 944 "myparser.cpp"
			}
		}
		break;
	case 49:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 296 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = OVER;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 
#line 962 "myparser.cpp"
			}
		}
		break;
	case 50:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 303 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = MOD;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 
#line 980 "myparser.cpp"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 310 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 3); 
#line 993 "myparser.cpp"
			}
		}
		break;
	case 52:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 311 ".\\myparser.y"
 savedName = copyString("_"+tokenString);
                   savedLineNo = lineno; 
                   
#line 1008 "myparser.cpp"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 315 ".\\myparser.y"
 YYSTYPE t = newExpNode(IdK);
                   t->attr.name = savedName;
                    if (st_lookup(t->attr.name) == -1)
                      typeError(t, "not defined");
                    else
                    {
                      st_insert(t->attr.name, t->lineno, 0, t);
                    }
                   (*(YYSTYPE YYFAR*)yyvalptr)=newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0]=t;
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op=INCRE;
                   (*(YYSTYPE YYFAR*)yyvalptr)->type=Integer;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 
#line 1034 "myparser.cpp"
			}
		}
		break;
	case 54:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 329 ".\\myparser.y"
 savedName = copyString("_"+tokenString);
                   savedLineNo = lineno; 
                   
#line 1049 "myparser.cpp"
			}
		}
		break;
	case 55:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 333 ".\\myparser.y"
 YYSTYPE t = newExpNode(IdK);
                   t->attr.name = savedName;
                    if (st_lookup(t->attr.name) == -1)
                      typeError(t, "not defined");
                    else
                    {
                      st_insert(t->attr.name, t->lineno, 0, t);
                    }
                   (*(YYSTYPE YYFAR*)yyvalptr)=newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0]=t;
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op=DECRE;
                   (*(YYSTYPE YYFAR*)yyvalptr)->type=Integer;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 
#line 1075 "myparser.cpp"
			}
		}
		break;
	case 56:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 348 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0]=newExpNode(ConstK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0]->attr.val=0;
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(2 - 2);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op=MINUS;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 
#line 1094 "myparser.cpp"
			}
		}
		break;
	case 57:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 356 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op=OR;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 
#line 1112 "myparser.cpp"
			}
		}
		break;
	case 58:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 363 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op=XOR;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 
#line 1130 "myparser.cpp"
			}
		}
		break;
	case 59:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 370 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=newExpNode(OpK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.op=AND;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 
#line 1148 "myparser.cpp"
			}
		}
		break;
	case 60:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 377 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(ConstK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.val = atoi(tokenString.c_str());
                 
#line 1163 "myparser.cpp"
			}
		}
		break;
	case 61:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 380 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(IdK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.name = copyString("_"+tokenString);
                   if (st_lookup((*(YYSTYPE YYFAR*)yyvalptr)->attr.name) == -1)
                      typeError((*(YYSTYPE YYFAR*)yyvalptr), "not defined");
                    else
                    {
                      st_insert((*(YYSTYPE YYFAR*)yyvalptr)->attr.name, (*(YYSTYPE YYFAR*)yyvalptr)->lineno, 0, (*(YYSTYPE YYFAR*)yyvalptr));
                    }
                 
#line 1184 "myparser.cpp"
			}
		}
		break;
	case 62:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 389 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(ChK);
                   (*(YYSTYPE YYFAR*)yyvalptr)->attr.val = tokenString[1];
                 
#line 1199 "myparser.cpp"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}

void YYPARSERNAME::yytables()
{
	yyattribute_size = sizeof(YYSTYPE);
	yysstack_size = YYSTACK_SIZE;
	yystack_max = YYSTACK_MAX;

#ifdef YYDEBUG
	static const yysymbol_t YYNEARFAR YYBASED_CODE symbol[] = {
		{ "$end", 0 },
		{ "\'{\'", 123 },
		{ "\'}\'", 125 },
		{ "error", 256 },
		{ "MAIN", 257 },
		{ "IF", 258 },
		{ "ELSE", 259 },
		{ "WHILE", 260 },
		{ "FOR", 261 },
		{ "INT", 262 },
		{ "CHAR", 263 },
		{ "FLOAT", 264 },
		{ "ID", 265 },
		{ "NUM", 266 },
		{ "CH", 267 },
		{ "ASSIGN", 268 },
		{ "_EQ", 269 },
		{ "_NE", 270 },
		{ "_LSH", 271 },
		{ "_RSH", 272 },
		{ "_NOT", 273 },
		{ "_OR", 274 },
		{ "_XOR", 275 },
		{ "_AND", 276 },
		{ "_LT", 277 },
		{ "_LE", 278 },
		{ "_GT", 279 },
		{ "_GE", 280 },
		{ "_PLUS", 281 },
		{ "_MINUS", 282 },
		{ "_TIMES", 283 },
		{ "_OVER", 284 },
		{ "_MOD", 285 },
		{ "_INCRE", 286 },
		{ "_DECRE", 287 },
		{ "LPAREN", 288 },
		{ "RPAREN", 289 },
		{ "SEMI", 290 },
		{ "COMMA", 291 },
		{ "_ANDAND", 292 },
		{ "_OROR", 293 },
		{ "INPUT", 295 },
		{ "OUTPUT", 296 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: program",
		"program: MAIN stmt_seq",
		"block: \'{\' stmt_seq \'}\'",
		"stmt_seq: stmt_seq stmt",
		"stmt_seq: stmt",
		"stmt: for_stmt",
		"stmt: if_stmt",
		"stmt: while_stmt",
		"stmt: assign_stmt SEMI",
		"stmt: declare_stmt SEMI",
		"stmt: read_stmt SEMI",
		"stmt: write_stmt SEMI",
		"stmt: exp SEMI",
		"stmt: block",
		"stmt: SEMI",
		"stmt:",
		"for_expr: exp",
		"for_expr: list",
		"for_expr:",
		"iw_expr: exp",
		"iw_expr: assign_stmt",
		"list: list COMMA id_stmt",
		"list: id_stmt",
		"id_stmt: assign_stmt",
		"id_stmt: ID",
		"declare_stmt: type_stmt list",
		"type_stmt: INT",
		"type_stmt: CHAR",
		"type_stmt: FLOAT",
		"if_stmt: IF LPAREN iw_expr RPAREN stmt ELSE stmt",
		"if_stmt: IF LPAREN iw_expr RPAREN stmt",
		"for_stmt: FOR LPAREN for_expr SEMI for_expr SEMI for_expr RPAREN stmt",
		"while_stmt: WHILE LPAREN iw_expr RPAREN stmt",
		"$$1:",
		"assign_stmt: ID $$1 ASSIGN exp",
		"read_stmt: INPUT exp",
		"write_stmt: OUTPUT exp",
		"exp: exp _OROR exp",
		"exp: exp _ANDAND exp",
		"exp: exp _NE exp",
		"exp: exp _EQ exp",
		"exp: exp _LT exp",
		"exp: exp _GT exp",
		"exp: exp _GE exp",
		"exp: exp _LE exp",
		"exp: exp _LSH exp",
		"exp: exp _RSH exp",
		"exp: exp _PLUS exp",
		"exp: exp _MINUS exp",
		"exp: exp _TIMES exp",
		"exp: exp _OVER exp",
		"exp: exp _MOD exp",
		"exp: LPAREN exp RPAREN",
		"$$2:",
		"exp: ID $$2 _INCRE",
		"$$3:",
		"exp: ID $$3 _DECRE",
		"exp: _MINUS exp",
		"exp: exp _OR exp",
		"exp: exp _XOR exp",
		"exp: exp _AND exp",
		"exp: NUM",
		"exp: ID",
		"exp: CH"
	};
	yyrule = rule;
#endif

	static const yyreduction_t YYNEARFAR YYBASED_CODE reduction[] = {
		{ 0, 1, -1 },
		{ 1, 2, 0 },
		{ 2, 3, 1 },
		{ 3, 2, 2 },
		{ 3, 1, 3 },
		{ 4, 1, 4 },
		{ 4, 1, 5 },
		{ 4, 1, 6 },
		{ 4, 2, 7 },
		{ 4, 2, 8 },
		{ 4, 2, 9 },
		{ 4, 2, 10 },
		{ 4, 2, 11 },
		{ 4, 1, 12 },
		{ 4, 1, 13 },
		{ 4, 0, 14 },
		{ 5, 1, 15 },
		{ 5, 1, 16 },
		{ 5, 0, 17 },
		{ 6, 1, 18 },
		{ 6, 1, 19 },
		{ 7, 3, 20 },
		{ 7, 1, 21 },
		{ 8, 1, 22 },
		{ 8, 1, 23 },
		{ 9, 2, 24 },
		{ 10, 1, 25 },
		{ 10, 1, 26 },
		{ 10, 1, 27 },
		{ 11, 7, 28 },
		{ 11, 5, 29 },
		{ 12, 9, 30 },
		{ 13, 5, 31 },
		{ 15, 0, 32 },
		{ 14, 4, 33 },
		{ 16, 2, 34 },
		{ 17, 2, 35 },
		{ 18, 3, 36 },
		{ 18, 3, 37 },
		{ 18, 3, 38 },
		{ 18, 3, 39 },
		{ 18, 3, 40 },
		{ 18, 3, 41 },
		{ 18, 3, 42 },
		{ 18, 3, 43 },
		{ 18, 3, 44 },
		{ 18, 3, 45 },
		{ 18, 3, 46 },
		{ 18, 3, 47 },
		{ 18, 3, 48 },
		{ 18, 3, 49 },
		{ 18, 3, 50 },
		{ 18, 3, 51 },
		{ 19, 0, 52 },
		{ 18, 3, 53 },
		{ 20, 0, 54 },
		{ 18, 3, 55 },
		{ 18, 2, 56 },
		{ 18, 3, 57 },
		{ 18, 3, 58 },
		{ 18, 3, 59 },
		{ 18, 1, 60 },
		{ 18, 1, 61 },
		{ 18, 1, 62 }
	};
	yyreduction = reduction;

	yytokenaction_size = 530;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 114, YYAT_SHIFT, 3 },
		{ 96, YYAT_SHIFT, 62 },
		{ 96, YYAT_SHIFT, 63 },
		{ 96, YYAT_SHIFT, 64 },
		{ 113, YYAT_SHIFT, 114 },
		{ 10, YYAT_REDUCE, 33 },
		{ 39, YYAT_SHIFT, 49 },
		{ 39, YYAT_SHIFT, 50 },
		{ 39, YYAT_SHIFT, 51 },
		{ 39, YYAT_SHIFT, 52 },
		{ 110, YYAT_SHIFT, 3 },
		{ 39, YYAT_SHIFT, 53 },
		{ 39, YYAT_SHIFT, 54 },
		{ 39, YYAT_SHIFT, 55 },
		{ 39, YYAT_SHIFT, 56 },
		{ 39, YYAT_SHIFT, 57 },
		{ 39, YYAT_SHIFT, 58 },
		{ 39, YYAT_SHIFT, 59 },
		{ 39, YYAT_SHIFT, 60 },
		{ 39, YYAT_SHIFT, 61 },
		{ 39, YYAT_SHIFT, 62 },
		{ 39, YYAT_SHIFT, 63 },
		{ 39, YYAT_SHIFT, 64 },
		{ 10, YYAT_REDUCE, 53 },
		{ 10, YYAT_REDUCE, 55 },
		{ 109, YYAT_SHIFT, 111 },
		{ 39, YYAT_SHIFT, 82 },
		{ 37, YYAT_REDUCE, 53 },
		{ 37, YYAT_REDUCE, 55 },
		{ 39, YYAT_SHIFT, 66 },
		{ 39, YYAT_SHIFT, 67 },
		{ 105, YYAT_SHIFT, 49 },
		{ 105, YYAT_SHIFT, 50 },
		{ 105, YYAT_SHIFT, 51 },
		{ 105, YYAT_SHIFT, 52 },
		{ 107, YYAT_SHIFT, 110 },
		{ 105, YYAT_SHIFT, 53 },
		{ 105, YYAT_SHIFT, 54 },
		{ 105, YYAT_SHIFT, 55 },
		{ 105, YYAT_SHIFT, 56 },
		{ 105, YYAT_SHIFT, 57 },
		{ 105, YYAT_SHIFT, 58 },
		{ 105, YYAT_SHIFT, 59 },
		{ 105, YYAT_SHIFT, 60 },
		{ 105, YYAT_SHIFT, 61 },
		{ 105, YYAT_SHIFT, 62 },
		{ 105, YYAT_SHIFT, 63 },
		{ 105, YYAT_SHIFT, 64 },
		{ 83, YYAT_SHIFT, 42 },
		{ 103, YYAT_SHIFT, 3 },
		{ 95, YYAT_SHIFT, 62 },
		{ 95, YYAT_SHIFT, 63 },
		{ 95, YYAT_SHIFT, 64 },
		{ 78, YYAT_SHIFT, 104 },
		{ 105, YYAT_SHIFT, 66 },
		{ 105, YYAT_SHIFT, 67 },
		{ 22, YYAT_ERROR, 0 },
		{ 22, YYAT_SHIFT, 65 },
		{ 76, YYAT_SHIFT, 83 },
		{ 102, YYAT_SHIFT, 3 },
		{ 77, YYAT_SHIFT, 49 },
		{ 77, YYAT_SHIFT, 50 },
		{ 77, YYAT_SHIFT, 51 },
		{ 77, YYAT_SHIFT, 52 },
		{ 74, YYAT_SHIFT, 103 },
		{ 77, YYAT_SHIFT, 53 },
		{ 77, YYAT_SHIFT, 54 },
		{ 77, YYAT_SHIFT, 55 },
		{ 77, YYAT_SHIFT, 56 },
		{ 77, YYAT_SHIFT, 57 },
		{ 77, YYAT_SHIFT, 58 },
		{ 77, YYAT_SHIFT, 59 },
		{ 77, YYAT_SHIFT, 60 },
		{ 77, YYAT_SHIFT, 61 },
		{ 77, YYAT_SHIFT, 62 },
		{ 77, YYAT_SHIFT, 63 },
		{ 77, YYAT_SHIFT, 64 },
		{ 71, YYAT_SHIFT, 102 },
		{ 75, YYAT_REDUCE, 33 },
		{ 88, YYAT_SHIFT, 49 },
		{ 88, YYAT_SHIFT, 50 },
		{ 88, YYAT_SHIFT, 51 },
		{ 88, YYAT_SHIFT, 52 },
		{ 77, YYAT_SHIFT, 66 },
		{ 77, YYAT_SHIFT, 67 },
		{ 88, YYAT_SHIFT, 54 },
		{ 88, YYAT_SHIFT, 55 },
		{ 88, YYAT_SHIFT, 56 },
		{ 88, YYAT_SHIFT, 57 },
		{ 88, YYAT_SHIFT, 58 },
		{ 88, YYAT_SHIFT, 59 },
		{ 88, YYAT_SHIFT, 60 },
		{ 88, YYAT_SHIFT, 61 },
		{ 88, YYAT_SHIFT, 62 },
		{ 88, YYAT_SHIFT, 63 },
		{ 88, YYAT_SHIFT, 64 },
		{ 75, YYAT_REDUCE, 53 },
		{ 75, YYAT_REDUCE, 55 },
		{ 27, YYAT_SHIFT, 3 },
		{ 75, YYAT_REDUCE, 24 },
		{ 75, YYAT_REDUCE, 24 },
		{ 75, YYAT_REDUCE, 24 },
		{ 44, YYAT_SHIFT, 83 },
		{ 42, YYAT_REDUCE, 33 },
		{ 72, YYAT_SHIFT, 49 },
		{ 72, YYAT_SHIFT, 50 },
		{ 72, YYAT_SHIFT, 51 },
		{ 72, YYAT_SHIFT, 52 },
		{ 3, YYAT_SHIFT, 3 },
		{ 72, YYAT_SHIFT, 53 },
		{ 72, YYAT_SHIFT, 54 },
		{ 72, YYAT_SHIFT, 55 },
		{ 72, YYAT_SHIFT, 56 },
		{ 72, YYAT_SHIFT, 57 },
		{ 72, YYAT_SHIFT, 58 },
		{ 72, YYAT_SHIFT, 59 },
		{ 72, YYAT_SHIFT, 60 },
		{ 72, YYAT_SHIFT, 61 },
		{ 72, YYAT_SHIFT, 62 },
		{ 72, YYAT_SHIFT, 63 },
		{ 72, YYAT_SHIFT, 64 },
		{ 87, YYAT_SHIFT, 60 },
		{ 87, YYAT_SHIFT, 61 },
		{ 87, YYAT_SHIFT, 62 },
		{ 87, YYAT_SHIFT, 63 },
		{ 87, YYAT_SHIFT, 64 },
		{ 36, YYAT_SHIFT, 81 },
		{ 72, YYAT_SHIFT, 66 },
		{ 72, YYAT_SHIFT, 67 },
		{ 86, YYAT_SHIFT, 60 },
		{ 86, YYAT_SHIFT, 61 },
		{ 86, YYAT_SHIFT, 62 },
		{ 86, YYAT_SHIFT, 63 },
		{ 86, YYAT_SHIFT, 64 },
		{ 35, YYAT_SHIFT, 80 },
		{ 114, YYAT_SHIFT, 4 },
		{ 34, YYAT_SHIFT, 79 },
		{ 114, YYAT_SHIFT, 5 },
		{ 114, YYAT_SHIFT, 6 },
		{ 114, YYAT_SHIFT, 7 },
		{ 114, YYAT_SHIFT, 8 },
		{ 114, YYAT_SHIFT, 9 },
		{ 114, YYAT_SHIFT, 10 },
		{ 114, YYAT_SHIFT, 11 },
		{ 114, YYAT_SHIFT, 12 },
		{ 110, YYAT_SHIFT, 4 },
		{ 32, YYAT_SHIFT, 10 },
		{ 110, YYAT_SHIFT, 5 },
		{ 110, YYAT_SHIFT, 6 },
		{ 110, YYAT_SHIFT, 7 },
		{ 110, YYAT_SHIFT, 8 },
		{ 110, YYAT_SHIFT, 9 },
		{ 110, YYAT_SHIFT, 10 },
		{ 110, YYAT_SHIFT, 11 },
		{ 110, YYAT_SHIFT, 12 },
		{ 1, YYAT_SHIFT, 3 },
		{ 23, YYAT_SHIFT, 68 },
		{ 21, YYAT_SHIFT, 48 },
		{ 20, YYAT_SHIFT, 47 },
		{ 114, YYAT_SHIFT, 13 },
		{ 19, YYAT_SHIFT, 46 },
		{ 6, YYAT_SHIFT, 33 },
		{ 111, YYAT_SHIFT, 75 },
		{ 111, YYAT_SHIFT, 11 },
		{ 111, YYAT_SHIFT, 12 },
		{ 114, YYAT_SHIFT, 14 },
		{ 30, YYAT_SHIFT, 3 },
		{ 114, YYAT_SHIFT, 15 },
		{ 30, YYAT_SHIFT, 70 },
		{ 110, YYAT_SHIFT, 13 },
		{ 5, YYAT_SHIFT, 32 },
		{ 4, YYAT_SHIFT, 31 },
		{ 114, YYAT_SHIFT, 16 },
		{ 114, YYAT_SHIFT, 17 },
		{ 2, YYAT_ACCEPT, 0 },
		{ 110, YYAT_SHIFT, 14 },
		{ 0, YYAT_SHIFT, 1 },
		{ 110, YYAT_SHIFT, 15 },
		{ -1, YYAT_ERROR, 0 },
		{ 111, YYAT_SHIFT, 13 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 110, YYAT_SHIFT, 16 },
		{ 110, YYAT_SHIFT, 17 },
		{ 103, YYAT_SHIFT, 4 },
		{ 111, YYAT_SHIFT, 14 },
		{ 103, YYAT_SHIFT, 5 },
		{ 103, YYAT_SHIFT, 6 },
		{ 103, YYAT_SHIFT, 7 },
		{ 103, YYAT_SHIFT, 8 },
		{ 103, YYAT_SHIFT, 9 },
		{ 103, YYAT_SHIFT, 10 },
		{ 103, YYAT_SHIFT, 11 },
		{ 103, YYAT_SHIFT, 12 },
		{ 102, YYAT_SHIFT, 4 },
		{ -1, YYAT_ERROR, 0 },
		{ 102, YYAT_SHIFT, 5 },
		{ 102, YYAT_SHIFT, 6 },
		{ 102, YYAT_SHIFT, 7 },
		{ 102, YYAT_SHIFT, 8 },
		{ 102, YYAT_SHIFT, 9 },
		{ 102, YYAT_SHIFT, 10 },
		{ 102, YYAT_SHIFT, 11 },
		{ 102, YYAT_SHIFT, 12 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 103, YYAT_SHIFT, 13 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 104, YYAT_SHIFT, 75 },
		{ 104, YYAT_SHIFT, 11 },
		{ 104, YYAT_SHIFT, 12 },
		{ 103, YYAT_SHIFT, 14 },
		{ -1, YYAT_ERROR, 0 },
		{ 103, YYAT_SHIFT, 15 },
		{ -1, YYAT_ERROR, 0 },
		{ 102, YYAT_SHIFT, 13 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 103, YYAT_SHIFT, 16 },
		{ 103, YYAT_SHIFT, 17 },
		{ -1, YYAT_ERROR, 0 },
		{ 102, YYAT_SHIFT, 14 },
		{ -1, YYAT_ERROR, 0 },
		{ 102, YYAT_SHIFT, 15 },
		{ -1, YYAT_ERROR, 0 },
		{ 104, YYAT_SHIFT, 13 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 102, YYAT_SHIFT, 16 },
		{ 102, YYAT_SHIFT, 17 },
		{ 27, YYAT_SHIFT, 4 },
		{ 104, YYAT_SHIFT, 14 },
		{ 27, YYAT_SHIFT, 5 },
		{ 27, YYAT_SHIFT, 6 },
		{ 27, YYAT_SHIFT, 7 },
		{ 27, YYAT_SHIFT, 8 },
		{ 27, YYAT_SHIFT, 9 },
		{ 27, YYAT_SHIFT, 10 },
		{ 27, YYAT_SHIFT, 11 },
		{ 27, YYAT_SHIFT, 12 },
		{ 3, YYAT_SHIFT, 4 },
		{ -1, YYAT_ERROR, 0 },
		{ 3, YYAT_SHIFT, 5 },
		{ 3, YYAT_SHIFT, 6 },
		{ 3, YYAT_SHIFT, 7 },
		{ 3, YYAT_SHIFT, 8 },
		{ 3, YYAT_SHIFT, 9 },
		{ 3, YYAT_SHIFT, 10 },
		{ 3, YYAT_SHIFT, 11 },
		{ 3, YYAT_SHIFT, 12 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 27, YYAT_SHIFT, 13 },
		{ -1, YYAT_ERROR, 0 },
		{ 81, YYAT_SHIFT, 37 },
		{ 81, YYAT_SHIFT, 11 },
		{ 81, YYAT_SHIFT, 12 },
		{ -1, YYAT_ERROR, 0 },
		{ 27, YYAT_SHIFT, 14 },
		{ -1, YYAT_ERROR, 0 },
		{ 27, YYAT_SHIFT, 15 },
		{ -1, YYAT_ERROR, 0 },
		{ 3, YYAT_SHIFT, 13 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 27, YYAT_SHIFT, 16 },
		{ 27, YYAT_SHIFT, 17 },
		{ -1, YYAT_ERROR, 0 },
		{ 3, YYAT_SHIFT, 14 },
		{ -1, YYAT_ERROR, 0 },
		{ 3, YYAT_SHIFT, 15 },
		{ 81, YYAT_SHIFT, 13 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 3, YYAT_SHIFT, 16 },
		{ 3, YYAT_SHIFT, 17 },
		{ 81, YYAT_SHIFT, 14 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 33, YYAT_SHIFT, 75 },
		{ 33, YYAT_SHIFT, 11 },
		{ 33, YYAT_SHIFT, 12 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 1, YYAT_SHIFT, 4 },
		{ -1, YYAT_ERROR, 0 },
		{ 1, YYAT_SHIFT, 5 },
		{ 1, YYAT_SHIFT, 6 },
		{ 1, YYAT_SHIFT, 7 },
		{ 1, YYAT_SHIFT, 8 },
		{ 1, YYAT_SHIFT, 9 },
		{ 1, YYAT_SHIFT, 10 },
		{ 1, YYAT_SHIFT, 11 },
		{ 1, YYAT_SHIFT, 12 },
		{ -1, YYAT_ERROR, 0 },
		{ 30, YYAT_SHIFT, 4 },
		{ 33, YYAT_SHIFT, 13 },
		{ 30, YYAT_SHIFT, 5 },
		{ 30, YYAT_SHIFT, 6 },
		{ 30, YYAT_SHIFT, 7 },
		{ 30, YYAT_SHIFT, 8 },
		{ 30, YYAT_SHIFT, 9 },
		{ 33, YYAT_SHIFT, 14 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 1, YYAT_SHIFT, 13 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 1, YYAT_SHIFT, 14 },
		{ -1, YYAT_ERROR, 0 },
		{ 1, YYAT_SHIFT, 15 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 1, YYAT_SHIFT, 16 },
		{ 1, YYAT_SHIFT, 17 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 30, YYAT_SHIFT, 15 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 30, YYAT_SHIFT, 16 },
		{ 30, YYAT_SHIFT, 17 },
		{ 41, YYAT_SHIFT, 49 },
		{ 41, YYAT_SHIFT, 50 },
		{ 41, YYAT_SHIFT, 51 },
		{ 41, YYAT_SHIFT, 52 },
		{ -1, YYAT_ERROR, 0 },
		{ 41, YYAT_SHIFT, 53 },
		{ 41, YYAT_SHIFT, 54 },
		{ 41, YYAT_SHIFT, 55 },
		{ 41, YYAT_SHIFT, 56 },
		{ 41, YYAT_SHIFT, 57 },
		{ 41, YYAT_SHIFT, 58 },
		{ 41, YYAT_SHIFT, 59 },
		{ 41, YYAT_SHIFT, 60 },
		{ 41, YYAT_SHIFT, 61 },
		{ 41, YYAT_SHIFT, 62 },
		{ 41, YYAT_SHIFT, 63 },
		{ 41, YYAT_SHIFT, 64 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 41, YYAT_SHIFT, 66 },
		{ 41, YYAT_SHIFT, 67 },
		{ 40, YYAT_SHIFT, 49 },
		{ 40, YYAT_SHIFT, 50 },
		{ 40, YYAT_SHIFT, 51 },
		{ 40, YYAT_SHIFT, 52 },
		{ -1, YYAT_ERROR, 0 },
		{ 40, YYAT_SHIFT, 53 },
		{ 40, YYAT_SHIFT, 54 },
		{ 40, YYAT_SHIFT, 55 },
		{ 40, YYAT_SHIFT, 56 },
		{ 40, YYAT_SHIFT, 57 },
		{ 40, YYAT_SHIFT, 58 },
		{ 40, YYAT_SHIFT, 59 },
		{ 40, YYAT_SHIFT, 60 },
		{ 40, YYAT_SHIFT, 61 },
		{ 40, YYAT_SHIFT, 62 },
		{ 40, YYAT_SHIFT, 63 },
		{ 40, YYAT_SHIFT, 64 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 40, YYAT_SHIFT, 66 },
		{ 40, YYAT_SHIFT, 67 },
		{ 101, YYAT_SHIFT, 49 },
		{ 101, YYAT_SHIFT, 50 },
		{ 101, YYAT_SHIFT, 51 },
		{ 101, YYAT_SHIFT, 52 },
		{ -1, YYAT_ERROR, 0 },
		{ 101, YYAT_SHIFT, 53 },
		{ 101, YYAT_SHIFT, 54 },
		{ 101, YYAT_SHIFT, 55 },
		{ 101, YYAT_SHIFT, 56 },
		{ 101, YYAT_SHIFT, 57 },
		{ 101, YYAT_SHIFT, 58 },
		{ 101, YYAT_SHIFT, 59 },
		{ 101, YYAT_SHIFT, 60 },
		{ 101, YYAT_SHIFT, 61 },
		{ 101, YYAT_SHIFT, 62 },
		{ 101, YYAT_SHIFT, 63 },
		{ 101, YYAT_SHIFT, 64 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 100, YYAT_SHIFT, 49 },
		{ 100, YYAT_SHIFT, 50 },
		{ 100, YYAT_SHIFT, 51 },
		{ 100, YYAT_SHIFT, 52 },
		{ 101, YYAT_SHIFT, 66 },
		{ 100, YYAT_SHIFT, 53 },
		{ 100, YYAT_SHIFT, 54 },
		{ 100, YYAT_SHIFT, 55 },
		{ 100, YYAT_SHIFT, 56 },
		{ 100, YYAT_SHIFT, 57 },
		{ 100, YYAT_SHIFT, 58 },
		{ 100, YYAT_SHIFT, 59 },
		{ 100, YYAT_SHIFT, 60 },
		{ 100, YYAT_SHIFT, 61 },
		{ 100, YYAT_SHIFT, 62 },
		{ 100, YYAT_SHIFT, 63 },
		{ 100, YYAT_SHIFT, 64 },
		{ 89, YYAT_SHIFT, 49 },
		{ 89, YYAT_SHIFT, 50 },
		{ 89, YYAT_SHIFT, 51 },
		{ 89, YYAT_SHIFT, 52 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 89, YYAT_SHIFT, 55 },
		{ 89, YYAT_SHIFT, 56 },
		{ 89, YYAT_SHIFT, 57 },
		{ 89, YYAT_SHIFT, 58 },
		{ 89, YYAT_SHIFT, 59 },
		{ 89, YYAT_SHIFT, 60 },
		{ 89, YYAT_SHIFT, 61 },
		{ 89, YYAT_SHIFT, 62 },
		{ 89, YYAT_SHIFT, 63 },
		{ 89, YYAT_SHIFT, 64 },
		{ 90, YYAT_SHIFT, 49 },
		{ 90, YYAT_SHIFT, 50 },
		{ 90, YYAT_SHIFT, 51 },
		{ 90, YYAT_SHIFT, 52 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 90, YYAT_SHIFT, 56 },
		{ 90, YYAT_SHIFT, 57 },
		{ 90, YYAT_SHIFT, 58 },
		{ 90, YYAT_SHIFT, 59 },
		{ 90, YYAT_SHIFT, 60 },
		{ 90, YYAT_SHIFT, 61 },
		{ 90, YYAT_SHIFT, 62 },
		{ 90, YYAT_SHIFT, 63 },
		{ 90, YYAT_SHIFT, 64 },
		{ 85, YYAT_SHIFT, 51 },
		{ 85, YYAT_SHIFT, 52 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 85, YYAT_SHIFT, 56 },
		{ 85, YYAT_SHIFT, 57 },
		{ 85, YYAT_SHIFT, 58 },
		{ 85, YYAT_SHIFT, 59 },
		{ 85, YYAT_SHIFT, 60 },
		{ 85, YYAT_SHIFT, 61 },
		{ 85, YYAT_SHIFT, 62 },
		{ 85, YYAT_SHIFT, 63 },
		{ 85, YYAT_SHIFT, 64 },
		{ 84, YYAT_SHIFT, 51 },
		{ 84, YYAT_SHIFT, 52 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 84, YYAT_SHIFT, 56 },
		{ 84, YYAT_SHIFT, 57 },
		{ 84, YYAT_SHIFT, 58 },
		{ 84, YYAT_SHIFT, 59 },
		{ 84, YYAT_SHIFT, 60 },
		{ 84, YYAT_SHIFT, 61 },
		{ 84, YYAT_SHIFT, 62 },
		{ 84, YYAT_SHIFT, 63 },
		{ 84, YYAT_SHIFT, 64 },
		{ 94, YYAT_SHIFT, 51 },
		{ 94, YYAT_SHIFT, 52 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 93, YYAT_SHIFT, 51 },
		{ 93, YYAT_SHIFT, 52 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 94, YYAT_SHIFT, 60 },
		{ 94, YYAT_SHIFT, 61 },
		{ 94, YYAT_SHIFT, 62 },
		{ 94, YYAT_SHIFT, 63 },
		{ 94, YYAT_SHIFT, 64 },
		{ 93, YYAT_SHIFT, 60 },
		{ 93, YYAT_SHIFT, 61 },
		{ 93, YYAT_SHIFT, 62 },
		{ 93, YYAT_SHIFT, 63 },
		{ 93, YYAT_SHIFT, 64 },
		{ 92, YYAT_SHIFT, 51 },
		{ 92, YYAT_SHIFT, 52 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 91, YYAT_SHIFT, 51 },
		{ 91, YYAT_SHIFT, 52 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 92, YYAT_SHIFT, 60 },
		{ 92, YYAT_SHIFT, 61 },
		{ 92, YYAT_SHIFT, 62 },
		{ 92, YYAT_SHIFT, 63 },
		{ 92, YYAT_SHIFT, 64 },
		{ 91, YYAT_SHIFT, 60 },
		{ 91, YYAT_SHIFT, 61 },
		{ 91, YYAT_SHIFT, 62 },
		{ 91, YYAT_SHIFT, 63 },
		{ 91, YYAT_SHIFT, 64 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ -81, 1, YYAT_ERROR, 0 },
		{ 32, 1, YYAT_REDUCE, 15 },
		{ 174, 1, YYAT_ERROR, 0 },
		{ -15, 1, YYAT_REDUCE, 15 },
		{ -117, 1, YYAT_ERROR, 0 },
		{ -118, 1, YYAT_ERROR, 0 },
		{ -127, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 26 },
		{ 0, 0, YYAT_REDUCE, 27 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ -263, 1, YYAT_REDUCE, 62 },
		{ 0, 0, YYAT_REDUCE, 61 },
		{ 0, 0, YYAT_REDUCE, 63 },
		{ 0, 0, YYAT_DEFAULT, 81 },
		{ 0, 0, YYAT_DEFAULT, 81 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_DEFAULT, 81 },
		{ 0, 0, YYAT_DEFAULT, 81 },
		{ 0, 0, YYAT_DEFAULT, 83 },
		{ -130, 1, YYAT_ERROR, 0 },
		{ -132, 1, YYAT_ERROR, 0 },
		{ -133, 1, YYAT_ERROR, 0 },
		{ -233, 1, YYAT_DEFAULT, 39 },
		{ -134, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ -25, 1, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 43, 1, YYAT_DEFAULT, 32 },
		{ 0, 0, YYAT_DEFAULT, 32 },
		{ -119, 1, YYAT_DEFAULT, 81 },
		{ 20, 1, YYAT_REDUCE, 18 },
		{ -151, 1, YYAT_ERROR, 0 },
		{ -152, 1, YYAT_ERROR, 0 },
		{ -142, 1, YYAT_ERROR, 0 },
		{ -259, 1, YYAT_REDUCE, 62 },
		{ 0, 0, YYAT_REDUCE, 57 },
		{ -263, 1, YYAT_ERROR, 0 },
		{ 96, 1, YYAT_REDUCE, 35 },
		{ 71, 1, YYAT_REDUCE, 36 },
		{ -165, 1, YYAT_REDUCE, 24 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ -189, 1, YYAT_REDUCE, 25 },
		{ 0, 0, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_DEFAULT, 81 },
		{ 0, 0, YYAT_DEFAULT, 81 },
		{ 0, 0, YYAT_DEFAULT, 81 },
		{ 0, 0, YYAT_DEFAULT, 81 },
		{ 0, 0, YYAT_DEFAULT, 81 },
		{ 0, 0, YYAT_DEFAULT, 81 },
		{ 0, 0, YYAT_DEFAULT, 81 },
		{ 0, 0, YYAT_DEFAULT, 81 },
		{ 0, 0, YYAT_DEFAULT, 81 },
		{ 0, 0, YYAT_DEFAULT, 81 },
		{ 0, 0, YYAT_DEFAULT, 81 },
		{ 0, 0, YYAT_DEFAULT, 81 },
		{ 0, 0, YYAT_DEFAULT, 81 },
		{ 0, 0, YYAT_DEFAULT, 81 },
		{ 0, 0, YYAT_DEFAULT, 81 },
		{ 0, 0, YYAT_DEFAULT, 81 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ 0, 0, YYAT_DEFAULT, 81 },
		{ 0, 0, YYAT_DEFAULT, 81 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ -212, 1, YYAT_ERROR, 0 },
		{ -165, 1, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ -225, 1, YYAT_ERROR, 0 },
		{ -190, 1, YYAT_REDUCE, 62 },
		{ -233, 1, YYAT_REDUCE, 17 },
		{ -209, 1, YYAT_REDUCE, 16 },
		{ -237, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 56 },
		{ 0, 0, YYAT_REDUCE, 54 },
		{ -6, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 52 },
		{ -217, 1, YYAT_ERROR, 0 },
		{ 204, 1, YYAT_REDUCE, 40 },
		{ 189, 1, YYAT_REDUCE, 39 },
		{ -152, 1, YYAT_REDUCE, 45 },
		{ -160, 1, YYAT_REDUCE, 46 },
		{ -190, 1, YYAT_REDUCE, 58 },
		{ 157, 1, YYAT_REDUCE, 59 },
		{ 174, 1, YYAT_REDUCE, 60 },
		{ 244, 1, YYAT_REDUCE, 41 },
		{ 239, 1, YYAT_REDUCE, 44 },
		{ 224, 1, YYAT_REDUCE, 42 },
		{ 219, 1, YYAT_REDUCE, 43 },
		{ -233, 1, YYAT_REDUCE, 47 },
		{ -282, 1, YYAT_REDUCE, 48 },
		{ 0, 0, YYAT_REDUCE, 49 },
		{ 0, 0, YYAT_REDUCE, 50 },
		{ 0, 0, YYAT_REDUCE, 51 },
		{ 140, 1, YYAT_REDUCE, 38 },
		{ 121, 1, YYAT_REDUCE, 37 },
		{ -64, 1, YYAT_REDUCE, 15 },
		{ -74, 1, YYAT_REDUCE, 15 },
		{ -54, 1, YYAT_REDUCE, 18 },
		{ -238, 1, YYAT_REDUCE, 34 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ -224, 1, YYAT_REDUCE, 30 },
		{ 0, 0, YYAT_REDUCE, 32 },
		{ -265, 1, YYAT_ERROR, 0 },
		{ -113, 1, YYAT_REDUCE, 15 },
		{ -103, 1, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ -285, 1, YYAT_ERROR, 0 },
		{ -123, 1, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_REDUCE, 31 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 59;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 114, 26 },
		{ 110, 112 },
		{ 114, 115 },
		{ 104, 109 },
		{ 111, 113 },
		{ 103, 108 },
		{ 111, 76 },
		{ 114, 19 },
		{ 114, 18 },
		{ 114, 29 },
		{ 114, 24 },
		{ 114, 25 },
		{ 114, 23 },
		{ 32, 74 },
		{ 114, 20 },
		{ 114, 21 },
		{ 114, 22 },
		{ 111, 77 },
		{ 83, 106 },
		{ 75, 35 },
		{ 75, 34 },
		{ 32, 73 },
		{ 18, 44 },
		{ 18, 43 },
		{ 83, 45 },
		{ 32, 72 },
		{ 3, 30 },
		{ 3, 28 },
		{ 102, 107 },
		{ 81, 105 },
		{ 67, 101 },
		{ 66, 100 },
		{ 64, 99 },
		{ 63, 98 },
		{ 62, 97 },
		{ 61, 96 },
		{ 60, 95 },
		{ 59, 94 },
		{ 58, 93 },
		{ 57, 92 },
		{ 56, 91 },
		{ 55, 90 },
		{ 54, 89 },
		{ 53, 88 },
		{ 52, 87 },
		{ 51, 86 },
		{ 50, 85 },
		{ 49, 84 },
		{ 42, 36 },
		{ 37, -1 },
		{ 33, 78 },
		{ 31, 71 },
		{ 30, 69 },
		{ 17, 41 },
		{ 16, 40 },
		{ 14, 39 },
		{ 13, 38 },
		{ 1, 27 },
		{ 0, 2 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 57, -1 },
		{ 54, 3 },
		{ 0, -1 },
		{ 23, 114 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, 75 },
		{ 0, -1 },
		{ 0, -1 },
		{ 38, -1 },
		{ 37, -1 },
		{ 0, -1 },
		{ 36, -1 },
		{ 35, -1 },
		{ 15, 83 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, 30 },
		{ 0, -1 },
		{ 0, -1 },
		{ 48, 114 },
		{ 45, 32 },
		{ 7, -1 },
		{ 45, 111 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 34, 75 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 33, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 29, -1 },
		{ 28, -1 },
		{ 27, -1 },
		{ 26, -1 },
		{ 25, -1 },
		{ 24, -1 },
		{ 23, -1 },
		{ 22, -1 },
		{ 21, -1 },
		{ 20, -1 },
		{ 19, -1 },
		{ 18, -1 },
		{ 17, -1 },
		{ 16, -1 },
		{ 15, -1 },
		{ 14, -1 },
		{ 0, -1 },
		{ 13, -1 },
		{ 12, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, 42 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 11, -1 },
		{ 0, -1 },
		{ 10, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 24, 114 },
		{ 1, 114 },
		{ -2, 111 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -3, 114 },
		{ -1, 18 },
		{ 0, -1 },
		{ 0, -1 },
		{ -2, -1 },
		{ 0, -1 }
	};
	yystategoto = stategoto;

	yydestructorptr = NULL;

	yytokendestptr = NULL;
	yytokendest_size = 0;

	yytokendestbaseptr = NULL;
	yytokendestbase_size = 0;
}
#line 394 ".\\myparser.y"


/////////////////////////////////////////////////////////////////////////////
// programs section
/*int yyerror()
{ 
  cout<<"Syntax error at line:"<<lineno<<endl;
  return 0;
}*/

int main(int argc, char *argv[])
{
	int n = 1;
	mylexer lexer;
	myparser parser;
	if (parser.yycreate(&lexer)) {
		if (lexer.yycreate(&parser)) {
			if (argc > 1)
			{
				lexer.yyin = new ifstream(argv[1]);
			}
			else
			{
				lexer.yyin = new ifstream("a.txt");
			}
			n = parser.yyparse();
		}
	}
	//printTree(savedTree);
  buildSymtab(savedTree);
  typeCheck(savedTree);
  asmMake(savedTree);
	return 0;
}
