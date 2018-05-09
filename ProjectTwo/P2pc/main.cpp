#include "Tournament.h"
#include "queue.h"
#include "stack.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
    if (argc != 3) {
        cout << "yoy, you did a dumb" << endl;
        return 1;
    }
    
    string list_type = argv[2];
    cout << list_type << endl;
    
    if (list_type == "QUEUE") {
        cout << "type QUEUE called" << endl;
        Tournament<Queue<string> > my_tourney;
        cout << "my_tourney created" << endl;
        my_tourney.start(argv[1]);
    }
    else if (list_type == "STACK") {
        Tournament<Stack<string> > my_tourney;
        my_tourney.start(argv[1]);
    }
    
    return 0;
}