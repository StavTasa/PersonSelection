#include "BSTclass.h"

BSTclass::~BSTclass()
{
	Free(root);
}

//should compare by person id
void BSTclass::Insert(Person * item)
{
	if (Find(item->id))
	{
		cout << "invalid input" << endl;
		exit(1);
	}
        
    BSTnode* temp = root;
    BSTnode* parent = nullptr;
    BSTnode* newnode;

    while (temp != nullptr)
    {
        parent = temp;
		if (item->id < temp->getValue()->id)
		{
			temp = temp->getLeft();
			NumComp++;
		}
        else
            temp = temp->getRight();
    }

    newnode = new BSTnode(item);


	if (parent == nullptr)
	{
		root = newnode;
		NumComp += 1;
	}
        
	else if (item->id < parent->getValue()->id)
	{
		parent->setLeft(newnode);
		NumComp += 2;
	}
	else
	{
		NumComp += 2;
		parent->setRight(newnode);
	}
        
}

void BSTclass::Free(BSTnode* root)
{
	if (root == NULL)
		return ;

	Free(root->getLeft());
	Free(root->getRight());
	delete root;
}



BSTnode * BSTclass::getRoot()
{
	return root;
}

BSTnode* BSTclass::findMin(BSTnode* node)
{
    BSTnode* current = node;

    //find the leftest leaf
    while (current && current->getLeft() != NULL)
        current = current->getLeft();

    return current;
}


BSTnode* BSTclass::Find(int id)
{
	BSTnode* temp = root;
	while (temp != nullptr)
	{
		if (id == (temp->getValue())->id)
			return temp;
		else if (id < (temp->getValue())->id)
			temp = temp->getLeft();
		else
			temp = temp->getRight();
	}
	return nullptr;
}


BSTnode* BSTclass::Delete(BSTnode* root, int key)
{
	if (root == NULL)
		return root;

	if (key < (root->getValue())->id)
		root->setLeft(Delete(root->getLeft(), key));

	else if (key > (root->getValue())->id)
		root->setRight(Delete(root->getRight(), key));

	else
	{
		if (root->getLeft() == NULL && root->getRight() == NULL)
			return NULL;

		else if (root->getLeft() == NULL)
		{
			BSTnode* temp = root->getRight();
			free(root);
			return temp;
		}

		else if (root->getRight() == NULL)
		{
			BSTnode* temp = root->getRight();
			free(root);
			return temp;
		}

		//for node with 2 children, replace with minimum from right side
		BSTnode* temp = findMin(root->getRight());
		root->setValue(temp->getValue());
		root->setRight(Delete(root->getRight(), temp->getValue()->id));
	}
	return root;
}