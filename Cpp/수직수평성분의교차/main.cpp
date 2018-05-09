#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class Line{
    public:
    int x1, y1;
    int x2, y2;
};

int main(void){
    ifstream inStream;
    int numTestCases;
    
    inStream.open("input.txt");
    if(inStream.fail()){
        cerr << "Input Error.\n";
        exit(1);
    }
    Line line[2];
    Line temp[2];

    inStream >> numTestCases;
    for(int i=0; i<numTestCases; i++){
        for(int j=0; j<2; j++){
            inStream >> temp[j].x1;
            inStream >> temp[j].y1;
            inStream >> temp[j].x2;
            inStream >> temp[j].y2;
            
            if(temp[j].x1 == temp[j].x2){
                line[0].x1 = temp[j].x1;
                line[0].x2 = temp[j].x2;
                if(temp[j].y1 > temp[j].y2){
                    line[0].y1 = temp[j].y2;
                    line[0].y2 = temp[j].y1;
                }
                else{
                    line[0].y1 = temp[j].y1;
                    line[0].y2 = temp[j].y2;
                }
            }
            else if(temp[j].y1 == temp[j].y2){
                line[1].y1 = temp[j].y1;
                line[1].y2 = temp[j].y2;
                if(temp[j].x1 > temp[j].x2){
                    line[1].x2 = temp[j].x1;
                    line[1].x1 = temp[j].x2;
                }
                else{
                    line[1].x1 = temp[j].x1;
                    line[1].x2 = temp[j].x2;
                }
            }
        }
        
        if((line[1].y1 >= line[0].y1 && line[1].y1 <= line[0].y2)
            && (line[0].x1 >= line[1].x1 && line[0].x1 <= line[1].x2)){
                
            if(line[0].x1 == line[1].x1 || line[0].x1 == line[1].x2 
                || line[1].y1 == line[0].y1 || line[1].y1 == line[0].y2){
                cout << "2" << endl;
            }
            else{
                cout << "1" << endl;
            }
        }
        else{
            cout << "0" << endl;
        }
    }
    return 0;
}