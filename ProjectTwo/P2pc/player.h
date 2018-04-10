/*
player.h
Robert Prouty
april 10th 2018
header for a player 
*/
#include <string>
using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class Player{
    private:
        string userName_;
        int numOfGames_;
    public:
        /*setters for number of games played and user names
        @param newNumOfGames - number of games
        @param newUserName - username
        */
        void setNumOfGames(int newNumOfGames);
        void setUserName(string newUserName);
        // this increments the number of games a of a player
        void incGames();
        /*
        getters for username and number of games
        */
        string getUsername();
        int getNumOfGames();
};
#endif