#include "myDate.h"

myDate::myDate(int year, int month, int day)
	: year(year), month(month), day(day)
{
}
// Accessor functions (접근자)
int myDate::getDayOfMonth() const {
	return day;
}
int myDate::getMonth() const {
	return month;
}
int myDate::getYear() const {
	return year;
}
// Mutator functions (변경자)
void myDate::setDayOfMonth(int day){
	this->day = day;
}
void myDate::setMonth(int month) {
	this->month = month;
}
void myDate::setYear(int year) {
	this->year = year;
}
void myDate::setDate(int year, int month, int day) {
	this->year = year;
	this->month = month;
	this->day = day;
}
// utility functions
bool myDate::isLeapYear() const {//윤년
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		return true;
	}
	return false;
}
int myDate::getDayOfWeek() const { //0=Sunday, 1=Monday, ..., 6=Saturday
	int year = this->year;
	int month = this->month;
	int day = this->day;
	int result = 0;

	if (month <= 2)
	{
		--year;
		month += 12;
	}
	int a = year / 100;
	int b = year % 100;
	result = ((21 * a / 4) + (5 * b / 4) + (26 * (month + 1) / 10) + day - 1) % 7;
	return result;
}


