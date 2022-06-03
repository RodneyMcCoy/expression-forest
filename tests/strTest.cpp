/* dictTest.cpp
 *
 * Rodney McCoy 
 * rbmj2001@outlook.com
 * https://github.com/RodneyMcCoy/expression-tree
 *
 * Meant to test the expression tree library.
 */

#include <iostream>
#include <string>
#include "str.h"


/*const char * buf[] = 
{
	"a",  "b",  "c",  "d",  "e",  "f",  "g",  "h",  "i",  "j",  "k",  "l",  "m", 
	"n",  "o",  "p",  "q",  "r",  "s",  "t",  "u",  "v",  "w",  "x",  "y",  "z", 
	"aa", "bb", "cc", "dd", "ee", "ff", "gg", "hh", "ii", "jj", "kk", "ll", "mm", 
	"nn", "oo", "pp", "qq", "rr", "ss", "tt", "uu", "vv", "ww", "xx", "yy", "zz"
};*/
	
int main() {
	/* ----- String Tests ----- */
	str s1, _s1;
	
	const char * ch = "hello";
	str s2(ch);
	
	std::string st("world!");
	str s3(st);
	
	
	s2.debug();
	s3.debug();
	
	if(s2 != str(ch) || s3 != str(st) ) { return -1; }	

	s1 = s2;
	_s1 = str(ch);
	
	if(s1 != _s1) { return -1; }
	
	if(s2 > s3) { return -1; }
	if(s2 >= s3) { return -1; }
	if(s3 != s3) { return -1; }
	
	
	str smallString("a");
	
	if(smallString != str("a")) {return -1;}
	
	
   return 0;
}
 