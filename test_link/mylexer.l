%{
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
%}

newline			\n
delim			[" "\n\t]
whitespace		{delim}+
digit			[0-9]
number			{digit}+(\.{digit}+)?(E[+-]?{digit}+)?
letter			[A-Za-z_]
identifier		({letter})({letter}|{digit})*
operator		\+|\-|\*|\/|:=|\>=|\<=|#|=
delimiter		[,\.;]
note1 			\/\/[^\n]*
note2 			\/\*([^*/]|[*]*[^*/]+[/]*)*\*\/
character		"'"."'"

// lexical analyser name
%name mylexer

%%

"main()"		{return MAIN;}
"{"				{return '{';}
"}"				{return '}';}
"if"            {return IF;}
"else"          {return ELSE;}
"while"			{return WHILE;}
"for"			{return FOR;}
"int"           {return INT;}
"char"			{return CHAR;}
"float"			{return FLOAT;}
"cin>>"			{return INPUT;}
"cout<<"		{return OUTPUT;}
"="				{return ASSIGN;}
"=="            {return _EQ;}
"!="			{return _NE;}
"<<"			{return _LSH;}
">>"			{return _RSH;}
"||"			{return _OROR;}
"&&"			{return _ANDAND;}
"!"				{return _NO;}
"<"             {return _LT;}
">"				{return _GT;}
">="			{return _GE;}
"<="			{return _LE;}
"+"             {return _PLUS;}
"-"             {return _MINUS;}
"*"             {return _TIMES;}
"/"             {return _OVER;}
"%"				{return _MOD;}
"++"			{return _INCRE;}
"--"			{return _DECRE;}
"&"				{return _AND;}
"|"				{return _OR;}
"^"				{return _XOR;}
"~"				{return _NOT;}
"("             {return LPAREN;}
")"             {return RPAREN;}
";"             {return SEMI;}
","				{return COMMA;}
{character}		{tokenString=yytext;return CH;}
{number}        {tokenString=yytext;return NUM;}
{identifier}    {tokenString=yytext;return ID;}
{newline}       {lineno++;}
{note1}			{}
{note2}			{}
{whitespace}    {/* skip whitespace */}               
.				{return ERROR;}

%%

/////////////////////////////////////////////////////////////////////////////
// programs section
