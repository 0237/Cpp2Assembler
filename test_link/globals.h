#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <malloc.h>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

typedef enum

{	/* book-keeping tokens */
	ENDFILE, ERROR,
	/* reserved words */
	IF, ELSE, WHILE, FOR,
	/* multicharacter tokens */
	ID, NUM, CH,
	/* special symbols */
	ASSIGN, 
	EQ, NE, 
	LSH, RSH, 
	NOT, OR, XOR, AND, 
	LT, LE, GT, GE, 
	PLUS, MINUS, 
	TIMES, OVER, MOD, 
	INCRE, DECRE, 
	LPAREN, RPAREN, 
	SEMI, COMMA,
	ANDAND, OROR, NO,
	INPUT, OUTPUT
} TokenType;

/**************************************************/
/***********   Syntax tree for parsing ************/
/**************************************************/

typedef enum { StmtK, ExpK } NodeKind;
typedef enum { Maink, Typek, Declarek, IfK, ForK, WhileK, AssignK, ReadK, WriteK } StmtKind;
typedef enum { OpK, ConstK, IdK, ChK} ExpKind;

/* ExpType is used for type checking */
typedef enum { Void, Integer, Character, Float, Boolean } ExpType;

#define MAXCHILDREN 4

typedef struct treeNode
{
	struct treeNode * child[MAXCHILDREN];//孩子节点
	struct treeNode * sibling;//兄弟节点
	int lineno;//行号
	NodeKind nodekind;
	union { StmtKind stmt; ExpKind exp; } kind;
	union {
		TokenType op;
		int val;
		char* name;
	} attr;
	//string name;
	ExpType type; /* for type checking of exps */
} TreeNode;

//extern FILE* listing; /* listing output text file */
extern int lineno; /* source line number for listing */

/* Function newStmtNode creates a new statement
* node for syntax tree construction
*/
TreeNode * newStmtNode(StmtKind kind)
{
	TreeNode * t = (TreeNode *)malloc(sizeof(TreeNode));
	int i;
	if (t == NULL)
		cout << "Out of memory error at line " << lineno << endl;
	else {
		for (i = 0;i<MAXCHILDREN;i++) t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = StmtK;
		t->kind.stmt = kind;
		t->lineno = lineno;
	}
	return t;
}

/* Function newExpNode creates a new expression
* node for syntax tree construction
*/
TreeNode * newExpNode(ExpKind kind)
{
	TreeNode * t = (TreeNode *)malloc(sizeof(TreeNode));
	int i;
	if (t == NULL)
		cout << "Out of memory error at line " << lineno << endl;
	else {
		for (i = 0;i<MAXCHILDREN;i++) t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = ExpK;
		t->kind.exp = kind;
		t->lineno = lineno;
		t->type = Void;
	}
	return t;
}

/* Procedure printToken prints a token 
 * and its lexeme to the listing file
 */
void printToken( TokenType token, const char* tokenString )
{ switch (token)
  { /*case IF:
    case ELSE:
    case WHILE:
    case FOR:
    case UNTIL:
    case READ:
    case WRITE:
      fprintf(listing,
         "reserved word: %s\n",tokenString);
      break;*/
    //case ASSIGN: fprintf(listing,":=\n"); break;
	case LSH: cout << "<<"; break;
	case RSH: cout << ">>"; break;
    case LT: cout<<"<"; break;
    case LE: cout<<"<="; break;
    case GT: cout<<">"; break;
    case GE: cout<<">="; break;
    case EQ: cout<<"=="; break;
    case NE: cout<<"!="; break;
    //case LPAREN: fprintf(listing,"(\n"); break;
    //case RPAREN: fprintf(listing,")\n"); break;
    //case SEMI: fprintf(listing,";\n"); break;
    case PLUS: cout<<"+"; break;
    case MINUS: cout<<"-"; break;
    case TIMES: cout<<"*"; break;
    case OVER: cout<<"/"; break;
    case MOD: cout<<"%"; break;
    case ANDAND: cout<<"&&"; break;
    case OROR: cout<<"||"; break;
    case NO: cout<<"!"; break;
    //case ENDFILE: fprintf(listing,"EOF\n"); break;
    /*case NUM:
      fprintf(listing,
          "NUM, val= %s\n",tokenString);
      break;
    case ID:
      fprintf(listing,
          "ID, name= %s\n",tokenString);
      break;
    case ERROR:
      fprintf(listing,
          "ERROR: %s\n",tokenString);
      break;*/
    default: /* should never happen */
      cout<<"unknown:"<<token;
  }
}

