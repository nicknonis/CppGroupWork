#include "student.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector> // to use vectors 
using namespace std;


int main() {
	char choice;
	int studentno;
	string fullname;
	char gender;
	char another;
	Student* Stud;
	//navigation
	do {
		system("CLS");
		cout << "Choose an operation: \n1.Subject\n2.Class\n3.Student\n4.Exit\nChoice: ";
		cin >> choice;
		switch (choice)
		{
		case '1':
			break;
		case '2':
			break;
		case '3':
			//this is add student need to move into student submenu
			//Student object may need to move out n use vector instead.
			do {
				system("CLS");
				cout << "Enter Student No: ";
				cin >> studentno;
				cout << "Enter Full Name: ";
				cin.ignore();
				getline(cin,fullname);
				do{
					cout << "Enter Gender [M/F]: ";
					cin >> gender;
				} while (gender != 'm' && gender != 'f' && gender != 'M' && gender != 'F');

				cout << "\nbefore adding student\n ";
				Student* Stud = &Student(studentno, fullname, gender);

				cout << "\nafter adding student\n ";
				Stud->addStudent(studentno, fullname, gender);
				cout << endl;
				Stud->viewStudent(Stud); //fullname not displaying 
				Stud->viewAllStudent(); // this works fine
				cout << "\nWould you like to enter more[n/N to abort]? ";
				cin >> another;
				cout << endl;
				
				
			} while (another != 'n' && another != 'N');
			
			break;
		case '4':
			system("CLS");
			cout << "Terminating..." << endl;
			break;
		default:
			cout << "\nInvalid option selected! Please select a proper option.\n" << endl;
		}
	} while (choice != '4');

	return 0;
}