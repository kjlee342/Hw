#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(void){
    ifstream inStream;
    int numTestCases, k, temp, num = 0;;
    
    inStream.open("input.txt");
    if(inStream.fail()){
        cerr << "Input Error.\n";
        exit(1);
    }
    
    inStream >> numTestCases;
    
    for(int i=0; i<numTestCases; i++){
        inStream >> k;
        
        for(int a=0; a<k; a++){
            temp = k - 1;
            num = a + 1;
            for(int b=0; b<=a; b++){
                if(a == b){
                    cout << num << endl;
                }
                else{
                    cout << num << " ";
                    num += temp;
                    temp--;
                }
            }
        }
    }
    return 0;
}