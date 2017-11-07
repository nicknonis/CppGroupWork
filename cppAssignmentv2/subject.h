#ifndef subject
#define subject
#include <string>
using namespace std;
#endif

class Subject {
	int id;
	string name;
	char type;
public:
	Subject() {}
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


};