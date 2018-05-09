#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
class Matrix{
    public:
        int mat[100][100];
        int i, j, k;
        int m, n;
        void MatrixSetting(){
            for(int a=0; a<100; a++){
                for(int b=0; b<100; b++){
                    mat[a][b] = 0;
                }
            }
        }
        void MatrixMultiple(int array1[][100], int array2[][100], int row1, int col1, int col2){
            j = 0;
            k = 0;
            m = 0;
            n = 0;
            while (m < row1){
                for(i=0; i<col1; i++){
                    mat[m][n] += (array1[j][i] * array2[i][k]);
                }
                n++;
                k++;
                if(n == col2){
                    n = 0;
                    m++;
                }
                if(k == col2){
                    k = 0;
                    j++;
                }
            }
        }
};

int main(void){
    ifstream inStream;
    int numTestCases;
    
    inStream.open("input.txt");
    if(inStream.fail()){
        cerr << "Input Error.\n";
        exit(1);
    }
    
    inStream >> numTestCases;
    int row1, col1;
    int col2;
    int mat1[100][100];
    int mat2[100][100];
    for(int i=0; i<numTestCases; i++){
        inStream >> row1 >> col1 >> col2;
        
        for(int j=0; j<row1; j++){
            for(int k=0; k<col1; k++){
                inStream >> mat1[j][k];
            }
        }
        for(int j=0; j<col1; j++){
            for(int k=0; k<col2; k++){
                inStream >> mat2[j][k];
            }
        }
        Matrix m;
        m.MatrixSetting();
        m.MatrixMultiple(mat1, mat2, row1, col1, col2);
        for(int j=0; j<row1; j++){
            for(int k=0; k<col2; k++){
                cout << m.mat[j][k] << " ";
            }
            cout << endl;
        }
        
    }
    inStream.close();
    return 0;
}