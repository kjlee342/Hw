#include <iostream>
#include <fstream>
#include <cstdlib>
#include <queue>
#include <algorithm>

using namespace std;
struct h2o {
	int start;
	int end;
};
static int counter(h2o arr[], int num, int distance);
static int cmp(const void *arg1, const void * arg2);

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
		int n = 0;
		inStream >> n;
		h2o *arr = new h2o[n];
		for (int j = 0; j < n; j++) {
			int temp1, temp2;
			inStream >> temp1 >> temp2;

			if (temp1 > temp2) {
				swap(temp1, temp2);
			}
			arr[j].start = temp1;
			arr[j].end = temp2;

		}
		qsort(arr, n, sizeof(h2o), cmp);
		int d = 0;
		inStream >> d;

		cout << counter(arr, n, d) << endl;

		delete[] arr;
	}
	inStream.close();
	return 0;
}

int counter(h2o arr[], int num, int distance) {
	int max = 0;

	priority_queue<int> q;
	for (int i = 0; i < num; i++) {
		q.push(-arr[i].start);
		
		while (!q.empty() && arr[i].end > -q.top() + distance) {
			q.pop();
		}

		max = std::max((int)q.size(), max);
	
	}
	
	return max;
}

int cmp(const void *arg1, const void * arg2) {
	int v1, v2;
	v1 = ((h2o *)arg1)->end;
	v2 = ((h2o *)arg2)->end;
	
	return (v1 > v2);
}