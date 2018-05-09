#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
using namespace std;
class Hamming{
    public:
    int hamming[1350];
    int min;
    void calHamming(){
        for(int j=1; j<1350; j++){
            min = hamming[j-1] * 5;
            for(int k=0; k<j; k++){
                if(min > hamming[k] * 2 && hamming[k] * 2 > hamming[j-1]){
                    min = hamming[k] * 2;
                }
                else if(min > hamming[k] * 3 && hamming[k] * 3 > hamming[j-1]){
                    min = hamming[k] * 3;
                }
                else if(min > hamming[k] * 5 && hamming[k] * 5 > hamming[j-1]){
                    min = hamming[k] * 5;
                }
            }
            hamming[j] = min;
        }
    }
    
};

int main(void){
    ifstream inStream;
    int numTestCases;
    int num;
    int min;
    int temp;
    
    inStream.open("input.txt");
    if(inStream.fail()){
        cerr << "Input Error.\n";
        exit(1);
    }
    
    inStream >> numTestCases;
    Hamming h;
    h.hamming[0] = 1;
    h.calHamming();
    
    for(int i=0; i<numTestCases; i++){
        inStream >> num;
        
        cout << h.hamming[num-1] << endl;
    }
    inStream.close();
    return 0;
}