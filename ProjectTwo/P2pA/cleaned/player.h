#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>     
#include <sstream>
#include <cctype>

using namespace std;
#include "board.h"
class Player{
    protected:
        int hit_Points_;
        Board Player_Board;
    public:
        virtual void attack(){};
};
#endif