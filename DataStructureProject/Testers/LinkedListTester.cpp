//
//  LinkedListTester.cpp
//  DataStructureProject
//
//  Created by Pearson, William on 2/20/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#include "LinkedListTester.hpp"

void LinkedListTester :: testListBasics()
{
    //Int List
    LinkedList<int> numbers;
    numbers.add(9);
    cout << numbers.getFront()->getData() << " Is at the front of the list and should be 9" << endl;
    cout << numbers.getEnd()->getData() << " Is at the end of the list and should be 9" << endl;
    
    numbers.add(0);
    cout << numbers.getFront()->getData() << " Is at the front of the list and should be 9" << endl;
    cout << numbers.getEnd()->getData() << " is at the end of the list and should be 0" << endl;
    
    numbers.addAtIndex(1,2);
    numbers.add(324);
    cout << numbers.getFront()->getData() << " Is at the front of the list and should be 9" << endl;
    cout << numbers.getEnd()->getData() << " is at the end of the list and should be 324" << endl;
    
    cout << "This loop should print 4 lines" << endl;
    for(int index = 0; index < numbers.getSize(); index++)
    {
        cout << numbers.getFromIndex(index) << endl;
    }
    
    numbers.remove(0);
    numbers.add(32567);
    numbers.addAtIndex(0,2312);
    
    cout << numbers.getFront()->getData() << " Is at the front of the list and should be 2312" << endl;
    cout << numbers.getEnd()->getData() << " is at the end of the list and should be 32567" << endl;
    
    //String List
    LinkedList<string> words;
    words.add("Hello");
    cout << words.getFront()->getData() << " Is at the front of the list and should be Hello" << endl;
    cout << words.getEnd()->getData() << " Is at the end of the list and should be Hello" << endl;
    
    words.add("Greetings");
    cout << words.getFront()->getData() << " Is at the front of the list and should be Hello" << endl;
    cout << words.getEnd()->getData() << " is at the end of the list and should be Greetings" << endl;
    
    words.addAtIndex(1,"Hola");
    words.add("Bonjour");
    cout << words.getFront()->getData() << " Is at the front of the list and should be Hello" << endl;
    cout << words.getEnd()->getData() << " is at the end of the list and should be Bonjour" << endl;
    
    cout << "This loop should print 4 lines" << endl;
    for(int index = 0; index < words.getSize(); index++)
    {
        cout << words.getFromIndex(index) << endl;
    }
    
    words.remove(0);
    words.add("Ni hao");
    words.addAtIndex(0,"Aloha");
    
    cout << words.getFront()->getData() << " Is at the front of the list and should be Aloha" << endl;
    cout << words.getEnd()->getData() << " is at the end of the list and should be Ni hao" << endl;
}

void LinkedListTester :: testListWithData()
{
    Timer listTimer;
    
    listTimer.startTimer();
    LinkedList<CrimeData> crimes = FileController :: readDataToList("/Users/wpea1865/Documents/C++ Projects/DataStructureProject/DataStructureProject/Data/crime.csv");
    listTimer.stopTimer();
    cout << "This is how long it took to read the structure into our custom data structure" << endl;
    listTimer.displayInformation();
    
    listTimer.resetTimer();
    cout << "Here is how long it takes to access a random data value" << endl;
    listTimer.startTimer();
    int randomLocation = (rand() * rand()) % crimes.getSize();
    cout << "The random index is " << randomLocation << endl;
    double totalViolentRate = crimes.getFromIndex(randomLocation).getAllViolentRates();
    listTimer.stopTimer();
    cout << "The random crime stat is: " << totalViolentRate << " , and here is the time" << endl;
    listTimer.displayInformation();
}
