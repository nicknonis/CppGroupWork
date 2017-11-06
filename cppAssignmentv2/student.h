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
	//vector<SubjectScore> subscore;

public:
	Student();
	Student(int stu_no) : studentno(stu_no) {
		studentno = stu_no;
		fullname = "A";
		gender = 'M';
	}
	Student(int stu_no, string f_name, char gen) {
		studentno = stu_no;
		fullname = f_name;
		gender = gen;
	}	
	~Student(); //student deconstructor	
	int getStudentNo();
	string getFullName();
	char getGender();

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