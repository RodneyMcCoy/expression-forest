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
	chmod +x arrayTest
	./arrayTest

strTest:
	g++ $(CFLAGS) $(INCLUDES) tests/strTest.cpp lib/Dictionary/str.cpp -o strTest
	chmod +x strTest
	./strTest
	echo "WEEEE"

symTest:
	g++ $(CFLAGS) $(INCLUDES) tests/symTest.cpp lib/Dictionary/sym_table.cpp -o symTest
	chmod +x symTest
	./symTest

dictTest:
	g++ $(CFLAGS) $(INCLUDES) tests/dictTest.cpp -o dictTest
	chmod +x dictTest
	./dictTest
