#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <climits>
using namespace std;
int d[501];
int m[501][501];
int s[501];
int main() {
	fstream inStream;
	inStream.open("input.txt");
	
	int testCase = 0;
	inStream >> testCase;

	for (int a = 0; a < testCase; a++) {
		int chapter = 0;
		inStream >> chapter;

		for (int i = 1; i <= chapter; i++) {
			inStream >> d[i];
			s[i] = s[i - 1] + d[i];
		}
		for (int i = 1; i <= chapter; i++) {
			m[i][i] = 0;
		}

		int i = 1;
		int j = 1;
		int diagonal;
		for (diagonal = 2; diagonal <= chapter; diagonal++) {
			for (i = 1; i <= chapter - diagonal + 1; i++) {
				j = i + diagonal - 1;
				m[i][j] = INT_MAX;
				for (int k = i; k <= j - 1; k++) {
					int q = m[i][k] + m[k + 1][j] + s[j] - s[i-1];
					if (q < m[i][j]) {
						m[i][j] = q;
					}
				}
			}
		}
		cout << m[1][chapter] << endl;

	}
	
	return 0;

}
