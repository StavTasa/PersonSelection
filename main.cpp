/* This program will find the Kth element out of an array of persons,
input:
	* RNG -> number for the randomization
	* n -> Number of persons
	* n persons -> each line is triplets of id number, first name, last name which indicate a person
output: the Kth person based on id number
*/
#include <iostream>
#include <string>
#include "time.h"
#include "Heap.h"
#include "Person.h"
#include "BSTclass.h"

using namespace std;

// throw error msg and exit
void raiseError(const char * msg)
{
	cout << msg << endl;
	exit(1);
}

Person **copyPersons(Person**p, int n)
{
	Person ** p2 = new Person*[n];
	for (int i = 0; i < n; i++)
	{
		p2[i] = p[i];
	}
	return p2;
}

// get input of persons from users
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
	Person ** personsCopy = copyPersons(persons, n);

	Heap personHeap = Heap(personsCopy, n, NumComp);

	Person * p = nullptr;

	// delete k-1 times to find the K one
	for (int i = 0; i < k; i++)
		p = personHeap.DeleteMin();

	return *p;
}

BSTnode* kthSmallestByBST(BSTnode* root, int& k, int &count)
{
	// loop over BST inorder to find the K Smallest number
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

int Partition(Person *persons[], int left, int right, int &NumComp)
{
	int randNum = left + rand() % (right - left);
	int pivot = persons[randNum]->id;
	int start = left;
	int end = right;
	int i;
	bool moved;

	// move the pivot to the beginging of the array
	swap(persons[start], persons[randNum]);
	left++;
	right--;
	// loop until left and right indexes collide
	while (left < right) {
		NumComp++;
		moved = false;
		// check if the element in the left/right index is in the right place
		if (persons[right]->id > pivot)
		{
			NumComp++;
			right--;
			moved = true;
		}
		if (persons[left]->id < pivot)
		{
			NumComp++;
			moved = true;
			left++;
		}

		// if none of them is not in the right place swap between them
		if (!moved)
			Swap(&persons[left], &persons[right]);
	}

	// find the right index for the pivot 
	for (i = start + 1; i < end; i++)
	{
		if (persons[i]->id > pivot)
		{
			NumComp++;
			break;
		}
	}
	Swap(&persons[i - 1], &persons[start]);

	return i - 1;
}

// using the selection algorithem with random pivot inorder to find the Kth element
const Person& RandSelection(Person *persons[], int left, int right, int k, int& NumComp)
{
	int pivot;
	int leftPart;

	// run partition
	pivot = Partition(persons, left, right, NumComp);
	leftPart = pivot - left + 1;

	// check if the amount of small elements equal to the K, if not check which array need tob be passed to the recurision
	if (k == leftPart)
	{
		NumComp++;
		return *persons[pivot];
	}
	if (k < leftPart)
	{
		NumComp += 2;
		return RandSelection(persons, left, pivot, k, NumComp);
	}
	else
	{
		NumComp += 2;
		return RandSelection(persons, pivot + 1, right, k - leftPart, NumComp);
	}
}

// Build the BST from an array of persons and find Kth one
const Person& BST(Person *persons[], int n, int k, int& NumComp)
{
	int count = 0;
	BSTclass* bst = new BSTclass(NumComp);

	for (int i = 0; i < n; i++)
		bst->Insert(persons[i]);

	Person * p = kthSmallestByBST(bst->getRoot(), k, count)->getValue();
	return *p;
}

void freePersons(Person** persons, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete(persons[i]);
	}
	delete(persons);
}

int main()
{
	int k, n, RNG;
	int BSTNumComp, HeapNumComp, SelectionNumComp;
	BSTNumComp = HeapNumComp = SelectionNumComp = 0;
	Person ** persons;
	cin >> RNG;
	cin >> n;
	srand(RNG);

	// check validation
	if (n < 1)
		raiseError("invalid input");

	persons = getPersons(n);
	cin >> k;

	// check validation
	if (k > n || k < 1)
		raiseError("invalid input");

	const Person pBST = BST(persons, n, k, BSTNumComp);
	const Person personSelection = RandSelection(persons, 0, n, k, SelectionNumComp);
	const Person pHeap = getTheKSizeByHeap(persons, n, k, HeapNumComp);

	cout << "RandSelection: " << personSelection.id << ' ' << personSelection.fname << ' ' << personSelection.lname << SelectionNumComp << " comparisons" << endl;
	cout << "selectHeap: " << pHeap.id << ' ' << pHeap.fname << ' ' << pHeap.lname << HeapNumComp << " comparisons" << endl;
	cout << "BST: " << pBST.id << ' ' << pBST.fname << ' ' << pBST.lname << BSTNumComp << " comparisons" << endl;

	freePersons(persons, n);
}