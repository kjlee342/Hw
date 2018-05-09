#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

class MyDigitalClock
{
public:
	friend ostream& operator<< (ostream&, const MyDigitalClock&);
	// constructors
	MyDigitalClock(int h = 12, int m = 0, bool ap = false);
	MyDigitalClock(char clock[]);
	MyDigitalClock tick();
	MyDigitalClock untick();
	MyDigitalClock operator++(); // prefix, ++c
	MyDigitalClock operator++(int); // postfix, c++
	MyDigitalClock operator--(); // prefix, --c
	MyDigitalClock operator--(int); // postfix, c--
private:
	int hour;
	int min;
	bool am_pm;
};
// constructors
MyDigitalClock::MyDigitalClock(int h, int m, bool ap)
	:hour(h), min(m), am_pm(ap)
{
}
MyDigitalClock::MyDigitalClock(char clock[])
{
	hour = 0;
	min = 0;
	if (clock[0] == '1') {
		hour = 10;
	}
	hour += clock[1] - '0';

	min = (clock[3] - '0') * 10;
	min += clock[4] - '0';

	if (clock[5] == 'A') {
		am_pm = false;
	}
	else {
		am_pm = true;
	}
}
MyDigitalClock MyDigitalClock::tick()
{
	++min;
	if (min == 60)
	{
		hour++;
		min = 0;
	}
	if (hour == 13)
		hour = 1;
	if (hour == 12 && min == 0)
		am_pm = !am_pm;
	return *this;
}
MyDigitalClock MyDigitalClock::untick()
{
	--min;
	if (min == -1) {
		hour--;
		min = 59;
	}
	if (hour == 0)
		hour = 12;
	if (hour == 11 && min == 59)
		am_pm = !am_pm;
	return *this;
}
MyDigitalClock MyDigitalClock::operator ++()
{
	return tick();
}
MyDigitalClock MyDigitalClock::operator ++(int)
{
	MyDigitalClock c = *this;
	tick();
	return c;
}
MyDigitalClock MyDigitalClock::operator --()
{
	return untick();
}
MyDigitalClock MyDigitalClock::operator --(int)
{
	MyDigitalClock c = *this;
	untick();
	return c;
}
ostream& operator<<(ostream& oStream, const MyDigitalClock& c)
{
	oStream << setfill('0') << setw(2) << c.hour
		<< ':' << setw(2) << c.min;
	if (!c.am_pm)
		oStream << "AM";
	else
		oStream << "PM";
	oStream << endl;

	return oStream;
}
const int max_length = 8;

int main()
{
	ifstream inStream;
	int numTestCases;
	inStream.open("input.txt");
	if (inStream.fail())
	{
		cerr << "Input file opening failed.\n";
		exit(1);
	}
	inStream >> numTestCases;
	for (int i = 0; i<numTestCases; i++)
	{
		char clock[max_length];
		int lap;
		inStream >> clock >> lap;
		MyDigitalClock digitalClock(clock);
		for (int j = 0; j<abs(lap); j++)
			if (lap > 0)
				digitalClock++;
			else
				--digitalClock;
		cout << digitalClock;
	}
	inStream.close();
	return 0;
}