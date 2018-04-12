//
//  BinaryTreeTester.cpp
//  DataStructureProject
//
//  Created by Pearson, William on 3/27/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#include "BinaryTreeTester.hpp"

void BinaryTreeTester :: doTreeStuff()
{
    stringTree.insert("Hi");
    stringTree.insert("Hello");
    stringTree.insert("Hola");
    stringTree.insert("Bonjour");
    stringTree.insert("Konichiwa");
    stringTree.insert("Ni Hao");
    stringTree.insert("Henlo");
    stringTree.insert("Hallo");
    stringTree.insert("Heyy");
    
    stringTree.demo();
    stringTree.inOrderTraversal();
    stringTree.preOrderTraversal();
    stringTree.postOrderTraversal();
    cout << "Height: " << stringTree.getHeight() << endl;
    cout << stringTree.isBalanced() << endl;
    cout << stringTree.isComplete() << endl;
    
    
    intTree.insert(1);
    intTree.insert(2);
    intTree.insert(3);
    intTree.insert(71);
    intTree.insert(12344);
    intTree.insert(433);
    intTree.insert(75634);
    intTree.insert(34);
    intTree.insert(43);
    
    intTree.demo();
    intTree.inOrderTraversal();
    intTree.preOrderTraversal();
    intTree.postOrderTraversal();
    cout << "Height: " << intTree.getHeight() << endl;
    cout << intTree.isBalanced() << endl;
    cout << intTree.isComplete() << endl;
}
