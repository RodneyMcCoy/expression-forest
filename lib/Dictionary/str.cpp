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
 
 
std::ostream& operator<<(std::ostream& out, const str& other) {
	for(int i = 0; i < other.len; i++) {
		out << other.buf[i];
	}
	return out;
}



/* ----- Constructors, Destructors, Copy Assignment ----- */

str::str() : buf(NULL), len(0), sum(0) { }


str::str(const str & input) : buf(new char[input.len]), len(input.len), sum(input.sum) {}
	
	
str::str(const char * input) : buf(NULL), len(0), sum(0) {
	// Get Length
	while(input[len] != '\0') { 
		sum += input[len];
		len++;
	}
	buf = new char[len];
	
	for(int i = 0; i < len; i++) {
		buf[i] = input[i];
	}
}


str::str(std::string input) : buf(new char[input.length()]), len(input.length()), sum(0) {
	for(int i = 0; i < len; i++) {
		sum += input[i];
		buf[i] = input[i];
	}
}


str::~str() {
	delete[] buf;
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


bool str::operator==(const str & other) {
	if (len != other.len) {return false;}
	if (sum != other.sum) {return false;}
	for(int i = 0; i < len; i++) {
		if(buf[i] != other.buf[i]) {return false;}
	}
	return true;
}


bool str::operator>(const str & other) { 
	return !(*this == other) && !(*this < other); 
}


bool str::operator!=(const str & other) { 
	return !(*this == other); 
}


bool str::operator>=(const str & other) { 
	return !(*this < other);
}


bool str::operator<=(const str & other) { 
	return (*this == other) || (*this < other); 
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




/* ----- Accessor ----- */

bool str::empty() {
	return len == 0;
}
