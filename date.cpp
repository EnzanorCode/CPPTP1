/**
 * @Author: Dominique Ginhac <d0m>
 * @Date:   2019-10-15T09:46:41+02:00
 * @Email:  dginhac@u-bourgogne.fr
 * @Project: C++ Programming - ESIREM 3A IT
 * @Last modified by:   d0m
 * @Last modified time: 2020-09-22T23:16:24+02:00
 */


#include "date.h"



namespace date {

	bool Date::checkDate(int year, int month, int day) {
		if (year <0) {
			return false;
		}
		if ((month < 1) || (month > 12)) {
			return false;
		}
		if ((day < 1) || (day > 31)) {
			return false;
		}
		if ((month == 1 || month == 3 || month == 5 || month == 7
		|| month == 8 || month == 10 || month == 12) && (day>31) ) {
			return false;
		}
		if ((month == 4 || month == 6 || month == 9 || month == 11)
		&& (day>30)) {
			return false;
		}
		if ((month == 2) && (day > 29)) {
			return false;
		}
		if ((month == 2) && (day==29)) {
			if ((year%4) || ((year%100==0) && (year%400))) {
				return false;
			}
		}
		return true;
	}



	Date::Date(int year, int month, int day) {
		bool status = checkDate(year, month, day);
		assert(status==true && "Date is not valid");
		_year = year;
		_month = month;
		_day = day;
		//std::cout << "Constructor: " << _year << "/" << _month << "/" << _day << '\n';
	}

	Date::~Date() {
		//std::cout << "  Destructor: " << _year << "/" << _month << "/" << _day << '\n';
	}

	int Date::year() const {
		return _year;
	}
	int Date::month() const {
		return _month;
	}

	int Date::day() const {
		return _day;
	}

	std::string Date::toString() const {
		std::string month[12] = {"Jan", "Feb", "March", "April", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec"};
		std::string to_display;
		to_display = std::to_string(_year) + "/" + month[_month-1] + "/" + std::to_string(_day);
		return to_display;
	}

	void Date::setYear(int year) {
		assert(year >= 0 && "Year must be positive");
		_year = year;
	}

	void Date::setMonth(int month) {
		assert((month >=1) && (month<=12) && "Month must be between 1 and 121");
		_month = month;
	}

	void Date::setDay(int day) {
		bool status = checkDate(_year, _month, day);
		assert(status == true && "Day is not valid");
		_day = day;
	}

	void Date::nextDay() {
		bool status = checkDate(_year, _month, _day+1);
		if (!status) {
			status = checkDate(_year, _month+1, 1);
			if (!status) {
				_year++;
				_month = 1;
				_day = 1;
			}
			else {
				_month++;
				_day = 1;
			}
		}
		else {
			_day+=1;
		}
	}
    bool Date::annebissextile(){
		if ((_year%4 == 0) || ((_year%100==0) && (_year%400 == 0))) {
				return 1;
			}
		else {
			return 0;
		}
	}
	int Date::dayindate() {
		int jour = 0;
		for (int i=0; i<year()-1 ; i++) {
			if (annebissextile() == 1){
				jour += 366;
			}
			if (annebissextile() == 0){
				jour += 365;
			}
		}
			if(month() == 1 ){
				jour += day() ;
			}
			if(month() == 2 ){
				jour= jour + 31 + day();
			}
			if(month() == 3 ){
				if (annebissextile() == 1 )
				jour = jour + 60 + day();
				if (annebissextile() == 0)
				jour = jour + 59 + day();
			}
			if(month() == 4 ){
				if (annebissextile() == 1 )
				jour = jour + 91 + day();
				if (annebissextile() == 0)
				jour = jour + 90 + day();
			}
			if(month() == 5 ){
				if (annebissextile() == 1 )
				jour = jour + 121 + day();
				if (annebissextile() == 0)
				jour = jour + 120 + day();
			}
			if(month() == 6 ){
				if (annebissextile() == 1 )
				jour = jour + 152 + day();
				if (annebissextile() == 0)
				jour = jour + 151 + day();
			}
			if(month() == 7 ){
				if (annebissextile() == 1 )
				jour = jour + 182 + day();
				if (annebissextile() == 0)
				jour = jour + 181 + day();
			}
			if(month() == 8 ){
				if (annebissextile() == 1 )
				jour = jour + 213 + day();
				if (annebissextile() == 0)
				jour = jour + 212 + day();
			}
			if(month() == 9 ){
				if (annebissextile() == 1 )
				jour = jour + 244 + day();
				if (annebissextile() == 0)
				jour = jour + 243 + day();
			}
			if(month() == 10 ){
				if (annebissextile() == 1 )
				jour = jour + 274 + day();
				if (annebissextile() == 0)
				jour = jour + 273 + day();
			}
			if(month() == 11 ){
				if (annebissextile() == 1 )
				jour = jour + 305 + day();
				if (annebissextile() == 0)
				jour = jour + 304 + day();
			}
			if(month() == 12 ){
				if (annebissextile() == 1 )
				jour = jour + 335 + day();
				if (annebissextile() == 0)
				jour = jour + 334 + day();
			}

	return jour;

	}

	bool operator == (const Date& d1,const Date& d2) { // check for equality
		if( (d1.day()==d2.day()) && (d1.month()==d2.month()) && (d1.year()==d2.year())) {
			return true;
		}
	return false;
	}

	bool operator !=(const Date& d1, const Date& d2) {
		return !(d1==d2);
	}

	bool operator < (const Date& d1, const Date& d2) {
		if (d1.year()<d2.year()) {
			return true;
		}
		else if (d1.year()>d2.year()) {
			return false;
		}
		else { // same year
			if (d1.month()<d2.month()) {
				return true;
			}
			else if (d1.month()>d2.month()) {
				return false;
			} else { // same month
				if ( d1.day()<d2.day()) {
					return true;
				}
				else {
					return false;
				}
			}
		}
		return false;
	}


	bool operator > (const Date& d1, const Date& d2) {
		if (d1==d2) {
			return false;
		}
		if (d1<d2) {
			return false;
		}
		return true;
	}

	bool operator <=(const Date& d1, const Date& d2) {
		if (d1==d2) {
			return true;
		}
		return (d1<d2);
	}

	bool operator >=(const Date& d1, const Date& d2) {
		if (d1==d2) {
			return true;
		}
		return (d1>d2);
	}
	int operator -(Date& d1, Date& d2) {
		if (d1<d2){
			return (d1.dayindate() - d2.dayindate()); 		
		}
		else {
			return (d2.dayindate() - d1.dayindate());
		}
	}
}