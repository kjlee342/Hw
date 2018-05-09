#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;
static void checkWord(char **puzzle, char word[], int row, int col);

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
        int m = 0;
        int n = 0;
        inStream >> m >> n;
        
        char **puzzle = new char*[100];
        for(int j=0; j<100; j++){
            puzzle[j] = new char[101];
            memset(puzzle[j], 0, sizeof(char)*n);
        }
        for(int j=0; j<m; j++){
            for(int k=0; k<n; k++){
                inStream >> puzzle[j][k];
            }
        }
        
        int wordNum = 0;
        inStream >> wordNum;
        
        char word[201] = {0,};
        
        for(int j=0; j<wordNum; j++){

            inStream >> word;
            checkWord(puzzle, word, m, n);
        }
        for(int j=0; j<100; j++){
            delete puzzle[j];
        }
        delete puzzle;
    }
    inStream.close();
    return 0;
}

void checkWord(char **puzzle, char word[], int row, int col){
    int x, y;
    int way;
    int length = strlen(word);
    int count = 0;
    int flag = 0;
    
    for(int i=length-1; i<row; i++){ //path 7
        for(int j=length-1; j<col; j++){
            count = 0;
            for(int k=0; k<length; k++){
                if(puzzle[i-k][j-k] == word[k]){
                    count++;
                }
            }
            if(count == length){
                x = i+1;
                y = j+1;
                way = 7;
                flag = 1;
                goto result;
            }
        }
    }
    
    for(int i=0; i<row-length+1; i++){ //path 4
        for(int j=0; j<col; j++){
            count = 0;
            for(int k=0; k<length; k++){
                if(puzzle[i+k][j] == word[k]){
                    count++;
                }
            }
            if(count == length){
                x = i+1;
                y = j+1;
                way = 4;
                flag = 1;
                goto result;
            }
        }
    }
    
    for(int i=length-1; i<row; i++){ //path 0
        for(int j=0; j<col; j++){
            count = 0;
            for(int k=0; k<length; k++){
                if(puzzle[i-k][j] == word[k]){
                    count++;
                }
            }
            if(count == length){
                x = i+1;
                y = j+1;
                way = 0;
                flag = 1;
                goto result;
            }
        }
    }
    
    for(int i=length-1; i<row; i++){ //path 1
        for(int j=0; j<col-length+1; j++){
            count = 0;
            for(int k=0; k<length; k++){
                if(puzzle[i-k][j+k] == word[k]){
                    count++;
                }
            }
            if(count == length){
                x = i+1;
                y = j+1;
                way = 1;
                flag = 1;
                goto result;
            }
        }
    }
    
    for(int i=0; i<row-length+1; i++){ //path 5
        for(int j=length-1; j<col; j++){
            count = 0;
            for(int k=0; k<length; k++){
                if(puzzle[i+k][j-k] == word[k]){
                    count++;
                }
            }
            if(count == length){
                x = i+1;
                y = j+1;
                way = 5;
                flag = 1;
                goto result;
            }
        }
    }
    
    for(int i=0; i<row; i++){ //path 2
        for(int j=0; j<col-length+1; j++){
            count = 0;
            for(int k=0; k<length; k++){
                if(puzzle[i][j+k] == word[k]){
                    count++;
                }
            }
            if(count == length){
                x = i+1;
                y = j+1;
                way = 2;
                flag = 1;
                goto result;
            }
        }
    }
    
    for(int i=0; i<row; i++){ //path 6
        for(int j=length-1; j<col; j++){
            count = 0;
            for(int k=0; k<length; k++){
                if(puzzle[i][j-k] == word[k]){
                    count++;
                }
            }
            if(count == length){
                x = i+1;
                y = j+1;
                way = 6;
                flag = 1;
                goto result;
            }
        }
    }
    
    for(int i=0; i<row-length+1; i++){ //path 3
        for(int j=0; j<col-length+1; j++){
            count = 0;
            for(int k=0; k<length; k++){
                if(puzzle[i+k][j+k] == word[k]){
                    count++;
                }
            }
            if(count == length){
                x = i+1;
                y = j+1;
                way = 3;
                flag = 1;
                goto result;
            }
        }
    }
    
result:
    if(flag == 1){
         cout << x << " " << y << " " << way << endl;
    }
    else{
        cout << "-1" << endl;
    }
}