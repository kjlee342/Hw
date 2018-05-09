#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <string.h>

using namespace std;
struct point {
	int x;
	int y;
} location[100002];
static int cmp(const point &a, const point &b);
static int cmp2(const point &a, const point &b);

int main(void) {
	ifstream inStream;
	int numTestCases;

	inStream.open("input.txt");
	if (inStream.fail()) {
		cerr << "Input Error.\n";
		exit(1);
	}

	inStream >> numTestCases;
	for (int i = 0; i < numTestCases; i++) {\
		int cafeNum = 0;
		inStream >> cafeNum;
		for (int j = 0; j < cafeNum; j++) {
			int temp1 = 0;
			int temp2 = 0;

			inStream >> temp1;
			inStream >> temp2;
			location[j].x = temp1;
			location[j].y = temp2;
			
		}
		
		sort(location, (location + cafeNum), cmp);

		for (int j = 0; j < cafeNum;) {
			int index = j;

			for (int k = j + 1; (location[j].x == location[k].x) && k < cafeNum; k++) {
				index = k;
			}

			if (index != j) {
				if (location[j - 1].y != location[j].y) {
					sort(location + j, location + index + 1, cmp2);
				}
				j = index + 1;
			}
			else {
				j++;
			}
		}
		
		int searchNum = 0;
		inStream >> searchNum;
		int index = 0;
		for (int j = 0; j < searchNum; j++) {
			inStream >> index;
			index--;
			cout << location[index].x << " " << location[index].y << endl;
		}
	}
	inStream.close();
	return 0;
}

int cmp(const point &a, const point &b) {
	if (a.x == b.x) {
		return a.y < b.y;
	}
	return a.x < b.x;
}

int cmp2(const point &a, const point &b) {
	return a.y > b.y;
}