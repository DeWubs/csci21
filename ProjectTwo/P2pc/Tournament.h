/*
Tournament .h
Robert Prouty
april 10th 2018
header for a Tournament  
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "queue.h"
#include "stack.h"
using namespace std;

#ifndef TOURNAMENT_H
#define TOURNAMENT_H

template<typename list_type>
class Tournament{
    private:
       struct Player{
            Player(string name){
                name_ = name;
            }
            string name_;
            int games_played = 0;
        };
        vector<Player> players_;
        list_type player_list_;
    public:
        /*it starts the tournament by calling these three functions
        @param file - its the name of the file */
        void start(char * file){
            cout << "start has been called" << endl;
            completeList(file);
            rounds();
            stats();
        }
        /*fills the list with usernames
        @param file - its the filename POGGERS*/
        void completeList(char * file){
            ifstream fst;
            
            fst.open(file);
            if(!fst.is_open()){
                cout << "Hey dumbo invalit file\n";
                return;
            }
            while(!fst.eof()){
                cout << "file Loaded" << endl;
                string temp;
                fst >> temp;
                player_list_.push(temp);
                players_.push_back(temp);
            }
            fst.close();
        }
        /*will determine winners of rounds and the tournament, sweet af if you ask me*/
        void rounds(){
            int round_ = 1;
            while(player_list_.size() > 1){
                string temp;
                string temp2;
                string w;
                string l;
                temp = player_list_.at(0);
                player_list_.pop();
                temp2 = player_list_.at(0);
                player_list_.pop();
                
                for(int i = 0; i < players_.size(); i++){
                    if(players_.at(i).name_ == temp || players_.at(i).name_ == temp2){
                        players_.at(i).games_played++;
                    }
                }
                if(temp < temp2){
                    w = temp;
                    l = temp2;
                }
                else{
                    w = temp2;
                    l = temp;
                }
                cout <<"                    Round " << round_ << "                           " << endl;
                cout <<"Winner: " << w << endl;
                cout <<"Loser : " << l << endl;
                
                player_list_.push(w);
                round_++;
            }
            for(int i = 0; i < 31; i++){
                cout << "#";
            }
            cout << endl;
            cout << "Tournament WINNER: " << player_list_.at(0) << endl;
            
            for (int i = 0; i < 31; i++) {
                cout << "#";
            }
            cout << endl;
        }
        /* prints the stats of the games played*/
        void stats(){
            double s = 0;
            for(int i = 0; i < players_.size(); i++){
                 cout << players_.at(i).name_ << " played " << players_.at(i).games_played;
                if(players_.at(i).games_played > 1){
                    cout << " games" << endl;
                }
                else{
                    cout << " game" << endl;
                }
                s += players_.at(i).games_played;
            }
            for(int i = 0; i < 31; i++){
                cout << "#";
            }
            cout << endl;
            cout << "average games played: " << fixed << setprecision(2) << s / players_.size() << endl;
            
            bool sorted = false;
            while(!sorted){
                bool swap = false;
                for(int i = 0; i < players_.size(); i++){
                    if(i != (players_.size() - 1) && (players_.at(i).games_played > players_.at(i + 1).games_played)){
                        Player t = players_.at(i);
                        players_.at(i) = players_.at(i + 1);
                        players_.at(i + 1) = t;
                        swap = true;
                    }
                }
                if(!swap){
                    sorted = true;
                }
            }
            cout << "median games played: " << players_.at(((players_.size() + 1) / 2) - 1).games_played << endl;
            cout << "total games played : " << setprecision(0) << s / 2 << endl;
            for(int i = 0; i < 31; i++){
                cout << "#";
            }
            cout << endl;
        }
};


#endif