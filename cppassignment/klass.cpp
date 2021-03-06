#include "klass.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>

bool Class::file_exist(const char *fileName) {
	ifstream infile("class.txt");
	return infile.good();
}


Class::Class() { //initialize class and vector if file exist else set default values.
	char fileName[] = "class.txt";
	if (file_exist(fileName)) {
		ifstream infile(fileName);
		string line;
		string s_c_id, c_name,y_form;
		char y_grade;


		while (getline(infile, line)) {
			stringstream claf(line);
			while (getline(claf, s_c_id, ',')) {
				getline(claf, c_name, ',');
				getline(claf, y_form, ',');
				claf >> y_grade;
				if (strstr(c_name.c_str(), classname.c_str()) == nullptr)
					return;

				classid = stoi(s_c_id);
				classname = c_name;
				yearform = stoi(y_form);
				yeargrade = y_grade;
				cla.push_back(new Class(classid, classname, yearform,yeargrade));
			}
		}
		infile.close();
	}
	else {
		classid = 0;
		classname = "";
		yearform = 0;
		yeargrade = 'n';
	}
}

Class::Class(int c_id, string c_name, int y_form, char y_grade) {

	classid = c_id;
	classname = c_name;
	yearform = y_form;
	yeargrade = y_grade;

	
}

void Class::displayClass() {
	string line;
	string s_c_id, c_name, s_y_form;
	char y_grade;
	char fileName[] = "class.txt";
	int c_id,y_form;

	if (file_exist(fileName)) {
		ifstream infile(fileName);
		cout << "\n" << setw(15) << left << "Class ID" << setw(25) << left << "Class Name" << setw(12) << left << "Year Form" << setw(12) << left << "Year Grade" << endl;
		while (getline(infile, line)) {
			stringstream claf(line);
			while (getline(claf, s_c_id, ',')) {
				getline(claf, c_name, ',');
				getline(claf, s_y_form, ',');
				claf >> y_grade;

				c_id = stoi(s_c_id);
				y_form = stoi(s_y_form);

				cout << setw(15) << left << c_id;
				cout << setw(25) << left << c_name;
				cout << setw(12) << left << y_form;
				cout << setw(12) << left << y_grade << endl;

			}
		}
		infile.close();
	}
	cout << endl;
}

void Class::addClass(vector<Class*> sub) {
	int c_id,y_year;
	string c_name;
	char y_grade;

	cout << "\nEnter Class ID: ";
	while (!(cin >> c_id)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter whole numbers only...\nEnter Class ID: ";
	}
	cout << "\nEnter Class Name: ";
	cin.ignore();
	getline(cin, c_name);
	do {
		cout << "\nEnter Year Form [1/2/3/4/5]: ";
		while (!(cin >>y_year)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter whole numbers only...\nEnter Year Form[1/2/3/4/5]: ";
		}
	} while (y_year != 1 && y_year != 2 && y_year != 3 && y_year != 4 && y_year != 5);
	if (y_year == 1 || y_year == 2 || y_year == 3)
		y_grade = 'L';
	else {
		do {
			cout << "\nSelect Stream [S/A]: ";
			cin >> y_grade;
		} while (y_grade != 'S' && y_grade != 'A');
	}
	cout << endl;

	ofstream outfile("class.txt", ios_base::app);
	outfile << c_id<< "," << c_name << "," << y_year << "," << y_grade << "\n";
	outfile.close();

	cla.push_back(new Class(c_id, c_name, y_year, y_grade));
}

void Class::removeClass() { // This needs refinement.
	string delLine, line;
	ifstream infile;
	infile.open("class.txt");
	ofstream temp;
	temp.open("temp.txt");
	cout << "\nEnter Class ID, Class Name to remove class[-1 to cancel]: ";
	cin >> delLine;
	if (delLine == "-1")
		return;

	while (getline(infile, line)) {
		if (strstr(line.c_str(), delLine.c_str()) == nullptr) {
			temp << line << endl;
		}
	}

	temp.close();
	infile.close();
	remove("class.txt");
	rename("temp.txt", "class.txt");

}


void Class::modifyClass(vector<Class*> cla) { // need to add vector modifer too...
	string modLine, line;
	ifstream infile;
	infile.open("class.txt");
	ofstream temp;
	temp.open("temp.txt");
	cout << "\nEnter the Exact Class ID modify[-1 to cancel]: ";
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
	remove("class.txt");
	rename("temp.txt", "class.txt");

	int c_id, y_year;
	string c_name;
	char y_grade;

	cout << "\nEnter new Class ID: ";
	while (!(cin >> c_id)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter whole numbers only...\nEnter new Class ID: ";
	}
	cout << "\nEnter new Class Name: ";
	cin.ignore();
	getline(cin, c_name);
	do {
		cout << "\nEnter new Year Form [1/2/3/4/5]: ";
		while (!(cin >> y_year)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter whole numbers only...\nEnter new Year Form[1/2/3/4/5]: ";
		}
	} while (y_year != 1 && y_year != 2 && y_year != 3 && y_year != 4 && y_year != 5);
	if (y_year == 1 || y_year == 2 || y_year == 3)
		y_grade = 'L';
	else {
		do {
			cout << "\nSelect Stream [S/A]: ";
			cin >> y_grade;
		} while (y_grade != 'S' && y_grade != 'A');
	}
	cout << endl;

	ofstream outfile("class.txt", ios_base::app);
	outfile << c_id << "," << c_name << "," << y_year << "," << y_grade << "\n";
	outfile.close();
}

void Class::searchClass(Class* cur_new) { 
	string search, line;

	string s_class_id, s_class_name, s_class_yearform;
	char class_stream;
	char fileName[] = "class.txt";

	ifstream infile(fileName);

	cin.ignore();
	cout << "\nEnter a Class ID to search: ";
	getline(cin, search);
	if (file_exist(fileName)) {
		ifstream infile_class(fileName);
		string candidate;

		while (getline(infile_class, line)) {
			stringstream stu(line);
			while (getline(stu, s_class_id, ',')) {

				getline(stu, s_class_name, ',');
				getline(stu, s_class_yearform, ',');
				stu >> class_stream;

				if (search == s_class_id) {
					cout << "\nClass Name: " << s_class_name << endl;
					cout << "Class Year Form: " << s_class_yearform << endl;
					getStudents(s_class_id);

				}
			}
		}
		infile_class.close();
	}
}

void Class::getStudents(string search) {
//	cout << "\nSEARCHING STUDENTS\n" << endl;//debug purpose
	string line;
	string s_stu_no, s_class_id;
	string f_name, gen_s;
	char gen;
	char fileName[] = "student.txt";

	ifstream infile(fileName);

	if (file_exist(fileName)) {
		ifstream infile_student(fileName);
		string candidate;

		while (getline(infile_student, line)) {
			stringstream stu(line);
			while (getline(stu, s_stu_no, ',')) {

				getline(stu, f_name, ',');
				getline(stu, s_class_id, ',');
				stu >> gen;
				if (s_class_id == search) {
					cout << "\nStudent Name: " << f_name << endl;
					getScore(s_stu_no);
				}
			}
		}
		infile_student.close();
	}
}

void Class::getScore(string search) {
//	cout << "\nSEARCHING SCORE\n" << endl; //debug
	string line;
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
					cout << setw(15) << left << sub_sco_subid;
					cout << setw(15) << left << sub_sco_score << endl;
				}
			}
		}
		infile_subjectScore.close();
	}
}
