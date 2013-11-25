%{
#include <string.h>
#include "util.h"
#include "tokens.h"
#include "errormsg.h"

int charPos=1;

int yywrap(void)
{
 charPos=1;
 return 1;
}


void adjust(void)
{
 EM_tokPos=charPos;
 charPos+=yyleng;
}

%}

%start  COMMENT
%%
"\t"       {adjust(); continue;}
" "	   {adjust(); continue;}
\n	   {adjust(); EM_newline(); continue;}
","	   {adjust(); return COMMA;}
"for"  	   {adjust(); return FOR;}
[0-9]+	   {adjust(); yylval.ival=atoi(yytext); return INT;}
"if"       {adjust(); return IF;}
"then"     {adjust(); return THEN;}
"else"     {adjust(); return ELSE;}
"while"    {adjust(); return WHILE;}
"to"       {adjust(); return TO;}
"do"       {adjust(); return DO;}
"let"      {adjust(); return LET;}
"in"       {adjust(); return IN;}
"end"      {adjust(); return END;}
"of"       {adjust(); return OF;}
"break"    {adjust(); return BREAK;}
"nil"      {adjust(); return NIL;}
"function" {adjust(); return FUNCTION;}
"var"      {adjust(); return VAR;}
"type"     {adjust(); return TYPE;}
"\""[^\"]*"\"" {adjust(); yylval.sval=String(yytext); return STRING;}
":"        {adjust(); return COLON;}
";"        {adjust(); return SEMICOLON;}
"("        {adjust(); return LPAREN;}
")"        {adjust(); return RPAREN;}
"["        {adjust(); return LBRACK;}
"]"        {adjust(); return RBRACK;}
"{"        {adjust(); return LBRACE;}
"}"        {adjust(); return RBRACE;}
"."        {adjust(); return DOT;}
"+"        {adjust(); return PLUS;}
"-"        {adjust(); return MINUS;}
"*"        {adjust(); return TIMES;}
"/"        {adjust(); return DIVIDE;}
"="        {adjust(); return EQ;}
"<>"       {adjust(); return NEQ;}
"<"        {adjust(); return LT;}
"<="       {adjust(); return LE;}
">"        {adjust(); return GT;}
">="       {adjust(); return GE;}
"&"        {adjust(); return AND;}
"|"        {adjust(); return OR;}
":="       {adjust(); return ASSIGN;}
"array"    {adjust(); return ARRAY;}
"int"      {adjust(); return R_INT;}
"string"   {adjust(); return R_STRING;}
"/*"       {adjust(); BEGIN COMMENT;}
<COMMENT>"*/" {adjust(); BEGIN INITIAL;}
<COMMENT>. {adjust();}
[a-z][a-zA-Z0-9_]* {adjust(); yylval.sval=String(yytext); return ID;}

.	 {adjust(); EM_error(EM_tokPos,"illegal token");}

