#include "student.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector> // to use vectors 

using namespace std;

void newStudent(int stu_no,string full_name,char gend) {
	Student Stud(stu_no);
	Stud.addStudent(stu_no, full_name, gend);
}

int main() {
	int choice;
	int studentno;
	string fullname;
	char gender;

	

	cout << "Choose an operation: \n1.Subject\n2.Class\n3.Student\n4.Exit\nChoice: ";
	cin >> choice;
	
	//navigation

	switch (choice)
	{
	case 1:
		
						
	case 2:
		
	case 3:
		cout << "Enter Student No: ";
		cin >> studentno;
		cout << "\nEnter Full Name: ";
		cin >> fullname;
		cout << "\nEnter Gender [M/F]: ";
		cin >> gender;
		cout << endl;
		newStudent(studentno, fullname, gender);
	case 4:
		break;
	default:
		cout << "Invalid option selected! Please select a proper option." << endl;
	}

	return 0;
}