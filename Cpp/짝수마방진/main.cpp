#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;
static void multipleOfFour(int num);
static void notMultipleOfFour(int num);

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
		if (n % 4 == 0) {
			multipleOfFour(n);
		}
		else {
			notMultipleOfFour(n);
		}
	}
	inStream.close();
	return 0;
}

void multipleOfFour(int num) {
	int **square = new int*[num];
	int **reverseSquare = new int*[num];
	for (int i = 0; i < num; i++) {
		square[i] = new int[num];
		memset(square[i], 0x00, (sizeof(int) * num));
		reverseSquare[i] = new int[num];
		memset(reverseSquare[i], 0x00, (sizeof(int) * num));
	}

	int count = 1;
	for (int i = 0; i<num; i++) {
		for (int j = 0; j<num; j++) {
			square[i][j] = count;
			reverseSquare[i][j] = 1 + num*num - count++;
		}
	}

	for (int i = 0; i<num; i++) {
		for (int j = 0; j<num; j++) {
			if (i % 4 == j % 4) {
				square[i][j] = reverseSquare[i][j];
			}
			if ((i + j + 1) % 4 == 0) {
				square[i][j] = reverseSquare[i][j];
			}
		}
	}

	for (int i = 0; i<num; i++) {
		for (int j = 0; j<num; j++) {
			cout << square[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i<num; i++) {
		delete square[i];
		delete reverseSquare[i];
	}
	delete square;
	delete reverseSquare;
}
void notMultipleOfFour(int num) {
	int n = num / 2;
	int **array = new int*[num];
	int **order = new int*[n];
	for (int i = 0; i < num; i++) {
		array[i] = new int[num];
		memset(array[i], 0x00, (sizeof(int) * num));
	}
	
	for (int i = 0; i < n; i++) {
		order[i] = new int[n];
		memset(order[i], 0x00, (sizeof(int) * n));
	}

	int row = 0;
	int col = (n - 1) / 2;
	order[row][col] = 1;
	int nextRow;
	int nextCol;

	for (int i = 2; i <= n*n; i++) {
		if (row - 1 < 0)
			nextRow = n - 1;
		else
			nextRow = row - 1;

		if (col + 1 == n)
			nextCol = 0;
		else
			nextCol = col + 1;

		if (order[nextRow][nextCol] > 0)
			row = (row + 1) % n;
		else {
			row = nextRow;
			col = nextCol;
		}

		order[row][col] = i;
	}

	int k = (num - 2) / 4;
	int i;
	for (i = 0; i<k + 1; i++) {
		for (int j = 0; j<n; j++) {
			if (i == k && j == n / 2) {
				array[0 + i * 2][0 + j * 2] = order[i][j] * 4 - 3;
				array[1 + i * 2][1 + j * 2] = order[i][j] * 4 - 1;
				array[1 + i * 2][0 + j * 2] = order[i][j] * 4 - 2;
				array[0 + i * 2][1 + j * 2] = order[i][j] * 4;
				continue;
			}
			array[0 + i * 2][0 + j * 2] = order[i][j] * 4;
			array[1 + i * 2][1 + j * 2] = order[i][j] * 4 - 1;
			array[1 + i * 2][0 + j * 2] = order[i][j] * 4 - 2;
			array[0 + i * 2][1 + j * 2] = order[i][j] * 4 - 3;
		}
	}
	for (int j = 0; j<n; j++) {
		if (j == n / 2) {
			array[0 + i * 2][0 + j * 2] = order[i][j] * 4;
			array[1 + i * 2][1 + j * 2] = order[i][j] * 4 - 1;
			array[1 + i * 2][0 + j * 2] = order[i][j] * 4 - 2;
			array[0 + i * 2][1 + j * 2] = order[i][j] * 4 - 3;
			continue;
		}
		array[0 + i * 2][0 + j * 2] = order[i][j] * 4 - 3;
		array[1 + i * 2][1 + j * 2] = order[i][j] * 4 - 1;
		array[1 + i * 2][0 + j * 2] = order[i][j] * 4 - 2;
		array[0 + i * 2][1 + j * 2] = order[i][j] * 4;
	}
	i++;
	for (; i<n; i++) {
		for (int j = 0; j<n; j++) {
			array[0 + i * 2][0 + j * 2] = order[i][j] * 4 - 3;
			array[1 + i * 2][1 + j * 2] = order[i][j] * 4 - 2;
			array[1 + i * 2][0 + j * 2] = order[i][j] * 4 - 1;
			array[0 + i * 2][1 + j * 2] = order[i][j] * 4;
		}
	}

	for (i = 0; i<num; i++) {
		for (int j = 0; j<num; j++) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
	for (i = 0; i<num; i++) {
		delete array[i];
	}
	for (i = 0; i < n; i++) {
		delete order[i];
	}
	delete array;
	delete order;
}