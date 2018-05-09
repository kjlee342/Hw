#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;
static void codeToEng(char *morse);

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
        char morse[2001] = {'\0',};
        inStream >> morse;
        codeToEng(morse);
    }
    inStream.close();
    return 0;
}

void codeToEng(char *morse){
    string morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", 
                        "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", 
                        "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                        "-.--", "--.."};
    char alpha[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 
         'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int i = 0;
    while(1){
        string temp = "";
        while(*(morse+i) != '|' && *(morse+i) != '#' && *(morse+i) != '\0'){
            temp += *(morse+i);
            i++;
        }
        for(int j=0; j<26; j++){
            if(temp == morseCode[j]){
                cout << alpha[j];
                break;
            }
        }
        if(*(morse+i) == '|'){
            i++;
        }
        else if(*(morse+i) == '#'){
            cout << '_';
            i++;
        }
        else if(*(morse+i) == '\0'){
            cout << endl;
            return;
        }
        
    }
}