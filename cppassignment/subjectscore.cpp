#include "subjectscore.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

bool subjectScore::file_exist(const char *fileName) {
	ifstream infile("student.txt");
	return infile.good();
}

subjectScore::subjectScore() {
	char fileName[] = "subjectScore.txt";
	if (file_exist(fileName)) {
		ifstream infile(fileName);
		string line;
		string student_id, subject_id, s_score,s_score_id;
		char stre;


		while (getline(infile, line)) {
			stringstream stu(line);
			while (getline(stu, student_id, ',')) {
				getline(stu, subject_id, ',');
				getline(stu, s_score, ',');
				getline(stu, s_score_id, ',');
				stu >> stre;
				if (stoi(student_id) == studentno && stream == stre)
					return;

				studentno = stoi(student_id);
				subjectid = stoi(subject_id);
				score = stod(s_score);
				stream = stre;
				scoreid = stoi(s_score_id);
				v_sco.push_back(new subjectScore(studentno, subjectid,score, stream,scoreid));
			}
		}
		infile.close();
	}
	else {
		studentno = 0;
		subjectid = 0;
		score = 0;
		stream = 'n';
		scoreid = 0;
	}
}
subjectScore::subjectScore(int stu_no, int sub_id, double sco, char strea, int sco_id) {
	studentno =stu_no;
	subjectid = sub_id;
	score = sco;
	stream = strea;
	scoreid = sco_id;
}

subjectScore::~subjectScore() {
	//cout << "Deconstructing student" << endl; //the echo here is not necessary (debugging purposes only)
}


void subjectScore::addScore(vector<subjectScore*> v_sco) { //add file manipulators here to write straight away...
	int f_year;


	do {
		cout << "\nEnter Year [1/2/3/4/5]: ";
		while (!(cin >> f_year)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter whole numbers only...\nEnter Year [1/2/3/4/5]: ";
		}
		if (f_year == 4 || f_year == 5) {
			do {
				cout << "\nEnter Stream [Art = A/Science = S]: ";
				cin >> stream;
			} while (stream != 'A' && stream != 'S');
		}
		else if (f_year == 1 || f_year == 2 || f_year == 3) {
			stream = 'N';
		}
	} while (f_year != 1 && f_year != 2 && f_year != 3 && f_year != 4 && f_year != 5);
	cout << endl;

	cout << "\nEnter Student Number: ";
	while (!(cin >> studentno)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter whole numbers only...\nEnter Student Number: ";
	}
	cout << "\nEnter Subject ID: ";
	while (!(cin >> subjectid)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter whole numbers only...\nSubject ID: ";
	}
	cout << "\nEnter Score ID: ";
		while (!(cin >> scoreid)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter whole numbers only...\nEnter Score ID: ";
	}
	cout << "\nEnter Score: ";
	cin >> score;

	ofstream outfile("subjectScore.txt", ios_base::app);
	try {
		outfile << studentno << "," << subjectid << "," << score << "," << scoreid << "," << stream << "\n";
	}
	catch (...) {
		cout << "Unexpected error occured!\n";
	}
	outfile.close();

	v_sco.push_back(new subjectScore(studentno, subjectid, score, stream,scoreid));

}


void subjectScore::removeScore() { 
	string delLine, line;
	ifstream infile;
	infile.open("subjectScore.txt");
	ofstream temp;
	temp.open("temp.txt");
	cout << "Enter Score ID [-1 to cancel]: ";
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
	remove("subjectScore.txt");
	rename("temp.txt", "subjectScore.txt");
}

void subjectScore::modifyScore() {
	string modLine, line;
	ifstream infile;
	infile.open("subjectScore.txt");
	ofstream temp;
	temp.open("temp.txt");
	cout << "\nEnter the Score ID to modify [-1 to cancel]: ";
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
	remove("subjectScore.txt");
	rename("temp.txt", "subjectScore.txt");

	int s_id, score_id,sub_id,f_year;
	double scor;
	char strea;

	cout << "Enter new Student ID: ";
	while (!(cin >> s_id)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter whole numbers only...\nEnter new Student ID: ";
	}
	cout << "\nEnter new Score ID: ";
	while (!(cin >> score_id)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter whole numbers only...\nEnter new Score ID: ";
	}
	cout << "\nEnter new Subject ID: ";
		while (!(cin >> sub_id)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter whole numbers only...\nEnter new Subject ID: ";
	}
	cout << "\nEnter new Score: ";
	cin >> scor;
	do {
	cout << "\nEnter Year [1/2/3/4/5]: ";
		while (!(cin >> f_year)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter whole numbers only...\nEnter Year [1/2/3/4/5]: ";
		}
		if (f_year == 4 || f_year == 5) {
			do {
				cout << "\nEnter Stream [Art = A/Science = S]: ";
				cin >> strea;
			} while (strea != 'A' && strea != 'S');
		}
		else if (f_year == 1 ||  f_year == 2 || f_year ==3){
			strea = 'N';
		}
	} while (f_year != 1 && f_year != 2 && f_year != 3 && f_year != 4 && f_year != 5);
	cout << endl;

	ofstream outfile("subjectScore.txt", ios_base::app);
	outfile << s_id << "," << sub_id << "," << scor << "," << score_id << "," << strea << "\n";
	outfile.close();
}

void subjectScore::viewScore() {
	char fileName[] = "subjectScore.txt";
	if (file_exist(fileName)) {
		ifstream infile(fileName);
		string line;
		string student_id, subject_id, s_score, s_score_id;
		char stre;

		cout << setw(15) << left << "Student Number" << setw(12) << left << "Subject ID" << setw(12) << left << "Score ID" << setw(12) << left << "Score" << endl;
		while (getline(infile, line)) {
			stringstream stu(line);
			while (getline(stu, student_id, ',')) {
				getline(stu, subject_id, ',');
				getline(stu, s_score, ',');
				getline(stu, s_score_id, ',');
				stu >> stre;

				cout << setw(15) << left << stoi(student_id) << setw(12) <<
					left << stoi(subject_id) << setw(12) << left <<
					stoi(s_score_id) << setw(12) << left << stod(s_score) << endl;
			}
		}
		infile.close();
	}
}