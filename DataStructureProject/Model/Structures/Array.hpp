//
//  Array.hpp
//  DataStructureProject
//
//  Created by Pearson, William on 2/2/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef Array_hpp
#define Array_hpp

#include <assert.h> //Used for validating user supplied data.
#include <iostream> //Used for tracing and debug statements.

using namespace std; //Used for keyword access.

template <class Type>
class Array
{
private:
    Type * internalArray;
    int size;
public:
    //Constructor
    Array<Type>(int size);
    
    //Copy Constructor
    Array<Type>(const Array<Type> & toCopy);
    //Destructor
    ~Array<Type>();
    
    //Operators
    Array<Type> & operator = (const Array<Type> & toReplace);
    Type& operator [] (int index);
    Type operator [] (int index) const;
    
    //Methods
    int getSize() const;
    Type getFromIndex(int index);
    void setAtIndex(int index, Type data);
}

template <class Type>
Array<Type> :: Array(int size)
{
    assert(size > 0);
    this->size = size;
    
    internalArray = new Type[size];
}

template <class Type>
Array<Type> :: Array(const Array<Type> & toCopy)
{
    this->size = toCopy.getSize();
    
    //Build Data Structure
    internalArray = new Type[size]
    
    for(int index = 0; index < size; index++)
    {
        internalArray[index] = toCopy[index];
    }
    
}


#endif /* Array_hpp */
