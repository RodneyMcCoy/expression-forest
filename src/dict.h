/* dict.h
 *
 * Rodney McCoy 
 * rbmj2001@outlook.com
 * https://github.com/RodneyMcCoy/expression-tree
 *
 * Template class interface that defines a bijection between strings <-> int
 */


#ifndef DICT_H
#define DICT_H


class dict {
private:

   // AVL tree: converts string <-> int
	typedef struct node {
		char * label;
		unsigned short int id;
		node * left;
		node * right;
	} node;
	node * root;
	unsigned short int next_id;
   

   // AVL tree operations
   // void singleRight(node * cur);
   // void singleLeft(node * cur);
   // void doubleLeft(node * cur);
   // void doubleRight(node * cur);


   // internal operations that extend basic public methods
   // Constructors, Destructors, and Overloaded Operators
   void deleteTree(node * cur);

   // Lookup Operation


   // Other Operations
   void insert(node * cur, char * label, int strDepth = 0);
   void remove(node * cur, char * label, int strDepth = 0);
   void remove(node * cur, int id);
   
   
   // Print Methods
   void print(node * cur);
   void printTree(node * cur, int depth);


public:


   // Constructors, Destructors, and Overloaded Operators
	dict() : root(NULL), next_id(0) {}
	~dict();
	dict & operator=(const dict&);  // assignment (=), copys one dictionary to another
   

   // Lookup Operation
   int operator[](char * label); // overload for look up
	int lookup(char * label);


   // Other Operations
	void insert(char * label);
	void remove(char * label);
   void remove(int id);
   bool empty() {return next_id == 0;}


   // Print Methods
	void print();
   void printTree();
};


#endif
