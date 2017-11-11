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

bool Student::file_exist(const char *fileName) {
	ifstream infile("student.txt");
	return infile.good();
}

Student::Student() {
	char fileName[] = "student.txt";
	if (file_exist(fileName)) {
		ifstream infile(fileName);
		string line;
		string s_id, s_name,s_c_id;
		char gend;


		while (getline(infile, line)) {
			stringstream stu(line);
			while (getline(stu, s_id, ',')) {
				getline(stu, s_name, ',');
				getline(stu, s_c_id, ',');
				stu >> gend;
				if (strstr(fullname.c_str(), s_name.c_str()) == nullptr)
					return;

				studentno = stoi(s_id);
				fullname = s_name;
				gender = gend;
				classid = stoi(s_c_id);
				stud.push_back(new Student(studentno,fullname,gender,classid));
			}
		}
		infile.close();
	}
	else {
		studentno = 0;
		fullname = " ";
		gender = 'n';
		classid = 0;
	}
}

Student::Student(int stu_no, string f_name, int class_id, char gen ) {
	studentno = stu_no;
	fullname = f_name;
	classid = class_id;
	gender = gen;

}

Student::~Student() {
	//cout << "Deconstructing student" << endl; //the echo here is not necessary (debugging purposes only)
}


void Student::addStudent(vector<Student*> stud) { //add file manipulators here to write straight away...
	char stream;

	cout << "\nEnter Student Number: ";
	cin >> studentno;
	cout << "\nEnter Student Name: ";
	cin.ignore();
	getline(cin, fullname);
	do {
		cout << "\nEnter Gender [M/F]: ";
		cin >> gender;
	} while (gender != 'M' && gender != 'F'); //This condition may need refinement..
	do {
		cout << "\nSelect stream[No Stream = n/Science = s/Art = a] : ";
		cin >> stream;
	} while (stream != 'n' && stream != 's' &&stream != 'a');

	cout << "\nEnter Class ID: ";
	cin >> classid;
	cout << endl;
	if (stream == 'n') {
		stud.push_back(new Student(studentno, fullname, classid, gender));
	}
	else if (stream == 's') {
		stud.push_back(new ScienceStudent(studentno, fullname, classid, gender));
	}
	else if (stream == 'a') {
		stud.push_back(new ArtStudent(studentno, fullname, classid, gender));
	}
	


	ofstream outfile("student.txt", ios_base::app);
	try {
		outfile << studentno << "," << fullname << "," << classid << "," << gender << "\n";
	}	
	catch (...) {
		cout << "Unexpected error occured!\n";
	}
	outfile.close();
	
}


void Student::removeStudent() { // This needs refinement. It works but not exactly how I want it to.
	string delLine, line;
	ifstream infile;
	infile.open("student.txt");
	ofstream temp;
	temp.open("temp.txt");
	cout << "Enter Student Number or Name: ";
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
	string modLine, line;
	ifstream infile;
	infile.open("student.txt");
	ofstream temp;
	temp.open("temp.txt");
	cout << "\nEnter the Exact Student ID or Student Name to modify[-1 to cancel]: ";
	cin >> modLine;
	if (modLine == "-1")
		return;

	while (getline(infile, line)) {
		if (strstr(line.c_str(), modLine.c_str()) == nullptr) {
			temp << line << endl;
		}
	}

	temp.close();
	infile.close();
	remove("student.txt");
	rename("temp.txt", "student.txt");

	int s_id,class_id;
	string s_name;
	char gend;

	cout << "Enter new Student ID: ";
	cin >> s_id;
	cout << "\nEnter new Student Name: ";
	cin.ignore();
	getline(cin, s_name);
	cout << "\nEnter new Class ID: ";
	cin >> class_id;
	do{
	cout << "\nEnter new Gender [M/F]: ";
	cin >> gend;
	} while (gend != 'M' && gend != 'F');
	cout << endl;

	ofstream outfile("student.txt", ios_base::app);
	outfile << s_id << "," << s_name << "," << class_id << "," << gend << "\n";
	outfile.close();
}


void Student::searchStudent() { //Working! use student ID and it returns the value
	string search, line;
	string s_stu_no, s_class_id;
	int stu_no, class_id;
	string f_name, gen_s;
	char gen;
	char fileName[] = "student.txt";

	ifstream infile(fileName);

	cin.ignore();
	cout << "Enter a Student Number to search: ";
	getline(cin, search);
	if (file_exist(fileName)) {
		ifstream infile(fileName);
		cout << setw(30) << left << "Student Number" << setw(40) << left << "Student Name" << setw(12) << left << "Class ID" << setw(12) << left << "Gender" << endl;
		string candidate;

		while (getline(infile, line)) {
			stringstream stu(line);
			while (getline(stu, s_stu_no, ',')) {

				getline(stu, f_name, ',');
				getline(stu, s_class_id, ',');
				stu >> gen;
				stu_no = stoi(s_stu_no);
				class_id = stoi(s_class_id);
				if (search == s_stu_no) {
					cout << setw(30) << left << stu_no;
					cout << setw(40) << left << f_name;
					cout << setw(12) << left << class_id;
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
	int stu_no,class_id;
	string f_name, s_class_id;
	char gen;
	char fileName[] = "student.txt";

	if (file_exist(fileName)) {
		ifstream infile(fileName);
		cout << setw(30) << left << "Student Number" << setw(40) << left << "Student Name" << setw(12) << left << "Class ID" << setw(12) << left << "Gender" << endl;
		try {
			while (getline(infile, line)) {
				stringstream stu(line);
				while (getline(stu, s_stu_no, ',')) {
					getline(stu, f_name, ',');
					getline(stu, s_class_id, ',');
					stu >> gen;

					stu_no = stoi(s_stu_no);
					class_id = stoi(s_class_id);
					cout << setw(30) << left << stu_no;
					cout << setw(40) << left << f_name;
					cout << setw(12) << left << class_id;
					cout << setw(12) << left << gen << endl;
				}
			}
		}
		catch (...) {
			cout << "A problem occured while opening file.\n";
		}
		
		
		infile.close();
	}

}

string Student::getTotalScore() {
	return 0;
}

char Student::getFinalGrade() {// any core subject <60
	return 0;
}

char ScienceStudent::getFinalGrade() {// any core subject <60 && 2 selective <60
	return 0;
}
char ArtStudent::getFinalGrade() { // any core subject <60 && 3 selective <60
	return 0;
}