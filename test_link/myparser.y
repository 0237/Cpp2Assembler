%{
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
%}

// parser name
%name myparser

// attribute type
%include {
#ifndef YYSTYPE
#define YYSTYPE TreeNode *//定义为节点类型
#endif
}

// place any declarations here
%token MAIN
%token IF ELSE WHILE FOR
%token INT CHAR FLOAT
%token ID NUM CH
%token ASSIGN 
%token _EQ _NE 
%token _LSH _RSH 
%token _NOT _OR _XOR _AND 
%token _LT _LE _GT _GE 
%token _PLUS _MINUS 
%token _TIMES _OVER _MOD 
%token _INCRE _DECRE 
%token LPAREN RPAREN 
%token SEMI COMMA
%token _ANDAND _OROR _NO
%token INPUT OUTPUT
%token ERROR 

%left _OROR
%left _ANDAND
%left _OR//|
%left _XOR//^
%left _AND//&
%left _EQ _NE
%left _LE _LT _GE _GT
%left _LSH _RSH
%left _PLUS _MINUS
%left _TIMES _OVER _MOD
%right _NOT _NO//~ !
%left _INCRE _DECRE // ++ --
%right LPAREN
%left RPAREN
%%

// place your YACC rules here (there must be at least one)

//Grammar

program     : MAIN stmt_seq
                 { savedTree = newStmtNode(Maink);
				           savedTree->child[0] = $2;
				         } 
            ;
block       : '{' stmt_seq '}'  { $$ = $2; }
            ;
stmt_seq    : stmt_seq stmt
                { YYSTYPE t = $1;
                  if (t != NULL)
                  { while (t->sibling != NULL)
                      t = t->sibling;
                    t->sibling = $2;
                    $$ = $1; }
                  else $$ = $2;
                }
            | stmt  { $$ = $1; }
            ;
stmt        : for_stmt			{ $$ = $1; }
            | if_stmt			{ $$ = $1; }
            | while_stmt		{ $$ = $1; }
            | assign_stmt SEMI  { $$ = $1; }
            | declare_stmt SEMI	{ $$ = $1; }
            | read_stmt SEMI  { $$ = $1; }
            | write_stmt SEMI { $$ = $1; }
            | exp SEMI			{ $$ = $1; }
            | block				{ $$ = $1; }
            | SEMI				{ $$ = NULL; }
            |					{ $$ = NULL; }
            ;
for_expr    : exp				{ $$ = $1; }
            | list				{ $$ = $1; }
            |					{ $$ = NULL; }
            ;
iw_expr     : exp				{ $$ = $1; }
            | assign_stmt		{ $$ = $1; }
            ;
list        : list COMMA id_stmt
                { YYSTYPE t = $1;
                  if (t != NULL)
                  { while (t->sibling != NULL)
                      t = t->sibling;
                    t->sibling = $3;
                    $$ = $1; }
                  else $$ = $3;
				        } 
            | id_stmt  { $$ = $1; }
            ;
id_stmt     : assign_stmt	{ $$ = $1; }
            | ID {  $$ = newExpNode(IdK);
                    $$->attr.name = copyString("_"+tokenString);
                    if (st_lookup($$->attr.name) == -1)
                    {
                      st_insert($$->attr.name, $$->lineno, location++, $$);
                    }
                    else
                    {
                      typeError($$, "duplicate definition");
                    }
                 }
            ;
declare_stmt: type_stmt list
                {  
                   $$ = newStmtNode(Declarek);
                   $$->child[0] = $1;
                   $$->child[1] = $2;
                }
            ;
type_stmt   : INT   { $$ = newStmtNode(Typek);
                    $$->type = Integer; }
            | CHAR	{ $$ = newStmtNode(Typek);
                    $$->type = Character; }
            | FLOAT	{ $$ = newStmtNode(Typek);
                    $$->type = Float; }
            ;		
if_stmt     : IF LPAREN iw_expr RPAREN stmt ELSE stmt
                 { $$ = newStmtNode(IfK);
                   $$->child[0] = $3;
                   $$->child[1] = $5;
                   $$->child[2] = $7;
                 }
            | IF LPAREN iw_expr RPAREN stmt
                 { $$ = newStmtNode(IfK);
                   $$->child[0] = $3;
                   $$->child[1] = $5;
                 }
            ;
for_stmt    : FOR LPAREN for_expr SEMI for_expr SEMI for_expr RPAREN stmt
                 { $$ = newStmtNode(ForK);
                   $$->child[0] = $3;
                   $$->child[1] = $5;
                   $$->child[2] = $7;
                   $$->child[3] = $9;
                 }
            ;
