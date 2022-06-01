default:
      echo "This will build the library in the future"

test:
      g++ -std=c++17 testDict.cpp -lcppunit -o testDict
      chmod +x testDict
      ./testDict
      $(RM) testDict

clean:
      $(RM) testDict
