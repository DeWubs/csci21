#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
// thanks to https://youtu.be/LM6EDIKS5Pk and
// https://youtu.be/qdkabVYgV24 for getting me some good review on files and strings
// this little program is just playing with strings and file input


int main()
{
    
    cout <<" put in an integer value \n";
    
    int input;
    cin >> input; // this value is an int which means it can have math done on it
    stringstream sso;
    
    sso << input;
    string strinput;
    sso >> strinput; // this is a string which can no no longer have math done on it
    
    cout << "the int number is" << input << endl;
    cout << "the string number is also " << strinput << endl;
    cout << "sring value cant have math done on it in the same way as an integer " << endl;
    cout << "integer value + 2 = " << input+2 << endl;
    
    ofstream robertsFile("figureingItOut.txt");
    
    if(robertsFile.is_open())
    {
        robertsFile << "im getting the hang of this?\n";
        cout << "the file was opened.\n";
    }
    else
    {
        cout << "I messed up somewhere!\n";
    }
    robertsFile.close();
    
    return 0;
}