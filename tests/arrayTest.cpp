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

	array<int> a1;

	for(int i = 0; i < 150; i++) { a1.push(i); }
	
	for(int i = 0; i < 150; i++) {
		if(a1.lookup(i) != i) { return -1; }
	}
	
	a1.print();
	
	for(int i = 149; i >= 15; i--) {
		if(a1.pop() != i) { return -i; }
	}
	
	a1.print();


	array<int> a2 = a1;
	
	for(int i = 0; i < 15; i++) {
		if(a1.lookup(i) != a2.lookup(i)) { return -1; }
	}
	
	
	if(a1.size() == a2.size() == 15) {
		return 0;
	}	
   return -1;
}
 