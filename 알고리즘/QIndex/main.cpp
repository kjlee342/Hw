#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
static int qIndex(int paper[], int n);

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
		int num = 0;
		inStream >> num;

		int *paper = new int[num];
		for (int i = 0; i < num; i++) {
			inStream >> paper[i];
		}

		cout << qIndex(paper, num) << endl;

		delete paper;
	}
	inStream.close();
	return 0;
}

int qIndex(int paper[], int n) {
	int qIndex = 0;
	int overCitaion = 0;

	for (int k = 0; k <= n; k++) {
		overCitaion = 0;

		for (int j = 0; j < n; j++) {
			if (k <= paper[j]) {
				overCitaion++;
			}
		}

		if (overCitaion >= k) {
			qIndex = k;
		}

	}

	return qIndex;
}