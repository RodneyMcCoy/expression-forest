/* dict.cpp
 *
 * Rodney McCoy 
 * rbmj2001@outlook.com
 * https://github.com/RodneyMcCoy/expression-tree
 *
 * Impliments a map between symbols (strings) <-> internal id (int) <-> Type type (Type)
 * This is made more complicated then needed for O(1) lookup time complexity 
 */


#include "array.h"
#include "sym_table.h"



// ----- Constructors, Destructors, and Overloaded Operators -----

template <typename Type>
dict<Type>::dict(unsigned int n=10) {
   syms = new sym_table;
   data = new array<Type>;
   removed_ids = new array<int>;
}


template <typename Type>
dict<Type>::~dict() {
   delete(syms);
   delete(data);
   delete(removed_ids);
}


template <typename Type>
dict<Type> & dict<Type>::operator=(const dict<Type> & other) {
   // stuff should be done here

}




// ----- Basic Operations -----

template <typename Type>
bool dict<Type>::insert(char * label) {
   
}


template <typename Type>
bool dict<Type>::insert(char * label, Type val) {

}


template <typename Type>
bool dict<Type>::remove(Type val) {

}


template <typename Type>
bool dict<Type>::remove(unsigned int id) {

}


template <typename Type>
Type & dict<Type>::lookup(char * label) {
   
}


template <typename Type>
Type & dict<Type>::lookup(int * val) {

}


template <typename Type>
Type & dict<Type>::operator[](char * label) {

}

template <typename Type>
Type & dict<Type>::operator[](int * id) {

}




// ----- Debug and Print Methods -----

template <typename Type>
void dict<Type>::print() {

}