%{
#include <stdio.h>
#include "util.h"
#include "errormsg.h"
#include "absyn.h"
#include "symbol.h"

int yylex(void); /* function prototype */

A_exp absyn_root;

void yyerror(char *s)
{
 EM_error(EM_tokPos, "%s", s);
}
%}

%locations

%union {
  int pos;
  int ival;
  string sval;
  A_var var;
  A_exp exp;
  A_expList explist;
  A_efieldList efieldlist;
  A_dec dec;
  A_ty ty;
  A_fieldList fieldList;
  S_symbol symbol;
  A_nametyList nametyList;
  A_namety namety;
  A_fundecList fundecList;
  A_decList decList;
  A_fundec fundec;
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

/* %type <exp> exp program */
%type <var> lvalue;
%type <exp> exp expr novalue func_call rec_crt seq assignment if_then if_then_else while_ for_ break_ let_ array_crt;
%type <explist> exp_list exp_list_opt seq_list seq_list_opt expseq_opt expseq;
%type <efieldlist> rec_list rec_list_opt ;
%type <decList> decs ;
%type <dec> dec vardec ;
%type <fundec> fundec ;
%type <ty> ty ;
%type <fieldList> tyfields tyfields_opt ;
%type <symbol> type_id ;
%type <nametyList> tydecs ;
%type <namety> tydec ;
%type <fundecList> fundecs ;

%%

program: exp { absyn_root = $1 ; }
;

decs: dec decs { $$ = A_DecList( $1 , $2 ) ; }
| { $$ = NULL ; }
; 

dec: tydecs { $$ = A_TypeDec( EM_tokPos , $1 ) ; }
| vardec { $$ = $1 ; }
| fundecs { $$ = A_FunctionDec( EM_tokPos , $1 ) ; }
;

fundecs: fundec fundecs { $$ = A_FundecList( $1 , $2 ) ; }
| fundec { $$ = A_FundecList( $1 , NULL ) ; }
;

tydecs: tydec tydecs { $$ = A_NametyList( $1 , $2 ) ; }
| tydec { $$ = A_NametyList( $1 , NULL ) ; }

tydec: TYPE type_id EQ ty { $$ = A_Namety( $2 , $4 ) ; }
;

ty: type_id { $$ = A_NameTy( EM_tokPos , $1 ) ; }
| LBRACE tyfields RBRACE { $$ = A_RecordTy( EM_tokPos , $2 ) ; }
| ARRAY OF type_id { $$ = A_ArrayTy( EM_tokPos , $3 ) ; }
;

tyfields: tyfields_opt { $$ = $1 ; }
| { $$ = NULL ; }
;

tyfields_opt: tyfields_opt COMMA ID COLON type_id { 
  $$ = A_FieldList( A_Field ( EM_tokPos , S_Symbol( $3 ) , $5 ) ,
	    $1 ) ; }
| ID COLON type_id { $$ = A_FieldList( A_Field ( EM_tokPos , S_Symbol( $1 ) ,
						 $3 ) ,
				       NULL ) ; }
;

vardec: VAR ID ASSIGN exp { $$ = A_VarDec( EM_tokPos , S_Symbol( $2 ) ,
					 NULL ,
					 $4 ) ; }
| VAR ID COLON type_id ASSIGN exp { $$ = A_VarDec( EM_tokPos ,
						 S_Symbol( $2 ),
						 $4,
						 $6 ) ; }
;

fundec: FUNCTION ID LPAREN tyfields RPAREN EQ exp {
  $$ = A_Fundec( EM_tokPos , S_Symbol( $2 ) , $4 , NULL , $7 ) ; }
| FUNCTION ID LPAREN tyfields RPAREN COLON type_id EQ exp {
  $$ = A_Fundec( EM_tokPos , S_Symbol( $2 ) , $4 , $7 , $9 ) ; }
;

lvalue: ID { $$ = A_SimpleVar( EM_tokPos, S_Symbol($1) ); }
| lvalue DOT ID { $$ = A_FieldVar( EM_tokPos, $1, S_Symbol($3) ); }
| ID LBRACK exp RBRACK { $$ = 
      A_SubscriptVar(EM_tokPos,
		     A_SimpleVar( EM_tokPos, S_Symbol($1) ),
		     $3); }
| lvalue LBRACK exp RBRACK { $$ = 
      A_SubscriptVar( EM_tokPos, $1, $3 ); }
;

exp: expr  { $$ = $1 ; }
;

expr: lvalue { $$ = A_VarExp( EM_tokPos , $1 ) ; }
| novalue { $$ = $1 ; }
| NIL { $$ = A_NilExp(EM_tokPos); }
| seq { $$ = $1 ; }
| INT { $$ = A_IntExp( EM_tokPos , $1 ) ; }
| STRING { $$ = A_StringExp(EM_tokPos,$1); }
| expr PLUS expr { $$ = A_OpExp( EM_tokPos , A_plusOp , $1 , $3 ) ; }
| expr MINUS expr { $$ = A_OpExp( EM_tokPos , A_minusOp , $1 , $3 ) ; }
| expr TIMES expr { $$ = A_OpExp( EM_tokPos , A_timesOp , $1 , $3 ) ; }
| expr DIVIDE expr { $$ = A_OpExp( EM_tokPos , A_divideOp , $1 , $3 ) ; }
| expr EQ expr { $$ = A_OpExp( EM_tokPos , A_eqOp , $1 , $3 ) ; }
| expr NEQ expr { $$ = A_OpExp( EM_tokPos , A_neqOp , $1 , $3 ) ; }
| expr LT expr { $$ = A_OpExp( EM_tokPos , A_ltOp , $1 , $3 ) ; }
| expr LE expr { $$ = A_OpExp( EM_tokPos , A_leOp , $1 , $3 ) ; }
| expr GT expr { $$ = A_OpExp( EM_tokPos , A_gtOp , $1 , $3 ) ; }
| expr GE expr { $$ = A_OpExp( EM_tokPos , A_geOp , $1 , $3 ) ; }
| MINUS expr %prec UMINUS { $$ = A_OpExp( EM_tokPos , A_minusOp ,
					  A_IntExp(EM_tokPos,0) ,
					  $2 ) ; }
| expr AND expr { $$ = A_IfExp( EM_tokPos , $1 , $3 ,
				A_IntExp( EM_tokPos , 0 ) ) ; }
| expr OR expr { $$ = A_IfExp( EM_tokPos , $1 ,
			       A_IntExp( EM_tokPos , 1 ) , $3 ) ; }
| paren { $$ = A_NilExp(EM_tokPos) ; }
| rec_crt { $$ = $1 ; }
| array_crt { $$ = $1 ; }
;

array_crt: ID/*array_id*/ LBRACK exp RBRACK OF exp {
  $$ = A_ArrayExp( EM_tokPos , S_Symbol( $1 ) , $3 , $6 ) ; }
;

rec_crt: ID/*type_id*/ LBRACE rec_list RBRACE {
  $$ = A_RecordExp( EM_tokPos , S_Symbol( $1 ) , $3 ) ;
}
;

rec_list: rec_list_opt { $$ = $1 ; }
| { $$ = NULL ;}
;

rec_list_opt: ID EQ exp COMMA rec_list_opt { 
  A_EfieldList(
	       A_Efield( S_Symbol( $1 ) ,$3 ) ,
	       $5 ) ; }
| ID EQ exp { $$ = A_EfieldList( A_Efield( S_Symbol( $1 ) , $3 ) ,
				 NULL ) ; }
;

paren: LPAREN exp RPAREN
;

seq: LPAREN seq_list RPAREN { $$ = A_SeqExp( EM_tokPos , $2 ) ; }
;

type_id: ID { $$ = S_Symbol( $1 ) ; }
;

novalue: func_call { $$ = $1 ; }
| LPAREN RPAREN { $$ = NULL ; }
| assignment { $$ = $1 ; }
| if_then { $$ = $1 ; }
| if_then_else { $$ = $1 ; }
| while_ { $$ = $1 ; }
| break_ { $$ = $1 ; }
| for_ { $$ = $1 ; }
| let_ { $$ = $1 ; }
;

func_call: ID LPAREN exp_list RPAREN { $$ = A_CallExp( EM_tokPos,
						       S_Symbol($1),
						       $3); }
;

exp_list: exp_list_opt { $$ = $1 ; }
| { $$ = NULL ; }
;

exp_list_opt: exp COMMA  exp_list_opt { $$ = A_ExpList( $1 , $3 ) ; }
| exp { $$ = A_ExpList( $1 , NULL ) ;}
;

assignment: lvalue ASSIGN exp { $$ = A_AssignExp( EM_tokPos , $1 , $3 ) ; }
;

if_then: IF exp THEN exp { $$ = A_IfExp( EM_tokPos , $2 , $4 , NULL ) ; }
;

if_then_else: IF exp THEN exp ELSE exp { $$ = A_IfExp ( EM_tokPos , 
							$2 , $4 , $6 ); }
;

while_: WHILE exp DO exp { $$ = A_WhileExp( EM_tokPos , $2 , $4 ) ; }
;

for_: FOR ID ASSIGN exp TO exp DO exp {
  $$ = A_ForExp( EM_tokPos ,
		 S_Symbol( $2 ) ,
		 $4 ,
		 $6 ,
		 $8 ) ; }
;

break_: BREAK { $$ = A_BreakExp ( EM_tokPos ) ; }
;

let_: LET decs IN expseq END { $$ = A_LetExp( EM_tokPos , $2 , $4 ) ; }
;

seq_list: exp SEMICOLON seq_list_opt { $$ = A_ExpList( $1 , $3 ) ; }
;

seq_list_opt: exp SEMICOLON seq_list_opt { $$ = A_ExpList( $1 , $3 ) ; }
| exp { $$ = A_ExpList( $1 , NULL ) ; }
;

expseq: expseq_opt { $$ = $1 ; }
| { $$ = NULL ; }
;

expseq_opt: exp SEMICOLON expseq_opt { $$ = A_ExpList( $1 , $3 ) ; }
| exp { $$ = A_ExpList( $1 , NULL ) ; }
;
