//
//  AVLTree.hpp
//  DataStructureProject
//
//  Created by Pearson, William on 4/17/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef AVLTree_hpp
#define AVLTree_hpp

#include "BinarySearchTree.hpp"

template <class Type>
class AVLTree : public BinarySearchTree<Type>
{
private:
    BinaryTreeNode<Type> * leftRotation(BinaryTreeNode<Type> * parent);
    BinaryTreeNode<Type> * rightRotation(BinaryTreeNode<Type> * parent);
    BinaryTreeNode<Type> * leftRightRotation(BinaryTreeNode<Type> * parent);
    BinaryTreeNode<Type> * rightLeftRotation(BinaryTreeNode<Type> * parent);
    
    BinaryTreeNode<Type> * balanceSubTree(BinaryTreeNode<Type> * parent);
    
    BinaryTreeNode<Type> * insertNode(BinaryTreeNode<Type> * parent, Type value);
    BinaryTreeNode<Type> * removeNode(BinaryTreeNode<Type> * parent, Type value);
    
    int heightDifference(BinaryTreeNode<Type> * parent);
    
public:
    AVLTree();
    
    void insert(Type itemToInsert);
    void remove(Type value);
};

/*
 A Negative value means the right is greater than the left
 */
template <class Type>
int AVLTree<Type> :: heightDifference(BinaryTreeNode<Type> * node)
{
    int balance;
    int leftHeight = this->calculateHeight(node->getLeftNode());
    int rightHeight = this->calculateHeight(node->getRightNode());
    balance = leftHeight - rightHeight;
    return balance;
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: leftRotation(BinaryTreeNode<Type> * parent)
{
    BinaryTreeNode<Type> * changedNode;
    changedNode = parent->getLeft();
    
    parent->setLeftChild(changedNode->getRight());
    
    changedNode->setRightChild(parent);
    
    return changedNode;
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: rightRotation(BinaryTreeNode<Type> * parent)
{
    BinaryTreeNode<Type> * changedNode;
    changedNode = parent->getRight();
    
    parent->setRightChild(changedNode->getLeft());
    
    changedNode->setLeftChild(parent);
    
    return changedNode;
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: rightLeftRotation(BinaryTreeNode<Type> * parent)
{
    BinaryTreeNode<Type> * changedNode;
    changeNode = parent->getRight();
    
    parent->setRightChild(leftRotation(changedNode));
    
    return rightRotation(parent);
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: leftRightRotation(BinaryTreeNode<Type> * parent)
{
    BinaryTreeNode<Type> * changedNode;
    changedNode = parent->getLeft();
    
    parent->setLeftChild(rightRotation(changedNode));
    
    return leftRotation(parent);
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: balanceSubTree(BinaryTreeNode<Type> * parent)
{
    int balanceFactor = heightDifference(parent);
    
    if(balanceFactor > 1)
    {
        if(heightDifference(parent->getLeft()) > 0)
        {
            parent = leftRotation(parent);
        }
        else
        {
            parent = leftRightRotation(parent);
        }
    }
    else if(balanceFactor < -1)
    {
        if(heightDifference(parent->getRight()) > 0)
        {
            parent = rightLeftRotation(parent);
        }
        else
        {
            parent = rightRotation(parent);
        }
    }
    
    return parent;
}

template <class Type>
AVLTree<Type> :: AVLTree() : BinarySearchTree<Type>()
{
    this->root = nullptr;
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: removeNode(BinaryTreeNode<Type> * parent, Type inserted)
{
    if(parent == nullptr)
    {
        return parent;
    }
    if(inserted < parent->getNodeData())
    {
        parent->setLeftChild(removeNode(parent->getLeft(), inserted));
    }
    else if(inserted > parent->getNodeData())
    {
        parent-setRightChild(removeNode(parent->getRight(), inserted));
    }
    else
    {
        BinaryTreeNode<Type> * temp;
        if(parent->getLeft() == nullptr && parent->getRight() == nullptr)
        {
            temp = parent;
            delete temp;
        }
        else if(parent->getLeft() == nullptr)
        {
            *parent = *parent->getRight();
        }
        else if(parent->getRight() == nullptr)
        {
            *parent = *parent->getLeft();
        }
        else
        {
            BinaryTreeNode<Type> * leftMost = this->getLeftMostChild(parent->getRight());
            parent->setNodeData(leftMost->getNodeData());
            parent->setRightChild(removeNode(parent->getRight(), leftMost->getNodeData()));
        }
    }
    
    if(parent == nullptr)
    {
        return parent;
    }
    
    return balanceSubTree(parent);
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: insertNode(BinaryTreeNode<Type> * parent, Type inserted)
{
    if(parent == nullptr)
    {
        parent = new BinaryTreeNode<Type>(inserted);
        return parent;
    }
    else if(inserted < parent->getNodeData())
    {
        parent->setLeftChild(insertNode(parent->getLeft(), inserted));
        parent = balanceSubTree(parent);
    }
    else if(inserted > parent->getNodeData())
    {
        parent->setRightChild(insertNode(parent->getRight(), inserted));
        parent = balanceSubTree(parent);
    }
    return parent;
}

template <class Type>
void AVLTree<Type> :: insert(Type item)
{
    insertNode(this->getRoot(), item);
}

template <class Type>
void AVLTree<Type> :: remove(Type item)
{
    removeNode(this->getRoot(), item);
}

#endif /* AVLTree_hpp */
