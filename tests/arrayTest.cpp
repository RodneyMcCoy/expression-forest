/* arrayTest.cpp
 *
 * Rodney McCoy 
 * rbmj2001@outlook.com
 * https://github.com/RodneyMcCoy/expression-tree
 *
 * Meant to test the expression tree library.
 */

#include <iostream>
#include "array.h"

int main() {
	/* ----- Array Tests ----- */

	array<int> a_test;

	for(int i = 0; i < 150; i++) { a_test.push(i); }
	
	for(int i = 0; i < 150; i++) {
		if(a_test.lookup(i) != i) { return -1; }
	}
	
	a_test.print();
	
	for(int i = 149; i > 1; i++) {
		if(a_test.pop() != i) { return -1; }
	}
	
	a_test.print();
	
	std::cout << "test finished\n";
	
   return 0;
}
 