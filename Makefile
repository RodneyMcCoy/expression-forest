default:
	echo "This will build the library in the future"

test:
	g++ -std=c++17 dictTest.cpp -lcppunit -o dictTest
	chmod +x dictTest
	./dictTest
	$(RM) dictTest

clean:
	$(RM) dictTest
