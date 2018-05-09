#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

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
        int numData, data;
        int sum = 0;
        
        inStream >> numData;
        
        for(int j=0; j<numData; j++){
            inStream >> data;
            sum += data;
        }
        cout << sum << endl;
    }
    
    inStream.close();
    
    return 0;
}