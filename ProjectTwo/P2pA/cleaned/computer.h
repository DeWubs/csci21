#ifndef COMPUTER_H
#define COMPUTER_H
#include "player.h"
#include "board.h"
#include "node.h"
#include "queue.h"
using namespace std;
class Computer: public Player{
    private:
        Board track_Board_C;
        Queue<int> attackNums_;
        
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