#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(void){
    ifstream inStream;
    int numTestCases;
    int cases;
    int value[100][2];
    int modeValue[100];
    int modeCases;
    int index;
    int num;
    int temp, temp2;
    int mode;
    
    inStream.open("input.txt");
    if(inStream.fail()){
        cerr << "Input Error.\n";
        exit(1);
    }
    
    inStream >> numTestCases;
    for(int i=0; i<numTestCases; i++){
        inStream >> cases;
        index = 0;
        for(int j=0; j<cases; j++){
            value[j][1] = 0;
        }
        
        for(int j=0; j<cases; j++){
            inStream >> num;
            for(temp=0; temp<index; temp++){
                if(value[temp][0] == num){
                    break;
                }
            }
            if(index == temp){
                value[index][0] = num;
                value[index][1]++;
                index++;
            }
            else{
                value[temp][1]++;
            }
        }
        mode = 0;
        for(int j=0; j<index; j++){
            if(mode < value[j][1]){
                mode = value[j][1];
            }
        }
        modeCases = 0;
        for(int j=0; j<index; j++){
            if(mode == value[j][1]){
                modeValue[modeCases] = value[j][0];
                modeCases++;
            }
        } 
        temp2 = modeCases;
        while(temp2--){
            for(int j=0; j <modeCases-1; j++){
                if(modeValue[j]>modeValue[j+1]){
                    temp = modeValue[j];
                    modeValue[j] = modeValue[j+1];
                    modeValue[j+1] = temp;
                }
            }
            
        }
        cout << modeCases << " " << mode << " ";
        for(int j=0; j<modeCases; j++){
            cout << modeValue[j] << " ";
        }
        cout << endl;
    }        
    inStream.close();
    return 0;
}