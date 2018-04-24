#include "human.h"
#include "player.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>     
#include <sstream>
#include <cctype>
//@param vector
//makes it so that we get a board for the human class
void Human::setBoard(vector <char> b){
    Player_Board.setBoard1(b);
}
//@param int(num)
//this function will take a parameter and use it to determine if an attack was a hit or a miss, if it is a miss it will replace the 'o' on
//the board with a 'M', if it is a hit it will replace the 'S' on the board with a 'H'
void Human::attack(int num){
    //cout <<Player_Board.getPosition(num)<<endl;
    // check to see if the position on the board is an s or an o
    if(Player_Board.getPosition(num) == 'S')
    {
         track_Board_.hit(num);
         cout << "Direct hit!"<< endl;
         track_Board_.displayBoard1();
    }
    else 
     {
        track_Board_.miss(num);
        cout <<"you missed\n";
        track_Board_.displayBoard1();
    }
}