void printType( ExpType type, const char* typeString )
{ switch (type)
  { case Void: cout<<"void"; break;
    case Integer: cout<<"int"; break;
    case Character: cout<<"char"; break;
    case Float: cout<<"float"; break;
    case Boolean: cout<<"bool"; break;
    default: /* should never happen */
      cout<<"unknown:"<<type;
  }
}

/* Function copyString allocates and makes a new
 * copy of an existing string
 */
char * copyString(string s)
{
  int n;
  char * t;
  n = s.length();
  t = (char*)malloc((n+1)*sizeof(char));
  if (t==NULL)cout<<"Out of memory error at line "<<lineno<<endl;
  else s.copy(t,n,0);
  return t;
}

string int2str(int i)
{
	stringstream s;
	s << i;
	return s.str();   //此处也可以用 stream>>string_temp  
}

/* Variable indentno is used by printTree to
 * store current number of spaces to indent
 */
static int indentno = 0;

/* macros to increase/decrease indentation */
#define INDENT indentno+=2
#define UNINDENT indentno-=2

/* printSpaces indents by printing spaces */
static void printSpaces(void)
{ int i;
for (i = 0;i < indentno;i++)
	cout << " ";
}

/* procedure printTree prints a syntax tree to the 
 * listing file using indentation to indicate subtrees
 */
void printTree( TreeNode * tree )
{ int i;
  INDENT;
  while (tree != NULL) {
    printSpaces();
    if (tree->nodekind==StmtK)
    { switch (tree->kind.stmt) {
		case Maink:
		  cout << "statement[main]" << endl;
		  break;
        case Typek:
          cout<<"type[";
          printType(tree->type,"\0");
          cout<<"]"<<endl;
          break;
        case Declarek:
          cout<<"statement[declare]"<<endl;
          break;
        case IfK:
          cout<<"statement[if]"<<endl;
          break;
        case ForK:
          cout<<"statement[for]"<<endl;
          break;
        case WhileK:
          cout<<"statement[while]"<<endl;
          break;
        case AssignK:
          //cout<<"assign["<< tree->attr.name <<"]"<<endl;
		  cout << "assign[=]" << endl;
          break;
        case ReadK:
          cout<<"statement[read]"<<endl;
          break;
        case WriteK:
          cout<<"statement[write]"<<endl;
          break;
        default:
          cout<<"statement[unknown]"<<endl;
          break;
      }
    }
    else if (tree->nodekind==ExpK)
    { switch (tree->kind.exp) {
        case OpK:
          cout<<"expr[";
          printToken(tree->attr.op,"\0");
          cout<<"]"<<endl;
          break;
        case ConstK:
          cout<<"num["<<tree->attr.val<<"]"<<endl;
          break;
        case IdK:
		  cout << "id[" << tree->attr.name << "]" << endl;
          break;
        default:
          cout<<"expr[unknown]"<<endl;
          break;
      }
    }
    else cout<<"unknown"<<endl;
    for (i=0;i<MAXCHILDREN;i++)
         printTree(tree->child[i]);
    tree = tree->sibling;
  }
  UNINDENT;
}

int TraceAnalyze = 0;//标记位可控制是否打印符号表，1为打印，0为不打印

int Error = 0;

/* SIZE is the size of the hash table */
#define SIZE 211

/* SHIFT is the power of two used as multiplier
in hash function  */
#define SHIFT 4

/* the hash function */
static int _hash(char * key)
{
	int temp = 0;
	int i = 0;
	while (key[i] != '\0')
	{
		temp = ((temp << SHIFT) + key[i]) % SIZE;
		++i;
	}
	return temp;
}

/* the list of line numbers of the source
* code in which a variable is referenced
*/
typedef struct LineListRec
{
	int lineno;
	struct LineListRec * next;
} *LineList;

/* The record in the bucket lists for
* each variable, including name,
* assigned memory location, and
* the list of line numbers in which
* it appears in the source code
*/
typedef struct BucketListRec
{
	char * name;
	TreeNode * node;
	//ExpType type;//符号类型
	LineList lines;
	int memloc; /* memory location for variable */
	struct BucketListRec * next;
} *BucketList;

