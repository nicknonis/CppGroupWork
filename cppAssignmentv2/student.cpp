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

void Student::addStudent(int stu_no, std::string full_name, char gend) { //add file manipulators here to write straight away...
	ofstream outfile("student.txt", ios_base::app);
	outfile << stu_no << "," << full_name << "," << gend << "\n";
	outfile.close();
}


void Student::removeStudent(int stu_no) {
	
}

void modifyStudent() {

}


bool file_exist(const char *fileName) {
	ifstream infile("student.txt");
	return infile.good();
}

void Student::viewStudent(Student* Stud) {
	cout << "Student No: " << Stud->getStudentNo() 
		<< "\nFull Name: " << Stud->getFullName() 
		<< "\nGender: " << Stud->getGender() 
		<< endl;
	
}

void Student::viewAllStudent() {
	string line;
	string s_stu_no;
	int stu_no;
	string f_name;
	char gen;
	char fileName[] = "student.txt";

	if (file_exist(fileName)) {
		ifstream infile("student.txt");
		cout << setw(30) << left << "Student Number" << setw(50) << left << "Student Name" << setw(12) << left << "Gender" << endl;
		while (getline(infile, line)) {
			stringstream stu(line);
			while (getline(stu, s_stu_no, ',')) {
				getline(stu, f_name, ',');
				stu >> gen;

				stu_no = stoi(s_stu_no);

				cout << setw(30) << left << stu_no;
				cout << setw(50) << left << f_name;
				cout << setw(12) << left << gen << endl;
			}
		}
	}
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
void viewSearchedStudent() { //display specific student (can be switched to overloaded viewStudent())

}