#include <iostream>
#include <fstream>
#include <cstdlib>
#include "MyPoint.h"
#include "MyLineSegment.h"

using namespace std;

int main(void) {
	ifstream inStream;
	int numTestCases;

	inStream.open("input.txt");
	if (inStream.fail()) {
		cerr << "Input Error.\n";
		exit(1);
	}

	inStream >> numTestCases;
	for (int i = 0; i<numTestCases; i++) {
		int ax, ay;
		int bx, by;
		int cx, cy;
		int dx, dy;

		inStream >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

		MyPoint pointA(ax, ay);
		MyPoint pointB(bx, by);
		MyPoint pointC(cx, cy);
		MyPoint pointD(dx, dy);

		MyLineSegment lineA(pointA, pointB);
		MyLineSegment lineB(pointC, pointD);

		if (lineA.properIntersection(lineB)) {
			cout << "1" << endl;
		}
		else if (lineA.improperIntersection(lineB)) {
			cout << "2" << endl;
		}
		else {
			cout << "0" << endl;
		}


	}
	inStream.close();
	return 0;
}