/* the hash table */
static BucketList hashTable[SIZE];

/* Procedure st_insert inserts line numbers and
* memory locations into the symbol table
* loc = memory location is inserted only the
* first time, otherwise ignored
*/
void st_insert(char * name, int lineno, int loc, TreeNode * &node)
{
	int h = _hash(name);
	BucketList l = hashTable[h];
	while ((l != NULL) && (strcmp(name, l->name) != 0))
		l = l->next;
	if (l == NULL) /* variable not yet in table */
	{
		l = (BucketList)malloc(sizeof(struct BucketListRec));
		l->name = name;
		l->node = node;
		//l->type = type;
		l->lines = (LineList)malloc(sizeof(struct LineListRec));
		l->lines->lineno = lineno;
		l->memloc = loc;
		l->lines->next = NULL;
		l->next = hashTable[h];
		hashTable[h] = l;
	}
	else /* found in table, so just add line number */
	{
		node = l->node;
		LineList t = l->lines;
		while (t->next != NULL) t = t->next;
		t->next = (LineList)malloc(sizeof(struct LineListRec));
		t->next->lineno = lineno;
		t->next->next = NULL;
	}
} /* st_insert */

  /* Function st_lookup returns the memory
  * location of a variable or -1 if not found
  */
int st_lookup(char * name)
{
	int h = _hash(name);
	BucketList l = hashTable[h];
	while ((l != NULL) && (strcmp(name, l->name) != 0))
		l = l->next;
	if (l == NULL) return -1;
	else return l->memloc;
}

/* Procedure printSymTab prints a formatted
* listing of the symbol table contents
* to the listing file
*/
void printSymTab()
{
	int i;
	cout << "Variable Name  Location   Line Numbers" << endl;
	cout << "-------------  --------   ------------" << endl;
	for (i = 0;i<SIZE;++i)
	{
		if (hashTable[i] != NULL)
		{
			BucketList l = hashTable[i];
			while (l != NULL)
			{
				LineList t = l->lines;
				//fprintf(listing, "%-14s ", l->name);
				//fprintf(listing, "%-8d  ", l->memloc);
				cout << left << setw(15) << l->name;
				cout << left << setw(11) << l->memloc;
				while (t != NULL)
				{
					//fprintf(listing, "%4d ", t->lineno);
					cout << left << setw(2) << t->lineno;
					t = t->next;
				}
				//fprintf(listing, "\n");
				cout << endl;
				l = l->next;
			}
		}
	}
} /* printSymTab */


/* counter for variable memory locations */
static int location = 0;
bool declare = true;
bool assign = false;

/* Procedure traverse is a generic recursive(递归)
* syntax tree traversal routine(遍历):
* it applies preProc in preorder(前序) and postProc
* in postorder(后序) to tree pointed to by t
*/
static void traverse(TreeNode * t,
	void(*preProc) (TreeNode *),
	void(*postProc) (TreeNode *))
{
	declare = true;
	assign = false;
	if (t != NULL)
	{
		preProc(t);
		if(declare)
		{
			int i = 0;if(assign)i = 1;
			for (i ; i < MAXCHILDREN; i++)
				traverse(t->child[i], preProc, postProc);
		}
		postProc(t);
		traverse(t->sibling, preProc, postProc);
	}
}

/* nullProc is a do-nothing procedure to
* generate preorder-only or postorder-only
* traversals from traverse
*/
static void nullProc(TreeNode * t)
{
	if (t == NULL) return;
	else return;
}

static void typeError(TreeNode * t, char * message);

