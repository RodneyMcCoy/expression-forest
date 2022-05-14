/* dict.h
 *
 * Rodney McCoy 
 * rbmj2001@outlook.com
 * https://github.com/RodneyMcCoy/expression-tree
 *
 * Interface for a class that maps strings to integers and vice versa.
 */

#ifndef DICT_H
#define DICT_H


class dict {
private:
	// This is an AVL tree
	typedef struct node {
		char * label;
		unsigned short int id;
		node * left;
		node * right;
	}
	node * root=NULL;
	int next_id;
	
	void ** vals=NULL;
	int length;

public:
// Constructors, Destructors, and Overloaded Operators
	dict();
	~dict();
	dict operator=(const dict&);  // assignment (=), copys one dictionary to another

	bool insert(char * label);
	bool remove(char * label);
  
	void * lookup(char * label);
	void * lookup(int id);
	
	bool inDict(char * label);
	bool inDict(int id);
	
	void printSymbols();
};


#endif
