#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {
	fstream inStream;
	inStream.open("input.txt");
	int testCase = 0;
	inStream >> testCase;
	for (int i = 0; i < testCase; i++) {
		vector<int> v;
		int num = 0;
		inStream >> num;
		bool happy = false;

		while (true) {
			v.push_back(num);
			int x = 0;
			int d[11] = {0,};
			while (num >= 10) {
				d[x++] = num % 10;
				num /= 10;
			}
			d[x] = num;
			num = 0;
			for (int j = 0; j <= x; j++) {
				num = num + (d[j] * d[j]);
			}
			int flag = 0;
			for (int j = 0; j < v.size(); j++) {
				if (v[j] == num) {
					flag = 1;
				}
			}
			
			if (num == 1) {
				happy = true;
				break;
			}
			else if (flag == 1) {
				break;
			}
		}
		if (happy) {
			cout << "HAPPY" << endl;
		}
		else {
			cout << "UNHAPPY" << endl;
		}
	}

	return 0;
}