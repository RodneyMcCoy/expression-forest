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

   sym_table syms;
   array<Type> data;
   array<int> removed_ids;


public:

// ----- Constructors, Destructors, and Overloaded Operators -----

   dict(unsigned int n=10) {
		syms = sym_table();
		data = array<Type>();
		removed_ids = array<int>();
	}


   ~dict() {
		delete(this);
	}
	
	
	dict<Type> & operator=(const dict<Type>& other) { // Copy Assignment
		this->syms = other.syms;
		this->data = other.data;
		this->removed_ids = other.removed_ids; 
		return this;
	}




// ----- Basic Operations -----

   bool insert(char * label) {
		syms.insert(label);
		data.insert();
		return true;
	}
	
	
   bool insert(char * label, Type val) {
		syms.insert(label);
		data.insert(val);
		return true;
	}
	

   bool remove(Type val) {
		for(int i = 0; i < data.cur_size; i++) {
		
		}
		return true;
	}
	
	
   bool remove(unsigned int id) {
		// char * label = syms.lookup(id);
		// syms.remove(label);
		removed_ids.push(id);
		return true;
	}

	
   bool remove(char * label) {
		return false;
	}


   /*Type & lookup(char * label) {
		
	}
	
	
   Type & lookup(int * id) {
		
	}
	

   Type & operator[](char * label) { // literaly just overloaded lookup method
		return this->lookup(label);
	}

	
   Type & operator[](int * id) {
		return this->lookup(id);
	}*/




// ----- Debug and Print Methods -----

   void print() {
		std::cout << "syms: ";
		syms.print();
		std::cout << "\ndata: ";
		data.print();
		std::cout << "\nRemoved Ids: ";
		removed_ids.print();
	}



};


#endif