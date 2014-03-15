a.out: parsetest.o y.tab.o lex.yy.o errormsg.o util.o absyn.o symbol.o table.o prabsyn.o semant.o types.o env.o expty.o
	cc -g symbol.o parsetest.o y.tab.o lex.yy.o errormsg.o util.o absyn.o table.o prabsyn.o semant.o types.o env.o expty.o && ./a.out ../testcases/queens.tig

semant.o: semant.c
	cc -g -c semant.c

types.o: types.c
	cc -g -c types.c

table.o: table.c
	cc -g -c table.c

symbol.o: symbol.c
	cc -g -c symbol.c

absyn.o: absyn.c
	cc -g -c absyn.c

parsetest.o: parsetest.c errormsg.h util.h
	cc -g -c parsetest.c

y.tab.o: y.tab.c
	cc -g -c y.tab.c

y.tab.c: tiger.y
	yacc -dv tiger.y

y.tab.h: y.tab.c
	echo "y.tab.h was created at the same time as y.tab.c"

errormsg.o: errormsg.c errormsg.h util.h
	cc -g -c errormsg.c

lex.yy.o: lex.yy.c y.tab.h errormsg.h util.h
	cc -g -c lex.yy.c

lex.yy.c: tiger.lex
	lex tiger.lex

util.o: util.c util.h
	cc -g -c util.c

env.o: util.h env.h env.c
	cc -g -c env.c

expty.o: expty.c types.h
	cc -g -c expty.c
clean: 
	rm -f a.out util.o parsetest.o lex.yy.o errormsg.o y.tab.c y.tab.h y.tab.o symbol.o absyn.o table.o 
