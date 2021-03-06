/* array.h
 *
 * Rodney McCoy 
 * rbmj2001@outlook.com
 * https://github.com/RodneyMcCoy/expression-tree
 *
 * Template Class for sequential array type. 
 * Implimenting with Inclusion Model. 
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

// ----- Constructors, Destructors, and Overloaded Operators -----
 
	array(unsigned int n=10) {
		data = new Type[n];
		max_size = n;
		cur_size = 0;
	}
	
	
   ~array() {
		delete[] data;
	}
	
	
	array & operator=(const array & other) { // COPY ASSIGNMENT
		this->resize(other.max_size);
		for(unsigned int i = 0; i < other.cur_size; i++) {
			data[i] = other.data[i];
		}
		cur_size = other.cur_size;
		return *this;
	}




// ----- Basic Operations -----

   bool push(Type val) {
		if(cur_size < max_size) {
			data[cur_size] = val;
			cur_size++;
			return true;
		} else {
			unsigned int new_max = max_size * (max_size < 100 ? 5 : 2 );
			if(!this->resize(new_max)) {
				return false;
			}

			data[cur_size] = val;
			cur_size++;
			max_size = new_max;
			return true;
		}
	}


   bool push() {
		if(cur_size < max_size) {
			cur_size++;
			return true;
		} else {
			unsigned int new_max = max_size * (max_size < 100 ? 5 : 2 );
			if(!this->resize(new_max)) {
				return false;
			}

			cur_size++;
			max_size = new_max;
			return true;
		}
	}
	
	
   Type pop() {
		cur_size--;
		return data[cur_size];
	}
	
	
   Type lookup(unsigned int val) {
		if(val < cur_size) {
			return data[val];
		}
		return data[0];
	}
   



// ----- Other Mutators -----

   bool resize(unsigned int new_size) {
		Type * temp = new Type[new_size];
		for(unsigned int i = 0; i < cur_size; i++) {
			temp[i] = data[i];
		}
		delete[] data;
		data = temp;
		return true;
	}


   bool shrink_to_fit() {
		return this->resize(cur_size);
	}




// ----- Other Accessors -----

   int size() {
		return cur_size;
	}
	
	
   int capacity() {
		return max_size;
	}
	
	
   bool empty() {
		return cur_size == 0;
	}
	



// ----- Debug and Print Methods -----

   void print() {
		for(unsigned int i = 0; i < cur_size; i++) {
			std::cout << data[i] << " ";
		}
		std::cout << "\n";
	}



};



#endif