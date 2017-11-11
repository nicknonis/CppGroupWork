#ifndef subjectscore_h
#define subjectscore_h
#include <string>
#include <vector>
using namespace std;
#endif

class subjectScore {
	double score;
	int scoreid;
	int studentno;
	int subjectid;
	char stream;

	vector<subjectScore*> v_sco;

public:
	subjectScore();
	subjectScore( int stu_no, int sub_id, double sco, char stream,int sco_id);
	~subjectScore();
	double getscore() {
		return score;
	}
	void setscore(double sco) {
		score = sco;
	}

	void addScore(vector<subjectScore*> v_sco);
	void removeScore();
	void modifyScore();
	void viewScore();
	bool file_exist(const char *fileName);
};