/* expr.h
 *
 * Rodney McCoy 
 * rbmj2001@outlook.com
 * https://github.com/RodneyMcCoy/expression-tree
 *
 * Expression Tree Class Interface.
 */


class expr {
private:
   typedef struct node {
      int id;
      node * left;
      node * right;
   }
   node * root;

   map operands;
   double * operands;
   map leafs;
   double * leafs;
   
   char * treeLabel;
public:
// Constructors, Destructors, and Overloaded Operators
   expr(char * str = NULL);      // construct tree. If arg given, calls initString
   ~expr();                      // manualy deallocate each vertex in tree
   expr operator=(const expr&);  // assignment (=), copys one expression tree to another


// Initializers
   bool initString(char * str);                    // pases string to lex / yacc parser, returns false if format not valid
   void initPolynomial(double * consts, int n);    // initalizes a degree n-1th polynomial with given constants
   void initFourier(double * consts, int n);       // initalizes a fourier series with 2n + 1 terms
   void initRandom(int size=-1);                   // randomly fill tree
   void initSeries(const expr& x, int n);                 // expr x is an expression tree with one variable. 
   void initProduct(const expr& x, int n);                

   
// Assigns values to leaves in tree
   bool assign(char * label, double val);    // passes label through map, and gives
   int getIndex(char * label);
   bool assign(int label, double val);

   
// DFS the tree and evalute given saved constants in the map
   double evaluate();
   
// Check format of expr tree
   bool properFormat(char * label, char ** consts); // throws error if label doesnt match trees label, or a single string in consts isnt contained in the map
};
