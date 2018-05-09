#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(void){
    ifstream inStream;
    int numTestCases, work, day, hour, minit, sec, temp;
    int sec1, sec2;
    inStream.open("input.txt");
    if(inStream.fail()){
        cerr << "Input Error.\n";
        exit(1);
    }
    
    inStream >> numTestCases;
    
    for(int i=0; i<numTestCases; i++){
        inStream >> work;
        sec = 0;
        for(int j=0; j<work; j++){
            inStream >> temp;
            sec1 = temp * 3600;
            inStream >> temp;
            sec1 += (temp * 60);
            inStream >> temp;
            sec1 += temp;
            
            inStream >> temp;
            sec2 = temp * 3600;
            inStream >> temp;
            sec2 += (temp * 60);
            inStream >> temp;
            sec2 += temp;
            
            sec += (sec2 - sec1);
        }
        day = sec / (3600 * 24);
        sec %= (3600 * 24);
        hour = sec / 3600;
        sec %= 3600;
        minit = sec / 60;
        sec %= 60;
        
        cout << day << " " << hour << " " << minit << " " << sec << endl;
    }
    return 0;
}