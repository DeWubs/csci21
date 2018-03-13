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


using namespace std;

class Board{
    private:
        vector <char> board1;
    public:
        Board();
        Board(vector <char> newVector);
        void setBoard1(string newFile);
        void displayBoard1();
        vector <char> getBoard();
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
       virtual void attack(int num );
        Board get_Track_Board();
    
};