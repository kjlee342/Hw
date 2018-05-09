#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
using namespace std;

static void henry(int y);
static int gcd(int n1, int n2);
int a, b;

int main() {
	ifstream inStream;
	inStream.open("input.txt");
	int testCase = 0;
	inStream >> testCase;
	for (int i = 0; i < testCase; i++) {
		inStream >> a >> b; // a / b

		henry(2);
		cout << b << endl;

	}

	inStream.close();
	return 0;
}

void henry(int y) {
	while (a != 1) {
		if (a * y >= b) {
			a = a * y - b;
			b = b * y;
			int d = gcd(a, b);
			a /= d;
			b /= d;
		}
		else {
			y++;

		}
	}
}

int gcd(int n1,int n2) {
	return (n2 == 0) ? n1 : gcd(n2, n1 % n2);
}