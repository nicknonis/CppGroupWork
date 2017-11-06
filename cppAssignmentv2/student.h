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


public:

	Student::Student(int stu_no) : studentno(stu_no) {
		studentno = stu_no;
		fullname = "A";
		gender = 'M';
	}
	Student::Student(int stu_no, string f_name, char gen) {
		studentno = stu_no;
		fullname = f_name;
		gender = gen;
	}


//DISABLED FOR NOW----------- to be used with vector for linking

	/*string getTotalScore() {
		return 0;
	}
	char getFinalGrade() {
		return 0;
	}*/
//--------------------------

	void addStudent(int stu_no, string full_name, char gend);
	void removeStudent();
	int getStudentNo();
	string getFullName();
	char getGender();
	void viewStudent();
	void viewAllStudent();
	~Student(); //student deconstructor	
};

// sub student classes

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