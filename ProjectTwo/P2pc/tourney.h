/*
tourney.h
Robert Prouty
april 10th 2018
header for a tourney 
*/
#include "player.h"
#include "stack.h"
#include "queue.h"
#include <algorithim>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
#ifndef TOURNEY_H
#define TOURNEY_H

class Tourney{
    private:
        string containerType;
        Stack<string> stackPlayers;
        Queue<string> queuePlayers;
        vector<string> names;
        vector<int> numOfGames;
    public:
        Tourney(string container);
        Tourney();
        
        string winner(string p1, string p2);
        void makeList(string fileName);
        
        float avg();
        int medi();
        string getPlayers();
        string getNextPlayer();
        void addPlayer(string name);
        int playersRemaining();
};