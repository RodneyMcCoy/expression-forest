/* dict.cpp
 *
 * Rodney McCoy 
 * rbmj2001@outlook.com
 * https://github.com/RodneyMcCoy/expression-tree
 *
 * Template class implimentation. 
 * Implimented using explicit instantiation model
 */


#include <iostream>
#include "dict.h"


// ----- PRIVATE METHODS -----

void dict::deleteTree(node * cur) {
   if(cur->left != NULL) {
      this->deleteTree(cur->left);
   }

   if(cur->right != NULL) {
      this->deleteTree(cur->right);
   }

   free(cur);
}



void dict::insert(node * cur, char * label, int strDepth) {
   // insert
   if(cur == NULL) {
      std::cerr << "ERROR. CURRENT NODE IS NULL, WE SHOULDNT BE HERE\n";
      return;
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
      return;
   }
}



void dict::print(node * cur) {
   if(cur->left != NULL) {
      this->print(cur->left);
   }

   std::cout << cur->label << "(" << cur->id << ")  ";

   if(cur->right != NULL) {
      this->print(cur->right);
   }
}



void dict::printTree(node * cur, int depth) {
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






// ----- PUBLIC METHODS -----

dict::~dict() {
   if(root != NULL) {
      this->deleteTree(root);
   }
}



dict & dict::operator=(const dict&) {
   // WORK NEEDS TO BE DONE HERE
   dict copy();
   return *this;
}



int dict::lookup(char * label) {
   // WORK NEEDS TO BE DONE HERE
   return 0;
}



int dict::operator[](char * label) {
   return this->lookup(label);
}



void dict::insert(char * label) {
   if(root == NULL) {
      root = new node {label, next_id++, NULL, NULL};
   } else if (label[0] == '\0') {
      std::cerr << "Label given is empty, not label inserted";
   } else {
      this->insert(root, label);
   }
   return;
}



void dict::remove(char * label) {
   // remove
   return;
}


void dict::remove(int id) {
   return;
}



void dict::print() {
   if (root == NULL) {
      std::cout << "Dictionary is empty\n";
      return;
   }
   this->print(root);
   std::cout << "\n";
   return;
}



void dict::printTree() {
   if (root == NULL) {
      std::cout << "Dictionary is empty\n";
      return;
   }
   this->printTree(root, 0);
   std::cout << "\n";
   return;
}