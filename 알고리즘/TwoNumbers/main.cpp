#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <string.h>
#include <climits>
using namespace std;

static int calcul(int focus, int numOfValue);
static int value[1000000];
static int cmp(const void *arg1, const void *arg2);

int main() {
	ifstream inStream;
	inStream.open("input.txt");
	int numTest = 0;
	inStream >> numTest;

	for (int i = 0; i < numTest; i++) {
		memset(value, 0, sizeof(value));
		int numInt = 0;
		inStream >> numInt;
		int focus = 0;
		inStream >> focus;
		for (int j = 0; j < numInt; j++) {
			inStream >> value[j];
		}
		qsort(value, numInt, sizeof(int), cmp);

		cout << calcul(focus, numInt) << endl;
	}
	inStream.close();
	return 0;
}

int calcul(int focus, int numOfValue) {
	int l = 0;
	int r = numOfValue - 1;
	int min = INT_MAX;
	int count = 0;
	while (l < r) {
		int sum = value[l] + value[r];

		if (abs(focus - sum) < abs(focus - min)) {
			min = sum;
			count = 1;
		}
		else if (abs(focus - sum) == abs(focus - min)) {
			count++;
		}

		if (focus - sum > 0) {
			l++;
		}
		else if(focus - sum < 0) {
			r--;
		}
		else {
			l++;
			r--;
		}
	}
	return count;
}
int cmp(const void *arg1, const void *arg2) {
	if (*(int *)arg1 > *(int *)arg2) {
		return 1;
	}
	else if (*(int *)arg1 < *(int *)arg2) {
		return -1;
	}
	else {
		return 0;
	}
}