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
    testTree.insert("Hi");
    testTree.insert("Hello");
    testTree.insert("Hola");
    testTree.insert("Bonjour");
    testTree.insert("Konichiwa");
    testTree.insert("Ni Hao");
    testTree.insert("Henlo");
    testTree.insert("Hallo");
    testTree.insert("Heyy");
    
    testTree.demo();
    testTree.inOrderTraversal();
    testTree.preOrderTraversal();
    testTree.postOrderTraversal();
}
