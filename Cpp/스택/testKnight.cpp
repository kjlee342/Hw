#include <fstream>
#include <cstdlib>
#include "KnightTour.h"
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
		int sizeRow, sizeCol;
		int startRow, startCol;
		inStream >> sizeRow >> sizeCol;
		inStream >> startRow >> startCol;
		KnightTour kTour(sizeRow, sizeCol);
		if (kTour.buildKnightTour(startRow, startCol))
		{
			cout << 1 << endl;
			kTour.printBoard();
		}
		else
			cout << 0 << endl;
	}
	inStream.close();
	return 0;
}