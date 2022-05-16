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

class expr {
private:
   typedef struct node {
      signed short int id;
      node * left;
      node * right;
   };
   node * root;
   
   
   union leaf {
      long double value;
      expr * expression;
   };

   union parent {
      long double (*unary) (long double);
      long double (*binary) (long double, long double);
   };

   dict<leaf> * consts;
   dict<parent> * funcs;
   
   char * treeLabel;
   
   void evaluateSubExpr(array<expr *> parents); // for nested expr trees. Throws error if a nest expr tree has label contained in treeLabels

public:
// ----- MAIN FUNCTIONALITY -----
 
// Evaluate Expr Tree
   long double operator()();
   long double operator()(char * label, long double val); // Apply assign with label, then evaluate tree
   long double operator()(int label, long double val);    // Apply assign with label, then evaluate tree
   
 
// Assigns values to leaves in tree
   bool assign(char * label, long double val);    // Assigns the leaf label the value val
   bool assign(int label, long double val);       // Assings the leaf with index label the value val
   
   

// ----- OTHERS -----
   
// Constructors, Destructors, and other Overloaded Operators
   expr(char * str = NULL);      // construct tree. If arg given, calls initString with str
   ~expr();                      // manualy deallocate each vertex in tree
   expr operator=(const expr&);  // assignment (=), copys one expression tree to another


// Initializers Part 1
   bool initString(char * str);                       // pases string to lex / yacc parser, and initializes tree. returns false if format not valid
   void initPolynomial(double * consts, int degree);  // initalizes a polynomial with given constants. consts of length degree + 1.
   void initFourier(double * consts, int len);        // initalizes a fourier series with len terms
   void initRandom(int size=-1);                      // randomly fill tree with operands and constants. If size >= 1, size is max amount of vertices in tree.
   bool initSeries(const expr& a_i, int l, int u);    // creates a n+1 termed series using a_i          
   bool initProduct(const expr& a_i, int l, int u);   // creates a n+1 termed product using a_i
   
   
// Call private map methods to get indicies
   int getLeafIndex(char * label);
   int getOperandIndex(char * label);

   
// Check format of expr tree
   bool isProperFormat(char * label, char ** consts); // returns false if label doesnt match trees label, or a single string in consts isn't contained in the dict
   
  
// Optimize
   expr & simplifyOther(bool rm_vars=false);
   void sipmlifySelf(bool rm_vars=false);
};

#endif
