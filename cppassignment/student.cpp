//-----------
//student
//----------
#include "student.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>

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

	while (!(cin >> studentno)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter whole numbers only...\nEnter Student Number: " ;
	}
	
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
	while (!(cin >> s_id)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter whole numbers only...\nEnter New Student ID: ";
	}
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

void Student::searchStudent(Student* cur_new) { //Working! use student ID and it returns the value
	string search, line;
	string s_stu_no, s_class_id;
	int stu_no, class_id;
	string f_name, gen_s;
	char gen; 
	char strea;
	char fileName[] = "student.txt";

	ifstream infile(fileName);

	cin.ignore();
	cout << "Enter a Student Number to search: ";
	getline(cin, search);
	if (file_exist(fileName)) {
		ifstream infile_student(fileName);
		string candidate;

		while (getline(infile_student, line)) {
			stringstream stu(line);
			while (getline(stu, s_stu_no, ',')) {

				getline(stu, f_name, ',');
				getline(stu, s_class_id, ',');
				stu >> gen;
				stu_no = stoi(s_stu_no);
				class_id = stoi(s_class_id);
				if (search == s_stu_no) {
					cout << "\nStudent Number: " << stu_no << endl;
					cout << "Student Name: " << f_name << endl;
					cout << "Gender: " << gen << endl;
					cout << "Class ID: " << class_id << endl;
				}
			}
		}
		infile_student.close();
	}
	if (file_exist("class.txt")) {
		
		string class_name, year_form;
		ifstream infile_class("class.txt");
		string candidate;

		while (getline(infile_class, line)) {
			stringstream stu(line);
			while (getline(stu, s_class_id, ',')) {

				getline(stu, class_name, ',');
				getline(stu, year_form, ',');
				stu >> strea;

				if (class_id == stoi(s_class_id)) {
					cout << "Class Name: " << class_name << endl;
					cout << "Year Form: " << year_form << endl;
					cout << "Stream: " << strea << endl;
				}
			}
		}
		infile_class.close();
	}
	if (file_exist("subjectScore.txt")) {
		ifstream infile_subjectScore("subjectScore.txt");
		string candidate;
		string sub_sco_stud_no, sub_sco_subid, sub_sco_score, sub_sco_scoreid;
		char sub_sco_type;
		cout << setw(15) << left << "Subject ID" << setw(15) << left << "Score" << endl;
		while (getline(infile_subjectScore, line)) {
			stringstream stu(line);
			while (getline(stu, sub_sco_stud_no, ',')) {
				getline(stu, sub_sco_subid, ',');
				getline(stu, sub_sco_score, ',');
				getline(stu, sub_sco_scoreid, ',');
				stu >> sub_sco_type;

				if (search == sub_sco_stud_no) {
					cout << setw(15) << left << sub_sco_subid ;
					cout << setw(15) << left << sub_sco_score << endl;
				}
			}
		}
		infile_subjectScore.close();
		
		cout << "\nTotal Score: " << getTotalScore(search) <<endl;



		if (strea == 'S') {
			Student* cur_new = &ScienceStudent();
		}
		else if (strea == 'A') {
			Student* cur_new = &ArtStudent();
		}

		cout << "Final Grade: " << cur_new->getFinalGrade(search) << endl;
		cout << "If Final Grade is 'N' the student could be missing classes,subjects or scores " <<  endl;
	}
	
}


string Student::getTotalScore(string search) {
	double totscore=0;
	string line;
	if (file_exist("subjectScore.txt")) {
		ifstream infile_subjectScore("subjectScore.txt");
		string candidate;
		string sub_sco_stud_no, sub_sco_subid, sub_sco_score, sub_sco_scoreid;
		char sub_sco_type;
		while (getline(infile_subjectScore, line)) {
			stringstream stu(line);
			while (getline(stu, sub_sco_stud_no, ',')) {
				getline(stu, sub_sco_subid, ',');
				getline(stu, sub_sco_score, ',');
				getline(stu, sub_sco_scoreid, ',');
				stu >> sub_sco_type;

				if (search == sub_sco_stud_no) {
					totscore += stod(sub_sco_score);
				}
			}
		}
		infile_subjectScore.close();
	}



	ostringstream totsco;
	totsco << totscore;
	string totsco_send = totsco.str();
		return totsco_send;
}


