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

#include <complex>
#include "array.h"
#include "dict.h"

typedef long double real;
typedef std::complex<long double> comp;

class expr {
private:

// ----- EXPRESSION TREE DATA STRUCTURE -----

   typedef struct node {
      unsigned short int id;
      node * left;
      node * right;
   } node;
   node * root;





// ----- EXTERNAL REFERNECES ----

   // leaf constant values
   dict vals;
   array<real> * vals_r;
   array<comp> * vals_c;
   

   // leaf expression tree references
   dict expr_ref;
   array<expr *> * expr_refs;


   // parent unary function value
   dict unary;
   array<real (*) (real)> * unary_r;
   array<comp (*) (comp)> * unary_c;


   // parent binary function value
   dict binary;
   array<real (*) (real, real)> * binary_r;
   array<comp (*) (comp, comp)> * binary_c;




   char * treeLabel;

   bool isReal;
   
   void evaluateSubExpr(array<expr *> parents); // for nested expr trees. Throws error if a nest expr tree has label contained in treeLabel

public:

// ----- MAIN FUNCTIONALITY -----

   // Operator for evaluating the Expression Tree (IF SET TO REAL)
   real operator()();
   real operator()(char * label, real val);  // Apply assign with label, then evaluate tree
   real operator()(int label, real val);     // Apply assign with label, then evaluate tree


   // Operator for evaluating the Expression Tree (IF SET TO COMPLEX)
   comp operator()(int i);
   comp operator()(char * label, comp val);  // Apply assign with label, then evaluate tree
   comp operator()(int label, comp val);     // Apply assign with label, then evaluate tree


   // Assigns values to leaves in tree
   bool assign(char * label, real val);   // Assigns the leaf label the value val
   bool assign(int label, real val);      // Assings the leaf with index label the value val
   bool assign(char * label, comp val);   // Assigns the leaf label the value val
   bool assign(int label, comp val);      // Assings the leaf with index label the value val

   
   
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

#endif
