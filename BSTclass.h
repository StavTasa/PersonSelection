#pragma once
#include <stdlib.h>
#include <iostream>
#include "BSTnode.h"
using namespace std;

class BSTclass
{
    BSTnode* root;

public:
	int &NumComp;
    BSTclass(int &_NumComp) : root(nullptr), NumComp(_NumComp) {};
    ~BSTclass();
    void Insert(Person *item);
	void Free(BSTnode*);

    BSTnode* Delete(BSTnode*, int);
    BSTnode* getRoot();
    BSTnode* findMin(BSTnode*);
    BSTnode* Find(int key);
    BSTnode* kthSmallest(BSTnode* root, int& k, int* count);
};


