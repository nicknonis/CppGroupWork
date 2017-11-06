#include "klass.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;



void Class::setclassid(int cid) {
	classid = cid;
}
void Class::setclassname(string cn) {
	classname = cn;
}
void Class::setyearform(int yf) {
	yearform = yf;
}
void Class::setyeargrade(char yg) {
	yeargrade = yg;
}