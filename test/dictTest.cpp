/* dictTest.cpp
 *
 * Rodney McCoy 
 * rbmj2001@outlook.com
 * https://github.com/RodneyMcCoy/expression-tree
 *
 * Meant to test the expression tree library.
 */

#include <iostream>
#include "array.h"
#include "sym_table.h"
#include "dict.h"


const char * buf[] = 
{
	"a",  "b",  "c",  "d",  "e",  "f",  "g",  "h",  "i",  "j",  "k",  "l",  "m", 
	"n",  "o",  "p",  "q",  "r",  "s",  "t",  "u",  "v",  "w",  "x",  "y",  "z", 
	"aa", "bb", "cc", "dd", "ee", "ff", "gg", "hh", "ii", "jj", "kk", "ll", "mm", 
	"nn", "oo", "pp", "qq", "rr", "ss", "tt", "uu", "vv", "ww", "xx", "yy", "zz"
};
	

// Complicated unit testing is cringe. So this program returns false if any data structure has unintended values


int main() {
	
	/* ----- Dictionary Tests ----- */
	
   //dict<double> d_test;
   
   for(int i = 0; i < 52; i++) {
      // d_test.insert(buf[i], (double)i + .01);
   }

   //d_test.print();
	
   return 0;
}
 