#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>  
#include "date.h"
using namespace std;

template <typename T>
T string_cast (string s) {
    istringstream is(s);
    T t;
    is >> t;
    return t;
}

int main(){
	try {
		int i = string_cast<int>("123");
		double d = string_cast<double>("12.34");
		Date date = string_cast<Date>("2013-01-10");
		cout << i << endl;
		cout << d << endl;
		cout << date << endl;
	} catch (std::invalid_argument& e) {
		cout << "Error: " << e.what() << endl;
	}
}