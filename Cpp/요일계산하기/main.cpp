#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
class weekDay{
    public:
    bool LeapYear(int i){
        if(((i % 4 == 0) && !(i % 100 == 0)) || (i % 400 == 0)){
            return true;
        }
        return false;
    }
    int MonthDay(int i, bool Leap){
        switch (i) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
                return 31;
            case 4:
            case 6:
            case 9:
            case 11:
                return 30;
                break;
            case 2:
                if(Leap == true){
                    return 29;      
                }
                else{
                    return 28;
                }
            default:
                return 0;
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
    int year;
    int month;
    int day;
    inStream >> numTestCases;
    for(int i=0; i<numTestCases; i++){
        int tempYear = 0;
        inStream >> year >> month >> day;
        weekDay w;
        tempYear = year - 1582;
        day--;
        for(int j=1582; j<year; j++){
            if(w.LeapYear(j)){
                day += 366;
            }
            else{
                day += 365;
            }
            day %= 7;
        }
        bool temp = w.LeapYear(year);
        for(int j=1; j<month; j++){
           day += w.MonthDay(j, temp);
        }
        day += 5;
        day %= 7;
        cout << day << endl;
    }   
    inStream.close();
    return 0;
}