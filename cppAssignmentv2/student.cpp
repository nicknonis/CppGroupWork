//-----------
//student
//----------
#include "student.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

bool file_exist(const char *fileName) {
	ifstream infile("student.txt");
	return infile.good();
}


Student::Student(int stu_no, string f_name, char gen) {
	studentno = stu_no;
	fullname = f_name;
	gender = gen;
	ofstream outfile("student.txt", ios_base::app);
	outfile << stu_no << "," << f_name << "," << gen << "\n";
	outfile.close();
}

Student::~Student() {
	//cout << "Deconstructing student" << endl; //the echo here is not necessary (debugging purposes only)
}


int Student::getStudentNo() { 
	return studentno;
}
string Student::getFullName() {
	return fullname;
}
char Student::getGender() { 
	return gender;
}

