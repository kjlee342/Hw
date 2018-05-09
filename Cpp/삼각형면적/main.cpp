#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class Triangle{
    public:
    int ax,ay, bx,by, cx,cy;
    int area, course;
    int calculateArea(int ax, int ay, int bx, int by, int cx, int cy){
        area = (bx-ax)*(cy-ay) - (cx-ax)*(by-ay);
        if (area < 0){
            course = -1;
            area *= -1;
        }
        else if(area > 0){
            course = 1;
        }
        else{
            course = 0;
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
    Triangle tri;
    inStream >> numTestCases;
    for(int i=0; i<numTestCases; i++){
        inStream >> tri.ax;
        inStream >> tri.ay;
        inStream >> tri.bx;
        inStream >> tri.by;
        inStream >> tri.cx;
        inStream >> tri.cy;
        
        tri.calculateArea(tri.ax, tri.ay, tri.bx, tri.by, tri.cx, tri.cy);
        cout << tri.area << " " << tri.course << endl;
        
    }
    return 0;
}