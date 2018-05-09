#include <iostream>
#include <fstream>
using namespace std;

static double Kai(double *frequency, double *alphabetFreq,int key);
static void caesar(char arr[], int iTemp);

int main(int argc, char *argv[]){
	fstream infile;
	int numcases;

	infile.open("input.txt");
	
	infile >> numcases;

	while (numcases--){ 
		int len = 0;
		char arr[500];
		double kaiFreq[26] = {8.167,1.492,2.782,4.253,12.702,2.228,2.015,6.094,6.996,0.153,
							0.772,4.025,2.406,6.749,7.507,1.929,0.095,5.987,6.327,9.056,
							2.758,0.978,2.360,0.150,1.974,0.074};
		int count[26] = {0};
		double arrFreq[26] = {0};
		double min = 0;
		double temp=0;
		int iTemp;

		infile >> arr;

		for (int i = 0; arr[i] != '\0'; i++){
			if (!('a' <= arr[i] && arr[i] <= 'z' || 'A' <= arr[i] && arr[i] <= 'Z'))
				continue;
			len++;
		}
		for (char i = 'a'; i <= 'z'; i++){
			for (int j = 0; arr[j] != '\0'; j++){
				if (arr[j] == i||arr[j]==i-32){
					count[i - 'a']++;
				}
			}
		}
		for (int i = 0; i < 26; i++){
			arrFreq[i] = count[i] / (float)len*100;
		}
		for (int i = 0; i <= 25; i++){
			temp = Kai(kaiFreq, arrFreq, i);

			if (i == 0){
				min = temp;
				iTemp = i;
			}
			if (min > temp){
				min = temp;
				iTemp = i;
			}
		}
		caesar(arr, iTemp);
		cout << arr << endl;
	}
	infile.close();
}

double Kai(double *frequency, double *alphabetFreq,int key){
	int i;
	double kai=0;

	for (i = 0; i < 26; i++){
		if (i + key>25){
			kai += ((alphabetFreq[i + key + 'a' - 'z'-1])*(alphabetFreq[i + key + 'a' - 'z'-1]) / frequency[i]);
		
		}
		else{
			kai += (alphabetFreq[i + key])*(alphabetFreq[i + key]) / frequency[i];
			
		}
	}
	return kai;
}

void caesar(char arr[], int iTemp){
	for (int i = 0; arr[i]!='\0'; i++){
			if (!('A' <= arr[i] && arr[i] <= 'Z' || 'a' <= arr[i] && arr[i] <= 'z'))
				continue;
			else{
				if ('A' <= arr[i] && arr[i] <= 'Z'){
					if ('A' > char(arr[i] - iTemp)){
						arr[i] -= iTemp - ('Z'- 'A'+1);
					}
					else{
						arr[i] -= iTemp;
					}
				}
				if ('a' <= arr[i] && arr[i] <= 'z'){
					if ('a' > char(arr[i] - iTemp)){
						arr[i] -= iTemp - ('z' - 'a'+1);
					}
					else{
						arr[i] -= iTemp;
					}
				}
			}
		}
}