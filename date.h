
/**
 * @Author: Dominique Ginhac <d0m>
 * @Date:   2020-09-07T15:15:52+02:00
 * @Email:  dginhac@u-bourgogne.fr
 * @Project: C++ Programming - ESIREM 3A IT
 * @Last modified by:   d0m
 * @Last modified time: 2020-09-23T11:39:17+02:00
 */

#ifndef DATE_H
#define DATE_H
#include <string>
#include <iostream>
#include <cassert>
class Date {
public:
   Date (int month, int day, int year);
   Date() = default;
   int getMonth() const;
   int getDay() const;
   int getYear() const;
   int month();
   bool checkDate(int month, int day) const;
   Date nextDay();
   void setMonth(int month);
   void setDay(int day);
   void setYear(int year);
   std::string toString();
private:
   int _month;
   int _day;
   int _year;
};
#endif // DATE_H