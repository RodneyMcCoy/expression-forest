INCLUDES=-I./lib/Dictionary -I./lib/ExpressionTree -I./lib/Parser -I./tests
CFLAGS= -Wall

default:
	echo "will be implimented in the future"

test:
	g++ $(CFLAGS) $(INCLUDES) tests/dictTest.cpp lib/Dictionary/sym_table.cpp -o dictTest
	./dictTest > results.txt
	diff -s tests/dictTestResults.txt results.txt
	
clean:
	$(RM) dictTest

dict.o:
	g++ -c dict.cpp
