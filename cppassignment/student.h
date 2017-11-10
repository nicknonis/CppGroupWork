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

	virtual string getTotalScore();
	virtual char getFinalGrade();

	void addStudent(vector<Student*> stud);
	void removeStudent();
	void modifyStudent();
	void viewAllStudent();
	void searchStudent();
	bool file_exist(const char *fileName);
};

class ScienceStudent : public Student {
public:
	ScienceStudent(int stu_no, string full_name, int class_id, char gend) {
		setstudentno(stu_no);
		setfullname(full_name);
		setgender(gend);
		setclassid(class_id);
	};
	char getFinalGrade();
};

class ArtStudent : public Student {
public:
	ArtStudent(int stu_no, string full_name, int class_id, char gend) {
		setstudentno(stu_no);
		setfullname(full_name);
		setgender(gend);
		setclassid(class_id);
	}
	char getFinalGrade();
};
