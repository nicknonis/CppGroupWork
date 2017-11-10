

#ifndef subject_h
#define subject_h
#include <string>
#include <vector>
using namespace std;
#endif

class Subject {
	int id;
	string name;
	char type;
	vector<Subject*> sub;
public:
	Subject();
	Subject(int s_id, string s_name, char s_type);
	~Subject() {}

	void displaySubject();

	int getsubjectid() {
		return id;
	}
	string getsubjectname() {
		return name;
	}
	char getsubjecttype() {
		return type;
	}
	void setsubjectid(int s_id) {
		id = s_id;
	}
	void setsubjectname(string s_name) {
		name = s_name;
	}
	void setsubjectype(char s_type) {
		type = s_type;
	}

	void addSubject(vector<Subject*> sub);
	void removeSubject();
	void modifySubject(vector<Subject*> sub);
	bool file_exist(const char *fileName);
};