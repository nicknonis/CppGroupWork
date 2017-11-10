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


Student::Student(int stu_no, string f_name, char gen, int class_id) {
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


void Student::addStudent(int stu_no, std::string full_name, char gend, int class_id) { //add file manipulators here to write straight away...
	ofstream outfile("student.txt", ios_base::app);
	outfile << stu_no << "," << full_name << "," <<class_id << "," << gend << "\n";
	outfile.close();
	stu.push_back(new Student(stu_no, full_name, gend,class_id));
}


void Student::removeStudent() { // This needs refinement. It works but will cincai delete based on other criteria...
	string delLine, line;
	ifstream infile;
	infile.open("student.txt");
	ofstream temp;
	temp.open("temp.txt");
	cout << "Enter Student Number or Name, or Gender to remove all records of a specific gender: ";
	cin >> delLine;
	while (getline(infile, line)) {
		if (strstr(line.c_str(), delLine.c_str()) == nullptr) {
			temp << line << endl;
		}
	}
	temp.close();
	infile.close();
	remove("student.txt");
	rename("temp.txt", "student.txt");

}

void Student::modifyStudent() {
}


void Student::viewStudent() { //Working! use student ID and it returns the value
	string search, line;
	string s_stu_no, s_class_id;
	int stu_no,class_id;
	string f_name,gen_s;
	char gen;
	char fileName[] = "student.txt";

	ifstream infile(fileName);

	cin.ignore();
	cout << "Enter a Student Number to search: ";
	getline(cin, search);
	if (file_exist(fileName)) {
		ifstream infile(fileName);
		cout << setw(30) << left << "Student Number" << setw(50) << left << "Student Name" << setw(12) << left << "Gender" << endl;
		string candidate;

		while (getline(infile, line)) {
			stringstream stu(line);
			while (getline(stu, s_stu_no, ',')) {

				getline(stu, f_name, ',');
				getline(stu, s_class_id, ',');
				stu >> gen;
				stu_no = stoi(s_stu_no);
				if (search == s_stu_no) {
					cout << setw(30) << left << stu_no;
					cout << setw(50) << left << f_name;
					cout << setw(12) << left << gen << endl;

				}
			}
		}
		infile.close();
	}
}



void Student::viewAllStudent() {
	string line;
	string s_stu_no;
	int stu_no;
	string f_name,s_class_id;
	char gen;
	char fileName[] = "student.txt";

	if (file_exist(fileName)) {
		ifstream infile(fileName);
		cout << setw(30) << left << "Student Number" << setw(50) << left << "Student Name" << setw(12) << left << "Gender" << endl;
		while (getline(infile, line)) {
			stringstream stu(line);
			while (getline(stu, s_stu_no, ',')) {
				getline(stu, f_name, ',');
				getline(stu, s_class_id, ',');
				stu >> gen;

				stu_no = stoi(s_stu_no);

				cout << setw(30) << left << stu_no;
				cout << setw(50) << left << f_name;
				cout << setw(12) << left << gen << endl;
			}
		}
		infile.close();
	}

}