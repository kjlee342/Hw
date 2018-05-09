#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class Rectangle{
    public:
    int x1,y1;
    int x2,y2;
    int px,py;
    int d1, d2;
    int result1, result2;
    
    int Euclid(int x, int y, int a, int b){
        return ((x-a) * (x-a)) + ((y-b) * (y-b));
    }
    int Rectil(int x, int y, int a, int b){
        return (abs(x-a)+abs(y-b));
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
    Rectangle ret;
    inStream >> numTestCases;
    for(int i=0; i<numTestCases; i++){
        inStream >> ret.x1;
        inStream >> ret.y1;
        inStream >> ret.x2;
        inStream >> ret.y2;
        inStream >> ret.px;
        inStream >> ret.py;
        
        if(ret.px < ret.x1 && ret.py < ret.y1){ //왼쪽 하단
            ret.result1 = ret.Euclid(ret.px, ret.py, ret.x1, ret.y1);
            ret.result2 = ret.Rectil(ret.px, ret.py, ret.x1, ret.y1);
        }
        else if((ret.px >= ret.x1 && ret.px <= ret.x2) && ret.py < ret.y1){ //중앙 하단
            ret.result1 = ret.Euclid(ret.px, ret.py, ret.px, ret.y1);
            ret.result2 = ret.Rectil(ret.px, ret.py, ret.px, ret.y1);
        }
        else if(ret.px > ret.x2 && ret.py <ret.y1){ //오른쪽 하단
            ret.result1 = ret.Euclid(ret.px, ret.py, ret.x2, ret.y1);
            ret.result2 = ret.Rectil(ret.px, ret.py, ret.x2, ret.y1);
        }
        else if(ret.px > ret.x2 && (ret.py >= ret.y1 && ret.py <= ret.y2)){ //오른쪽 중단
            ret.result1 = ret.Euclid(ret.px, ret.py, ret.x2, ret.py);
            ret.result2 = ret.Rectil(ret.px, ret.py, ret.x2, ret.py);
        }
        else if(ret.px > ret.x2 && ret.py > ret.y2){ //오른쪽 상단
            ret.result1 = ret.Euclid(ret.px, ret.py, ret.x2, ret.y2);
            ret.result2 = ret.Rectil(ret.px, ret.py, ret.x2, ret.y2);
        }
        else if((ret.px >= ret.x1 && ret.px <= ret.x2) && ret.py > ret.y2){ //중앙 상단
            ret.result1 = ret.Euclid(ret.px, ret.py, ret.px, ret.y2);
            ret.result2 = ret.Rectil(ret.px, ret.py, ret.px, ret.y2);
        }
        else if(ret.px < ret.x1 && ret.py > ret.y2){ //왼쪽 상단
            ret.result1 = ret.Euclid(ret.px, ret.py, ret.x1, ret.y2);
            ret.result2 = ret.Rectil(ret.px, ret.py, ret.x1, ret.y2);
        }
        else if(ret.px < ret.x1 && (ret.py >= ret.y1 && ret.py <= ret.y2)){ //왼쪽 중단
            ret.result1 = ret.Euclid(ret.px, ret.py, ret.x1, ret.py);
            ret.result2 = ret.Rectil(ret.px, ret.py, ret.x1, ret.py);            
        }
        else{
            ret.result1 = 0;
            ret.result2 = 0;
        }
        cout << ret.result1 << " " <<ret.result2 << endl;
    }
    return 0;
}