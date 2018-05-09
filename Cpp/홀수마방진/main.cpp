#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

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
        short n = 0;
        inStream >> n;
        
        int square[n][n];
        memset(square, 0x00,sizeof(int)*n*n);

        int row = 0;
        int col = (n-1)/2;
        square[row][col] = 1;
        int nextRow;
        int nextCol;

        for (int i = 2; i <= n*n; i++) {
            if (row - 1 < 0)
            	nextRow = n-1;
            else
            	nextRow = row-1;
            
            if(col + 1 == n)
            	nextCol = 0;
            else
            	nextCol = col+1;
            
            if(square[nextRow][nextCol] > 0)
            	row = (row+1)%n;
            else{
            	row = nextRow;
            	col = nextCol;
            }
            
            square[row][col] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << square[i][j] << " ";
            }
            cout << endl;
        }
    }
    inStream.close();
    return 0;
}