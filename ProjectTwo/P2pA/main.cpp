#include "classes.h"
int getOption();
int main(int argc, char* argv[]){
   

   // Check number of arguments
   if (argc != 2) {
      cout << endl << "input FileName next time" << endl;
      return 1; // 1 indicates error
   }
    Board b1;
    Board b2;
    Human h1;
    int option;
    cout <<"You are playing a game of battleship, sink the other player's ships before they kill you"<< endl << endl;
    cout <<"this is the board you will be tracking your progress with."<< endl;
    b1.displayBoard1();
    cout << endl << endl;
    option = getOption();
    while (option != 3){
        
        int command;
        
        switch(option)
        {
            case 1:
                // cout << "PLease put in the file you wish to use, make sure it is 100 percent accurate." << endl;
                // cin >> fileName;
                b1.setBoard1(argv[1]);
                cout <<"this is the file you put in" << endl;
                b1.displayBoard1();
                break;
            case 2:
                cout << "tracking board"<< endl;
                b2.displayBoard1();
                //cout << endl << endl;
                //cout << "your board" << endl;
                //b1.displayBoard1();
                //cout << endl << endl;
                //h1.Player_Board.displayBoard1();
                cout << "make an order! Say a position" << endl;
                cin >> command;
            
                h1.attack(command);
                cout << endl;
                
                
                
                break;
        }
        option = getOption();
    }
    
    return 0;
}
int getOption()
{
    int choice;
    
    cout <<"[1]: Show imported Board"<< endl;
    cout <<"[2]: play!"<< endl;
    cout <<"[3]: quit game"<< endl;
    
    cin >> choice;
    return choice;
    
}

