#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
int arr[46];
int main() {
	fstream inStream;
	inStream.open("input.txt");
	int testCase = 0;
	inStream >> testCase;
	int sum = 0;
	for (int j = 0; j < 46; j++) {
		sum += j;
		arr[j] = sum;
	}
	for (int i = 0; i < testCase; i++) {
		int value = 0;
		inStream >> value;
		int flag = 0;
		for (int a = 1; arr[a] < value && flag == 0; a++) {
			for (int b = 1; arr[b] < value && flag == 0; b++) {
				for (int c = 1; arr[c] < value && flag == 0; c++) {
					if (arr[a] + arr[b] + arr[c] == value) {
						flag = 1;
					}
				}
			}
		}
		cout << flag << endl;

	}

	inStream.close();
	return 0;
}




