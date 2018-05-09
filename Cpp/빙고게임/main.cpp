#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
static bool checkBingo(int bingo[][5]);

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
        int bingo[5][5] = {0,};
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                inStream >> bingo[i][j];
            }
        }
        int num[75] = {0,};
        for(int j=0; j<75; j++){
            inStream >> num[j];
        }
        
        int l = 0;
        while(l < 75){
            for(int j=0; j<5; j++){
                for(int k=0; k<5; k++){
                    if(bingo[j][k] == num[l]){
                        bingo[j][k] = 0;
                        if(checkBingo(bingo)){
                            cout << l+1 << endl;
                            k = j = 5;
                            l = 75;
                        }
                    }
                }
            }
            l++;
        }
        
    }
    inStream.close();
    return 0;
}

bool checkBingo(int bingo[][5]){
    int flag = 0;
    
    flag = bingo[0][0] + bingo[1][1] + bingo[3][3] + bingo[4][4];
    if(flag == 0){
        return true;
    }
    
    flag = bingo[4][0] + bingo[3][1] + bingo[1][3] + bingo[0][4];
    if(flag == 0){
        return true;
    }
    flag = bingo[0][0] + bingo[0][4] + bingo[4][0] + bingo[4][4];
    if(flag == 0){
        return true;
    }
    
    for(int i=0; i<5; i++){
        flag = bingo[i][0] + bingo[i][1] + bingo[i][2] + bingo[i][3] + bingo[i][4];
        if(flag == 0){
            return true;
        }
        flag = bingo[0][i] + bingo[1][i] + bingo[2][i] + bingo[3][i] + bingo[4][i];
        if(flag == 0){
            return true;
        }
    }
    
    return false;
}