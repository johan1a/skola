#include <string>
#include <iostream>
#include <sstream>
#include "Date.h"
using namespace std;

template <typename T>
string toString (T data) {
    ostringstream os;
    os << data;
    return os.str();
}

int main(){
	double d = 1.234;
	Date today;
	string sd = toString(d);
	string st = toString(today);
	cout << sd << endl;
	cout << st << endl;
}
