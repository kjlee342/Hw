#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

static int checkISBN(char *isbn);

int main(void){
    ifstream inStream;
    int numTestCases;
    
    inStream.open("input.txt");
    if(inStream.fail()){
        cerr << "Input Error.\n";
        exit(1);
    }
    
    inStream >> numTestCases;
    for(int i=0; i<numTestCases; i++){
        char isbn[128] = {0,};
        inStream >> isbn;
        
        cout << checkISBN(isbn) << endl;
    }
    inStream.close();
    return 0;
}

int checkISBN(char *isbn){
    int j = 0;
    int count = 0;
    int checksum = 10;
    int sum = 0;
    int countNum = 0;
    for(count=0; *(isbn+j) != '-'; j++,count++){
        if(*(isbn+j) < 48 || *(isbn+j) > 57){
            return 0;
        }
        
        sum += (*(isbn+j) - '0') * checksum--;
    }
    if(count == 0 || count > 5){
        return 0;
    }
    j++;
    countNum += count;
    
    for(count=0; *(isbn+j) != '-'; j++,count++){
        if(*(isbn+j) < 48 || *(isbn+j) > 57){
            return 0;
        }
        
        sum += (*(isbn+j) - '0') * checksum--;
    } 
    if(count == 0 || count > 7){
        return 0;
    }
    j++;
    countNum += count;
    
    for(count=0; *(isbn+j) != '-'; j++,count++){

        if(*(isbn+j) < 48 || *(isbn+j) > 57){
            return 0;
        }
        
        sum += (*(isbn+j) - '0') * checksum--;
    }
    if(count == 0 || count > 6){
        return 0;
    }
    j++;
    countNum += count;
    
    for(count=0; *(isbn+j) != '\0'; j++,count++){
        if((*(isbn+j) < 48 || *(isbn+j) > 57) && *(isbn+j) != 'X'){
            return 0;
        }
        
        if(*(isbn+j) == 'X'){
            sum += 10;
        }
        else{
            sum += *(isbn+j) - '0';
        }
    }
    if(count == 0 || count > 1){
        return 0;
    }
    countNum += count;
    if(countNum != 10){
        return 0;
    }
    if(sum % 11 != 0){
        return 0;
    }
    
    return 1;
}