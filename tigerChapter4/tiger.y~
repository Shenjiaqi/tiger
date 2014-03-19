%{
#include <stdio.h>
#include "util.h"
#include "errormsg.h"

int yylex(void); /* function prototype */

void yyerror(char *s)
{
 EM_error(EM_tokPos, "%s", s);
}
%}


%union {
	int pos;
	int ival;
	string sval;
	}

%token <sval> ID STRING
%token <ival> INT

%token 
  COMMA COLON SEMICOLON LPAREN RPAREN LBRACK RBRACK 
  LBRACE RBRACE DOT 
  PLUS MINUS TIMES DIVIDE EQ NEQ LT LE GT GE
  AND OR ASSIGN
  ARRAY IF THEN ELSE WHILE FOR TO DO LET IN END OF 
  BREAK NIL
  FUNCTION VAR TYPE 
  UMINUS

%start program

%nonassoc ASSIGN
%left OR
%left AND
%nonassoc EQ NEQ LT LE GT GE
%left PLUS MINUS
%left TIMES DIVIDE
%left UMINUS

%%

program: exp
;

decs: decs dec |
; 

dec: tydec |
vardec |
fundec
;

tydec: TYPE type_id EQ ty

ty: type_id |
LBRACE tyfields RBRACE |
ARRAY OF type_id
;

tyfields: tyfields_opt |

;

tyfields_opt: tyfields_opt COMMA ID COLON type_id |
ID COLON type_id
;

vardec: VAR ID ASSIGN exp |
VAR ID COLON type_id ASSIGN exp
;

fundec: FUNCTION ID LPAREN tyfields RPAREN EQ exp |
FUNCTION ID LPAREN tyfields RPAREN COLON type_id EQ exp;

lvalue: ID |
lvalue DOT ID |
ID LBRACK exp RBRACK |
lvalue LBRACK exp RBRACK
;

exp: expr 
;
expr: lvalue |
novalue |
NIL|
seq|
INT|
STRING|
expr PLUS expr|
expr MINUS expr|
expr TIMES expr|
expr DIVIDE expr|
expr EQ expr|
expr NEQ expr|
expr LT expr|
expr LE expr|
expr GT expr|
expr GE expr|
expr AND expr|
expr OR expr|
paren|
rec_crt|
array_crt|
MINUS expr %prec UMINUS
;

array_crt: ID/*array_id*/ LBRACK exp RBRACK OF exp
;

rec_crt: ID/*type_id*/ LBRACE rec_list RBRACE
;

rec_list: rec_list_opt |

;

rec_list_opt: rec_list_opt COMMA ID EQ exp |
ID EQ exp
;

paren: LPAREN exp RPAREN
;

seq: LPAREN seq_list RPAREN
;

type_id: ID
;

novalue: func_call |
LPAREN RPAREN |
assignment |
if_then |
if_then_else |
while_ |
break_ |
for_ |
let_
;

func_call: ID LPAREN exp_list RPAREN //{printf("fc %s\n",$1);};
;

exp_list: exp_list_opt |

;

exp_list_opt: exp_list_opt COMMA exp |
exp
;

assignment: lvalue ASSIGN exp
;

if_then: IF exp THEN exp
;

if_then_else: IF exp THEN exp ELSE exp
;

while_: WHILE exp DO exp
;

for_: FOR ID ASSIGN exp TO exp DO exp
;

break_: BREAK
;

let_: LET decs IN expseq END
;

seq_list: seq_list_opt exp
;

seq_list_opt: seq_list_opt exp SEMICOLON|
exp SEMICOLON
;

expseq: expseq_opt|

;

expseq_opt: expseq_opt SEMICOLON exp |
exp
;
