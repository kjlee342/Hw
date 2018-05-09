#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class Triangle{
    public:
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
    for(int i=0; i<numTestCases; i++){
        inStream >> tri.a;
        inStream >> tri.b;
        inStream >> tri.c;
        
        if ((tri.a >= tri.b + tri.c) || (tri.b >= tri.a + tri.c) || (tri.c >= tri.a + tri.b)){
            cout << "0" <<endl;
        }
        else if ((tri.a == tri.b) && (tri.b == tri.c)){
            cout << "1" << endl;
        }
        else if((tri.a * tri.a == tri.b * tri.b + tri.c * tri.c) ||
            (tri.b * tri.b == tri.a * tri.a + tri.c * tri.c) || 
            (tri.c * tri.c == tri.a * tri.a + tri.b * tri.b)){
                cout << "2" <<endl;
        }
        else if((tri.a == tri.b) || (tri.b == tri.c) || (tri.a == tri.c)){
            cout << "3" << endl;
        }
        else{
            cout << "4" << endl;
        }
    }
    return 0;
}