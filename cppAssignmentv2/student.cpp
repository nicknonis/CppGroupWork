//-----------
//student
//----------
#include "student.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;




Student::~Student() {
	//cout << "Deconstructing student" << endl; //the echo here is not necessary (debugging purposes only)
}

void Student::addStudent(int stu_no, std::string full_name, char gend) { //add file manipulators here to write straight away...
	studentno = stu_no;
	fullname = full_name;
	gender = gend;
}
void Student::removeStudent(int stu_no) {
	
}
void modifyStudent() {

}

void Student::viewStudent(Student Stud) {
	cout << "Student No: " << Stud.getStudentNo() << "\nFull Name: " << Stud.getFullName() << "\nGender: " << Stud.getGender() << endl;
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

//searchstudent
void removeSearchedStudent() {

}
void modifySearchedStudent() {

}
void viewSearchedStudent() { //display specific student

}