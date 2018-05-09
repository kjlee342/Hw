#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
class Point{
    public:
    int x, y;
};

int main(void){
    ifstream inStream;
    int numTestCases;
    int n, area, course;
    
    inStream.open("input.txt");
    if(inStream.fail()){
        cerr << "Input Error.\n";
        exit(1);
    }
    
    inStream >> numTestCases;
    for(int i=0; i<numTestCases; i++){
        inStream >> n;
        Point p[n];
        for(int j=0; j<n; j++){
            inStream >> p[j].x;
            inStream >> p[j].y;
        }
        p[n].x = p[0].x;
        p[n].y = p[0].y;
        area = 0;
        for(int j=0; j<n; j++){
            area += ((p[j].x*p[j+1].y) - (p[j+1].x*p[j].y));
        }
        if(area < 0){
            area *= -1;
            course = -1;
        }
        else if(area > 0){
            course = 1;
        }
    cout << area << " " << course << endl;
    }
    return 0;
}