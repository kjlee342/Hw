#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
class Moving{
    public:
    int count;
    int sum;
    int result[256];
    void Average(int array[], int cases ,int k){
        for(count=0; count<cases-k+1; count++){
            sum = 0;
            for(int i=count; i<count+k; i++){
                sum +=array[i];
            }
            result[count] = sum / k;
        }
    }
};

int main(void){
    ifstream inStream;
    int numTestCases;
    int cases;
    
    inStream.open("input.txt");
    if(inStream.fail()){
        cerr << "Input Error.\n";
        exit(1);
    }
    
    inStream >> numTestCases;
    for(int i=0; i<numTestCases; i++){
        inStream >> cases;
        int distance[256];
        int k;
        Moving m;
        for(int j=0; j<cases; j++){
            inStream >> distance[j];
        }
        inStream >> k;
        m.Average(distance, cases, k);
        
        cout << m.count << " ";
        for(int j=0; j<m.count; j++){
            cout << m.result[j] << " ";
        }
        cout << endl;
    }
    inStream.close();
    return 0;
}