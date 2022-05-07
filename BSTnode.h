#pragma once
#include "Person.h"

class BSTnode
{
private:
	Person *value;
	BSTnode* left, * right;
public:
	BSTnode(Person *value);
	//~BSTnode();
	Person* getValue() { return value; }
	BSTnode* getLeft() { return left; }
	BSTnode* getRight() { return right; }
	void setLeft(BSTnode* _left) { left = _left; }
	void setRight(BSTnode* _right) { right = _right; }
};

