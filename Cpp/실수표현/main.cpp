#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

static int readlNum(char arr[], int size);

int main(void){
    ifstream inStream;
    int numTestCases;
    
    inStream.open("input.txt");
    if(inStream.fail()){
        cerr << "Input Error.\n";
        exit(1);
    }
    
    inStream >> numTestCases;
    char a[1];
    inStream.getline(a, 1);
    for(int i=0; i<numTestCases; i++){
        char arr[256];
        int size = 0;
        inStream.getline(arr, 256);
        while(arr[size] > 0 && arr[size] < 256){
            size++;
        }
        cout << readlNum(arr, size) << endl;

    }
    inStream.close();
    return 0;
}

int readlNum(char arr[], int size){
    int dotIndex = 0;
    int eIndex = 0;
    int eNum = 0;
    int dotNum = 0;
    int integralPart = 0;
    int fractionalPart = 0;
    int exponentPart = 0;
    
    for(int i=0; i<size; i++){
        switch(arr[i]){
            case '.':
                dotNum++;
                dotIndex = i;
                break;
            case 'e':
                eNum++;
                eIndex = i;
                break;
            case 'E':
                eNum++;
                eIndex = i;
                break;
            case '+': case '-': case '0': case '1':
            case '2': case '3': case '4': case '5':
            case '6': case '7': case '8': case '9':
                continue;
            default:
                return 0;
            
        }
    }
    
    if(dotNum > 1){
        return 0;
    }
    if(eNum > 1){
        return 0;
    }
    
    if(dotNum == 1){
        for(int i=0; i<dotIndex; i++){
            integralPart++;
        }
    }
    else if(eNum ==1){
        for(int i=0; i<eIndex; i++){
           integralPart++;
        }
    }
    
    if(eNum == 1){
        for(int i=dotIndex+1; i<eIndex; i++){
            fractionalPart++;
        }        
    }
    else if(dotNum == 1){
        for(int i=dotIndex+1; i<size; i++){
           fractionalPart++;
        }
    }
    for(int i=eIndex+1; i<size; i++){
        exponentPart++;
    }
    
    if(integralPart == 0 && fractionalPart == 0){
        return 0;
    }
    
    if(dotNum == 0 && exponentPart == 0){
        return 0;
    }
    
    if(eNum == 1 && exponentPart == 0){
        return 0;
    }
    
    return 1;
}