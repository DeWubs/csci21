//#ifndef BOARD_H
//#define BOARD_H
/*
* NAME                : PROJECT 2 PART a
* CREATOR             : ROBERT PROUTY
* DATE CREATED        : 3-6-18
* PROJECT DESCRIPTION : This project is the first half of a battleship game, it has a player put in attacks and sees
*                       if it hits or misses. It uses a couplpe classes to achieve this.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <ctime>



using namespace std;

class Board{
    private:
        vector <char> board1;
    public:
        Board();
        Board(vector <char> newVector);
        void setBoard1(string newFile);
        void setBoard1(vector <char> newBoard);
        void displayBoard1();
        vector <char> getBoard();
        char getPosition(int newPosition);
        void hit(int newPosition);
        void miss(int newPosition);
};
//#endif

class Player{
    protected:
        int hit_Points_;
        int board_attack_;
        Board Player_Board;
    public:
        virtual void attack(){};
};

class Human : protected Player{
    private:
        Board track_Board_;
    public:
        //Human();
        //Human(vector <char> new_Player_Board);
        void setBoard(vector <char> b);
        virtual void attack(int num );
        // vector <char> get_track_Board();
    
};

class Computer: public Player{
    private:
        Board track_Board_C;
        queue<int> attackNums_;
        
        int attackNum_;
        
        bool first_;
        
    
    public:
        Computer();
        virtual void attack(int num);
        void setBoardC(vector <char> c);
        void turn();
        int getAttackNum_();
        
};