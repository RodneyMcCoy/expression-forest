/* vector.h
 *
 * Rodney McCoy 
 * rbmj2001@outlook.com
 * https://github.com/RodneyMcCoy/expression-tree
 *
 * Template Class for (non linked list) vector type. Implimented via inclusion model. Interface and Implimentation stored here
 */

#ifndef VECTOR_H
#define VECTOR_H

template <typename T>
class vector {
private:
    T * data;
    int size;
public:
    vector();
    vector(T * data, int n);
    ~vector();
    
    bool add(T val);
    bool remove(T val);
    bool containedIn(T val);
    
    friend function vec;
};

vector<T> vec(T * data, int n);

#endif
