#include "classes.h"
int getOption();
int main(int argc, char* argv[]){
 srand(time(NULL));   

   // Check number of arguments
   int turn = 0;
    if(argc == 4) {
        if(argv[3] == string("COMPUTER")) {
            turn = 0;
        }
        else if(argv[3] == string("HUMAN")) {
            turn = 1;
        }
        else {
            cout << "Enter HUMAN, COMPUTER, or nothing." << endl;
            return 1;
        }
    }
    else if(argc == 3) {
        //if no value inputed for human, make it a random turn
        time_t timer; 
        // whose turn it is, true if player turn, false if computers turn
        srand(time(&timer));  //seed the clock to generate "random" numbers each time
        if(rand() % 2 == 0) {
            //player goes first
            turn = 1; 
        }
        else {
            //Player goes last
            turn = 0; 
        }
    }
    else if(argc < 3) {
        cout << "Please put fileNames next time." << endl;
        return 1;
    }
    Board b1;
    Board b2;
    Board b3;
    Human h1;
    Computer c1;
    int option;
    cout <<"You are playing a game of battleship, sink the other player's ships before they kill you"<< endl << endl;
    //cout <<"this is the board you will be tracking your progress with."<< endl;
    //b1.displayBoard1();
    cout << endl << endl;
    option = getOption();
    while (option != 3){
        
        int command;
        
        switch(option)
        {
            case 1:
                
                b1.setBoard1(argv[1]);
                b3.setBoard1(argv[2]);
                h1.setBoard(b1.getBoard());
                c1.setBoardC(b3.getBoard());
                cout <<"The boards are set!" << endl;
                //b1.displayBoard1();
                break;
            case 2:
                cout << "tracking board"<< endl;
                b2.displayBoard1();
                
                cout << "make an order! Say a position" << endl;
                cin >> command;
                
                h1.attack(command);
                cout << endl;
                cout<< "computer's turn" << endl;
                c1.turn();
               // c1.attack(c1.getAttackNum_());
                break;
        }
        option = getOption();
    }
    
    return 0;
}
// returns an integer
//displays a menu for the user to navigate
int getOption()
{
    int choice;
    
    cout <<"[1]: Set the boards, Use this one first please!"<< endl;
    cout <<"[2]: play!"<< endl;
    cout <<"[3]: quit game"<< endl;
    
    cin >> choice;
    return choice;
    
}

