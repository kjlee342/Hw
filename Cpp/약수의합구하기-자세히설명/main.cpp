#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Number{
    public:
    int value;
    int sum;
    int aliquot;
    int temp;
};

int main(void){
    ifstream inStream;
    int numTestCases;
    
    inStream.open("input.txt");
    if(inStream.fail()){
        cerr << "Input Error.\n";
        exit(1);
    }
    Number num;
    inStream >> numTestCases;
    for(int i=0; i<numTestCases; i++){
        inStream >> num.value;
        num.sum = 0;
        num.aliquot = 0;
        num.temp = sqrt(num.value);
        
        for(; num.temp>0; num.temp--){
            if(num.temp == 1){
                num.sum++;
                num.aliquot++;
                continue;
            }
            else if((num.value % num.temp) == 0){
                num.sum += num.value / num.temp;
                num.sum += num.temp;
                num.aliquot += 2;
            }
        }
        cout << num.aliquot << " " << num.sum << endl;
    }
    return 0;
}