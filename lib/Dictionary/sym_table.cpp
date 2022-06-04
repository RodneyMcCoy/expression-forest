/* sym_table.cpp
 *
 * Rodney McCoy 
 * rbmj2001@outlook.com
 * https://github.com/RodneyMcCoy/expression-tree\search
 *
 * Template class implimentation. 
 * Implimented using explicit instantiation model
 */


#include <iostream>

#include "sym_table.h"
#include "str.h"


// ----- Internal (Recursive) Destructor -----

void sym_table::deleteTree(node * cur) {
   if(cur->left != NULL) { this->deleteTree(cur->left); }

   if(cur->right != NULL) { this->deleteTree(cur->right); }

   delete(cur);
}


sym_table::node * sym_table::assignTree(node * other) {
	node * cur = new node;
	
	cur->label = other->label;
	cur->id = other->id;
	
   if(other->left != NULL) { cur->left = this->assignTree(other->left); }

   if(other->right != NULL) { cur->right = this->assignTree(other->right); }

	return cur;
}



// ----- Internal (Recursive) Basic Operations -----

bool sym_table::insert(node * cur, str & label) {
	if(label == cur->label) {
		std::cout << "Duplicate label " << label << " found in dict. No action taken.\n";
	} 
	else if (label < cur->label) {
		if( cur->left == NULL) {
			cur->left = new node {label, next_id++, NULL, NULL };
      } 
		else {
			this->insert(cur->left, label);
      }
	} 
	else if (label > cur->label) {
		if( cur->right == NULL) {
         cur->right = new node {label, next_id++, NULL, NULL };
      } 
		else {
         this->insert(cur->right, label);
      }
	} 
	return true;
}


bool sym_table::remove(node * cur, str & label) {
	if(label == cur->label) {
		// remove label here
		
		return true;
	} 
	
	if (label < cur->label && cur->left != NULL) { return remove(cur->left, label); }
	
	if (label > cur->label && cur->right != NULL) { return remove(cur->right, label); }
	
	return false;	
}


bool sym_table::remove(node * cur, int id) {
	if(id == cur->id) {
		// remove label here
		
		return true;
	} 
	
	if (cur->left != NULL) { return remove(cur->left, id); }
	
	if (cur->right != NULL) { return remove(cur->right, id); }
	
	return false;
}
   
	
int sym_table::lookup(node * cur, str & label) {
	if(label == cur->label) { return cur->id; } 
	
	if (label < cur->label && cur->left != NULL) { return lookup(cur->left, label); }
	
	if (label > cur->label && cur->right != NULL) { return lookup(cur->right, label); }
	
	return -1;	
}




// ----- Internal (Recursive) Debug and Print Methods -----

void sym_table::print(node * cur) {
   if(cur->left != NULL) { this->print(cur->left); }

   std::cout << cur->label << "(" << cur->id << ") ";

   if(cur->right != NULL) { this->print(cur->right); }
}


void sym_table::printTree(node * cur, int depth) {
   for(int i = 0; i < depth; i++) {
      std::cout << "  ";
   }

   std::cout << cur->label << "(" << cur->id << ")\n";
   
   if(cur->left != NULL) { this->printTree(cur->left, depth + 1); }

   if(cur->right != NULL) { this->printTree(cur->right, depth + 1); }
}




// ----- Constructors, Destructors, and Overloaded Operators -----

sym_table::~sym_table() {
   if(root != NULL) { this->deleteTree(root); }
}


sym_table::sym_table(const sym_table & other) {
	if(other.root == NULL) {
		root = NULL;
	} else {
		root = assignTree(other.root);
	}

	next_id = other.next_id;
}



sym_table & sym_table::operator=(const sym_table & other) {
	if(other.root == NULL) {
		root = NULL;
	} else {
		root = assignTree(other.root);
	}

	next_id = other.next_id;
	return *this;
}   

   


// ----- Basic Operations -----

bool sym_table::insert(str label) {
   if(root == NULL) {
      root = new node {label, next_id++, NULL, NULL};
   } else if (label.empty()) {
      std::cerr << "Label given is empty, not label inserted";
   } else {
      this->insert(root, label);
   }
   return true;
}


bool sym_table::remove(str label) {
   if(root == NULL) { return false; }
	return remove(root, label);
}


bool sym_table::remove(int id) {
   if(root == NULL) { return false; }
	return remove(root, id);
}

int sym_table::lookup(str label) {
   if(root == NULL) { return -1; }
  	return lookup(root, label);
}





// ----- Other Accessors -----




// ----- Other Mutators -----




// ----- Debug and Print Methods -----

void sym_table::print() {
   if (root == NULL) {
      std::cout << "Dictionary is empty\n";
      return;
   }
   this->print(root);
   std::cout << "\n";
   return;
}


void sym_table::printTree() {
   if (root == NULL) {
      std::cout << "Dictionary is empty\n";
      return;
   }
   this->printTree(root, 0);
   std::cout << "\n";
   return;
}



