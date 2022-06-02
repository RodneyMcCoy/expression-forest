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


#include <string> // only for converting std::string to str class
#include <ostream>

class str {
private:

	char * buf;
	unsigned short int len;
	unsigned short int sum;
	
public:

/* ----- Constructors, Destructors, Copy Assignment ----- */
	str();
	str(char *);
	str(std::string);
	~str();
	str & operator=(const str & other);  // Copy Assignment
	std::ostream& operator<<(std::ostream& out, const str& other); // Converting to string for iostream
 
	
	
/* ----- Comparison Operators ----- */
	bool operator<(const str & other);
	bool operator>(const str & other);
	bool operator==(const str & other);



/* ----- Basic Operations ----- */
	char lookup(unsigned int id);
	
	
};
 
 
#endif