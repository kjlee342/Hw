#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
class Parity{
 public:
    unsigned int input;
    unsigned int output;
    int count;
    unsigned int i;
    unsigned int maxOne;
    unsigned int maxZero;
    unsigned int ParityBit(){
            for(i<<=30; i>0; i>>=1){
                if(input & i){
                    count++;
                }
                if(count % 2 != 0){
                    output = input | maxOne;
                }
                else{
                    output = input & maxZero;           
                }
            }
        return output;
    }
};
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
        Parity p;
        inStream >> p.input;
        p.i = 1;
        p.count = 0;
        p.maxOne  = 0x80000000;
        p.maxZero = 0x7FFFFFFF;
        p.ParityBit();
        cout << p.output << endl;
    }
    return 0;
}