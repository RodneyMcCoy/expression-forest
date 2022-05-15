/* vector.h
 *
 * Rodney McCoy 
 * rbmj2001@outlook.com
 * https://github.com/RodneyMcCoy/expression-tree
 *
 * Interface for a class that maps strings to integers and vice versa.
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
    ~vector();
    
    void add(T val);
};


#endif
