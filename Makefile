all:
      echo "Hello World"

test:
      g++ -std=c++17 testDict.cpp -lcppunit -o testDict
      chmod +x testDict
      ./testDict
      $(RM) testDict

clean:
      $(RM) testDict