/* Procedure insertNode inserts
* identifiers stored in t into
* the symbol table
*/
static void insertNode(TreeNode * t)
{
	switch (t->nodekind)
	{
	case StmtK:
		switch (t->kind.stmt)
		{
		case AssignK:
			assign = true;
			//if (st_lookup(t->child[0]->attr.name) == -1)
			//	/* not yet in table, so treat as new definition */
			//	//typeError(t->child[0], "未定义的标识符！");
			//	typeError(t->child[0], "not defined");
			////st_insert(t->attr.name, t->lineno, location++);
			//else
			//{
			//	/* already in table, so ignore location,
			//	add line number of use only */
			//	st_insert(t->child[0]->attr.name, t->child[0]->lineno, 0, t->child[0]);

			//}
			break;
		//case ReadK:
		case Declarek:
		{
			declare = false;
			TreeNode * p = t->child[1];
			while (p != NULL)
			{
				TreeNode * q = p;
				if (p->kind.stmt == AssignK)p = p->child[0];
				p->type = t->child[0]->type;
				if (st_lookup(p->attr.name) == -1)
				{
					st_insert(p->attr.name, p->lineno, location++, p);
				}
				else
				{
					typeError(p, "duplicate definition");
				}
				p = q->sibling;
			}
			break;
		}
		default:
			break;
		}
		break;
	case ExpK:
		switch (t->kind.exp)
		{
		case IdK:
			//if (st_lookup(t->attr.name) == -1)
			//	/* not yet in table, so treat as new definition */
			//	//st_insert(t->attr.name, t->lineno, location++);
			//	//typeError(t, "未定义的标识符！");
			//	typeError(t, "not defined");
			//else
			//{
			//	/* already in table, so ignore location,
			//	add line number of use only */
			//	st_insert(t->attr.name, t->lineno, 0, t);
			//}
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

/* Function buildSymtab constructs the symbol
* table by preorder traversal of the syntax tree
*/
void buildSymtab(TreeNode * syntaxTree)
{
	traverse(syntaxTree, insertNode, nullProc);
	if (TraceAnalyze)
	{
		//fprintf(listing, "\nSymbol table:\n\n");
		cout << endl << "Symbol table:" << endl << endl;
		printSymTab();
	}
}

static void typeError(TreeNode * t, char * message)
{
	//fprintf(listing, "Type error at line %d: %s\n", t->lineno, message);
	cout << "Type error at line " << t->lineno << ": " << message << endl;
	Error = 1;
}

static void typeNote(TreeNode * t, char * message)
{
	//fprintf(listing, "Type error at line %d: %s\n", t->lineno, message);
	cout << "Note at line " << t->lineno << ": " << message << endl;
	Error = 1;
}

/* Procedure checkNode performs
* type checking at a single tree node
*/
static void checkNode(TreeNode * t)
{
	switch (t->nodekind)
	{
	case ExpK:
		switch (t->kind.exp)
		{
		case OpK:
			if (t->child[1] != NULL)
			if ((t->child[0]->type == Void) ||
				(t->child[1]->type == Void))
				typeError(t, "op Void");
			else if (t->child[0]->type != t->child[1]->type)
				typeNote(t, "change into Int");
			if ((t->attr.op == OROR) ||
				(t->attr.op == ANDAND)||
				(t->attr.op == NE) ||
				(t->attr.op == EQ) ||
				(t->attr.op == LT) ||
				(t->attr.op == GT) ||
				(t->attr.op == GE) ||
				(t->attr.op == LE))
				t->type = Boolean;
			else
				t->type = Integer;
			break;
		case ConstK:
			t->type = Integer;
			break;
		case ChK:
			t->type = Character;
			break;
		/*case IdK:
			t->type = Integer;
			break;*/
		default:
			break;
		}
		break;
	case StmtK:
		switch (t->kind.stmt)
		{
		case IfK:
		case WhileK:
			if (t->child[0]->type == Void)
				typeError(t->child[0], "if judgment Void");
			break;
		case AssignK:
			if (t->child[1]->type == Void)
				typeError(t->child[1], "assign Void");
			else if(t->child[0]->type == Character&&t->child[1]->type != Character)
				typeNote(t->child[1], "change into Char");
			else if (t->child[0]->type == Integer&&t->child[1]->type != Integer)
				typeNote(t->child[1], "change into Int");
			break;
		case Declarek:
			break;
		/*case WriteK:
			if (t->child[0]->type != Integer)
				typeError(t->child[0], "write of non-integer value");
			break;*/
		/*case ForK:
			if (t->child[1]->type == Integer)
				typeError(t->child[1], "repeat test is not Boolean");
			break;*/
		default:
			break;
		}
		break;
	default:
		break;

	}
}

/* Procedure typeCheck performs type checking
* by a postorder syntax tree traversal
*/
void typeCheck(TreeNode * syntaxTree)
{
	traverse(syntaxTree, nullProc, checkNode);
}

static void expasmMake(TreeNode * t);
static void stmasmMake(TreeNode * t);
static void idasmMake();

ofstream fout("test.asm");

static void asmMake(TreeNode * t)
{
	fout << ".486" << endl;
	fout << ".model flat, stdcall" << endl;
	fout << "option casemap :none" << endl << endl;
	fout << "	include    \\masm32\\include\\msvcrt.inc" << endl;
	fout << "	includelib \\masm32\\lib\\msvcrt.lib" << endl;
	fout << ".data" << endl;
	fout << "	typchar db '%c', 0" << endl;// 指明类型
	fout << "	typnum db '%d', 0" << endl;// 指明类型
	fout << "	output dd 0" << endl;// 输出结果
	idasmMake();
	fout << ".code" << endl;
	fout << "_start:" << endl;
	stmasmMake(t);
	//fout << "	invoke crt__getch" << endl;
	fout << "	invoke crt__exit, 0" << endl;
	fout << "end _start" << endl;
	fout.close();
}

int blockno;
int rightn = 1;

static void expasmMake(TreeNode * t)
{
	if (t == NULL)return;
	for (int i = 0; i < MAXCHILDREN; i++) 
	{//实现的自底向上的输出  因为是综合属性
		if (t->child[i] != NULL) 
		{
			expasmMake(t->child[i]);
		}
	}
	switch (t->kind.exp)
	{
	case IdK:
		fout << "	push " << t->attr.name << endl;
		break;
	case ConstK:
	case ChK:
		fout << "	push " << t->attr.val << endl;
		break;
	case OpK:
		switch (t->attr.op)
		{
		case OROR:
			fout << "	pop ecx" << endl;
			fout << "	pop eax" << endl;
			fout << "	xor edx, edx" << endl;
			fout << "	cmp eax, 0" << endl;
			fout << "	jne @" << blockno << endl;
			fout << "	cmp ecx, 0" << endl;
			fout << "	jne @" << blockno << endl;
			fout << "	jmp @" << blockno + 1 << endl;
			fout << "@" << blockno++ << ":" << endl;
			fout << "	inc edx" << endl;
			fout << "@" << blockno++ << ":" << endl;
			fout << "	push edx" << endl;
			break;
		case ANDAND:
			fout << "	pop ecx" << endl;
			fout << "	pop eax" << endl;
			fout << "	xor edx, edx" << endl;
			fout << "	cmp eax, 0" << endl;
			fout << "	je @" << blockno << endl;
			fout << "	cmp ecx, 0" << endl;
			fout << "	je @" << blockno << endl;
			fout << "	inc edx" << endl;
			fout << "@" << blockno++ << ":" << endl;
			fout << "	push edx" << endl;
			break;
		case NE:
			fout << "	pop ecx" << endl;
			fout << "	pop eax" << endl;
			fout << "	xor edx, edx" << endl;
			fout << "	cmp eax, ecx" << endl;
			fout << "	je @" << blockno << endl;
			fout << "	inc edx" << endl;
			fout << "@" << blockno++ << ":" << endl;
			fout << "	push edx" << endl;
			break;
		case EQ:
			fout << "	pop ecx" << endl;
			fout << "	pop eax" << endl;
			fout << "	xor edx, edx" << endl;
			fout << "	cmp eax, ecx" << endl;
			fout << "	jne @" << blockno << endl;
			fout << "	inc edx" << endl;
			fout << "@" << blockno++ << ":" << endl;
			fout << "	push edx" << endl;
			break;
		case LT://<
			fout << "	pop ecx" << endl;
			fout << "	pop eax" << endl;
			fout << "	xor edx, edx" << endl;
			fout << "	cmp eax, ecx" << endl;
			fout << "	jge @" << blockno << endl;
			fout << "	inc edx" << endl;
			fout << "@" << blockno++ << ":" << endl;
			fout << "	push edx" << endl;
			break;
		case GT://>
			fout << "	pop ecx" << endl;
			fout << "	pop eax" << endl;
			fout << "	xor edx, edx" << endl;
			fout << "	cmp eax, ecx" << endl;
			fout << "	jle @" << blockno << endl;
			fout << "	inc edx" << endl;
			fout << "@" << blockno++ << ":" << endl;
			fout << "	push edx" << endl;
			break;
		case GE://>=
			fout << "	pop ecx" << endl;
			fout << "	pop eax" << endl;
			fout << "	xor edx, edx" << endl;
			fout << "	cmp eax, ecx" << endl;
			fout << "	jl @" << blockno << endl;
			fout << "	inc edx" << endl;
			fout << "@" << blockno++ << ":" << endl;
			fout << "	push edx" << endl;
			break;
		case LE://<=
			fout << "	pop ecx" << endl;
			fout << "	pop eax" << endl;
			fout << "	xor edx, edx" << endl;
			fout << "	cmp eax, ecx" << endl;
			fout << "	jg @" << blockno << endl;
			fout << "	inc edx" << endl;
			fout << "@" << blockno++ << ":" << endl;
			fout << "	push edx" << endl;
			break;
		case LSH://<<
			fout << "	pop ebx" << endl;
			fout << "	pop eax" << endl;
			fout << "	mov cl, bl" << endl;
			fout << "	sal eax, cl" << endl;
			fout << "	push eax" << endl;
			break;
		case RSH://>>
			fout << "	pop ebx" << endl;
			fout << "	pop eax" << endl;
			fout << "	mov cl, bl" << endl;
			fout << "	sar eax, cl" << endl;
			fout << "	push eax" << endl;
			break;
		case PLUS:
			fout << "	pop ecx" << endl;
			fout << "	pop eax" << endl;
			fout << "	add eax, ecx" << endl;
			fout << "	push eax" << endl;
			break;
		case MINUS:
			fout << "	pop ecx" << endl;
			fout << "	pop eax" << endl;
			fout << "	sub eax, ecx" << endl;
			fout << "	push eax" << endl;
			break;
		case TIMES:
			fout << "	pop ecx" << endl;
			fout << "	pop eax" << endl;
			fout << "	imul eax, ecx" << endl;
			fout << "	push eax" << endl;
			break;
		case OVER:
			fout << "	pop ecx" << endl;
			fout << "	pop eax" << endl;
			fout << "	cdq" << endl;
			fout << "	xor edx, edx" << endl;
			fout << "	idiv ecx" << endl;
			fout << "	push eax" << endl;
			break;
		case MOD:
			fout << "	pop ecx" << endl;
			fout << "	pop eax" << endl;
			fout << "	cdq" << endl;
			fout << "	xor edx, edx" << endl;
			fout << "	idiv ecx" << endl;
			fout << "	push edx" << endl;
			break;
		case INCRE: //++i就先+1再入栈，i++就先入栈再+1
			if (rightn)
			{
				fout << "	pop eax" << endl;
				fout << "	push eax" << endl;
				fout << "	inc eax" << endl;
				fout << "	push eax" << endl;
				fout << "	pop " << t->child[0]->attr.name << endl;
			}
			else
			{
				fout << "	pop eax" << endl;
				fout << "	inc eax" << endl;
				fout << "	push eax" << endl;
				fout << "	push eax" << endl;
				fout << "	pop " << t->child[0]->attr.name << endl;
			}
			break;
		case DECRE: //--同++
			if (rightn)
			{
				fout << "	pop eax" << endl;
				fout << "	push eax" << endl;
				fout << "	dec eax" << endl;
				fout << "	push eax" << endl;
				fout << "	pop " << t->child[0]->attr.name << endl;
			}
			else
			{
				fout << "	pop eax" << endl;
				fout << "	dec eax" << endl;
				fout << "	push eax" << endl;
				fout << "	push eax" << endl;
				fout << "	pop " << t->child[0]->attr.name << endl;
			}
			break;
		case OR://|
			fout << "	pop ecx" << endl;
			fout << "	pop eax" << endl;
			fout << "	or eax, ecx" << endl;
			fout << "	push eax" << endl;
			break;
		case XOR://^
			fout << "	pop ecx" << endl;
			fout << "	pop eax" << endl;
			fout << "	xor eax, ecx" << endl;
			fout << "	push eax" << endl;
			break;
		case AND://&
			fout << "	pop ecx" << endl;
			fout << "	pop eax" << endl;
			fout << "	and eax, ecx" << endl;
			fout << "	push eax" << endl;
			break;
		default:
			break;
		}
	default:
		break;
	}
}

static void stmasmMake(TreeNode * t)
{
	if (t->nodekind == StmtK)
	{//从上到下遍历语句
		switch (t->kind.stmt)
		{
		case Maink:
		{
			stmasmMake(t->child[0]);
			break;
		}
		case Declarek:
		{
			TreeNode * p = t->child[1];
			while (p != NULL)
			{
				if (p->kind.stmt == AssignK)
				{
					expasmMake(p->child[1]);
					fout << "	pop " << p->attr.name << endl;
				}
				p = p->sibling;
			}
			break;
		}
		case IfK:
		{
			expasmMake(t->child[0]);
			if (t->child[2] == NULL)
			{
				fout << "	pop eax" << endl;
				fout << "	cmp eax, 0" << endl;
				int i = blockno;
				blockno++;
				fout << "	je @" << i << endl;
				stmasmMake(t->child[1]);
				fout << "@" << i << ":" << endl;
			}
			else
			{
				fout << "	pop eax" << endl;
				fout << "	cmp eax, 0" << endl;
				int i = blockno;
				blockno += 2;
				fout << "	je @" << i << endl;
				stmasmMake(t->child[1]);
				fout << "	jmp @" << i + 1 << endl;
				fout << "@" << i << ":" << endl;
				stmasmMake(t->child[2]);
				fout << "@" << i + 1 << ":" << endl;
				break;
			}
			break;
		}
		case ForK: 
		{
			stmasmMake(t->child[0]);
			int i = blockno;
			blockno += 2;
			fout << "@" << i << ":" << endl;
			stmasmMake(t->child[1]);
			fout << "	pop eax" << endl;
			fout << "	cmp eax, 0" << endl;
			fout << "	je @" << i+1 << endl;
			stmasmMake(t->child[3]);
			stmasmMake(t->child[2]);
			fout << "	jmp @" << i << endl;
			fout << "@" << i + 1 << ":" << endl;
			break;
		}
		case WhileK: 
		{
			int i = blockno;
			blockno += 2;
			fout << "@" << i << ":" << endl;
			stmasmMake(t->child[0]);
			fout << "	pop eax" << endl;
			fout << "	cmp eax, 0" << endl;
			fout << "	je @" << i + 1 << endl;
			stmasmMake(t->child[1]);
			fout << "	jmp @" << i << endl;
			fout << "@" << i + 1 << ":" << endl;
			break;
		}
		case AssignK:
		{
			expasmMake(t->child[1]);
			fout << "	pop " << t->attr.name << endl;
			break;
		}
		case ReadK: 
		{
			if (t->child[0]->type == Integer) 
			{//从命令行读取
				fout << "	invoke crt_scanf, addr typnum, addr " << t->child[0]->attr.name << endl;
			}
			if (t->child[0]->type == Character) 
			{
				fout << "	invoke crt_scanf, addr typchar, addr " << t->child[0]->attr.name << endl;
			}
			break;
		}
		case WriteK: 
		{
			expasmMake(t->child[0]);
			fout << "	pop output" << endl;
			if (t->child[0]->type == Integer)
			{//输出
				fout << "	invoke crt_printf, addr typnum, output" << endl;
			}
			if (t->child[0]->type == Character)
			{
				fout << "	invoke crt_printf, addr typnum, output" << endl;
			}
			break;
		}
		default:
			break;
		}
	}
	else
	{
		expasmMake(t);
	}
	if (t->sibling != NULL)
		stmasmMake(t->sibling);
}

//extern int tno;

static void idasmMake()
{// 符号声明段
	for (int i = 0;i < SIZE;i++)
	{
		//copyString("_"+tokenString);
		BucketList l = hashTable[i];
		while (l != NULL)
		{
			TreeNode * p = l->node;
			if (p->type == Character)
			{
				fout << "	" << p->attr.name << " dd 0" << endl;
			}
			if (p->type == Integer) {
				fout << "	" << p->attr.name << " dd 0" << endl;
			}
			l = l->next;
		}
		//for (int i = 0;i < tno;i++)
		//{
		//	fout << "t" << i << " db 0" << endl;
		//}
	}
	//if (st_lookup("_pi") == -1)
		//cout << "why" << endl;
}