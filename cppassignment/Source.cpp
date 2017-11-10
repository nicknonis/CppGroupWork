#include "subject.h"
#include "student.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>


int subjectMenu(vector<Subject*> sub) {
	
	char choice;
	Subject* cur_sub = new Subject();
	do {
		cout << "Choose an operation. \n1. Add Subject\n2. View Subjects\n3. Modify Subject\n4. Remove\n5. Return\nChoice: ";
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
	return 0;
}

void studentMenu(vector<Student*> Stud) { //vector<Student> Stud
	Student* cur_stud = new Student();
	char choice;

	do {
		cout << "Choose an operation: \n1.Add Student\n2.View Student\n3.Modify Student\n4.Delete Student\n5.Search Student Record\n6.Return\nChoice: ";
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
	return;
}

int main() {
	char choice;
	vector<Subject*> sub;
	vector<Student*> Stud;
	do {
		cout << "Choose an operation: \n1.Subject\n2.Class\n3.Student\n4.Exit\nChoice: ";
		cin >> choice;
		switch (choice)
		{
		case '1':
			subjectMenu(sub);
			break;
		case '2':
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