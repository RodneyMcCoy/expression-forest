/* dict.h
 *
 * Rodney McCoy 
 * rbmj2001@outlook.com
 * https://github.com/RodneyMcCoy/expression-tree
 *
 * Initializes a map between symbols (strings) <-> internal id (int) <-> Type type (Type)
 * This is made more complicated then needed for O(1) lookup time complexity 
 */


#ifndef DICT_H
#define DICT_H


#include "array.h"
#include "sym_table.h"


template <typename Type>
class dict {
private:

   sym_table * syms;
   array<Type> * data;
   array<int> * removed_ids;


public:

// ----- Constructors, Destructors, and Overloaded Operators -----
   dict(unsigned int n=10) ;
   ~dict();
	dict<Type> & operator=(const dict<Type>& other);  // Assignment



// ----- Basic Operations -----
   bool insert(char * label);
   bool insert(char * label, Type val);

   bool remove(Type val);
   bool remove(unsigned int id);

   Type & lookup(char * label);
   Type & lookup(int * val);

   Type & operator[](char * label); // literaly just overloaded lookup method
   Type & operator[](int * id);



// ----- Debug and Print Methods -----
   void print() ;



};


#include "dict.cpp"


#endif