using namespace std;
//student classes

class Student {
	int studentno;
	string fullname;
	char gender;
	

public:
	Student() {
		studentno = 0;
		fullname = "";
		gender = 'M';
	}
	Student(int stu_no) : studentno( stu_no ) {} //beautiful constructor for student
	~Student(); //student deconstructor
	string getTotalScore() {
		return 0;
	}
	char getFinalGrade() {
		return 0;
	}


	void addStudent(int stu_no, string full_name, char gend);
};

// sub student classes

class ScienceStudent : public Student {
public:
	char getFinalGrade() {
		return 0;
	}
};



class ArtStudent : public Student {
public:
	char getFinalGrade() {
		return 0;
	}
};