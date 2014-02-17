#include <ctime>  // time and localtime
#include "stdlib.h"
#include "date.h"
using namespace std;

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

istream& operator>>(istream& is, Date date){
	string y,m,d;
	getline(is,y,'-');
	getline(is,m,'-');
	getline(is,d);
	date.year = atoi(y.c_str());
	date.month = atoi(m.c_str());
	date.day = atoi(d.c_str());
	return is;
}

ostream& operator<<(ostream& os, const Date date){
	os << date.getYear() << '-' << date.getMonth() << '-' << date.getDay();
	return os;
}


int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

void Date::next() {
	if(day == daysPerMonth[month-1]){
		if(month == 12){
			year++;
			month = 1;
		}else{
			month++;
		}
		day = 1;
	}else{
		day++;
	}
}