char Student::getFinalGrade(string search) {// any core subject <60
	char grade = 'N';
	double totscore = 0;
	string line;
	int ctr = 0;
	if (file_exist("subjectScore.txt")) {
		ifstream infile_subjectScore("subjectScore.txt");
		string candidate;
		string sub_sco_stud_no, sub_sco_subid, sub_sco_score, sub_sco_scoreid;
		char sub_sco_type;
		while (getline(infile_subjectScore, line)) {
			stringstream stu(line);
			while (getline(stu, sub_sco_stud_no, ',')) {
				getline(stu, sub_sco_subid, ',');
				getline(stu, sub_sco_score, ',');
				getline(stu, sub_sco_scoreid, ',');
				stu >> sub_sco_type;

				if (search == sub_sco_stud_no) {
					if (stod(sub_sco_score) < 60) {
						infile_subjectScore.close();
						grade = 'F';
						return grade;
					}
					totscore += stod(sub_sco_score);
					ctr++;
				}
			}
		}
		infile_subjectScore.close();
	}

	double finsco = totscore / ctr;
	if (finsco >= 90 && finsco <= 100)
		grade = 'A';
	else if (finsco >= 80 && finsco <= 89)
		grade = 'B';
	else if (finsco >= 70 && finsco <= 79)
		grade = 'C';
	else if (finsco >= 60 && finsco <= 69)
		grade = 'D';
	else if (finsco < 60 && finsco >= 0)
		grade = 'F';

	return grade;
}
char Student::subjectfinder(string sub_sco_subid) {
	string search, line,sub_id,sub_name;
	char type;
	
	char fileName[] = "subject.txt";

	ifstream infile(fileName);
	if (file_exist(fileName)) {
		ifstream infile_student(fileName);
		string candidate;

		while (getline(infile_student, line)) {
			stringstream stu(line);
			while (getline(stu, sub_id, ',')) {
				getline(stu, sub_name, ',');
				stu >> type;
				
				if (sub_sco_subid == sub_id)
					break;
				
			}
		}
		infile_student.close();
	}
	return type;
}

char ScienceStudent::getFinalGrade(string search) {// any core subject <60 && 2 selective <60
	char grade = 'N';
	double totscore = 0;
	string line;
	int ctr = 0;
	int fails = 0;
	if (file_exist("subjectScore.txt")) {
		ifstream infile_subjectScore("subjectScore.txt");
		string candidate;
		string sub_sco_stud_no, sub_sco_subid, sub_sco_score, sub_sco_scoreid;
		char sub_sco_type;
		while (getline(infile_subjectScore, line)) {
			stringstream stu(line);
			while (getline(stu, sub_sco_stud_no, ',')) {
				getline(stu, sub_sco_subid, ',');
				getline(stu, sub_sco_score, ',');
				getline(stu, sub_sco_scoreid, ',');
				stu >> sub_sco_type;

				if (search == sub_sco_stud_no) {

					if (subjectfinder(sub_sco_subid) == 'c' && stod(sub_sco_score) < 60) {
						infile_subjectScore.close();
						grade = 'F';
						return grade;
					}
					else if (subjectfinder(sub_sco_subid) == 'e' && stod(sub_sco_score) < 60) {
						fails++;
					}
					totscore += stod(sub_sco_score);
					ctr++;
				}
			}
		}
		infile_subjectScore.close();
	}

	double finsco = totscore / ctr;
	if (fails >= 2)
		grade = 'F';
	else if (finsco >= 90 && finsco <= 100)
		grade = 'A';
	else if (finsco >= 80 && finsco <= 89)
		grade = 'B';
	else if (finsco >= 70 && finsco <= 79)
		grade = 'C';
	else if (finsco >= 60 && finsco <= 69)
		grade = 'D';
	else if (finsco < 60 && finsco >= 0)
		grade = 'F';

	return grade;
}
char ArtStudent::getFinalGrade(string search) { // any core subject <60 && 3 selective <60
	char grade = 'N';
	double totscore = 0;
	string line;
	int ctr = 0;
	int fails = 0;
	if (file_exist("subjectScore.txt")) {
		ifstream infile_subjectScore("subjectScore.txt");
		string candidate;
		string sub_sco_stud_no, sub_sco_subid, sub_sco_score, sub_sco_scoreid;
		char sub_sco_type;
		while (getline(infile_subjectScore, line)) {
			stringstream stu(line);
			while (getline(stu, sub_sco_stud_no, ',')) {
				getline(stu, sub_sco_subid, ',');
				getline(stu, sub_sco_score, ',');
				getline(stu, sub_sco_scoreid, ',');
				stu >> sub_sco_type;

				if (search == sub_sco_stud_no) {

					if (subjectfinder(sub_sco_subid) == 'c' && stod(sub_sco_score) < 60) {
						infile_subjectScore.close();
						grade = 'F';
						return grade;
					}
					else if (subjectfinder(sub_sco_subid) == 'e' && stod(sub_sco_score) < 60) {
						fails++;
					}
					totscore += stod(sub_sco_score);
					ctr++;
				}
			}
		}
		infile_subjectScore.close();
	}

	double finsco = totscore / ctr;
	if (fails >= 3)
		grade = 'F';
	else if (finsco >= 90 && finsco <= 100)
		grade = 'A';
	else if (finsco >= 80 && finsco <= 89)
		grade = 'B';
	else if (finsco >= 70 && finsco <= 79)
		grade = 'C';
	else if (finsco >= 60 && finsco <= 69)
		grade = 'D';
	else if (finsco < 60 && finsco >= 0)
		grade = 'F';

	return grade;
}

