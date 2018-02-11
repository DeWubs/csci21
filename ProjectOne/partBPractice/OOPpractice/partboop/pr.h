/*
in this program ill be playing around with classes stetters and getters, to see if i can manipulate the file input in the way i want to.
*/
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Card
{
    private:
        string cardNumber;
        string firstName;
        string lastName;
        double balance;
    
    public:
        Card();
        Card(string NewCardNumber, string newFirstName);
        Card(string NewCardNumber, string newFirstName, string newLastName);
        Card(string NewCardNumber, string newFirstName, string newLastName, double newBalance);

        void setCardNumber(string newCardNumber);
        void setFirstName(string newFirstName);
        void setLastName(string newLastName);
        void setBalance(double newBalance);
        
        string getCardNumber();
        string getFirstName();
        string getLastName();
        double getBalance();
        
};
