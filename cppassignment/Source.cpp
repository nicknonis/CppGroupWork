#include "subject.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>





void addSubject(vector<Subject*> sub) {
	int s_id;
	string s_name;
	char s_type;

	cout << "Enter Subject ID: ";
	cin >> s_id;
	cout << "\nEnter Subject Name: ";
	cin.ignore();
	getline(cin, s_name);
	cout << "\nEnter Subject Type [Core = c/ Elective = e]: ";
	cin >> s_type;
	cout << endl;

	sub.push_back(new Subject(s_id, s_name,s_type));
}



int main() {
	char choice;
	vector<Subject*> sub;
	
	do {
		cout << "Choose an operation. \n1. Add Subject\n2. View Subjects\n3. Modify Subject\n4. Exit\n?";
		cin >> choice;

		switch (choice) {
		case '1':
			addSubject(sub);
			break;
		case'2':
			//for (vector<Subject*>::iterator it = sub.begin(); it != sub.end(); it++)//this doesnt work either...
			//	(*it)->displaySubject();
			//(*sub)->displaySubject();
			break;
		case '3':
			break;
		case '4':
			cout << "Terminating..." << endl;
			break;
		default:
			cout << "\nInvalid option selected! Please select a proper option.\n" << endl;
		}
	} while (choice != '4');
	
	return 0;
}