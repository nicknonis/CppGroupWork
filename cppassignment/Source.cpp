//vectors used all over
//exception handling in student.cpp - (addstudent and viewallstudent)
//virtual functions in student.h
//function overloading all over the place.
//operator overloading in subjectscore - TODO
//inheritance in student (student has 2 children art and science)
// -- Nicholas

#include "subject.h"
#include "klass.h"
#include "student.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>


int subjectMenu(vector<Subject*> sub) {
	
	char choice;
	Subject* cur_sub = new Subject();
	do {
		cout << "\nChoose an operation. \n1. Add Subject\n2. View Subjects\n3. Modify Subject\n4. Remove\n5. Return\nChoice: ";
		cin >> choice;

		switch (choice) {
		case '1':
			cur_sub->addSubject(sub);
			
			break;
		case'2':
			cur_sub->displaySubject();
			//for (vector<Subject*>::iterator it = sub.begin(); it != sub.end(); it++)//alternatives for display.
			//	(*it)->displaySubject();
			//(*sub)->displaySubject();
			break;
		case '3':
			cur_sub->modifySubject(sub);
			break;
		case '4':
			cur_sub->removeSubject();
			break;
		case '5':
			cout << "Terminating..." << endl;
			break;
		default:
			cout << "\nInvalid option selected! Please select a proper option.\n" << endl;
		}
	} while (choice != '5');

	//clean up
	delete cur_sub;
	cur_sub = NULL;
	cout << endl;
	return 0;
}

int classMenu(vector<Class*> cla) {

	char choice;
	Class* cur_cla = new Class();
	do {
		cout << "\nChoose an operation. \n1. Add Class\n2. View Classes\n3. Modify Class\n4. Remove Class\n5. Return\nChoice: ";
		cin >> choice;

		switch (choice) {
		case '1':
			cur_cla->addClass(cla);

			break;
		case'2':
			cur_cla->displayClass();
			break;
		case '3':
			cur_cla->modifyClass(cla);
			break;
		case '4':
			cur_cla->removeClass();
			break;
		case '5':
			cout << "Terminating..." << endl;
			break;
		default:
			cout << "\nInvalid option selected! Please select a proper option.\n" << endl;
		}
	} while (choice != '5');

	//clean up
	delete cur_cla;
	cur_cla = NULL;
	cout << endl;
	return 0;
}


void studentMenu(vector<Student*> Stud) { //vector<Student> Stud
	Student* cur_stud = new Student();
	char choice;

	do {
		cout << "\nChoose an operation: \n1.Add Student\n2.View Student\n3.Modify Student\n4.Delete Student\n5.Search Student Record\n6.Return\nChoice: ";
		cin >> choice;
		switch (choice)
		{
		case '1':
			cur_stud->addStudent(Stud);
			break;
		case '2':
			cur_stud->viewAllStudent(); // displays all student
			break;
		case '3':
			cur_stud->modifyStudent();

			break;
		case '4':
			cur_stud->removeStudent(); //deletes student record from file. 
			break;
		case '5':
			cur_stud->searchStudent(); //search for particular student
			break;
		case '6':
			cout << "Returning..." << endl;
			break;
		default:
			cout << "\nInvalid option selected! Please select a proper option.\n" << endl;
		}
	} while (choice != '6');
	
	//clean up
	delete cur_stud;
	cur_stud = NULL;
	cout << endl;
	return;
}

int main() {
	char choice;
	vector<Subject*> sub;
	vector<Student*> Stud;
	vector<Class*> cla;
	do {
		cout << "Choose an operation: \n1.Subject\n2.Class\n3.Student\n4.Exit\nChoice: ";
		cin >> choice;
		switch (choice)
		{
		case '1':
			subjectMenu(sub);
			break;
		case '2':
			classMenu(cla);
			break;
		case '3':
			studentMenu(Stud);
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