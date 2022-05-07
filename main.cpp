#include <iostream>
#include <string>
#include "time.h"
#include "Heap.h"
#include "Person.h"
#include "BSTclass.h"

using namespace std;

void raiseError(const char * msg)
{
	cout << msg << endl;
	exit(1);
}

Person ** getPersons(int n)
{
	int id;
	string fname, lname;
	Person **persons = new Person*[n];
	for (int i = 0; i < n; i++)
	{
		cin >> id;
		getline(cin, fname, ' ');
		getline(cin, lname, '\n');
		persons[i] = new Person(id, lname, fname);
	}

	return persons;
}
const Person getTheKSizeByHeap(Person **persons, int n, int k, int &NumComp)
{
	Heap personHeap = Heap(persons, n);

	Person * p = nullptr;
	for (int i = 0; i < k; i++)
		p = personHeap.DeleteMin();
	return *p;
}

BSTnode* kthSmallestByBST(BSTnode* root, int& k, int &count)
{
	if (root == NULL)
		return NULL;

	BSTnode* left = kthSmallestByBST(root->getLeft(), k, count);

	if (left != NULL)
		return left;

	count++;
	if (count == k)
		return root;

	return kthSmallestByBST(root->getRight(), k, count);
}

void Swap(Person **p1, Person **p2) {
	Person *temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int Partition(Person *persons[], int left, int right)
{
	srand(time(NULL));
	int randNum = left + rand() % (right - left);
	int pivot = persons[randNum]->id;
	int start = left;
	int end = right;
	// move the pivot to the beginging of the array
	swap(persons[start], persons[randNum]);
	left++;
	right--;
	bool moved;
	while (left < right) {
		moved = false;
		if (persons[right]->id > pivot)
		{
			right--;
			moved = true;
		}

		if (persons[left]->id < pivot)
		{
			moved = true;
			left++;
		}
		if (!moved)
			Swap(&persons[left], &persons[right]);
	}
	int i = start + 1;
	for (i = start + 1; i < end; i++)
	{
		if (persons[i]->id > pivot)
			break;
		
	}
	Swap(&persons[i - 1], &persons[start]);
	return i - 1;
}

const Person& RandSelection(Person *persons[], int left, int right, int k, int& NumComp)
{
	int pivot;
	int leftPart;

	pivot = Partition(persons, left, right);
	leftPart = pivot - left + 1;
	if (k == leftPart)
		return *persons[pivot];
	if (k < leftPart)
		return RandSelection(persons, left, pivot, k, NumComp);
	else
		return RandSelection(persons, pivot + 1, right, k - leftPart, NumComp);
}

const Person& BST(Person *persons[], int n, int k, int& NumComp)
{
	int count = 0;
	BSTclass* bst = new BSTclass();

	for (int i = 0; i < n; i++)
		bst->Insert(persons[i]);

	Person * p = kthSmallestByBST(bst->getRoot(), k, count)->getValue();
	return *p;
}

int main()
{
	int k, n;
	cin >> n;
	Person ** persons = getPersons(n);
	cin >> k;
	
	// check validation
	if (k > n)
	{
		raiseError("invalid input");
	}

	int numComp = 0;

	const Person pBST = BST(persons, n, k, numComp);
	const Person personSelection = RandSelection(persons, 0, n, k, numComp);
	const Person pHeap = getTheKSizeByHeap(persons, n, k, numComp);
	

	cout << "RandSelection: " << personSelection.fname << ' ' << personSelection.lname << endl;
	cout << "selectHeap: " << pHeap.fname << ' ' << pHeap.lname << endl;
	cout << "BST: " << pBST.fname << ' ' << pBST.lname << endl;
}