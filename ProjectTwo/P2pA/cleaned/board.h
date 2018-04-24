#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>     
#include <sstream>
#include <cctype>
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
#endif