INCLUDES=-I./lib/Dictionary -I./lib/ExpressionTree -I./lib/Parser -I./tests
CFLAGS= -Wall

default:
	echo "will be implimented in the future"

test:
	g++ $(CFLAGS) $(INCLUDES) tests/dictTest.cpp -o dictTest
	./dictTest
	
clean:
	$(RM) dictTest

dict.o:
	g++ -c dict.cpp
