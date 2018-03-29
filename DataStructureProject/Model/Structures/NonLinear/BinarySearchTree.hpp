//
//  BinarySearchTree.hpp
//  DataStructureProject
//
//  Created by Pearson, William on 3/29/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include "Tree.hpp"
#include <iostream>
using namespace std;

template <class Type>
class BinarySearchTree : public Tree<Type>
{
protected:
    //Recursive Information Helpers
    int calculateSize(BinaryTreeNode<Type> * startNode);
    int calculateHeight(BinaryTreeNode<Type> * startNode);
    bool isBalanced(BinaryTreeNode<Type> * startNode);
    bool isComplete(BinaryTreeNode<Type> * startNode, int index, int size);
    //Recursive Data Helpers
    void removeNode(BinaryTreeNode<Type> * removeMe);
    //Recursive Traversal Helpers
    void inOrderTraversal(BinaryTreeNode<Type> * inStart);
    void preOrderTraversal(BinaryTreeNode<Type> * preStart);
    void postOrderTraversal(BinaryTreeNode<Type> * postStart);
    BinaryTreeNode<Type> * getRightMostChild(BinaryTreeNode<Type> * current);
    BinaryTreeNode<Type> * getLeftMostChild(BinaryTreeNode<Type> * current);
public:
    //Structure
    BinarySearchTree();
    ~BinarySearchTree();
    //Informational Methods
    int getSize();
    int getHeight();
    bool isComplete();
    bool isBalanced();
    BinaryTreeNode<Type> * getRoot();
    void setRoot(BinaryTreeNode<Type> * root);
    //Data Methods
    void insert(Type itemToInsert);
    bool contains(Type);
    void remove(Type);
    Type findMinimum();
    Type findMaximum();
    //Traversals
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    void demo();
    void demoTraversalSteps(BinaryTreeNode<Type> * node);
};

/*
 Structure
 */
template <class Type>
BinarySearchTree<Type> :: BinarySearchTree()
{
    this->root = nullptr;
}

template <class Type>
BinarySearchTree<Type> :: ~BinarySearchTree()
{
  
}

/*
 Informational Methods
 */
template <class Type>
int BinarySearchTree<Type> :: getSize()
{
    return -1;
}

template <class Type>
int BinarySearchTree<Type> :: getHeight()
{
    return -1;
}

template <class Type>
bool BinarySearchTree<Type> :: isComplete()
{
    return false;
}

template <class Type>
bool BinarySearchTree<Type> :: isBalanced()
{
    return false;
}

template <class Type>
BinaryTreeNode<Type> * BinarySearchTree<Type> :: getRoot()
{
    
}

template <class Type>
void BinarySearchTree<Type> :: setRoot(BinaryTreeNode<Type> * root)
{
    
}

/*
 Recursive Information Helpers
 */
template <class Type>
int BinarySearchTree<Type> :: calculateSize(BinaryTreeNode<Type> * startNode)
{
    
}

template <class Type>
int BinarySearchTree<Type> :: calculateHeight(BinaryTreeNode<Type> * startNode)
{
    
}

template <class Type>
bool BinarySearchTree<Type> :: isBalanced(BinaryTreeNode<Type> * startNode)
{
    
}

template <class Type>
bool BinarySearchTree<Type> :: isComplete(BinaryTreeNode<Type> * startNode, int index, int size)
{
    
}

/*
 Data Methods
 */
template <class Type>
void BinarySearchTree<Type> :: insert(Type itemToInsert)
{
    BinaryTreeNode<Type> * insertMe = new BinaryTreeNode<Type>(itemToInsert);
    BinaryTreeNode<Type> * previous = nullptr;
    BinaryTreeNode<Type> * current = this->root;
    
    if(current == nullptr)
    {
        this->root = insertMe;
    }
    else
    {
        while(current != nullptr)
        {
            previous = current;
            if(itemToInsert < current->getData())
            {
                current = current->getLeft();
            }
            else if(itemToInsert > current->getData())
            {
                current = current->getRight();
            }
            else
            {
                cerr << "Item exists already - Exiting insert" << endl;
                delete insertMe;
                return;
            }
        }
        
        if(previous->getData() > itemToInsert)
        {
            previous->setLeftNode(insertMe);
        }
        else
        {
            previous->setRightNode(insertMe);
        }
        insertMe->setRootNode(previous);
    }
}

template <class Type>
bool BinarySearchTree<Type> :: contains(Type)
{
    return false;
}

template <class Type>
void BinarySearchTree<Type> :: remove(Type)
{
    
}

template <class Type>
Type BinarySearchTree<Type> :: findMinimum()
{
    
}

template <class Type>
Type BinarySearchTree<Type> :: findMaximum()
{
    
}

/*
 Recursive Data Helpers
 */
template <class Type>
void BinarySearchTree<Type> :: removeNode(BinaryTreeNode<Type> * removeMe)
{
    
}

/*
 Traversals
 */
template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal()
{
    inOrderTraversal(this->root);
}

template <class Type>
void BinarySearchTree<Type> :: preOrderTraversal()
{
    preOrderTraversal(this->root);
}

template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal()
{
    postOrderTraversal(this->root);
}

template <class Type>
void BinarySearchTree<Type> :: demoTraversalSteps(BinaryTreeNode<Type> * start)
{
    if(start != nullptr)
    {
        cout << "check if left is here" << endl;
        demoTraversalSteps(start->getLeft());
        cout << "at root" << endl;
        cout << "check if right is here" << endl;
        demoTraversalSteps(start->getRight());
    }
    else
    {
        cout << "reached nullptr - if on right its back up the recursive call stack" << endl;
    }
}

template <class Type>
void BinarySearchTree<Type> :: demo()
{
    demoTraversalSteps(this->root);
}

/*
 Recursive Traversal Helpers
 */
template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal(BinaryTreeNode<Type> * inStart)
{
    if(inStart != nullptr)
    {
        inOrderTraversal(inStart->getLeft());
        cout << inStart->getData() << endl;
        inOrderTraversal(inStart->getRight());
    }
}

template <class Type>
void BinarySearchTree<Type> :: preOrderTraversal(BinaryTreeNode<Type> * preStart)
{
    if(preStart != nullptr)
    {
        cout << preStart->getData() << endl;
        preOrderTraversal(preStart->getLeft());
        preOrderTraversal(preStart->getRight());
    }
}

template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal(BinaryTreeNode<Type> * postStart)
{
    if(postStart != nullptr)
    {
        postOrderTraversal(postStart->getLeft());
        postOrderTraversal(postStart->getRight());
        cout << postStart->getData() << endl;
    }
}

template <class Type>
BinaryTreeNode<Type> * BinarySearchTree<Type> :: getRightMostChild(BinaryTreeNode<Type> * current)
{
    
}

template <class Type>
BinaryTreeNode<Type> * BinarySearchTree<Type> :: getLeftMostChild(BinaryTreeNode<Type> * current)
{
    
}
#endif /* BinarySearchTree_hpp */
