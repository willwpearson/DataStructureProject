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
#include "../Nodes/BinaryTreeNode.hpp"

template<class Type>
class BinarySearchTree<Type> : public Tree<Type>
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
    //Data Method
    void insert(Type);
    bool contains(Type);
    void remove(Type);
    //Traversals
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
};

#endif /* BinarySearchTree_hpp */
