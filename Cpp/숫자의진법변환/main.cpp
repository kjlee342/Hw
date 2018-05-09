#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

static int systemToDecimal(int system, char num[]);
static void decimalToSystem(int toSystem, int num, char c[]);

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
        int system;
        char num[32];
        int toSystem;
        inStream >> system >> num >> toSystem;
        
        if(toSystem == 10){
           cout << systemToDecimal(system, num) << endl;
           continue;
        }
        char c[32] = {'\0',}; 
        int temp = systemToDecimal(system, num);
        decimalToSystem(toSystem, temp, c);
        int size = 0;
        while(c[size] != '\0'){
            size++;
        }
        for(int j=size-1; j>=0; j--){
            cout << c[j];
        }
        cout << endl;
    }
    inStream.close();
    return 0;
}

int systemToDecimal(int system, char num[]){
    int size = 0;
    while(num[size] != '\0'){
        size++;
    }
    int temp = 1;
    int result = 0;
    for(int i=size-1; i>=0; i--){
        if(num[i] >= 97 && num[i] <= 122){
            result = result + ((num[i] - 87) * temp);
            temp *= system;
            continue;
        }
        else if(num[i] >= 65 && num[i] <= 90){
            result = result + ((num[i] - 55) * temp);
            temp *= system;
            continue;
        }
        result = result + ((num[i] - '0') * temp);
        temp *= system;
    }
    return result;
}

static void decimalToSystem(int toSystem, int num, char c[]){
    int temp = num;
    int mode = 0;
    int i = 0;
    while(temp / toSystem != 0){
        mode = temp % toSystem;
        temp = temp / toSystem;
        if(mode >= 10){
            c[i] = mode - 10 + 'a';
        }
        else{
            c[i] = mode + '0';
        }
        i++;
    }
        
    if(temp != 0){
        if(temp >= 10){
            c[i] = temp - 10 + 'a';
        }
        else{
            c[i] = temp + '0';
        }
    }
}