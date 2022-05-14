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

template<> struct type_name<int> { static int type() {return -1;} };
template<> struct type_name<string> { static int type() {return 1;} };

template <typename Data>
class dict {
private:
  // This is an AVL tree
  typedef struct node {
    char * label;
    unsigned short int id;
    node * left;
    node * right;
  }
  node * root;
   
  Data * vals=NULL;

  a

public:
// Constructors, Destructors, and other Overloaded Operators
  dict();
  ~dict();
  dict operator=(const dict&);  // assignment (=), copys one dictionary to another

  bool insert(char * label);
  bool remove(char * label);
  
  Data lookup(char * label);
  Data operator[](char * label);
  Data lookup(int id);
  Data operator[](int id);
};


#endif
