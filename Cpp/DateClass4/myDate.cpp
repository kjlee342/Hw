#include <iomanip>
#include "myDate.h"
myDate::myDate(int year, int month, int day)
	: year(year), month(month), day(day)
{
}
myDate::myDate(const myDate& date)
{
	this->year = date.getYear();
	this->month = date.getMonth();
	this->day = date.getDayOfMonth();
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
			day += 30;
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
		for (int j = 1; j <= monthDays[i - 1]; j++) {
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

int myDate::getNumSummerTimeDays() const {
	int numSummerTimeDays = 0;
	myDate march(this->year, 3, 31);
	myDate october(this->year, 10, 31);

	numSummerTimeDays = october.getDayOfYear() - march.getDayOfYear();

	int count = 31;
	while (march.getDayOfWeek() != 0) {
		march.setDate(this->year, 3, count--);
		numSummerTimeDays++;
	}
	if (count == 31) {
		numSummerTimeDays++;
	}
	count = 31;
	while (october.getDayOfWeek() != 0) {
		october.setDate(this->year, 10, count--);
		numSummerTimeDays--;
	}
	if (count == 31) {
		numSummerTimeDays--;
	}

	return numSummerTimeDays;
}

void myDate::printCalendarOfMonth() const {
	int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear()) {
		monthDays[1] = 29;
	}
	int days = 0;
	int firstdate = 0;
	int count = 0;

	cout << this->year << " " << this->month << endl;
	days = (year - 1) * 365 + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400);

	for (int j = 0; j<month - 1; j++) {
		days += monthDays[j];
	}

	firstdate = days % 7;

	for (int j = 0; j <= firstdate; j++) {
		if (firstdate != 6) {
			cout << 0 << " ";
			count++;
		}
	}
	for (int j = 1; j <= monthDays[month - 1]; j++) {
		if (count >= 7) {
			cout << endl;
			count = 0;
		}
		cout << j << " ";
		count++;
	}

	for (int j = 0; j<7 - count; j++) {
		cout << 0 << " ";
	}
}

ostream &operator <<(ostream &outStream, const myDate& date) {
	outStream << setfill('0') << setw(2) << date.getDayOfMonth()
		<< '/' << setw(2) << date.getMonth() << '/' << date.getYear();

	return outStream;
}

istream &operator >>(istream &inStream, myDate& date) {
	int data[3] = { 0, };
	inStream >> data[0] >> data[1] >> data[2];
	date.setDate(data[0], data[1], data[2]);

	return inStream;
}

myDate operator +(int num, const myDate& date) {
	if (num < 0) {
		myDate temp(date.getYear(), date.getMonth(), date.getDayOfMonth());
		return (temp - -num);
	}
	int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (date.isLeapYear()) {
		monthDays[1] = 29;
	}
	int tempDay = num + date.getDayOfMonth();
	int tempMonth = date.getMonth();
	int tempYear = date.getYear();

	while (tempDay > monthDays[tempMonth - 1]) {
		tempDay -= monthDays[tempMonth - 1];
		tempMonth++;
		if (tempMonth > 12) {
			tempMonth = 1;
			tempYear++;
			myDate temp(tempYear, 1, 1);
			if (temp.isLeapYear()) {
				monthDays[1] = 29;
			}
			else {
				monthDays[1] = 28;
			}
		}
	}

	myDate resultDate(tempYear, tempMonth, tempDay);

	return resultDate;
}

int myDate::operator -(const myDate& date) const {
	int tempDay1 = getDayOfYear();
	int tempDay2 = date.getDayOfYear();

	for (int i = year; i < date.getYear(); i++) {
		myDate temp(i, 12, 31);
		tempDay1 -= temp.getDayOfYear();
	}

	for (int i = date.getYear(); i < year; i++) {
		myDate temp(i, 12, 31);
		tempDay2 -= temp.getDayOfYear();
	}

	return tempDay1 - tempDay2;
}

myDate myDate::operator +(int num) const {
	if (num < 0) {
		return (*this - -num);
	}
	int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear()) {
		monthDays[1] = 29;
	}
	int tempDay = num + getDayOfMonth();
	int tempMonth = getMonth();
	int tempYear = getYear();

	while (tempDay > monthDays[tempMonth - 1]) {
		tempDay -= monthDays[tempMonth - 1];
		tempMonth++;
		if (tempMonth > 12) {
			tempMonth = 1;
			tempYear++;
			myDate temp(tempYear, 1, 1);
			if (temp.isLeapYear()) {
				monthDays[1] = 29;
			}
			else {
				monthDays[1] = 28;
			}
		}
	}

	myDate resultDate(tempYear, tempMonth, tempDay);

	return resultDate;

}

