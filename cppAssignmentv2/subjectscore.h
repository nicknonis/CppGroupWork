#pragma once
#ifndef subjectscore
#define subjectscore

#include <string>
using namespace std;
#endif

class SubjectScore {
	double score;
public:
	void setscore(double scr);
	double getscore() {
		return score;
	}
};