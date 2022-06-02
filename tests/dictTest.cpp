/* dictTest.cpp
 *
 * Rodney McCoy 
 * rbmj2001@outlook.com
 * https://github.com/RodneyMcCoy/expression-tree
 *
 * Meant to test the expression tree library.
 */

#include <iostream>
// #include "dict.h"
#include "array.h"


int main() {
   array<double> d;
   
   //char buffer[2];
   //buffer[1] = '\0';

   double i;
   for(i = 97; i < 97+26; i++) {
      //buffer[0] = (char)i;
      //d.insert(buffer, i/2);
		d.insert(i/2);
   }

   d.print();
   return 0;
}
 