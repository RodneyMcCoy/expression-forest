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


// Assigns values to leaves in tree
   bool assign(char * label, double val);    // Assigns the leaf label the value val
   bool assign(int label, double val);       // Assings the leaf with index label the value val

   
// DFS the tree and evalute given saved constants in the map
   double evaluate();
   
   
// Check format of expr tree
   bool isProperFormat(char * label, char ** consts); // returns false if label doesnt match trees label, or a single string in consts isn't contained in the map
   
  
// Optimize
   expr & optimizeOther();
   void optimizeSelf();
};
