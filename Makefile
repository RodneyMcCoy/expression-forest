INCLUDES= -I./lib/Dictionary -I./lib/ExpressionTree -I./lib/Parser -I./tests
CFLAGS= -Wall

default:
	echo "will be implimented in the future"
	
clean:
	$(RM) arrayTest
	$(RM) strTest
	$(RM) symTest
	$(RM) dictTest


# ----- TESTS ------
arrayTest:
	g++ $(CFLAGS) $(INCLUDES) tests/arrayTest.cpp -o arrayTest
	./arrayTest
	
strTest:
	g++ $(CFLAGS) $(INCLUDES) tests/strTest.cpp lib/Dictionary/str.cpp -o strTest
	./strTest

symTest:
	g++ $(CFLAGS) $(INCLUDES) tests/symTest.cpp lib/Dictionary/sym_table.cpp -o symTest
	./symTest

dictTest:
	g++ $(CFLAGS) $(INCLUDES) tests/dictTest.cpp -o dictTest
	./dictTest