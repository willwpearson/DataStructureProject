//
//  Queue.h
//  DataStructureProject
//
//  Created by Pearson, William on 2/22/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include "LinkedList.hpp"

#include <iostream>
using namespace std;

template <class Type>
class Queue : public LinkedList<Type>
{
public:
    Queue();
    ~Queue();
    
    //Queue methods
    void enqueue(Type data);
    Type dequeue();
    Type peek();
    void clear();
    
    //Overridden LinkedList methods
    void add(Type data);
    void addAtIndex(int index, Type data);
    Type getFromIndex(int index);
    Type remove(int index);
};

#endif /* Queue_hpp */
