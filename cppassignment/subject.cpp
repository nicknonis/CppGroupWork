#include "subject.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>


bool file_exist(const char *fileName) {
	ifstream infile("subject.txt");
	return infile.good();
}


Subject::Subject(int s_id, string s_name, char s_type){
	id = s_id;
	name = s_name;
	type = s_type;

	ofstream outfile("subject.txt", ios_base::app);
	outfile << id << "," << name << "," << type << "\n";
	outfile.close();
	}

void Subject::displaySubject() {
	string line;
	string s_id, s_name, s_type;
	int int_s_id;
	char fileName[] = "subject.txt";

	if (file_exist(fileName)) {
		ifstream infile(fileName);
		cout << setw(30) << left << "Subject ID" << setw(50) << left << "Subject Name" << setw(12) << left << "Type" << endl;
		while (getline(infile, line)) {
			stringstream stu(line);
			while (getline(stu, s_id, ',')) {
				getline(stu, s_name, ',');
				stu >> s_type;

				int_s_id = stoi(s_id);

				cout << setw(30) << left << s_id;
				cout << setw(50) << left << s_name;
				cout << setw(12) << left << s_type << endl;
			}
		}
		infile.close();
	}

}