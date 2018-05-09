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
void myDate::setDayOfMonth(int day) {
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

int myDate::getDayOfYear() const {
	int year = this->year;
	int month = this->month;
	int day = this->day;

	for (int i = 1; i < month; i++) {
		switch (i) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
			day += 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			day+= 30;
			break;
		case 2:
			if (isLeapYear() == true) {
				day += 29;
			}
			else {
				day += 28;
			}
			break;
		default:
			break;
		}
	}
	return day;
}

int myDate::getNumHolidays() const {
	int numHolidays = 0;
	int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear()) {
		monthDays[1] = 29;
	}

	myDate temp;
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= monthDays[i-1]; j++) {
			temp.setDate(this->year, i, j);
			if (temp.getDayOfWeek() == 0 || temp.getDayOfWeek() == 6) {
				numHolidays++;
			}
		}
	}
	
	temp.setDate(this->year, 1, 1);
	if (temp.getDayOfWeek() != 0 && temp.getDayOfWeek() != 6) {
		numHolidays++;
	}

	temp.setDate(this->year, 3, 1);
	if (temp.getDayOfWeek() != 0 && temp.getDayOfWeek() != 6) {
		numHolidays++;
	}

	temp.setDate(this->year, 5, 5);
	if (temp.getDayOfWeek() != 0 && temp.getDayOfWeek() != 6) {
		numHolidays++;
	}

	temp.setDate(this->year, 6, 6);
	if (temp.getDayOfWeek() != 0 && temp.getDayOfWeek() != 6) {
		numHolidays++;
	}

	temp.setDate(this->year, 7, 17);
	if (temp.getDayOfWeek() != 0 && temp.getDayOfWeek() != 6) {
		numHolidays++;
	}

	temp.setDate(this->year, 8, 15);
	if (temp.getDayOfWeek() != 0 && temp.getDayOfWeek() != 6) {
		numHolidays++;
	}

	temp.setDate(this->year, 10, 3);
	if (temp.getDayOfWeek() != 0 && temp.getDayOfWeek() != 6) {
		numHolidays++;
	}

	temp.setDate(this->year, 12, 25);
	if (temp.getDayOfWeek() != 0 && temp.getDayOfWeek() != 6) {
		numHolidays++;
	}

	temp.setDate(this->year, 2, 1);
	if (temp.getDayOfWeek() != 0 && temp.getDayOfWeek() != 6) {
		numHolidays++;
	}
	temp.setDate(this->year, 2, 2);
	if (temp.getDayOfWeek() != 0 && temp.getDayOfWeek() != 6) {
		numHolidays++;
	}
	temp.setDate(this->year, 2, 3);
	if (temp.getDayOfWeek() != 0 && temp.getDayOfWeek() != 6) {
		numHolidays++;
	}

	temp.setDate(this->year, 5, 15);
	if (temp.getDayOfWeek() != 0 && temp.getDayOfWeek() != 6) {
		numHolidays++;
	}

	temp.setDate(this->year, 9, 15);
	if (temp.getDayOfWeek() != 0 && temp.getDayOfWeek() != 6) {
		numHolidays++;
	}
	temp.setDate(this->year, 9, 16);
	if (temp.getDayOfWeek() != 0 && temp.getDayOfWeek() != 6) {
		numHolidays++;
	}
	temp.setDate(this->year, 9, 17);
	if (temp.getDayOfWeek() != 0 && temp.getDayOfWeek() != 6) {
		numHolidays++;
	}
	return numHolidays;
}
