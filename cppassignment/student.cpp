//-----------
//student
//----------
#include "student.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

Student::Student(int stu_no) : studentno(stu_no) {
	studentno = stu_no;
	fullname = "";
	gender = 'M';
}

Student::~Student() {
	cout << "Deconstructing student"<<endl;
}

void Student::addStudent(int stu_no,string full_name,char gend) {
	studentno = stu_no;
	fullname = full_name;
	gender = gend;
}
void removeStudent() {

}
void modifyStudent() {

}
void viewStudent() { //display all students

}
//searchstudent
void removeSearchedStudent() {

}
void modifySearchedStudent() {

}
void viewSearchedStudent() { //display specific student

}