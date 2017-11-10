#include "subject.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>





int subjectmenu(vector<Subject*> sub) {
	char choice;
	Subject* cur_sub = new Subject();
	do {
		cout << "Choose an operation. \n1. Add Subject\n2. View Subjects\n3. Modify Subject\n4. Remove\n5. Return\n?";
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


int main() {
	vector<Subject*> sub;
	subjectmenu(sub);
	
	return 0;
}