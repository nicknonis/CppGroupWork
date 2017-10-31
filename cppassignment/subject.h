using namespace std;
//subject classes
class Subject {
	int id;
	string name;
	char type;

public:
	Subject() {
		id = 0;
		name = "";
		type = ' ';
	}
};

class SubjectScore {
	double score;
public:
	SubjectScore() {
		score = 0;
	}
};