/* dict.h
 *
 * Rodney McCoy 
 * rbmj2001@outlook.com
 * https://github.com/RodneyMcCoy/expression-tree
 *
 * Template class interface that defines a bijection between strings <-> internal id <-> entry type. 
 * Implimented using explicit instantiation model
 */


#ifndef DICT_H
#define DICT_H


#include "expr.h"
#include "array.h"



template <typename Data>
class dict {
// ----- AVL TREE: CONVERTS STRING <-> INT -----
private:
	typedef struct node {
		char * label;
		unsigned short int id;
		node * left;
		node * right;
	} node;
	node * root;
	int next_id;

	
// ----- DATA: CONVERTS INT <-> ENTRY -----
public:
   typedef struct entry {
      Data data;
      unsigned char flag;
   } entry;


private:
	array<entry> entries;


// ----- METHODS -----
public:
// Constructors, Destructors, and Overloaded Operators
	dict();
	~dict();
	dict operator=(const dict&);  // assignment (=), copys one dictionary to another

	bool insert(char * label, unsigned char flag=0);
	bool remove(char * label);
  
	entry & lookup(char * label);
	entry & lookup(int id);
	
	bool inDict(char * label);
	bool inDict(int id);
	
	void printSymbols();
};


#endif
