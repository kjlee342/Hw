#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

static void decimalToBinary(unsigned int *num, short arr[][2]);
static void hammingDistance(short arr[][2], short* result);

int main(void){
    ifstream inStream;
    int numTestCases;
    
    inStream.open("input.txt");
    if(inStream.fail()){
        cerr << "Input Error.\n";
        exit(1);
    }
    
    inStream >> numTestCases;
    for(int i=0; i<numTestCases; i++){
        unsigned num[2] = {0,};
        inStream >> num[0] >> num[1];
        short arr[32][2] = {0,};
        decimalToBinary(&num[0], arr);
        short result[3] = {0,};
        hammingDistance(arr, &result[0]);
        cout << result[0] << " " << result[1] << " " << result[2] << endl;
    }
    inStream.close();
    return 0;
}

void decimalToBinary(unsigned int *num, short arr[][2]){
    for(int j=0; j<2; j++){
        unsigned int temp = *(num+j);
        int mode = 0;
        int i = 0;
        while(temp / 2 != 0){
            mode = temp % 2;
            temp = temp / 2;
            arr[i][j] = mode;
            i++;
        }
            
        if(temp != 0){
            arr[i][j] = temp;
        }
    }
}

void hammingDistance(short arr[][2], short *result){
    short distance = 0;
    short weight[2] = {0, 0};
    for(int j=0; j<32; j++){
        if(arr[j][0] == 1){
            weight[0]++;
        }
        if(arr[j][1] == 1){
            weight[1]++;
        }
        if(arr[j][0] != arr[j][1]){
            distance++;
        }
    }
    *result = weight[0];
    *(result+1) = weight[1];
    *(result+2) = distance;
}