/* expr.h
 *
 * Rodney McCoy 
 * rbmj2001@outlook.com
 * https://github.com/RodneyMcCoy/expression-tree
 *
 * Expression Tree Class Interface.
 */

#ifndef EXPR_H
#define EXPR_H


#include "array.h"
#include "dict.h"


template <typename Type>
class expr {
private:

// ----- Expression Tree Data Structure -----
   typedef struct node {
      unsigned short int id;
      node * left;
      node * right;
   } node;
   node * root;




// ----- References ----
   dict< Type > vals;
   dict< expr<Type >* > expr_ref;
   dict< auto(*)(auto) > * unary;
   dict< auto(*)(auto, auto)> * binary;



// ----- Other Members and Methods -----
   char * treeLabel;
   void evaluateSubExpr(array< expr<Type> * > parents); // for nested expr trees. Throws error if a nest expr tree has label contained in treeLabel

public:

// ----- MAIN FUNCTIONALITY -----

   // Operator for evaluating the Expression Tree (IF SET TO REAL)
   Type operator()();
   Type operator()(char * label, Type val);  // Apply assign with label, then evaluate tree



   // Assigns values to leaves in tree
   bool assign(char * label, Type val);   // Assigns the leaf label the value val
   bool assign(int label, Type val);      // Assings the leaf with index label the value val

   
   
   // Constructors, Destructors, and other Overloaded Operators
   expr(char * str = NULL, bool isReal=true);   // construct tree. If arg given, calls initString with str
   ~expr();                                     // manualy deallocate each vertex in tree
   expr operator=(const expr&);                 // assignment (=), copys one expression tree to another
   void setReal();                              // changes values to long double (real numbers)
   void setComplex();                           // changes values to complex (complex numbers)


   // Initializers Part 1
   bool initString(char * str);                       // pases string to lex / yacc parser, and initializes tree. returns false if format not valid
   void initPolynomial(double * consts, int degree);  // initalizes a polynomial with given constants. consts of length degree + 1.
   void initFourier(double * consts, int len);        // initalizes a fourier series with len terms
   void initRandom(int size=-1);                      // randomly fill tree with operands and constants. If size >= 1, size is max amount of vertices in tree.
   bool initSeries(const expr& a_i, int l, int u);    // creates a n+1 termed series using a_i          
   bool initProduct(const expr& a_i, int l, int u);   // creates a n+1 termed product using a_i
   

   // Call private map methods to get indicies
   int getLeaf(char * label);

   
   // Check format of expr tree
   bool isProperFormat(char * label, char ** consts); // returns false if label doesnt match trees label, or a single string in consts isn't contained in the dict
   
  
   // Optimize
   expr & simplifyOther(bool rm_vars=false);
   void sipmlifySelf(bool rm_vars=false);
};


#include "expr.cpp"


#endif
