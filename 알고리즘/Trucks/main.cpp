#include <iostream>
#include <fstream>
#include <cstdlib>
#include <queue>
using namespace std;
static int checkTime(int truckNum, int length, int maxWeight, queue<int> truck);

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
		int truckNum = 0;
		int length = 0;
		int weight = 0;

		inStream >> truckNum >> length >> weight;
		queue<int> truck;

		for (int j = 0; j < truckNum; j++) {
			int temp;
			inStream >> temp;
			truck.push(temp);
		}

		cout << checkTime(truckNum, length, weight, truck) << endl;

	}
	inStream.close();
	return 0;
}

int checkTime(int truckNum, int length, int maxWeight, queue<int> truck) {
	int time = 0;
	int currentWeight = 0;
	queue<int> bridge;
	queue<int> timer;
	int index = 0;
	while (1) {
		time++;
		if (!bridge.empty() && time - timer.front() == length) {
			currentWeight -= bridge.front();
			bridge.pop();
			timer.pop();
		}

		if (!truck.empty() && currentWeight + truck.front() <= maxWeight) {
			currentWeight += truck.front();
			bridge.push(truck.front());
			truck.pop();
			timer.push(time);
		}
		
		if (truck.empty() && bridge.empty()) {
			break;
		}

	}
	return time;
}