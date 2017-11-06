#pragma once
//Transaction file for student -> class
// we are going to use vector to link classes to stud each class can have many students.

#ifndef stu_cla
#define stu_cla

#include<vector>
#include <string>
#include "student.h"
#include "klass.h"
#include "subjectscore.h"
#include "subject.h"
using namespace std;
#endif


class studcla { // this is a transaction class.
	vector<Student> stu;
	vector<Class> cla;
	vector<Subject> subby;
	vector<SubjectScore> subsco;

public:
	studcla();

	void addStudent(int stu_no, string full_name, char gend);
	void removeStudent();
	void viewStudent();
	void viewAllStudent();
	void modifyStudent();
};