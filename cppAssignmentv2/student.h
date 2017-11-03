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

	~Student(); //student deconstructor	

//DISABLED FOR NOW----------- to be used with vector for linking

	/*string getTotalScore() {
		return 0;
	}
	char getFinalGrade() {
		return 0;
	}*/
//--------------------------

	void addStudent(int stu_no, string full_name, char gend);
	void removeStudent(int stu_no);
	int getStudentNo();
	string getFullName();
	char getGender();
	void viewStudent(Student* Stud);
	void viewAllStudent();
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