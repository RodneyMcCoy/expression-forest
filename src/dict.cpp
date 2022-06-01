/* dict.cpp
 *
 * Rodney McCoy 
 * rbmj2001@outlook.com
 * https://github.com/RodneyMcCoy/expression-tree
 *
 * Impliments a map between symbols (strings) <-> internal id (int) <-> Type type (Type)
 * This is made more complicated then needed for O(1) lookup time complexity 
 */


#include <iostream>
#include "array.h"
#include "sym_table.h"



// ----- Constructors, Destructors, and Overloaded Operators -----

template <typename Type>
dict<Type>::dict(unsigned int n=10) {
   syms = sym_table();
   data = array<Type>();
   removed_ids = array<int>();
}


template <typename Type>
dict<Type>::~dict() {
   delete(this);
}


template <typename Type>
dict<Type> & dict<Type>::operator=(const dict<Type> & other) {
   // stuff should be done here
   this->syms = other.syms;
   this->data = other.data;
   this->removed_ids = other.removed_ids; 
   return this;
}




// ----- Basic Operations -----

template <typename Type>
bool dict<Type>::insert(char * label) {
   syms.insert(label);
   data.insert();
}


template <typename Type>
bool dict<Type>::insert(char * label, Type val) {
   syms.insert(label);
   data.insert(val);
}


template <typename Type>
bool dict<Type>::remove(Type val) {
   for(int i = 0; i < )
}


template <typename Type>
bool dict<Type>::remove(unsigned int id) {

}


template <typename Type>
bool dict<Type>::remove(char * label) {
   int id = syms.lookup(label);
   syms.remove(label);
   removed_ids.insert(id);

}



template <typename Type>
Type & dict<Type>::lookup(char * label) {
   
}


template <typename Type>
Type & dict<Type>::lookup(int * val) {

}


template <typename Type>
Type & dict<Type>::operator[](char * label) {
   return this->lookup(label);
}

template <typename Type>
Type & dict<Type>::operator[](int * id) {
   return this->lookup(label);
}




// ----- Debug and Print Methods -----

template <typename Type>
void dict<Type>::print() {
   std::cout << "syms: ";
   syms.print();
   std::cout << "\ndata: ";
   data.print();
   std::cout << "\nRemoved Ids: ";
   removed_ids.print();
}