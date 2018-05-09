#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;
class Prime{
    public:
    int sqrtn;
    vector<int> ret;
    int count;
    vector<int> factorNum;
    bool flag1;
    bool flag2;
    
    vector<int> Factor(int n){
        sqrtn = sqrt(n);
        for(int div=2; div<=sqrtn; div++){
            count = 0;
            flag1 = false;
            flag2 = true;
            while(n%div == 0){
                n /= div;
                count += 1;
                if(flag2){
                    ret.push_back(div);
                    flag2 = false;
                }
                flag1 = true;
            }
            if(flag1){
                factorNum.push_back(count);
                flag1 = false;
            }
        }
        if(n > 1) {
            ret.push_back(n);
            factorNum.push_back(1);
        }
        return ret;
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
    int input;
    for(int i=0; i<numTestCases; i++){
        inStream >> input;
        Prime p;
        vector<int> prime;
        prime = p.Factor(input);
        cout << prime.size()<< " ";
        for(int j=0; j<prime.size(); j++){
            cout << prime[j] << " " <<p.factorNum[j] << " ";
        }
        cout << endl;
    }
    
    inStream.close();
    return 0;
}