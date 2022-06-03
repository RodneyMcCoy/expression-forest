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



// ----- Internal (Recursive) Destructor -----

void sym_table::deleteTree(node * cur) {
   if(cur->left != NULL) {
      this->deleteTree(cur->left);
   }

   if(cur->right != NULL) {
      this->deleteTree(cur->right);
   }

   free(cur);
}




// ----- Internal (Recursive) Basic Operations -----

bool sym_table::insert(node * cur, str & label, int strDepth) {
   // insert
   if(cur == NULL) {
      std::cerr << "ERROR. CURRENT NODE IS NULL, WE SHOULDNT BE HERE\n";
      return false;
   }

   char u, v;
   while(true) {
      v = cur->label[strDepth];
      u = label[strDepth];

      if(label[strDepth] == '\0') {
         std::cout << "Duplicate label " << label << " found in dict. No action taken: " << strDepth << "\n";

      } else if(u < v) {
         if( cur->left == NULL) {
            cur->left = new node {label, next_id++, NULL, NULL };
         } else {
            this->insert(cur->left, label);
         }

      } else if (u > v) {
         if( cur->right == NULL) {
            cur->right = new node {label, next_id++, NULL, NULL };
         } else {
            this->insert(cur->right, label);
         }

      } else {
         strDepth++;
         continue;
      }
      return true;
   }
}


// bool remove(node * cur, str & label, int strDepth = 0);

// bool remove(node * cur, int id);
   
   


// ----- Internal (Recursive) Debug and Print Methods -----

void sym_table::print(node * cur) {
   if(cur->left != NULL) {
      this->print(cur->left);
   }

   std::cout << cur->label << "(" << cur->id << ")  ";

   if(cur->right != NULL) {
      this->print(cur->right);
   }
}


void sym_table::printTree(node * cur, int depth) {
   for(int i = 0; i < depth; i++) {
      std::cout << "  ";
   }

   std::cout << cur->label << "(" << cur->id << ")\n";
   
   if(cur->left != NULL) {
      this->printTree(cur->left, depth + 1);
   }


   if(cur->right != NULL) {
      this->printTree(cur->right, depth + 1);
   }
}




// ----- Constructors, Destructors, and Overloaded Operators -----

sym_table::~sym_table() {
   if(root != NULL) {
      this->deleteTree(root);
   }
}


sym_table & sym_table::operator=(const sym_table&) {
   // WORK NEEDS TO BE DONE HERE
   return *this;
}   

   


// ----- Basic Operations -----

bool sym_table::insert(str label) {
   if(root == NULL) {
      root = new node {label, next_id++, NULL, NULL};
   } else if (label[0] == '\0') {
      std::cerr << "Label given is empty, not label inserted";
   } else {
      this->insert(root, label);
   }
   return true;
}


bool sym_table::remove(str label) {
   // remove
   return true;
}


bool sym_table::remove(int id) {
   return true;
}


int sym_table::lookup(str label) {
   // WORK NEEDS TO BE DONE HERE
   return 0;
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



