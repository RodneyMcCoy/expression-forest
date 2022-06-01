all:
      g++ -std=c++17 testDict.cpp -lcppunit -o testDict

test:
      chmod +x testDict
      ./testDict

clean:
      $(RM) testDict
