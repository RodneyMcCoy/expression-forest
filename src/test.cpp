/* test.cpp
 *
 * Rodney McCoy 
 * rbmj2001@outlook.com
 * https://github.com/RodneyMcCoy/expression-tree
 *
 * Meant to test the expression tree library.
 */

#include <iostream>
#include "dict.h"


int main() {
   array<char *> d;
   char a[] = "Hello";
   char b[] = "World";
   char c[] = "!";
   char e[] = "This";
   char f[] = "Is";
   char g[] = "Super";
   char h[] = "cool";

   d.print();

   d.insert(a);
   d.insert(b);
   d.insert(c);
   d.insert(e);
   d.insert(f);
   d.insert(g);
   d.insert(h);

   d.print();
}
