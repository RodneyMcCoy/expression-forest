/* array.h
 *
 * Rodney McCoy 
 * rbmj2001@outlook.com
 * https://github.com/RodneyMcCoy/expression-tree
 *
 * Template Class for (non linked list) vector type. 
 */

#ifndef ARRAY_H
#define ARRAY_H


template <typename Type>
class array {
private:

   Type * data;
   unsigned int cur_size;
   unsigned int max_size;



public:

// ----- Constructors, Destructors, and Overloaded Operators -----
   array(unsigned int n=10) ;
   ~array();
	array & operator=(const array&);  // Copy Assignment



// ----- Basic Operations -----
   bool insert(Type val);
   bool remove(Type val);
   Type lookup(int val);



// ----- Other Mutators -----
   bool resize(unsigned int new_size);
   bool shrink_to_fit();



// ----- Other Accessors -----
   int size();
   int capacity();
   bool empty();



// ----- Debug and Print Methods -----
   void print() ;



};


#include "array.cpp" // LINKER ERRORS IF REMOVED. I think...


#endif
