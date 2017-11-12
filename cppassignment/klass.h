#ifndef class_h
#define class_h
#include <string>
#include <vector>
using namespace std;
#endif

class Class {
	int classid;
	string classname;
	int yearform;
	char yeargrade; // lower = L, upper science = S, upper art = A

	vector<Class*> cla;

public:
	Class();
	Class(int c_id, string c_name, int y_form, char y_grade);

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
	void setclassid(int c_id) {
		classid = c_id;
	}
	void setclassname(string c_name) {
		classname = c_name;
	}
	void setyearform(int y_form) {
		yearform = y_form;
	}
	void setyeargrade(char y_grade) {
		yeargrade = y_grade;
	}

	void addClass(vector<Class*> cla);
	void removeClass();
	void modifyClass(vector<Class*> cla);
	void displayClass();
	bool file_exist(const char *fileName);

	void searchClass(Class* classa);
	void getStudents(string search);
	void getScore(string search);
};