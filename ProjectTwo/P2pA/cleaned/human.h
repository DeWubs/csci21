#ifndef HUMAN_H
#define HUMAN_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>     
#include <sstream>
#include <cctype>

#include "player.h"
#include "board.h"

class Human : protected Player{
    private:
        Board track_Board_;
    public:
        void setBoard(vector <char> b);
        virtual void attack(int num );
};

#endif