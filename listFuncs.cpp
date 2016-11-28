// Name:
// Loginid:
// CSCI 455 PA5
// Fall 2016


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
    key = theKey;
    value = theValue;
    next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
    key = theKey;
    value = theValue;
    next = n;
}


//*************************************************************************
// put the function definitions for your list functions below
void listPrint(ListType list) {
    ListType tmp = list;
    while (tmp != NULL) {
        cout  << tmp->key << " " << tmp->value << endl;
        tmp = tmp->next;
    }
}


int listSize(ListType list) {
    ListType tmp = list;
    int count = 0;
    while (tmp != NULL) {
        count++;
        tmp = tmp->next;
    }
    return count;
}


bool listContainsKey(ListType list, string target) {
    ListType tmp = list;
    while (tmp != NULL) {
        if (tmp->key == target) {
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

int* listLookUp(ListType list, string target) {
    ListType tmp = list;
    while (tmp != NULL) {
        if (tmp->key == target) {
            return &(tmp->value);
        }
        tmp = tmp->next;
    }

    return NULL;


}

bool listInsert(ListType &list, string target, int value) {
    if (listContainsKey(list, target)) {
        return 0;
    }

    if (list == NULL) {
        list = new Node(target, value);
        return 1;
    }

    ListType tmp = list;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    ListType append = new Node(target, value);
    tmp->next = append;
    return 1;
}



bool listRemove(ListType &list, string target) {
    if (!listContainsKey(list, target)) {
        return 0;
    }

    ListType cur = list;
    ListType pre = cur;

    if (cur->key == target) {
        list = cur->next;
        return 1;
    }

    while (cur != NULL) {
        if (cur->key == target) {
            pre->next = cur->next;
            return 1;
        }
        pre=cur;
        cur=cur->next;
    }

    return 0;


}