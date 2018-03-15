//
//  Controller.cpp
//  DataStructureProject
//
//  Created by Pearson, William on 1/31/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#include "Controller.hpp"

using namespace std;

void Controller :: start()
{
//    Timer codeTimer;
//    codeTimer.startTimer();
//    cout << "Look code on the screen" << endl;
//    codeTimer.stopTimer();
//    codeTimer.displayInformation();
//    codeTimer.resetTimer();
//    codeTimer.startTimer();
//
//    vector<CrimeData> myData = FileController :: readCrimeDataToVector("/Users/wpea1865/Documents/C++ Projects/DataStructureProject/DataStructureProject/Data/crime.csv");
//
//    for(int index = 200; index < 216; index++)
//    {
//        cout << index << " is " << myData[index] << endl;
//    }
//
//    codeTimer.stopTimer();
//    codeTimer.displayInformation();
    
//    findMaxandMin();
//
//    testArray();
//    ArrayTester myTest;
//    myTest.testArrayUse();
//    myTest.testAdvancedArray();
    
//    LinkedListTester linkedTest;
//    linkedTest.testListBasics();
//    linkedTest.testListWithData();
    
//    TestingStacksAndQueues versusTest;
//    versusTest.stackVersusList();
//    versusTest.stackVersusQueue();
//    versusTest.queueVersusList();
    
//    RecursionTester test;
//    test.testRecursionNumbers();
//    test.testRecursionString();
    
    SortingTester test;
    test.testSorts();
}

void Controller :: findMaxandMin()
{
    Timer searchTimer;
    searchTimer.startTimer();
    vector<CrimeData> myData = FileController :: readCrimeDataToVector("/Users/wpea1865/Documents/C++ Projects/DataStructureProject/DataStructureProject/Data/crime.csv");
    
    int minIndex = 0;
    int maxIndex = 0;
    
    for (int index = 1; index < myData.size(); index++)
    {
        if (myData [minIndex] > myData [index])
        {
            minIndex = index;
        }
        else if (myData [maxIndex] < myData [index])
        {
            maxIndex = index;
        }
    }
    searchTimer.stopTimer();
    cout << "The smallest Crime stat is at " << minIndex << " and it is: " << myData[minIndex] << endl;
    cout << "The largest Crime stat is at " << maxIndex << " and it is: " << myData[maxIndex] << endl;
    searchTimer.displayInformation();
}

void Controller :: testArray()
{
    Array<int> codyArray(45);
    
    for(int i = 0; i < codyArray.getSize(); i ++)
    {
        codyArray[i] = i;
        cout << codyArray[i] << endl;
    }
}
