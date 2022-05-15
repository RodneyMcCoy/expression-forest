/* vector.h
 *
 * Rodney McCoy 
 * rbmj2001@outlook.com
 * https://github.com/RodneyMcCoy/expression-tree
 *
 * Template Class for (non linked list) vector type. Implimented via inclusion model. Interface and Implimentation stored here.
 * Used internally in library.
 */

#ifndef VECTOR_H
#define VECTOR_H

template <typename T>
class vector {
private:
    T * data;
    int size;
public:
// Constructors and Destructors
    vector() : data:(null), size(0)
    vector(T * vals, int n) {
        data = vals;
        size = n;
    }
    ~vector();
    
    
// Basic Operations
    bool add(T val);
    bool remove(T val);
    bool containedIn(T val);
    void print();
};


#endif
