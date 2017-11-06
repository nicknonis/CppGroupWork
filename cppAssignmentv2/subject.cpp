#include "subject.h"

#include <iostream>
#include <string>


using namespace std;

void Subject::setid( int iden) {
	id = iden;
}
void Subject::setname(string nm) {
	name = nm;
}

void Subject::settype(char tp) {
	type = tp;
}