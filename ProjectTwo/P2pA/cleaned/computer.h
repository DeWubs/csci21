#ifndef COMPUTER_H
#define COMPUTER_H
#include "player.h"
#include "board.h"
#include <queue>
using namespace std;
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
#endif