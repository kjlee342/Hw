#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <string.h>

using namespace std;
int trans[1 << 5];

static int toBase(int num, int base);
static int checkPalind(int first, int last);

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
		memset(trans, 0, sizeof(trans));

		int num = 0;
		inStream >> num;

		int length = 0;
		int result = 0;
		for (int j = 2; j < 65; j++) {
			length = toBase(num, j);
			result = checkPalind(0, length - 1);
			if (result == 1) {
				break;
			}
		}
		cout << result << endl;

	}
	inStream.close();
	return 0;
}

int toBase(int num, int base) {
	int index = 0;
	int count = 0;
	while (num >= base) {
		trans[index] = num % base;
		num /= base;
		index++;
		count++;
	}
	trans[index] = num;

	return (count + 1);
}

int checkPalind(int first, int last) {
	if (last <= first) {
		return 1;
	}
	else if (trans[first] != trans[last]) {
		return 0;
	}
	else {
		return checkPalind(first + 1, last - 1);
	}
}