#include "BSTclass.h"


//should compare by person id
void BSTclass::Insert(Person * item)
{
    /*if (Find(item->id) != nullptr)
    {
		cout << "invalid input" << endl;
		exit(1);
    }*/
        
    BSTnode* temp = root;
    BSTnode* parent = nullptr;
    BSTnode* newnode;

    while (temp != nullptr)
    {
        parent = temp;
        if (item->id < temp->getValue()->id)
            temp = temp->getLeft();
        else
            temp = temp->getRight();
    }

    newnode = new BSTnode(item);

    if (parent == nullptr)
        root = newnode;

    else if (item->id < parent->getValue()->id)
        parent->setLeft(newnode);
    else
        parent->setRight(newnode);
}

/*
BSTnode* BSTclass::Delete(BSTnode* root, int key)
{
    if (root == NULL)
        return root;

    if (key < (root->getValue()).data)
        root->getLeft() = Delete(root->getLeft(), key);

    else if (key > root->data)
        root->getRight() = Delete(root->getRight(), key);

    else
    {
        if (root->getLeft() == NULL && root->getRight() == NULL)
            return NULL;

        else if (root->getLeft() == NULL)
        {
            BSTclass* temp = root->getRight();
            free(root);
            return temp;
        }

        else if (root->getRight() == NULL)
        {
            BSTclass* temp = root->getRight();
            free(root);
            return temp;
        }


        //for node with 2 children, replace with minimum from right side
        BSTclass* temp = findMin(root->getRight());
        root->data = temp->data;
        root->getRight() = Delete(root->getRight(), temp->data);
    }
    return root;
}*/

//BSTclass* BSTclass::Delete(BSTclass* root, int key)
//{
//    if (root == NULL)
//        return root;
//
//    if (key < root->data)
//        root->left = Delete(root->left, key);
//
//    else if (key > root->data)
//        root->right = Delete(root->right, key);
//
//    else
//    {
//        if (root->left == NULL && root->right == NULL)
//            return NULL;
//
//        else if (root->left == NULL)
//        {
//            BSTclass* temp = root->right;
//            free(root);
//            return temp;
//        }
//
//        else if (root->right == NULL)
//        {
//            BSTclass* temp = root->left;
//            free(root);
//            return temp;
//        }
//
//
//        //for node with 2 children, replace with minimum from right side
//        BSTclass* temp = findMin(root->right);
//        root->data = temp->data;
//        root->right = Delete(root->right, temp->data);
//    }
//    return root;
//}



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


BSTnode* BSTclass::Find(int k)
{
    /*BSTnode* temp = root;
    while (temp != nullptr)
    {
        if (k == (temp->value).key)
            return temp;
        else if (k < (temp->value).key)
            temp = temp->getLeft();
        else
            temp = temp->getRight();
    }*/
    return nullptr;
}


