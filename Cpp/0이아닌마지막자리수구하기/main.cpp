#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
class NoneZero{
    public:
    int two;
    int five;
    int ten;
    NoneZero(){
        two = 0;
        five = 0;
        ten = 0;
    }
    
    void Prime(int num[], int cases){
        for(int i=0; i<cases; i++){
            while((num[i] % 2) == 0){
                two++;
                num[i] /= 2;
            }
            while((num[i] % 5) == 0){
                five++;
                num[i] /= 5;
            }
        }
    }
    int Zero(){
        while(two && five){
            ten++;
            two--;
            five--;
        }
        return ten;
    }
    int RestNum(){
        int i = 1;
        for(int j=0; j<two; j++){
            i *= 2;
            i %= 10;
        }
        for(int j=0; j<five; j++){
            i *= 5;
            i %= 10;
        }
        return i;
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
    int cases;
    int num[100];
    int result;
    int zeroNum;
    for(int i=0; i<numTestCases; i++){
        inStream >> cases;
        for(int j=0; j<cases; j++){
            inStream >> num[j];
        }
        NoneZero z;
        result = 1;
        z.Prime(num, cases);
        for(int j=0; j<cases; j++){
            result *= num[j] % 10;
            result %= 10;
        }
        zeroNum = z.Zero();
        result *= z.RestNum();
        result %= 10;
        cout << result << " " << zeroNum << endl;
        
    }
    inStream.close();
    return 0;
}