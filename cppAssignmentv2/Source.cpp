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
			do {
				system("CLS");
				cout << "Enter Student No: ";
				cin >> studentno;
				cout << "Enter Full Name: ";
				cin.ignore();
				getline(cin,fullname);
				cout << "Enter Gender [M/F]: ";
				cin >> gender;
				Student Stud(studentno);
				Stud.addStudent(studentno, fullname, gender);
				cout << endl;
				Stud.viewStudent(Stud);
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