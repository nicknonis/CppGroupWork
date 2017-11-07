//-----------
//student/class transaction
//----------
#include "stu_cla.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

//using these to initialize my structs..
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;


bool file_exist(const char *fileName) {
	ifstream infile("student.txt");
	return infile.good();
}

/*studcla::studcla() { //this stuff is broken... regex maybe?

	string line;
	string s_stu_no;
	int stu_no;
	string f_name;
	char gen;

	char fileName1[] = "student.txt";
	char fileName2[] = "class.txt";



	if (file_exist(fileName1) && file_exist(fileName2)) {
		
		ifstream studfile("student.txt");
		ifstream classfile("class.txt");
		//These would be good but I cant get it to split the file...
		//copy(istream_iterator<string>(studfile), istream_iterator<string>(), back_inserter(stu));
		//copy(istream_iterator<string>(classfile), istream_iterator<string>(), back_inserter(cla));
		while (getline(studfile, line)) {
			stringstream stude(line);
			while (getline(stude, s_stu_no, ',')) {
				stu.push_back(s_stu_no);
				getline(stude, f_name, ',');
				stude >> gen;

				stu_no = stoi(s_stu_no);

				
			}
		}
		studfile.close();
		classfile.close();
		
	}
}
*/



void studcla::addStudent(int stu_no, std::string full_name, char gend) { //add file manipulators here to write straight away...
	ofstream outfile("student.txt", ios_base::app);
	outfile << stu_no << "," << full_name << "," << gend << "\n";
	outfile.close();
	stu.push_back(new Student(stu_no,full_name,gend));
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
