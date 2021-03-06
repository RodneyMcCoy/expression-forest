/* str.h
 *
 * Rodney McCoy 
 * rbmj2001@outlook.com
 * https://github.com/RodneyMcCoy/expression-tree
 *
 * A str class interface.
 */
 
 
#ifndef STR_H
#define STR_H

#include <iostream>
#include <string> // only for converting std::string to str class

class str {
private:

	char * buf;
	unsigned short int len;
	unsigned short int sum;
	
public:

/* ----- Constructors, Destructors, Copy Assignment ----- */
	str();
	str(const str & input);
	str(const char * input);
	str(std::string input);
	~str();
	str & operator=(const str & other);  // Copy Assignment
 
	
	
/* ----- Comparison Operators ----- */
	bool operator<(const str & other) ;
	bool operator==(const str & other) ;
	bool operator>(const str & other) ;
	bool operator!=(const str & other) ;
	bool operator>=(const str & other) ;
	bool operator<=(const str & other) ;



/* ----- Basic Operations ----- */
	char lookup(unsigned int id);
	char * to_string();
	
	void debug() { std::cout << len << " " << sum << " " << *this << "\n" ;}
	
	friend std::ostream& operator<<(std::ostream& out, const str& other);
	
	
/* ----- Accessor ----- */
	bool empty();
	
};
 
 
#endif