while_stmt	: WHILE LPAREN iw_expr RPAREN stmt
                 { $$ = newStmtNode(WhileK);
                   $$->child[0] = $3;
                   $$->child[1] = $5;
                 }
            ;
assign_stmt : ID { savedName = copyString("_"+tokenString);
                   savedLineNo = lineno; 
                   }
              ASSIGN exp
                 { YYSTYPE t = newExpNode(IdK);
                   t->attr.name = savedName;
                    if (st_lookup(t->attr.name) == -1)
                      typeError(t, "not defined");
                    else
                    {
                      st_insert(t->attr.name, t->lineno, 0, t);
                    }
                   $$ = newStmtNode(AssignK);
                   $$->child[0] = t;
                   $$->child[1] = $4;
                   $$->attr.name = savedName;
                   $$->lineno = savedLineNo;
                 }
            ;
read_stmt   : INPUT exp
                 { $$ = newStmtNode(ReadK);
                   $$->child[0] = $2;
                 }
            ;
write_stmt  : OUTPUT exp
                 { $$ = newStmtNode(WriteK);
                   $$->child[0] = $2;
                 }
            ;
exp         : exp _OROR exp 
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = OROR;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 }
            | exp _ANDAND exp 
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = ANDAND;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 }
            | exp _NE exp 
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = NE;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 }
            | exp _EQ exp
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = EQ;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 }
            | exp _LT exp 
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = LT;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 }
            | exp _GT exp
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = GT;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 }
            | exp _GE exp 
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = GE;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 }
            | exp _LE exp
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = LE;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 }
            | exp _LSH exp 
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = LSH;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 }
            | exp _RSH exp
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = RSH;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 } 
            | exp _PLUS exp 
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = PLUS;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 }
            | exp _MINUS exp
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = MINUS;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 } 
            | exp _TIMES exp 
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = TIMES;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 }
            | exp _OVER exp
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = OVER;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 }
            | exp _MOD exp
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = MOD;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 }
            | LPAREN exp RPAREN
                 { $$ = $2; }
            | ID { savedName = copyString("_"+tokenString);
                   savedLineNo = lineno; 
                   }
              _INCRE
                 { YYSTYPE t = newExpNode(IdK);
                   t->attr.name = savedName;
                    if (st_lookup(t->attr.name) == -1)
                      typeError(t, "not defined");
                    else
                    {
                      st_insert(t->attr.name, t->lineno, 0, t);
                    }
                   $$=newExpNode(OpK);
                   $$->child[0]=t;
                   $$->attr.op=INCRE;
                   $$->type=Integer;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 }
            | ID { savedName = copyString("_"+tokenString);
                   savedLineNo = lineno; 
                   }
              _DECRE
                 { YYSTYPE t = newExpNode(IdK);
                   t->attr.name = savedName;
                    if (st_lookup(t->attr.name) == -1)
                      typeError(t, "not defined");
                    else
                    {
                      st_insert(t->attr.name, t->lineno, 0, t);
                    }
                   $$=newExpNode(OpK);
                   $$->child[0]=t;
                   $$->attr.op=DECRE;
                   $$->type=Integer;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 }
            | _MINUS exp %prec _NOT//这里是负数与！同等优先级
                 { $$ = newExpNode(OpK);
                   $$->child[0]=newExpNode(ConstK);
                   $$->child[0]->attr.val=0;
                   $$->child[1]=$2;
                   $$->attr.op=MINUS;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 }
            | exp _OR exp //| WOR
                 { $$=newExpNode(OpK);
                   $$->child[0]=$1;
                   $$->child[1]=$3;
                   $$->attr.op=OR;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 }
            | exp _XOR exp //^ NOR
                 { $$=newExpNode(OpK);
                   $$->child[0]=$1;
                   $$->child[1]=$3;
                   $$->attr.op=XOR;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 }
            | exp _AND exp //& WAND
                 { $$=newExpNode(OpK);
                   $$->child[0]=$1;
                   $$->child[1]=$3;
                   $$->attr.op=AND;
                   //$$->attr.name = copyString(t+int2str(tno++));
                 }
            | NUM
                 { $$ = newExpNode(ConstK);
                   $$->attr.val = atoi(tokenString.c_str());
                 }
            | ID { $$ = newExpNode(IdK);
                   $$->attr.name = copyString("_"+tokenString);
                   if (st_lookup($$->attr.name) == -1)
                      typeError($$, "not defined");
                    else
                    {
                      st_insert($$->attr.name, $$->lineno, 0, $$);
                    }
                 }
            | CH { $$ = newExpNode(ChK);
                   $$->attr.val = tokenString[1];
                 }
            ;

%%

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