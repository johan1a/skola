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

istream& operator>>(istream& is, Date& date){
	string y,m,d;
	getline(is,y,'-');
	getline(is,m,'-');
	getline(is,d);
	int y_int = atoi(y.c_str());
	int m_int = atoi(m.c_str());
	int d_int = atoi(d.c_str());

	if(y_int >= 1 && y_int <= 9999 && m_int >= 1 && m_int <= 12 
		&& d_int > 1 && d_int <= Date::daysPerMonth[d_int]){
		date = Date(y_int, m_int, d_int);
	}else{
		is.setstate(ios_base::badbit);
	}
	return is;
}

ostream& operator<<(ostream& os, const Date date){
	os << date.getYear() << '-';
	if(date.getMonth() < 10){
		os << 0;
	}
	os << date.getMonth() << '-'; 
	if(date.getDay() < 10){
		os << 0;
	}
	os << date.getDay(); 
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

