/* dictTest.cpp
 *
 * Rodney McCoy 
 * rbmj2001@outlook.com
 * https://github.com/RodneyMcCoy/expression-tree
 *
 * Meant to test the expression tree library.
 */

#include <iostream>
#include "sym_table.h"
#include "str.h"

const char * buf[] = 
{
	"a",  "b",  "c",  "d",  "e",  "f",  "g",  "h",  "i",  "j",  "k",  "l",  "m", 
	"n",  "o",  "p",  "q",  "r",  "s",  "t",  "u",  "v",  "w",  "x",  "y",  "z", 
	"aa", "bb", "cc", "dd", "ee", "ff", "gg", "hh", "ii", "jj", "kk", "ll", "mm", 
	"nn", "oo", "pp", "qq", "rr", "ss", "tt", "uu", "vv", "ww", "xx", "yy", "zz"
};
	


int main() {
	/* ----- Symbol Table Test ----- */
	
	sym_table s1, s2;
	
	for(int i = 0; i < 10; i++) {
		s1.insert(str(buf[i]));
	}
	
	s1.insert(str("__"));
	
	s1.print();
	std::cout << "\n";
	
	for(int i = 10; i < 26; i++) {
		s1.insert(str(buf[i]));
	}
	
	s1.print();
	std::cout << "\n";
	
	s2 = s1;
	
	s2.insert(str("abcdefg"));
	
	for(int i = 26; i < 52; i++) {
		s1.insert(str(buf[i]));
	}
	
	s1.print();
	std::cout << "\n";
	s2.print();
	std::cout << "\n";
	

	return 0;
	
}