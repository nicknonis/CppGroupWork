#pragma once
//student classes
#ifndef student
#define student

#include <string>
using namespace std;
#endif


class Student {
	int studentno;
	string fullname;
	char gender;
	int classid;

public:
	Student() {}
	Student(int stu_no, string f_name, char gen, int class_id);
	~Student(); //student deconstructor	
	int getStudentNo();
	string getFullName();
	char getGender();
	void addStudent(int stu_no, string full_name, char gend, int class_id);
	void removeStudent();
	void viewStudent();
	void viewAllStudent();
	void modifyStudent();
//DISABLED FOR NOW----------- to be used with vector for linking (link to subject****)
/*
virtual string getTotalScore() {
return score;
}
virtual char getFinalGrade() {
return grade;
}
*/
//--------------------------

};

// sub student classes -- need to get some form of loading to get some students here...

class ScienceStudent : public Student {
public:
	char getFinalGrade() {
		return 0;
	}
};



class ArtStudent : public Student {
public:
	char getFinalGrade() {
		return 0;
	}
};