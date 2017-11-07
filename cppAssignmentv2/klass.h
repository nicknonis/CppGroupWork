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
	Class(){}
	Class(int cla_id, string c_name,int y_form, char y_grade) {
		classid = cla_id;
		classname = c_name;
		yearform = y_form;
		yeargrade = y_grade;
	}
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