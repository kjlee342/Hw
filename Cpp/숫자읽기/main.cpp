#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;
static void readN(unsigned int num);

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
        unsigned int num;
        inStream >> num;
        readN(num);
    }
    inStream.close();
    return 0;
}

void readN(unsigned int num){
    string read1[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
                    "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                    "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string read2[] = {"", "ten ", "Twenty", "Thirty", "Forty", "Fifty", "Sixty",
                            "Seventy", "Eighty", "Ninety"};
    int flag = 0;
    int temp1 = num / 1000000000;
    int temp2 = num % 1000000000;
    if(temp1 > 0){
        cout << read1[temp1] << "_Billion";
        flag = 1;
    }
    if(flag == 1 && temp2 > 0){
        cout << "_";
    }
    
    flag = 0;
    temp1 = temp2 / 100000000;
    int temp3 = (temp2 % 100000000) / 1000000;
    temp2 %= 1000000;
    if(temp1 > 0){
        cout << read1[temp1] << "_Hundred";
        if(temp3 > 0){
            cout << "_";
        }
        flag = 1;
    }
    if(temp3 > 0){
        if(temp3 >= 20){
            cout << read2[temp3/10];
            if(read1[temp3%10] != ""){
                cout << "_" << read1[temp3%10];
            }
        }
        else{
            cout << read1[temp3];
        }
        flag = 1;
    }
    if(flag == 1){
        cout << "_Million";
        if(temp2 > 0){
            cout << "_";
        }
    }
    
    flag = 0;
    temp1 = temp2 / 100000;
    temp3 = (temp2 % 100000) / 1000;
    temp2 %= 1000;
    if(temp1 > 0){
        cout << read1[temp1] << "_Hundred";
        if(temp3 > 0){
            cout << "_";
        }
        flag = 1;
    }
    if(temp3 > 0){
        if(temp3 >= 20){
            cout << read2[temp3/10];
            if(read1[temp3%10] != ""){
                cout << "_" << read1[temp3%10];
            }
        }
        else{
            cout << read1[temp3];
        }
        flag = 1;
    }
    if(flag == 1){
        cout << "_Thousand";
        if(temp2 > 0){
            cout << "_";
        }
    }
    
    temp1 = temp2 / 100;
    temp3 = temp2 % 100;
    if(temp1 > 0){
        cout << read1[temp1] << "_Hundred";
        if(temp3 > 0){
            cout << "_";
        }
    }
    if(temp3 > 0){
        if(temp3 >= 20){
            cout << read2[temp3/10];
            if(read1[temp3%10] != ""){
                cout << "_" << read1[temp3%10];
            }
        }
        else{
            cout << read1[temp3];
        }
    }
    cout << endl; 
}