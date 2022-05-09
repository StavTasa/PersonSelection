#pragma once
#include "Person.h"

class BSTnode
{
private:
	Person *value;
	BSTnode* left, * right;
public:
	BSTnode(Person *value);
	Person* getValue() { return value; }
	BSTnode* getLeft() { return left; }
	BSTnode* getRight() { return right; }
	void setValue(Person *item) { value = item; }
	void setLeft(BSTnode* _left) { left = _left; }
	void setRight(BSTnode* _right) { right = _right; }
};

