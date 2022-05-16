/* vector.h
 *
 * Rodney McCoy 
 * rbmj2001@outlook.com
 * https://github.com/RodneyMcCoy/expression-tree
 *
 * Template Class for (non linked list) vector type.  Interface and Implimentation stored here.
 * Used internally in library. Implimented via inclusion model.
 * Method names should mirror std::vector method names
 * https://en.cppreference.com/w/cpp/container/vector 
 */

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template <typename Type>
class array {
private:
   Type * data;
   unsigned int cur_size;
   unsigned int max_size;
public:
// Constructors and Destructors
   array(unsigned int n=10) {
      data = (Type *) malloc (sizeof(Type) * n);
      max_size = n;
      cur_size = 0;
   }


   ~array() {
      free(data);
   }
    
   
   Type & operator[](unsigned int index) {
      return data[(index < max_size ? index : max_size)];
   }




// Basic Operations
   bool resize(unsigned int new_size) {
         Type * temp = (Type *) realloc(data, sizeof(Type) * new_size );
         if(temp == NULL) {
            std::cerr << "Realloc call in array class failed\n";
            return -1;
         }
         data = temp;
         return 0;
   }


   bool insert(Type val) {
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


   bool erase(Type val) {
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


   bool erase_index(unsigned int ind) {
      if(ind < cur_size) {
         for(int i = ind; i < cur_size-1; i++) {
            data[i] = data[i+1];
         }
         cur_size--;
         return 1;
      } else {
         return 0;
      }
   }


   bool isIn(Type val) {
      int i = 0;
      while(i < cur_size && val != data[i]) { i++; }

      return val == data[i];
   }


   void print() {
      for(int i = 0; i < cur_size; i++) {
         std::cout << data[i] << " ";
      }
      std::cout << "\n";
   }




// Iterator Methods
   bool end(unsigned int i) {
      return i >= cur_size;
   }
};


#endif
