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
        unsigned int num;
        inStream >> num;
        
        int check[4] = {255, 255, 255, 255};
        for(int j=0; j<4; j++){
            check[j] &= num;
            num >>= 8;
        }
        int result = 0;
        for(int j=1; j<4; j++){
            result += check[j];
        }
        while(result > 255){
            result -= 256;
        }
        if(result + check[0] == 255){
            cout << 1 << endl;
            continue;
        }
        cout << 0 << endl;
    }
    inStream.close();
    return 0;
}