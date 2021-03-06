%{
#include <string.h>
#include "util.h"
#include "errormsg.h"
#include "absyn.h"
#include "y.tab.h"

int charPos=1;

int yywrap(void)
{
 charPos=1;
 return 1;
}


void adjust(void)
{
  /* printf("%s\n",yytext); */
 EM_tokPos=charPos;
 charPos+=yyleng;
}

%}

%start  COMMENT
%%
<INITIAL>"\t"       {adjust(); continue;}
<INITIAL>" "	    {adjust(); continue;}
<INITIAL>\n	        {adjust(); EM_newline(); continue;}
<INITIAL>","	    {adjust(); return COMMA;}
<INITIAL>"for"      {adjust(); return FOR;}
<INITIAL>[0-9]+	    {adjust(); yylval.ival=atoi(yytext); return INT;}
<INITIAL>"if"       {adjust(); return IF;}
<INITIAL>"then"     {adjust(); return THEN;}
<INITIAL>"else"     {adjust(); return ELSE;}
<INITIAL>"while"    {adjust(); return WHILE;}
<INITIAL>"to"       {adjust(); return TO;}
<INITIAL>"do"       {adjust(); return DO;}
<INITIAL>"let"      {adjust(); return LET;}
<INITIAL>"in"       {adjust(); return IN;}
<INITIAL>"end"      {adjust(); return END;}
<INITIAL>"of"       {adjust(); return OF;}
<INITIAL>"break"    {adjust(); return BREAK;}
<INITIAL>"nil"      {adjust(); return NIL;}
<INITIAL>"function" {adjust(); return FUNCTION;}
<INITIAL>"var"      {adjust(); return VAR;}
<INITIAL>"type"     {adjust(); return TYPE;}
<INITIAL>"\""[^\"]*"\"" {adjust(); yylval.sval=String(yytext); return STRING;}
<INITIAL>":"        {adjust(); return COLON;}
<INITIAL>";"        {adjust(); return SEMICOLON;}
<INITIAL>"("        {adjust(); return LPAREN;}
<INITIAL>")"        {adjust(); return RPAREN;}
<INITIAL>"["        {adjust(); return LBRACK;}
<INITIAL>"]"        {adjust(); return RBRACK;}
<INITIAL>"{"        {adjust(); return LBRACE;}
<INITIAL>"}"        {adjust(); return RBRACE;}
<INITIAL>"."        {adjust(); return DOT;}
<INITIAL>"+"        {adjust(); return PLUS;}
<INITIAL>"-"        {adjust(); return MINUS;}
<INITIAL>"*"        {adjust(); return TIMES;}
<INITIAL>"/"        {adjust(); return DIVIDE;}
<INITIAL>"="        {adjust(); return EQ;}
<INITIAL>"<>"       {adjust(); return NEQ;}
<INITIAL>"<="       {adjust(); return LE;}
<INITIAL>"<"        {adjust(); return LT;}
<INITIAL>">"        {adjust(); return GT;}
<INITIAL>">="       {adjust(); return GE;}
<INITIAL>"&"        {adjust(); return AND;}
<INITIAL>"|"        {adjust(); return OR;}
<INITIAL>":="       {adjust(); return ASSIGN;}
<INITIAL>"array"    {adjust(); return ARRAY;}
<INITIAL>"/*"       {adjust(); BEGIN COMMENT;}
<COMMENT>\n         {adjust(); EM_newline(); }
<COMMENT>"*/"       {adjust(); BEGIN INITIAL; continue;}
<COMMENT>"*"        {adjust(); }
<COMMENT>.          {adjust(); continue;}
<INITIAL>[a-zA-Z_][a-zA-Z0-9_]*  {adjust(); 
    yylval.idval.sval = String(yytext);
    yylval.idval.pos = EM_tokPos; return ID;}

<INITIAL>.	 {adjust(); EM_error(EM_tokPos,"illegal token: %s\n", yytext);}
