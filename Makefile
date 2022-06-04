INCLUDES= -I./lib/Dictionary -I./lib/ExpressionTree -I./lib/Parser -I./test
CFLAGS= -Wall -O3


build:
	echo "Build Command Ran. No behavior here yet"

build_parser:
	echo "Build Parser Command Ran. No behavior here yet"






calc: lex.yy.c y.tab.c y.tab.h 
	g++ lex.yy.c y.tab.c y.tab.h  -ly -o calc

clean:
	rm lex.yy.c y.tab.c y.tab.h  calc

y.tab.c y.tab.h : calc.y sym.h
	yacc -d calc.y

lex.yy.c: calc.l y.tab.c y.tab.h  sym.h
	lex calc.l
