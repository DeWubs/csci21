#include "classes.h"
vector <char> Board::getBoard(){
    return board1;
}
// defaulting out the vector to an empty board, just the character 'o' 100 times
Board::Board(){
    board1.resize(100);
    for(int i = 0; i<=board1.size(); i++){
        board1[i] = 'o';
    }
}
// this construtor is making it so that the board vector gets set with whatever is inside of the parameter
Board::Board(vector <char> newVector){
    board1.resize(100);
    for(int i = 0; i<=board1.size(); i++){
       board1[i] = newVector[i]; 
    }
    
}
// will take our positions file and use it to populate the 100 slots of the board vector with what is in the input file
void Board::setBoard1(string newFile){
    // use a while loop to populate the vector all at once inside of here????
    board1.clear();
    ifstream boards(newFile.c_str());
    char stuff;
    while(!boards.eof()){
        boards >> stuff;
        board1.push_back(stuff);
    }
}
// this function takes what is in the vector and makes a 10 by 10 grid of the contents, it also will display numbers 0-9 across the top
//and a-k on the side to make things easier to see.
void Board::displayBoard1(){
    string letters = "ABCDEFGJIK";
    
    //print out line of numbers from 0 - 9 with a space in front 
    for (int i = 0; i <10; i++){
        if(i == 0){
            cout << " ";
        }
        
        cout << i << " ";
    }
    
    
    //print out first letter of alphabet, print 10 characters from vector with a new line
    int j = 0;
        
    
       // cout << letters[j] << " ";
        for(int i = 0; i < 100; i++){
            
            //line break every 10
            if(i%10 <= 0){
                cout<<endl;
                cout << letters[j] << " ";
                j++;
            }
            cout << board1[i] << " ";
     }
    cout << endl;
}
//################################################################################################################################
Board Human::get_Track_Board(){
    return track_Board_;
}
//this function will take a parameter and use it to determine if an attack was a hit or a miss, if it is a miss it will replace the 'o' on
//the board with a 'M', if it is a hit it will replace the 'S' on the board with a 'H'
void Human::attack(int newAttack){
    // check to see if the position on the board is an s or an o
    if(Player_Board.getBoard().at(newAttack - 1) == 'S')
    {
        Player_Board.getBoard().at(newAttack - 1) = 'H';
        cout << "Direct hit!"<< endl;
        Player_Board.displayBoard1();
    }
    // if its an o replace it with m on the tracking board
    // if its an s replace it with h on the tracking board and subtract one from hitpoints.
}