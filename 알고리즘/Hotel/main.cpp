#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
	ifstream inStream;
	inStream.open("input.txt");
	int numTest = 0;
	inStream >> numTest;
	for (int i = 0; i < numTest; i++) {
		int H, W, N;
		inStream >> H >> W >> N;
	
		int row = 0;
		int col = 1;
		while (N > 0) {
			N--;
			row++;
			if (row > H) {
				row = 1;
				col++;
			}
			
		}

		cout << row * 100 + col << endl;

	}
	inStream.close();
	return 0;
}
