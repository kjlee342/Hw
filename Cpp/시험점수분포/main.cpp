#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
class Test{
    public:
    int score[100][2];
    int index;
    
};
int main(void){
    ifstream inStream;
    int numTestCases;
    int cases;
    int tempScore;
    int temp;
    inStream.open("input.txt");
    if(inStream.fail()){
        cerr << "Input Error.\n";
        exit(1);
    }
    
    inStream >> numTestCases;
    for(int i=0; i<numTestCases; i++){
        Test t;
        t.index = 0;
        temp = 0;
        inStream >> cases;
        for(int j=0; j<cases; j++){
            t.score[j][1] = 0;
        }
        
        for(int j=0; j<cases; j++){
            inStream >> tempScore;
            for(temp=0; temp<t.index; temp++){
                if(t.score[temp][0] == tempScore){
                    break;
                }
            }
            if(temp == t.index){
                t.score[t.index][0] = tempScore;
                t.score[t.index][1]++;
                t.index++;
            }
            else{
                t.score[temp][1]++;
            }
        }
        
        for(int j=0; j<t.index; j++){
            for(int k=0; k<t.index-1; k++){
                if(t.score[k+1][0]<t.score[k][0]){
                    tempScore = t.score[k][0];
                    temp = t.score[k][1];
                    t.score[k][0] = t.score[k+1][0];
                    t.score[k][1] = t.score[k+1][1];
                    t.score[k+1][0] = tempScore;
                    t.score[k+1][1] = temp;
                    
                }
            }
        }
        for(int j=0; j<t.index; j++){
            cout << t.score[j][0] << " " << t.score[j][1] << " ";
        }
        cout << endl;
    }
    return 0;
    inStream.close();
}