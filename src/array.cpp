/* array.cpp
 *
 * Rodney McCoy 
 * rbmj2001@outlook.com
 * https://github.com/RodneyMcCoy/expression-tree
 *
 * Template Class for (non linked list) vector type. 
 */

#include <iostream>
#include "array.h"


// ----- Constructors, Destructors, and Overloaded Operators -----

template <typename Type>
array<Type>::array(unsigned int n) {
   data = (Type *) calloc (sizeof(Type) * n);
   max_size = n;
   cur_size = 0;
}


template <typename Type>
array<Type>::~array() {
   free(data);
}


template <typename Type>
array<Type> & array<Type>::operator=(const array<Type> & other) {
   this->resize(other.max_size);
}; 




// ----- Basic Operations -----

template <typename Type>
bool array<Type>::insert(Type val) {
   if(cur_size < max_size) {
      data[cur_size] = val;
      cur_size++;
      return 0;
   } else {
      unsigned int new_max = max_size * (max_size < 100 ? 5 : 2 );
      if(this->resize(new_max) == -1) {
         return -1;
      }

      data[cur_size] = val;
      cur_size++;
      max_size = new_max;
      return 0;
   }
}


template <typename Type>
bool array<Type>::insert() {
   if(cur_size < max_size) {
      cur_size++;
      return 0;
   } else {
      unsigned int new_max = max_size * (max_size < 100 ? 5 : 2 );
      if(this->resize(new_max) == -1) {
         return -1;
      }

      cur_size++;
      max_size = new_max;
      return 0;
   }
}


template <typename Type>
bool array<Type>::remove(Type val) {
   int i = 0;
   while(i < cur_size && val != data[i]) { i++; }
   if(val == data[i]) {
      for(; i < cur_size-1; i++) {
         data[i] = data[i+1];
      }
      cur_size--;
      return 1;
   } else {
      return 0;
   }
}


template <typename Type>
Type array<Type>::lookup(int val) {
   if(val < max_size) {
      return data[val];
   }
   return data[0];
}




// ----- Other Mutators -----

template <typename Type>
bool array<Type>::resize(unsigned int new_size) {
      Type * temp = (Type *) realloc(data, sizeof(Type) * new_size );
      if(temp == NULL) {
         std::cerr << "Realloc call in array class failed\n";
         return -1;
      }
      data = temp;
      return 0;
}


template <typename Type>
bool array<Type>::shrink_to_fit() {
   return this->resize(cur_size);
}




// ----- Other Accessors -----

template <typename Type>
int array<Type>::size() {
   return cur_size;
}


template <typename Type>
int array<Type>::capacity() {
   return max_size;
}


template <typename Type>
bool array<Type>::empty() {
   return cur_size == 0;
}




// ----- Debug and Print Methods -----

template <typename Type>
void array<Type>::print() {
   for(int i = 0; i < cur_size; i++) {
      std::cout << data[i] << " ";
   }
   std::cout << "\n";
}




