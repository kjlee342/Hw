#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;
int ducci[15];
int temp[15];
int main() {
	fstream inStream;
	inStream.open("input.txt");
	int testCase = 0;
	inStream >> testCase;

	for (int i = 0; i < testCase; i++) {
		int T = 0;
		inStream >> T;

		for (int j = 0; j < T; j++) {
			inStream >> ducci[j];
		}
		ducci[T] = ducci[0];

		bool zeroFlag = false;
		int loopCount = 0;
		while (loopCount < 1001 && !zeroFlag) {
			int zeroCount = 0;
			for (int j = 0; j < T; j++) {
				temp[j] = abs(ducci[j] - ducci[j + 1]);
				if (temp[j] == 0) {
					zeroCount++;
				}
			}
			if (zeroCount == T) {
				zeroFlag = true;
			}
			else {
				for (int j = 0; j < T; j++) {
					ducci[j] = temp[j];
				}
				ducci[T] = temp[0];
			}
			loopCount++;
		}

		if (zeroFlag) {
			cout << "ZERO" << endl;
		}
		else {
			cout << "LOOP" << endl;
		}
	}

	inStream.close();
	return 0;
}