myDate myDate::operator -(int num) const {
	if (num < 0) {
		return (*this + -num);
	}
	int monthDays[13] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear()) {
		monthDays[1] = 29;
	}
	int tempDay = getDayOfMonth() - num;
	int tempMonth = getMonth();
	int tempYear = getYear();

	while (tempDay <= 0) {
		tempMonth--;
		if (tempMonth <= 0) {
			tempMonth = 12;
			tempYear--;
			myDate temp(tempYear, 1, 1);
			if (temp.isLeapYear()) {
				monthDays[1] = 29;
			}
			else {
				monthDays[1] = 28;
			}
		}
		tempDay += monthDays[tempMonth - 1];
		
	}

	myDate resultDate(tempYear, tempMonth, tempDay);

	return resultDate;
}

myDate& myDate::operator ++() {
	int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear()) {
		monthDays[1] = 29;
	}


	day++;
	if (day > monthDays[month - 1]) {
		day = 1;
		month++;
	}
	if (month > 12) {
		month = 1;
		year++;
	}

	return *this;
}

myDate& myDate::operator --() {
	int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear()) {
		monthDays[1] = 29;
	}

	day--;
	if (day == 0) {
		day = monthDays[month - 2];
		month--;
	}
	if (month == 0) {
		month = 12;
		year--;
	}

	return *this;
}

myDate myDate::operator ++(int) {
	myDate temp = *this;
	++*this;
	return temp;
}

myDate myDate::operator --(int) {
	myDate temp = *this;
	--*this;
	return temp;
}

myDate& myDate::operator =(const myDate& date) {
	day = date.getDayOfMonth();
	month = date.getMonth();
	year = date.getYear();

	return *this;
}

myDate& myDate::operator +=(int num) {
	if (num < 0) {
		return (*this -= -num);
	}
	int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear()) {
		monthDays[1] = 29;
	}
	day = num + day;

	while (day > monthDays[month - 1]) {
		day -= monthDays[month - 1];
		month++;
		if (month > 12) {
			month = 1;
			year++;
			if (isLeapYear()) {
				monthDays[1] = 29;
			}
			else {
				monthDays[1] = 28;
			}
		}
	}

	return *this;
}

myDate& myDate::operator -=(int num) {
	if (num < 0) {
		return (*this += -num);
	}
	int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear()) {
		monthDays[1] = 29;
	}
	day = month - num;

	while (day <= 0) {
		month--;
		if (month <= 0) {
			month = 12;
			year--;
			if (isLeapYear()) {
				monthDays[1] = 29;
			}
			else {
				monthDays[1] = 28;
			}
		}
		day += monthDays[month - 1];
		
	}

	return *this;
}

bool myDate::operator >(const myDate& date) const {
	if (year > date.getYear()) {
		return true;
	}
	else if (year < date.getYear()) {
		return false;
	}

	if (month > date.getMonth()) {
		return true;
	}
	else if (month < date.getMonth()) {
		return false;
	}

	if (day > date.getDayOfMonth()) {
		return true;
	}
	else if (day < date.getDayOfMonth()) {
		return false;
	}

	return false;
}

bool myDate::operator >=(const myDate& date) const {
	if (year >= date.getYear()) {
		return true;
	}
	else if (year < date.getYear()) {
		return false;
	}

	if (month >= date.getMonth()) {
		return true;
	}
	else if (month < date.getMonth()) {
		return false;
	}

	if (day >= date.getDayOfMonth()) {
		return true;
	}
	else if (day < date.getDayOfMonth()) {
		return false;
	}

	return false;
}

bool myDate::operator <(const myDate& date) const {
	if (year < date.getYear()) {
		return true;
	}
	else if (year > date.getYear()) {
		return false;
	}

	if (month < date.getMonth()) {
		return true;
	}
	else if (month > date.getMonth()) {
		return false;
	}

	if (day < date.getDayOfMonth()) {
		return true;
	}
	else if (day > date.getDayOfMonth()) {
		return false;
	}

	return false;
}

bool myDate::operator <=(const myDate& date) const {
	if (year <= date.getYear()) {
		return true;
	}
	else if (year > date.getYear()) {
		return false;
	}

	if (month <= date.getMonth()) {
		return true;
	}
	else if (month > date.getMonth()) {
		return false;
	}

	if (day <= date.getDayOfMonth()) {
		return true;
	}
	else if (day > date.getDayOfMonth()) {
		return false;
	}

	return false;
}

bool myDate::operator ==(const myDate& date) const {
	if (year == date.getYear()) {
		if (month == date.getMonth()) {
			if (day == date.getDayOfMonth()) {
				return true;
			}
		}
	}

	return false;
}

bool myDate::operator !=(const myDate& date) const {
	if (year == date.getYear()) {
		if (month == date.getMonth()) {
			if (day == date.getDayOfMonth()) {
				return false;
			}
		}
	}

	return true;
}