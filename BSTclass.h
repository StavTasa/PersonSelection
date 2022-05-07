#pragma once
#include <stdlib.h>
#include <iostream>
#include "BSTnode.h"
using namespace std;

class BSTclass
{
    BSTnode* root;

public:
    BSTclass() : root(nullptr) {};
    //~BSTclass();
    void Insert(Person *item);
    BSTnode* Delete(BSTnode*, int);
    BSTnode* getRoot();
    BSTnode* findMin(BSTnode*);
    BSTnode* Find(int key);
    BSTnode* kthSmallest(BSTnode* root, int& k, int* count);
};


