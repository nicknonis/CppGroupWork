#pragma once
#ifndef klass
#define klass

#include <string>
using namespace std;
#endif

class Class{
	int classid;
	string classname;
	int yearform; // form1 to 5
	char yeargrade; // Year Grade: Lower Secondary / Upper Secondary Science / Upper Secondary Art



public:
	int getclassid() {
		return classid;
	}
	string getclassname() {
		return classname;
	}
	int getyearform() {
		return yearform;
	}
	char getyeargrade() {
		return yeargrade;
	}

	void setclassid(int cid);
	void setclassname(string cn);
	void setyearform(int yf);
	void setyeargrade(char yg);

};