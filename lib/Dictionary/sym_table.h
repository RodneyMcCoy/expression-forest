/* sym_table.h
 *
 * Rodney McCoy 
 * rbmj2001@outlook.com
 * https://github.com/RodneyMcCoy/expression-tree
 *
 * Template class interface that defines a map between strings <-> int
 */


#ifndef SYM_TABLE_H
#define SYM_TABLE_H


class sym_table {
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




// ----- Internal (Recursive) Destructor -----
   void deleteTree(node * cur);


// ----- Internal (Recursive) Basic Operations -----
   bool insert(node * cur, char * label, int strDepth = 0);
   bool remove(node * cur, char * label, int strDepth = 0);
   bool remove(node * cur, int id);
   
   
// ----- Internal (Recursive) Debug and Print Methods -----
   void print(node * cur);
   void printTree(node * cur, int depth);


public:

// ----- Constructors, Destructors, and Overloaded Operators -----
	sym_table() : root(NULL), next_id(0) {}
	~sym_table();
	sym_table & operator=(const sym_table & other);  // Copy Assignment
   

   
// ----- Basic Operations -----
	bool insert(char * label);
	bool remove(char * label);
   bool remove(int id);
	int lookup(char * label);



// ----- Other Accessors -----
   bool empty() {return next_id == 0;}



// ----- Other Mutators -----



// ----- Debug and Print Methods -----
	void print();
   void printTree();



};


#endif
