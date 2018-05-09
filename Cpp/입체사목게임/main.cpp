#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

static int checkWinner(int (*arr)[7]);

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
        int arr[6][7] = {0,};
        int turnNum = 0;
        inStream >> turnNum;
            
        int turn = 0;
        int chip = 0;
        for(int k=0; k<turnNum; k++){
            inStream >> chip;
            int l = 0;
            while(arr[l][chip-1] > 0){
                l++;
            }
            arr[l][chip-1] = (turn % 2) + 1;
            turn++;
        }
        cout << checkWinner(&arr[0]) << endl;
        // for(int a=0; a<6; a++){
        //     for(int b=0; b<7; b++){
        //         cout << arr[a][b] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }
    inStream.close();
    return 0;
}

int checkWinner(int (*arr)[7]){
    int count = 0;
    
    for(int i=0; i<6; i++){
        for(int j=0; j<4; j++){
            if((arr[i][j] == arr[i][j+1]) && (arr[i][j+1] == arr[i][j+2])
                                                && (arr[i][j+2]== arr[i][j+3])){
                count = arr[i][j];
                if(count == 1){
                    return 1;
                }
                else if(count == 2){
                    return 2;
                }
            }
        }
    }
    
    for(int j=0; j<7; j++){
        for(int i=0; i<3; i++){
            if((arr[i][j] == arr[i+1][j]) && (arr[i+1][j] == arr[i+2][j])
                                                && (arr[i+2][j]== arr[i+3][j])){
                count = arr[i][j];
                if(count == 1){
                    return 1;
                }
                else if(count == 2){
                    return 2;
                }
            }
        }
    }
    
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            if((arr[i][j] == arr[i+1][j+1]) && (arr[i+1][j+1] == arr[i+2][j+2])
                                                && (arr[i+2][j+2]== arr[i+3][j+3])){
                count = arr[i][j];
                if(count == 1){
                    return 1;
                }
                else if(count == 2){
                    return 2;
                }
            }
        }
    }
    
    for(int i=0; i<3; i++){
        for(int j=6; j>=3; j--){
            if((arr[i][j] == arr[i+1][j-1]) && (arr[i+1][j-1] == arr[i+2][j-2])
                                                && (arr[i+2][j-2]== arr[i+3][j-3])){
                count = arr[i][j];
                if(count == 1){
                    return 1;
                }
                else if(count == 2){
                    return 2;
                }
            }
        }
    }
    return 0;
}