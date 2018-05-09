#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int score[1001][2];
int expectation[1001];
int main() {
	fstream inStream;
	inStream.open("input.txt");
	int testCase = 0;
	inStream >> testCase;

	for (int i = 0; i < testCase; i++) {
		memset(score, 0, sizeof(score));
		memset(expectation, 0, sizeof(expectation));
		int n, m;
		inStream >> n >> m;
		int a, b, p, q;
		for (int j = 1; j <= m; j++) {
			inStream >> a >> b >> p >> q;
			score[a][0] += p;
			score[a][1] += q;
			score[b][0] += q;
			score[b][1] += p;

		}
		float tempExpect = 0;
		int max = 0;
		int min = 1000;
		for (int j = 1; j <= n; j++) {
			if (score[j][0] == 0 && score[j][1] == 0) {
				expectation[j] = 0;
			}
			else {
				tempExpect = (float)(score[j][0] * score[j][0]) / (float)(score[j][0] * score[j][0] + score[j][1] * score[j][1]);
				expectation[j] = tempExpect * 1000;
			}
			max = std::max(max, expectation[j]);
			min = std::min(min, expectation[j]);
		}

		cout << max << endl;
		cout << min << endl;
		

	}

	inStream.close();
	return 0;
}