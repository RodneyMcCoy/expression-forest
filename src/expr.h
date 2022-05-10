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
   bool initString(char * str);                 // pases string to lex / yacc parser, returns false if format not valid
   void initPolynomial(double * consts, int n); // initalizes a degree nth polynomial with given constants
   void initFourier(double * consts, int n);    // initalizes a fourier series with  terms
   void initRandom(int size=-1);                // randomly fill tree
   

// Initialziers Part 2
// a_i must be a tree with only varaibles i and x.
// i being the index which turns into a constant, x being an evaluatable varaible
// initSeries(a_i, 0, n) with a_i = x^n would be equivalent to initPolynomial({1, ..., 1}, n)
   bool initSeries(const expr& a_i, int n);                 // creates a n+1 termed series using a_i          
   bool initProduct(const expr& a_i, int n);                // creates a n+1 termed product using a_i
   bool initWithOperand(const expr& a_i, int opInd, int l, int u); // creates a n termed product 
   bool initNested(const expr&, int constInd, int opInd, int n); 
   
// Call private map methods to get indicies
   int getLeafIndex(char * label);
   int getOperandIndex(char * label);


// Assigns values to leaves in tree
   bool assign(char * label, double val);    // Assigns the leaf label the value val
   bool assign(int label, double val);       // Assings the leaf with index label the value val

   
// DFS the tree and evalute given saved constants in the map
   double evaluate();
   
   
// Check format of expr tree
   bool properFormat(char * label, char ** consts); // returns false if label doesnt match trees label, or a single string in consts isn't contained in the map
};
