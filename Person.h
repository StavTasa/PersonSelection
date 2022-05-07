#pragma once
#include <string>

using namespace std;

class Person {
public:
	string fname;
	string lname;
	int id;
	Person(int _id, string _fname, string _lname) : id(_id), fname(_fname), lname(_lname) {};
};
