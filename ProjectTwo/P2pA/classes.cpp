#include "classes.h"
//returns a vector
//getting a board vector
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
// @param vector of charaters
// constructor
Board::Board(vector <char> newVector){
    board1.resize(100);
    for(int i = 0; i<=board1.size(); i++){
       board1[i] = newVector[i]; 
    }
    
}

// will take our positions file and use it to populate the 100 slots of the board vector with what is in the input file
//@param file name
//will occupy the vctor with what is in the file
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
// overloaded set board that takes a vector instead so that i can pretty much acess it in the human class
// @param vector
// sets one vector to equal another
void Board::setBoard1(vector <char> newBoard){
    for(int i = 0; i< 100; i++){
        board1[i] = newBoard[i];
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
//@ param intger(position)
// returns a char from the position - 1 int he corrisponding vector
char Board::getPosition(int newPosition){
     char Position;
     //displayBoard1();
     Position = board1.at(newPosition - 1);
     //cout<<"Pos: "<<Position<<endl;
     return Position;
}
//@ param int(position)
// sets a position in corrisponding vector equal to H
void Board::hit(int newPosition){
     board1.at(newPosition - 1) = 'H';
}

//@ param int (position)
//sets a position in corrisponding vector to m
void Board::miss(int newPosition){
    board1.at(newPosition - 1) = 'M';
}
//################################################################################################################################
// Human::Human(){
    
// }

// Human::Human(vector <char> new_Player_Board){
//     Player_Board.setBoard1;
    
// }

//################################################################################################################################

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