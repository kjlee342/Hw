#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(void){
    ifstream inStream;
    int numTestCases, numCases, temp;
    unsigned long long value;
    inStream.open("input.txt");
    if(inStream.fail()){
        cerr << "Input Error.\n";
        exit(1);
    }
    
    inStream >> numTestCases;
    
    for(int i = 0; i < numTestCases; i++){
        inStream >> numCases;
        inStream >> value;
        value %= 10;
        
        for(int j = 1; j < numCases; j++){
            inStream >> temp;
            value *= temp;
            value %= 10;
        }
         
        cout << value << endl;
    }
    
    return 0;
}