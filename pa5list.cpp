// Name:
// loginid:
// CS 455 PA5

// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"


int main() {
    ListType p = NULL;
    listAppend(p, "Amy", 60);
    listAppend(p, "Bob", 90);
    listAppend(p, "Caro", 85);
    listAppend(p, "David", 40);
    listPrint(p);
    cout << "This is listSize currently : " << listSize(p) << endl;

    cout << "does list contain Bob? " << listContainsKey(p, "Bob") << endl;
    cout << "does list contain Caro? " << listContainsKey(p, "Caro") << endl;


    cout << "remove successful? : " <<  listRemove(p, "David") << endl;

    cout << "does list contain Zoe? " << listContainsKey(p, "zoe") << endl;
    cout << "update successful? : " << listUpdate(p, "Amy", 75) << endl;

    listPrint(p);
    cout << "current list size  : " << listSize(p) << endl;
    cout << "does list contain David anymore? " << listContainsKey(p, "David") << endl;

    cout << "Amy's current number : " << listLookUp(p, "Amy") << endl;
    return 0;


}
