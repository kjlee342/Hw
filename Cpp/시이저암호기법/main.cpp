#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

static void caesar(char c[], int size, int num);

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
        int num;
        inStream >> num;
        
        char arr[100];
        inStream >> arr;
        
        int size = 0;
        while(arr[size] > 0 && arr[size] < 256){
            size++;
        }
        
        caesar(arr, size, num);
        
        cout << arr << endl;
        
    }
    inStream.close();
    return 0;
}

void caesar(char c[], int size, int num){
    for(int i=0; i<size; i++){
        if(c[i] >= 97 && c[i] <= 122){
            if(c[i] + num > 122){
                int temp;
                temp = c[i] + num - 123;
                c[i] = 'a' + temp;
            }else{
                c[i] += num;    
            }
        }
        else if(c[i] >= 65 && c[i] <= 90){
            if(c[i] + num > 90){
                int temp;
                temp = c[i] + num - 91;
                c[i] = 'A' + temp;
            }else{
                c[i] += num;    
            }
        }
    }
}