// Name: Haolin Zhang
// Loginid: haolinzh
// CSCI 455 PA5
// Fall 2016

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 *
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"
#include <iostream>

// cstdlib needed for call to atoi
#include <cstdlib>

void printCommandSum();


int main(int argc, char *argv[]) {

    // gets the hash table size from the command line

    int hashSize = Table::HASH_SIZE;

    Table *grades;  // Table is dynamically allocated below, so we can call
    // different constructors depending on input from the user.

    if (argc > 1) {
        hashSize = atoi(argv[1]);  // atoi converts c-string to int

        if (hashSize < 1) {
            cout << "Command line argument (hashSize) must be a positive number"
                 << endl;
            return 1;
        }

        grades = new Table(hashSize);

    } else {   // no command line args given -- use default table size
        grades = new Table();
    }


    grades->hashStats(cout);

    // add more code here
    // Reminder: use -> when calling Table methods, since grades is type Table*

    bool flag = true;
    string cmd;
    string name;
    int score;

    cout << "cmd>";

//Using while loop to read command and data util we input quit
    while (flag) {
        cin >> cmd;
        if (cmd == "insert") {
            cin >> name;
            cin >> score;
            if (grades->lookup(name) == NULL) {
                grades->insert(name, score);
            } else {
                cout << "The student has already existed" << endl;

            }
            cout << "cmd>";
            continue;
        }


        if (cmd == "change") {
            cin >> name;
            cin >> score;
            if (grades->remove(name)) {
                grades->insert(name, score);
            } else {
                cout << "The student is not existed" << endl;
            }
            cout << "cmd>";
            continue;
        }


        if (cmd == "lookup") {
            cin >> name;

            if (grades->lookup(name) != NULL) {
                cout << "The score of " << name << " is " << *(grades->lookup(name)) << endl;
            } else {
                cout << "The student is not existed" << endl;
            }
            cout << "cmd>";
            continue;
        }


        if (cmd == "remove") {
            cin >> name;
            if (!grades->remove(name)) {
                cout << "The student is not existed" << endl;
            }
            cout << "cmd>";
            continue;
        }

        if (cmd == "print") {
            grades->printAll();
            cout << "cmd>";
            continue;
        }

        if (cmd == "size") {
            cout << grades->numEntries() << endl;
            cout << "cmd>";
            continue;
        }

        if (cmd == "stats") {
            grades->hashStats(cout);
            cout << "cmd>";
            continue;
        }

        if (cmd == "help") {
            printCommandSum();
            cout << "cmd>";
            continue;

        }

        if (cmd == "quit") {
            flag = false;
            continue;
        }


        cout << "ERROR: invalid command" << endl;
        printCommandSum();
        cout << "cmd>";

    }

    return 0;
}

//Print the commands sum to instruct user input
void printCommandSum() {
    cout << "Please Follow the folling command format" << endl;
    cout << "insert name score" << endl;
    cout << "change name newscore" << endl;
    cout << "lookup name" << endl;
    cout << "remove name" << endl;
    cout << "print" << endl;
    cout << "size" << endl;
    cout << "stats" << endl;
    cout << "help" << endl;
    cout << "quit" << endl;
}
