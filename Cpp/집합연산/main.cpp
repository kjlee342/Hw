#include <iostream>
#include <fstream>
#include <cstdlib>
#include <bitset>
using namespace std;
class Bit{
    public:
    unsigned int bit[5];
    int count;
    int value[132];
    
    void Setting(){
        for(int j=0; j<5; j++){
            bit[j] = 0;
        }
    }
    
    void Add(int n){
        if(n < 32){
            bit[0] = bit[0] | (1<<n);
        }
        else if(n>=32 && n<64){
            n = n-32;
            bit[1] = bit[1] | (1<<n);
        }
        else if(n>=64 && n<96){
            n = n-64;
            bit[2] = bit[2] | (1<<n);
        }
        else if(n>=96 && n<128){
            n = n-96;
            bit[3] = bit[3] | (1<<n);
        }
        else if(n>=128 && n<=132){
            n = n-128;
            bit[4] = bit[4] | (1<<n);
        }
        
    }
    void Masking(){
        for(int i=0; i<5; i++){
            for(int j=0; j<32; j++){
                if(bit[i] & (1<<j)){
                    value[count] = 32 * i + j;
                    count++;
                }
            }
        }
    }
};

int main(void){
    ifstream inStream;
    int numTestCases;
    int cases;
    int num;
    
    inStream.open("input.txt");
    if(inStream.fail()){
        cerr << "Input Error.\n";
        exit(1);
    }
    Bit b1, b2, temp;
    inStream >> numTestCases;
    for(int i=0; i<numTestCases; i++){
        b1.Setting();
        b2.Setting();
        temp.Setting();
        
        inStream >> cases;
        for(int j=0; j<cases;j++){
            inStream >> num;
            b1.Add(num);
        }
        inStream >> cases;
        for(int j=0; j<cases;j++){
            inStream >> num;
            b2.Add(num);
        }
        
        for(int j=0; j<5; j++){
            temp.bit[j] = b1.bit[j] & b2.bit[j];
        }
        temp.count = 0;
        temp.Masking();
        cout << temp.count << " ";
        for(int j=0; j<temp.count; j++){
            cout << temp.value[j] << " ";
        }
        cout << endl;
        
        for(int j=0; j<5; j++){
            temp.bit[j] = b1.bit[j] | b2.bit[j];
        }
        temp.count = 0;
        temp.Masking();
        cout << temp.count << " ";
        for(int j=0; j<temp.count; j++){
            cout << temp.value[j] << " ";
        }
        cout << endl;
        
        for(int j=0; j<5; j++){
            temp.bit[j] = b1.bit[j] & b2.bit[j];
            temp.bit[j] = b1.bit[j] ^ temp.bit[j];
        }
        temp.count = 0;
        temp.Masking();
        cout << temp.count << " ";
        for(int j=0; j<temp.count; j++){
            cout << temp.value[j] << " ";
        }
        cout << endl;
    }
    inStream.close();
    return 0;
}