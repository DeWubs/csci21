#include "pr.h"

Card::Card()
{
    cardNumber = "no Card Number";
}

Card::Card(string cardNumber)
{
    cardNumber = newCardNumber;
}

Card::Card(string cardNumber, string firstName)
{
    cardNumber = newCardNumber;
    firstName = newFirstName;
}

Card::Card(string cardNumber, string firstName, string lastName)
{
    cardNumber = newCardNumber;
    firstName = newFirstName;
    lastName = newLastName;
}

Card::Card(string cardNumber, string firstName, string lastName, double balance)
{
    cardNumber = newCardNumber;
    firstName = newFirstName;
    lastName = newLastName;
    balance = newBalance;
}

string Card::getCardNumber()
{
    return cardNumber;
}

string Card::getFirstName()
{
    return firstName;
}

string Card::getLastName()
{
    return lastName;
}

double Card::getBalance()
{
    return balance;
}

void Card::setCardNumber(string newCardNumber)
{
    cardNumber = newCardNumber;
}

void Card::setFirstName(string newFirstName)
{
    firstName = newFirstName;
}

void Card::setLastName(string newLastName)
{
    lastName = newLastName;
}

void Card::setBalance(double newBalance)
{
    balance = newBalance;
}

int main()
{
    ifstream cards("cards1.txt");
    string cardNumber;
   
    while(!cards.eof())
    {
        cards >> cardNumber >> firstName >> lastName >> balance;
        cout << cards;
    }
    
    
    return 0;
}