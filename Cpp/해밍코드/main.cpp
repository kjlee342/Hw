#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

static unsigned int transHamming(unsigned int number);
static unsigned int extractHamming(unsigned int number);

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
        int branch = -1;
        inStream >> branch;
        
        unsigned value = 3;
        inStream >> value;
        switch (branch){
            case 0:
            cout << transHamming(value) << endl;
            break;
            
            case 1:
            cout << extractHamming(value) << endl;
            break;
            
            default:
            break;
        }
    }
    inStream.close();
    return 0;
}

unsigned int transHamming(unsigned int number){
    short arr[32] = {0,};
    arr[0] = arr[1] = arr[3] = arr[7] = arr[15] = arr[31] = 10;
    
    unsigned int bit = 1;
    for(int i=0; i<32; i++){
        if(arr[i] == 10){
            continue;
        }
        if(number & bit){
            arr[i] = 1;
        }
        bit <<= 1;
    }
    
    int p = 1;
    while(p < 32){
        int sum = 0;
        for(int i = p-1; i < 31; i += p){
            int count = 0;
            while(count < p){
                if(arr[i] == 10){
                    i++;
                    count++;
                    continue;
                }
                sum += arr[i];
                i++;
                count++;
            }
        }
        
        if(sum % 2 == 0){
            arr[p-1] = 0;
        }
        else{
            arr[p-1] = 1;
        }
        p *= 2;
    }
    
    unsigned int result = 0;
    for(int i = 30; i >= 0; i--){
        if(arr[i] == 1){
            result = arr[i] | result;
        }
        result <<= 1;
    }

    return (result / 2);
}

unsigned int extractHamming(unsigned int number){
    short arr[32] = {0,};
    unsigned int temp = number;
    for(int i = 0; i < 32; i++){
        if(temp & 1){
            arr[i] = 1;
        }
        temp >>= 1;
    }
    
    short flag[5] = {0,};
    int flagCount = 0;
    for(int i = 0; i<5; i++){
        int sum = 0;
        int p = (int) pow(2, i);
        for(int j = p - 1; j <= 31; j += p){
            int count = 0;
            while(count < p){
                sum += arr[j];
                j++;
                count++;
            }
        }
        if(sum % 2 == 1){
            flag[i] = 1;
            flagCount++;
        }
    }
    
    if(flagCount > 1){
        int error = -1;
        for(int i = 0; i < 5; i++){
            switch (flag[i]){
                case 1:
                error += (int) pow(2, i);
                break;
            }
        }
        
        int bit = 1;
        bit <<= error;
        if(bit & number){
            number = number ^ bit;
        }
        else{
            number = number | bit;
        }
    }
    
    unsigned result = 0;
    short p = 16;
    unsigned int bit = 1;
    bit <<= 30;
    for(int i = 31; i > 0; i--){
        if(i == p){
            p /= 2;
            bit >>= 1;
            continue;
        }
        if(number & bit){
            result = result | 1;
        }
        result <<= 1;
        bit >>= 1;
    }
    
    return (result / 2);
}