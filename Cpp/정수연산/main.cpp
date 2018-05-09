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
    int sum, sub, max, abs, mult, divi, modul, equal;
    int a, b;
    for(int i=0; i<numTestCases; i++){
   
        inStream >> a;
        inStream >> b;
        
        if(a > b){
            max = a;
        }
        else{
            max = b;
        }
        sum = (a + b);
        sub = a - b;
        abs = std::abs(a - b);
        mult = a * b;
        divi = a / b;
        modul = a % b;
        if(a == b){
            equal = 1;
        }
        else{
            equal = 0;
        }
        
        cout << sum << " " << sub << " " << abs << " " << mult << " " 
        << divi << " " << modul << " " << max << " " << equal << endl;
    }
    inStream.close();
    
    return 0;
}
