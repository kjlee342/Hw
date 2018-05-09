#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
static int verifyCard(char *cardNum);

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
        char cardNum[21];
        inStream >> cardNum;
        
        cout << verifyCard(cardNum) << endl;
        
    }
    inStream.close();
    return 0;
}

int verifyCard(char *cardNum){
    if(*cardNum != '3' && *cardNum != '4' && *cardNum != '5' && *cardNum != '6'){
        return 0;
    }
    
    int lengthNum = 0;
    for(int i=0; *(cardNum+i) != '\0'; i++){
        lengthNum++;
    }
    
    switch(*cardNum - '0'){
        case 3:
        if(lengthNum != 15 && lengthNum != 14){
            return 0;
        }
        break;
        
        case 4:
        if(lengthNum != 13 && lengthNum != 16){
            return 0;
        }
        break;
        
        case 5:
        case 6:
        if(lengthNum != 16){
            return 0;
        }
        break;
        
        default:
        break;
    }
    
    int checksum = 0;
    checksum = (*(cardNum + --lengthNum) - '0');
    lengthNum--;
    int mode1 = -1;
    int mode2 = -1;
    if(lengthNum % 2 == 0){
        mode1 = 1;
        mode2 = 0;
    }
    else{
        mode1 = 0;
        mode2 = 1;
    }
    while(lengthNum != -1){
        if(lengthNum % 2 == mode1){
            checksum += (*(cardNum+lengthNum) - '0');
        }
        else if(lengthNum % 2 == mode2){
            if(2 * (*(cardNum+lengthNum) - '0') >= 10){
                checksum += ((2 * (*(cardNum+lengthNum) - '0')) - 9);
            }
            else{
                checksum += (2 * (*(cardNum+lengthNum) - '0'));
            }
        }
        lengthNum--;
    }
    
    if(checksum % 10 != 0){
        return 0;
    }
    return 1;
}
