#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

static unsigned int intToIP(char *arr);
static void ipToInt(unsigned int value, int *array);

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
        int branch = 0;
        inStream >> branch;
        
        switch (branch){
            case 1:
            char arr[16];
            inStream >> arr;
            cout << intToIP(arr) << endl;
            break;
            
            case 2:
            unsigned int value;
            inStream >> value;
            int array[4] = {0,};
            ipToInt(value, array);
            cout << array[3] <<  "." << array[2] <<  "."  << array[1] <<  "."  << array[0] << endl;
            break;
        }
        
    }
    inStream.close();
    return 0;
}

unsigned int intToIP(char *arr){
    unsigned int result = 0;
    char temp[3] = {0,};
    for(int i=0,j=0; *(arr+i) != '\0'; i++){
        if(*(arr+i) == '.'){
            result += atoi(temp);
            result <<= 8;
            j = temp[0] = temp[1] = temp[2] = 0;
            continue;
        }
        temp[j++] = *(arr+i);
    }
    result += atoi(temp);
    
    return result;
}

void ipToInt(unsigned int value, int *array){
    int masking = 0x000000FF;
    for(int i=0; i<4; i++){
        unsigned int temp = 0;
        temp = value & masking;
        *(array+i) = temp;
        value >>= 8;
    }
        
}