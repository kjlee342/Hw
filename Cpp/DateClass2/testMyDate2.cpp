#include <iostream>
#include <fstream>
#include <cstdlib>
#include "myDate.h"
using namespace std;
int main(void)
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
		int year, month, day;
		inStream >> year >> month >> day;
		myDate date(year, month, day);
		cout << date.getDayOfYear() << " ";
		cout << date.getNumHolidays() << endl;
	}
	inStream.close();
	return 0;
}