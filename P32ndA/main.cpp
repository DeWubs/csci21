//Includes
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "bs_tree.h"
using namespace std; 


int main() {
    BSTree tree;
    string line;
    int i = 0;
    ifstream file("words");
    if(file.is_open()){
        bool firstLine = true;
        while(getline(file, line)){  
            if(firstLine) {
                stringstream numLinesSS(line);
                firstLine = false;
            } else {
                bool firstSpace = false;
                stringstream numSS, wordSS;
                int num;
                string word;
                for(int i = 0; i < line.length();i++) {
                    if(firstSpace == false) {
                        numSS << line.at(i);
                        if(line.at(i) == ' ') {
                            firstSpace = true;
                        }
                    } else {
                        wordSS << line.at(i);
                    }
                }
                 numSS >> num; 
                word = wordSS.str();
                tree.insert(word, num);
            }
        }
    }

    string prefix;
    string words;
    cout << "enter a prefix: ";
    cin >> prefix;
    
    cout << tree.samePrefix(prefix);
    
    cout << endl;
    return 0;
}


