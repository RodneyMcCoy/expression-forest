default:
	echo "This will build the library in the future"

test:
	g++ -std=c++17 tests/dictTest.cpp src/dict.cpp -o dictTest
	chmod +x dictTest
	./dictTest
	$(RM) dictTest

clean:
	$(RM) dictTest
