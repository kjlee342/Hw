#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Triangle{
    public:
    int ax, ay;
    int bx, by;
    int cx, cy;
    int ab, ac, bc;
    int a, b, c;
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
    
    Triangle tri;
    for(int i=0; i<numTestCases; i++) {
        inStream >> tri.ax;
        inStream >> tri.ay;
        inStream >> tri.bx;
        inStream >> tri.by;
        inStream >> tri.cx;
        inStream >> tri.cy;
        
        if((tri.ax == tri.bx && tri.bx == tri.cx) || 
            (tri.ay == tri.by && tri.by == tri.cy)) {
            cout << "0" << endl;
            continue;
        }
        else if((abs(tri.ax-tri.bx) == abs(tri.ay-tri.by)) &&
                (abs(tri.bx-tri.cx) == abs(tri.by-tri.cy)) &&
                (abs(tri.ax-tri.cx) == abs(tri.ay-tri.cy))) {
            cout << "0" << endl;
            continue;
        }
        
        tri.ab = (tri.ax - tri.bx) * (tri.ax - tri.bx) + (tri.ay - tri.by) * (tri.ay - tri.by);
        tri.ac = (tri.ax - tri.cx) * (tri.ax - tri.cx) + (tri.ay - tri.cy) * (tri.ay - tri.cy);
        tri.bc = (tri.bx - tri.cx) * (tri.bx - tri.cx) + (tri.by - tri.cy) * (tri.by - tri.cy);
        
        if ((tri.ab > tri.ac) && (tri.ab > tri.bc)){
            tri.c = tri.ab;
            tri.a = tri.ac;
            tri.b = tri.bc;
        }
        else if((tri.ac > tri.ab) && (tri.ac > tri.bc)){
            tri.c = tri.ac;
            tri.a = tri.bc;
            tri.b = tri.ab;
        }
        else if ((tri.bc > tri.ab) && (tri.bc > tri.ac)){
            tri.c = tri.bc;
            tri.a = tri.ab;
            tri.b = tri.ac;
        }
        
        if (tri.c == tri.a + tri.b){
            cout << "1" << endl;
            continue;
        }
        else if (tri.c > tri.a + tri.b){
            cout << "2" << endl;
            continue;
        }
        else if (tri.c < tri.a + tri.b){
            cout << "3" << endl;
            continue;
        }
    }
    return 0;
}