//-----------
//student/class transaction
//----------
#include "stu_cla.h"

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

studcla::studcla() {

}


void studcla::addStudent(int stu_no, std::string full_name, char gend) { //add file manipulators here to write straight away...
	ofstream outfile("student.txt", ios_base::app);
	outfile << stu_no << "," << full_name << "," << gend << "\n";
	outfile.close();
}


void studcla::removeStudent() { // This needs refinement. It works but will cincai delete based on other criteria...
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

void studcla::modifyStudent() {
}


void studcla::viewStudent() { //Working! use student ID and it returns the value
	string search, line;
	string s_stu_no;
	int stu_no;
	string f_name;
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



void studcla::viewAllStudent() {
	string line;
	string s_stu_no;
	int stu_no;
	string f_name;
	char gen;
	char fileName[] = "student.txt";

	if (file_exist(fileName)) {
		ifstream infile(fileName);
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
		infile.close();
	}

}