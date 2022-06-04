/* expr.h
 *
 * Rodney McCoy 
 * rbmj2001@outlook.com
 * https://github.com/RodneyMcCoy/expression-tree
 *
 * Expression Tree Class Interface. 
 * Explict Instantiation Model Used.
 */


#ifndef EXPR_H
#define EXPR_H


#include "array.h"
#include "dict.h"
#include "str.h"


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

   dict <Type>  vals;
   dict <expr<Type>*>  expr_ref;


   template <typename Type> struct unary { Type(*function)(Type), bool(*domain)(Type) };
   static dict <unary<Type>> unary;

   template <typename Type> struct binary { Type(*function)(Type,Type), bool(*domain)(Type,Type) };
   static dict <binary<Type>> binary;



// ----- Other Members and Methods -----

   str treeLabel;
   bool defined; // assigned false if previous evaluation of expr tree had a function undefined
   void evaluateSubExpr(array< expr<Type>* > parents); // for nested expr trees. Throws error if a nested expr tree refers to another.



public:

// ----- Main Class Functionality -----

   bool assign(char * label, Type val);   // Assigns the leaf label the value val
   bool assign(int id, Type val);         // Assings the leaf with index label the value val

   bool define(char * label, Type(*function)(Type), bool(*domain)(Type) = NULL);
   bool define(char * label, Type(*function)(Type,Type), bool(*domain)(Type,Type) = NULL);

   int index(char * label);

   Type operator()();                        // Evaluates Expr Tree
   Type operator()(char * label, Type val);  // Assign given label the value, then evaluate tree
   Type operator()(int id, Type val);        // Assign given ID the value, then evaluate tree

   

// ----- Constructors, Destructors, and Copy Assignment -----

   expr(char * str = NULL, bool isReal=true);   // construct tree. If arg given, calls initString with str
   ~expr();                                     // manualy deallocate each vertex in tree
	expr(const expr<Type> & other);					// copy constructor
   expr operator=(const expr&);                 // copy assignment (=), copys one expression tree to another



// ----- Initializers -----
   // bool initString(char * str);                       // pases string to lex / yacc parser, and initializes tree. returns false if format not valid
   // void initPolynomial(double * consts, int degree);  // initalizes a polynomial with given constants. consts of length degree + 1.
   // void initFourier(double * consts, int len);        // initalizes a fourier series with len terms
   // void initRandom(int size=-1);                      // randomly fill tree with operands and constants. If size >= 1, size is max amount of vertices in tree.
   // bool initSeries(const expr& a_i, int l, int u);    // creates a n+1 termed series using a_i          
   // bool initProduct(const expr& a_i, int l, int u);   // creates a n+1 termed product using a_i
   


// ----- Check Format Of Expression Tree -----

   // bool checkFormat(char * label, char ** consts); // returns false if label doesnt match trees label, or a single string in consts isn't contained in the dict
   // bool checkFormat(char * label);
   // bool checkFormat(char ** consts);
  


// ----- Simplifies The Expression Tree -----

   // void sipmlify();



};


#include "expr.cpp"


#endif
