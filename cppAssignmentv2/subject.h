#pragma once

#ifndef subject
#define subject

#include <string>
using namespace std;
#endif

class Subject {
	int id;
	string name;
	char type;

public:
	int getid() {
		return id;
	}
	string getname() {
		return name;
	}
	char gettype() {
		return type;
	}
	void setid(int iden);
	void setname(string name);
	void settype(char type);
};