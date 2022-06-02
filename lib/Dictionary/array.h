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
		data = (Type *) malloc (sizeof(Type) * n);
		max_size = n;
		cur_size = 0;
	}
	
	
   ~array() {
		free(data);
	}
	
	
	array & operator=(const array & other) { // COPY ASSIGNMENT
		this->resize(other.max_size);
		for(int i = 0; i < other.cur_size; i++) {
			this->data[i] = other.data[i];
		}
		this->cur_size = other.cur_size;
		return *this;
	}




// ----- Basic Operations -----

   bool insert(Type val) {
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


   bool insert() {
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
	
	
   bool remove(Type val) {
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
	
	
   Type lookup(int val) {
		if(val < max_size) {
			return data[val];
		}
		return data[0];
	}
   



// ----- Other Mutators -----

   bool resize(unsigned int new_size) {
		Type * temp = (Type *) realloc(data, sizeof(Type) * new_size );
		if(temp == NULL) {
			std::cerr << "Realloc call in array class failed\n";
			return false;
		}
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