/* test.cpp
 *
 * Rodney McCoy 
 * rbmj2001@outlook.com
 * https://github.com/RodneyMcCoy/expression-tree
 *
 * Meant to test the expression tree library.
 */

#include "vector.h"

int main() {
    vector<char *> v;
    v.add("hello");
    v.add("world");
    v.add("!");
    v.print();
    v.remove("world");
    v.print();
}
