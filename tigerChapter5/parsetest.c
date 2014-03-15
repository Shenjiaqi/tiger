#include <stdio.h>
#include "util.h"
#include "errormsg.h"
#include "absyn.h"
#include "prabsyn.h"
#include "semant.h"
#include <stdlib.h>

extern int yyparse(void);
extern A_exp absyn_root;
void parse(string fname) 
{EM_reset(fname);
 if (yyparse() == 0) /* parsing worked */
   fprintf(stderr,"Parsing successful!\n");
 else fprintf(stderr,"Parsing failed\n");
}


int main(int argc, char **argv) {
 if (argc!=2) {fprintf(stderr,"usage: a.out filename\n"); exit(1);}
 parse(argv[1]);
 FILE * res = fopen( "res" , "w" );
 pr_exp( res ,  absyn_root , 0 );
 S_table vtab = S_empty();
 S_table ttab = S_empty();
// transExp( vtab, ttab, absyn_root );
 return 0;
}
