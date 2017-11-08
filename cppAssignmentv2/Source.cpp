#include "stu_cla.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector> // to use vectors 


using namespace std;
//Subject Function to be removed?
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

	sub.push_back(new Subject(s_id, s_name, s_type));
}


void studentMenu() { //vector<Student> Stud
	vector<studcla> Stud;
	int studentno;
	string fullname;
	char gender;
	char choice;
	char another;

	do {
		
		cout << "Choose an operation: \n1.Add Student\n2.View Student\n3.Modify Student\n4.Delete Student\n5.Return\nChoice: ";
		cin >> choice;
		switch (choice)
		{
		case '1':
			do {
				
				cout << "Enter Student No: ";
				cin >> studentno;
				cout << "Enter Full Name: ";
				cin.ignore();
				getline(cin, fullname);
				do {
					cout << "Enter Gender [M/F]: ";
					cin >> gender;
				} while (gender != 'm' && gender != 'f' && gender != 'M' && gender != 'F'); //This condition may need refinement..

				//Trying to figure out how to get the damned thing to work...
				//Stud.push_back(student(studentno, fullname, gender)); 
				//Stud.stu.push_back(student(studentno, fullname, gender)); // this doesnt work either
				//Stud.push_back(new Student(studentno, fullname, gender));

				//Student Stud1 = Stud.addStudent(studentno, fullname, gender);
				Stud.addStudent(studentno, fullname, gender);
				cout << endl;
				
				cout << "\nWould you like to enter more[n/N to abort]? ";
				cin >> another;
				cout << endl;


			} while (another != 'n' && another != 'N');

			break;
		case '2':
			Stud->viewStudent(); //search for particular student
			Stud->viewAllStudent(); // displays all student
			break;
		case '3':
			Stud->modifyStudent();

			break;
		case '4':
			Stud->removeStudent(); //deletes student record from file. 
			break;
		case '5':
			system("CLS");
			cout << "Returning..." << endl;
		default:
			cout << "\nInvalid option selected! Please select a proper option.\n" << endl;
		}
	} while (choice != '5');
	
}




int main() {
	char choice;
	//vector<Student> Stud;
	

	//navigation
	do {
		cout << "Choose an operation: \n1.Subject\n2.Class\n3.Student\n4.Exit\nChoice: ";
		cin >> choice;
		switch (choice)
		{
		case '1':
			//
			break;
		case '2':
			break;
		case '3':
			//call student menu
			//studentMenu(Stud);
			studentMenu();
			
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