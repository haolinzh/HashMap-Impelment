// Name: Haolin Zhang
// Loginid: haolinzh
// CSCI 455 PA5
// Fall 2016

// Table.cpp  Table class implementation


/*
 * Modified 11/22/11 by CMB
 *   changed name of constructor formal parameter to match .h file
 */

#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************

//Constructor function for table using default size
Table::Table() {
    hashSize = HASH_SIZE;
    table = new ListType[hashSize];
    entryNum = 0;
    for (int i = 0; i < hashSize; i++) {
        table[i] = NULL;
    }

}

//Constructor function for table using specific size
Table::Table(unsigned int hSize) {
    hashSize = hSize;
    entryNum = 0;
    table = new ListType[hashSize];
    for (int i = 0; i < hashSize; i++) {
        table[i] = NULL;
    }

}

//Lookup Key in a table
int *Table::lookup(const string &key) {
    int bucket = hashCode(key);
    return listLookUp(table[bucket], key);
}

//Remove key in a table
bool Table::remove(const string &key) {
    int bucket = hashCode(key);
    if (listRemove(table[bucket], key)) {
        entryNum--;
        return 1;
    } else {
        return 0;
    }


}

//Insert key-value in a table
bool Table::insert(string &key, int value) {
    int bucket = hashCode(key);
    if (listInsert(table[bucket], key, value)) {
        entryNum++;
        return 1;
    } else {
        return 0;
    }
}


//Print all the value in table
void Table::printAll() const {
    for (int i = 0; i < hashSize; i++) {
        listPrint(table[i]);
    }
}

int Table::numEntries() const {
    return entryNum;
}

int Table::numBuckets() const {
    return hashSize;
}


//Return no-empty buckets in the Hashtable
int Table::numNoEmptyBuckets() const {
    int numNoEmptyBuckets = 0;
    for (int i = 0; i < hashSize; i++) {
        if (table[i] != NULL) {
            numNoEmptyBuckets++;
        }
    }
    return numNoEmptyBuckets;
}


//Return the length of longest chain
int Table::numLongestChain() const {
    int LongestChain = 0;

    for (int i = 0; i < hashSize; i++) {
        if (listSize(table[i]) > LongestChain) {
            LongestChain = listSize(table[i]);
        }
    }
    return LongestChain;
}


void Table::hashStats(ostream &out) const {
    out << "number of buckets " << numBuckets() << endl;
    out << "number of entries " << numEntries() << endl;
    out << "number of non-empty buckets " << numNoEmptyBuckets() << endl;
    out << "longest chain " << numLongestChain() << endl;

}







// add definitions for your private methods here
