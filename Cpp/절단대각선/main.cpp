#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

static int backBrokenDiagonal(int m[][100], int n);
static int brokenDiagonal(int m[][100], int n);
static int sum(int m[], int n);

int main(void){
    ifstream inStream;
    int numTestCases;
    
    inStream.open("input.txt");
    if(inStream.fail()){
        cerr << "Input Error.\n";
        exit(1);
    }
    
    inStream >> numTestCases;
    int n;
    
    for(int i=0; i<numTestCases; i++){
        int m[100][100];
        inStream >> n;
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                inStream >> m[j][k];
            }
        }
        int temp1 = brokenDiagonal(m, n);
        int temp2 = backBrokenDiagonal(m, n);
        int result =  (temp1 > temp2 ? temp1 : temp2);
        cout << result << endl;
        
    }
    inStream.close();
    return 0;
}

int brokenDiagonal(int m[][100], int n){
    int max = 0;
    int temp [100];
    for(int i=0; i<n;){
        for(int j=0; j<n;){
            max += m[i][j];
            i++;
            j++;
        }
    }
    int col=1;
    for(int a=0; a< n-1; a++){
        int i=0;
        int j=col;
        while(i < n){
            temp[i] = m[i][j];
            i++;
            j++;
            if(j == n){
                j = 0;
            }
        }
        col++;
        max = (max > sum(temp, n) ? max : sum(temp, n));
    }
    return max;
}
static int backBrokenDiagonal(int m[][100], int n){
    int max = 0;
    int temp [100];
    for(int i=0; i<n;){
        for(int j=n-1; j>=0;){
            max += m[i][j];
            i++;
            j--;
        }
    }
    int col=n-2;
    for(int a=0; a< n-1; a++){
        int i=0;
        int j=col;
        while(i < n){
            temp[i] = m[i][j];
            i++;
            j--;
            if(j == -1){
                j = n-1;
            }
        }
        col--;
        max = (max > sum(temp, n) ? max : sum(temp, n));
    }
    return max;
}
int sum(int m[], int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += m[i];
    }
    return sum;
}