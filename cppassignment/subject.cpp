#include "subject.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>
//#include <iterator>//used for proper vector solution

bool Subject::file_exist(const char *fileName) {
	ifstream infile("subject.txt");
	return infile.good();
}

Subject::Subject() { //initialize class and vector if file exist else set default values.
	char fileName[] = "subject.txt";
	if (file_exist(fileName)) {
		ifstream infile(fileName);
		string line;
		string s_id, s_name;
		char s_type;

			
			while (getline(infile, line)) {
				stringstream stu(line);
				while (getline(stu, s_id, ',')) {
					getline(stu, s_name, ',');
					stu >> s_type;
					if (strstr(name.c_str(), s_name.c_str()) == nullptr)
						return;

					id = stoi(s_id);
					name = s_name;
					type = s_type;
					sub.push_back(new Subject(id, name, type));
					}
			}
			infile.close();
	}
	else {
		id = 0;
		name = " ";
		type = 'n';
	}
}

Subject::Subject(int s_id, string s_name, char s_type){
	
	id = s_id;
	name = s_name;
	type = s_type;

	ofstream outfile("subject.txt", ios_base::app);
	outfile << id << "," << name << "," << type << "\n";
	outfile.close();
	}
//proper vector method but too lazy to get this to work properly...
//meant to be used together with file manipulator to assign values if not present.
//void Subject::displaySubject(vector<Subject*> sub) {
//	if (sub.empty())
//		return;
//	else {
//		for (size_t n = 0; n < sub.size(); n++)
//			cout << sub[n] << " ";
//		cout << endl;
//	}
//}

void Subject::displaySubject() {
	string line;
	string s_id, s_name, s_type;
	int int_s_id;
	char fileName[] = "subject.txt";

	if (file_exist(fileName)) {
		ifstream infile(fileName);
		cout << "\n" << setw(30) << left << "Subject ID" << setw(50) << left << "Subject Name" << setw(12) << left << "Type" << endl;
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
	cout << endl;
}

void Subject::addSubject(vector<Subject*> sub) {
	int s_id;
	string s_name;
	char s_type;

	cout << "\nEnter Subject ID: ";
	cin >> s_id;
	cout << "\nEnter Subject Name: ";
	cin.ignore();
	getline(cin, s_name);
	cout << "\nEnter Subject Type [Core = c/ Elective = e]: ";
	cin >> s_type;
	cout << endl;

	sub.push_back(new Subject(s_id, s_name, s_type));
}

void Subject::removeSubject() { // This needs refinement. It works but will cincai delete based on other criteria...
	string delLine, line;
	ifstream infile;
	infile.open("subject.txt");
	ofstream temp;
	temp.open("temp.txt");
	cout << "\nEnter Subject ID, Subject Name, or any part of the subject\ndetail and it will remove the related subjects[-1 to cancel]: ";
	cin >> delLine;
	if (delLine == "-1") 
		return;
	
	while (getline(infile, line)) {
		if (strstr(line.c_str(), delLine.c_str()) == nullptr ) {
			temp << line << endl;
		}
	}

	temp.close();
	infile.close();
	remove("subject.txt");
	rename("temp.txt", "subject.txt");

}


void Subject::modifySubject(vector<Subject*> sub) { // need to add vector modifer too...
	string modLine, line;
	ifstream infile;
	infile.open("subject.txt");
	ofstream temp;
	temp.open("temp.txt");
	cout << "\nEnter the Exact Subject ID or Subject Name to modify[-1 to cancel]: ";
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
	remove("subject.txt");
	rename("temp.txt", "subject.txt");

	int s_id;
	string s_name;
	char s_type;

	cout << "Enter new Subject ID: ";
	cin >> s_id;
	cout << "\nEnter new Subject Name: ";
	cin.ignore();
	getline(cin, s_name);
	cout << "\nEnter new Subject Type [Core = c/ Elective = e]: ";
	cin >> s_type;
	cout << endl;

	ofstream outfile("subject.txt", ios_base::app);
	outfile << s_id << "," << s_name << "," << s_type << "\n";
	outfile.close();

	//-- better method but it only modifies part of the target...
	//ostringstream text;
	//ifstream infile("subject.txt");

	//text << infile.rdbuf();
	//string str = text.str();
	//int new_id,search_id;
	//string s_name;
	//char s_type;

	//cout << "Enter a Subject ID to modify: ";
	//cin >> search_id;

	//cout << "\nEnter a new Subject ID: ";
	//cin >> new_id;
	//cout << "\nEnter a new Subject Name: ";
	//cin.ignore();
	//getline(cin, s_name);
	//cout << "\nEnter a new Subject Type[Core = c/ Elective = e]: ";
	//cin >> s_type;
	//
	//string str_found = to_string(search_id);
	//string str_replace = to_string(new_id);
	//size_t pos = str.find(str_found);
	//str.replace(pos, string(str_found).length(), str_replace);//replace subject id
	//infile.close();

	//ofstream outfile("subject.txt");
	//outfile << str;
}