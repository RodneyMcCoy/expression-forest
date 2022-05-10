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
   map leafs;
   char * label;
public:
   expr();
   ~expr();
   expr operator=(const expr&);
  
   void initString(char * str);
   void initPolynomial(double * consts);
   void initFourier(double * consts);
   void initRandom(int size); // -1 for random size

   assign(char * label, double val);
   getIndex(char * label);
   assign(int label, double val);
  
   evaluate();
};
