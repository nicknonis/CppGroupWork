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

