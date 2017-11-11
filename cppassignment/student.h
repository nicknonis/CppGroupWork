#ifndef student_h
#define student_h
#include <string>
#include <vector>
using namespace std;
#endif

class Student {
	int studentno;
	string fullname;
	char gender;
	int classid;

	vector<Student*> stud;

public:
	Student();
	Student(int stu_no, string f_name, int class_id, char gen);
	~Student();
	void operator =(const Student& copy) { //operator overload in case we need to dup.
		int studentno= copy.studentno;
		string fullname = copy.fullname;
		char gender = copy.gender;
		int classid = copy.classid;

	}
	int getstudentno() {
		return studentno;
	}
	string getfullname() {
		return fullname;
	}
	char getgender() {
		return gender;
	}
	int getclassid() {
		return classid;
	}
	void setstudentno(int s_no) {
		studentno = s_no;
	}
	void setfullname(string f_name) {
		fullname = f_name;
	}
	void setgender(char gen) {
		gender = gen;
	}
	void setclassid(int c_id) {
		classid = c_id;
	}

	virtual string getTotalScore(string search);
	virtual char getFinalGrade(string search);

	void addStudent(vector<Student*> stud);
	void removeStudent();
	void modifyStudent();
	void viewAllStudent();
	void searchStudent(Student* cur_stud);
	bool file_exist(const char *fileName);
	char subjectfinder(string sub_sco_subid);
};

class ScienceStudent : public Student {
public:
	ScienceStudent(){}
	ScienceStudent(int stu_no, string full_name, int class_id, char gend) {
		setstudentno(stu_no);
		setfullname(full_name);
		setgender(gend);
		setclassid(class_id);
	};
	char getFinalGrade(string search);
};

class ArtStudent : public Student {
public:
	ArtStudent(){}
	ArtStudent(int stu_no, string full_name, int class_id, char gend) {
		setstudentno(stu_no);
		setfullname(full_name);
		setgender(gend);
		setclassid(class_id);
	}
	char getFinalGrade(string search);
};
