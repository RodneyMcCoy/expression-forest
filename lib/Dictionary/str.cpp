/* str.cpp
 *
 * Rodney McCoy 
 * rbmj2001@outlook.com
 * https://github.com/RodneyMcCoy/expression-tree
 *
 * A string class
 */
 
 
#include <ostream>
#include <string>
#include "str.h"
 
 
std::ostream& operator<<(std::ostream& out, const str& other); // Converting to string for iostream



/* ----- Constructors, Destructors, Copy Assignment ----- */

str::str() {
	buf = NULL;
	len = 0;
	sum = 0;
}


str::str(const char * input) {
	// Get Length
	len = 0;
	sum = 0;
	while(input[len+1] != '\0') { 
		sum += input[len];
		len++;
	}
	buf = new char[len];
	
	for(int i = 0; i < len; i++) {
		buf[i] = input[i];
	}
}


str::str(std::string input) {
	len = input.length();
	buf = new char[len];
	for(int i = 0; i < len; i++) {
		sum += input[i];
		buf[i] = input[i];
	}
}


str::~str() {
	delete(buf);
}


str & str::operator=(const str & other) {  // Copy Assignment
	sum = other.sum;
	len = other.len;
	buf = new char[len];
	for(int i = 0; i < len; i++) {
		buf[i] = other.buf[i];
	}
	return *this;
}


	
	
/* ----- Comparison Operators ----- */

bool str::operator<(const str & other) {
	if (len < other.len) {return true;}
	if (sum < other.sum) {return true;}
	for(int i = 0; i < len; i++) {
		if(buf[i] < other.buf[i]) {return true;}
	}
	return false;
}


bool str::operator>(const str & other) {
	if (len > other.len) {return true;}
	if (sum > other.sum) {return true;}
	for(int i = 0; i < len; i++) {
		if(buf[i] > other.buf[i]) {return true;}
	}
	return false;
}


bool str::operator==(const str & other) {
	if (len != other.len) {return false;}
	if (sum != other.sum) {return false;}
	for(int i = 0; i < len; i++) {
		if(buf[i] != other.buf[i]) {return false;}
	}
	return true;
}





/* ----- Basic Operations ----- */

char str::lookup(unsigned int id) {
	return buf[id];
}


char * str::to_string() {
	char * rt = new char[len+1];
	for(int i = 0; i < len; i++) {
		rt[i] = buf[i];
	}
	rt[len] = '\0';
	return rt;
}
	