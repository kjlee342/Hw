#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(void){
    ifstream inStream;
    int numTestCases, numCases, value, min, max;
    
    inStream.open("input.txt");
    if(inStream.fail()){
        cerr << "Input Error.\n";
        exit(1);
    }
    
    inStream >> numTestCases;
    
    for(int i = 0; i < numTestCases; i++){
        inStream >> numCases;
        inStream >> value;
        max = value;
        min = value;
        for (int j = 1; j < numCases; j++){
            inStream >> value;
            if (value > max){
                max = value;
            }
            else if (value < min){
                min = value;
            }
        }
        
        cout << max << " " << min <<endl;
        
    }
     return 0;
}