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

typedef struct entry {
	union value {
		long double val;
		long double (*unary_op)(long double);
		long double (*binary_op)(long double, long double);
		typedef struct expr_ref {
			expr * f;
			vector<char *> * refs;
		}
	};
	
	enum flag : unsigned char {
		val,
		unary_op,
		binary_op,
		expr_ref,
	};
};

class dict {
private:
	// This is an AVL tree: converts label (string) to id (int)
	typedef struct node {
		char * label;
		unsigned short int id;
		node * left;
		node * right;
	}
	node * root=NULL;
	int next_id;
	
	
	// Array: converts id (int) into dictionary entry
	entry * entries=NULL;
	int length;

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
