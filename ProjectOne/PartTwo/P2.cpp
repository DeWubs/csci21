#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "p2.h"

using namespace std;

/*
this section is the really boring part of the coding, the "donkey work", as it were, setters, getters and, constructer set up, not much to say about it other than its important, but still very
boring to read and write :P
*/ 

Account::Account()
{
    firstName_ = "no name";
}

Account::Account(string newFirstName)
{
    firstName_ = newFirstName;
    lastName_ = "no Lastname";
}

Account::Account(string newFirstName, string newLastName)
{
    firstName_ = newFirstName;
    lastName_ = newLastName;
    type_ = "no type";
}

Account::Account(string newFirstName, string newLastName, string newType)
{
    firstName_ = newFirstName;
    lastName_ = newLastName;
    type_ = newType;
    cardNumber_ = "no card number";
}

Account::Account(string newFirstName, string newLastName, string newType, string newCardNumber)
{
    firstName_ = newFirstName;
    lastName_ = newLastName;
    type_ = newType;
    cardNumber_ = newCardNumber;
    currentBalance_ = 0.0;
}

Account::Account(string newFirstName, string newLastName, string newType, string newCardNumber, double newCurrentBalance)
{
    firstName_ = newFirstName;
    lastName_ = newLastName;
    type_ = newType;
    cardNumber_ = newCardNumber;
    currentBalance_ = newCurrentBalance;
}

string Account::getFirstName()
{
    return firstName_;
}

string Account::getLastName()
{
    return lastName_;
}

string Account::getType()
{
    return type_;
}

string Account::getCardNumber()
{
    return cardNumber_;
}

double Account::getCurrentBalance()
{
    return currentBalance_;
}

void Account::setFirstName(string newFirstName)
{
    firstName_ = newFirstName;
}

void Account::setLastName(string newLastName)
{
    lastName_ = newLastName;
}

void Account::setType(string newType)
{
    type_ = newType;
}

void Account::setCardNumber(string newCardNumber)
{
    cardNumber_ = newCardNumber;
}

void Account::setCurrentBalance(double newCurrentBalance)
{
    currentBalance_ = newCurrentBalance;
}
/* 
this fuction will take in the card number and check to see if it is a valid card type, one of the four major card types. it will take in the first couple digits of the card number
and process if it is or isnt a valid bin number upon completion it will cout if it is a valid card type and what vendor its from and if it isnt it will say unknown card type.
*/
bool Account::isValidBin(string newCardNumber)
{
    int binNum;
        stringstream sso; 
        if(newCardNumber[0] == '3' && (newCardNumber[1] == '4' || newCardNumber[1] == '7'))
        {
            //cout<<"ae"<<endl;
            return true;
        }
        else if (newCardNumber[0] == '6')
        {
            // use logic to make sure the rest of the integers are valid
           
            
            sso << newCardNumber[0] << newCardNumber[1] << newCardNumber[2] << newCardNumber[3];
            sso >> binNum;
            if(binNum == 6011)
            {
                //cout << "made it here\n";
                //cout<<"discover"<<endl;
                return true;
            }
            
            sso << newCardNumber[0] << newCardNumber[1] << newCardNumber[2] << newCardNumber[3] << newCardNumber[4] << newCardNumber[5];
            sso >> binNum;
             if (binNum >= 622126 && binNum <= 622925)
            {
               // cout<<"discover"<<endl;

                return true;
            }
            
            sso << newCardNumber[0] << newCardNumber[1] << newCardNumber[2];
            sso >> binNum;
             if (binNum >= 644 && binNum <= 649)
            {
               // cout<<"discover"<<endl;
                
                return true;
            }
            sso << newCardNumber[0] << newCardNumber[1];
            sso >> binNum;
             if (binNum == 65)
            {
                //cout<<"discover"<<endl;

                return true;
            }
            else 
            {
                //cout << "Unknown card type!\n";
                return false;
            }
        }
        else if (newCardNumber[0] == '5' )
        {
            sso << newCardNumber[0] << newCardNumber[1];
            sso >> binNum;
            if(binNum >= 51 && binNum <= 55)
            {
                //cout<<"master"<<endl;
                return true;
            }
            else
            {
                //cout << "Unknown card type! (master)\n";
                return false;
            }
        }
        else if (newCardNumber[0] == '4')
        {
            //cout<<"visa"<<endl;
            return true;
        }
        else
        {
            //cout << "Unknown card type! (visa)\n";
            return false;
        }
}
/*
this checks to see if the card is valid, even if a bin number is valid it will have to go through this to check if the rest of the card is valid, it will run luhns algorithm on 
the card number to check to see if it is valid, if its valid it will return true if it's invalid it will return false.
*/

bool Account::isValidCard(string newCardNumber)
{
    int cardNumberS[newCardNumber.length() - 1];
   // cout << "got dumped\n";
    

        int sum = 0;
        int evenSum, oddSum = 0;
       // cards >> cardNumber;
        cout << newCardNumber << endl;
        // cout << cardNumber<<endl;
        // int cardNumberS[cardNumber.length() - 1];
        // cout << "got dumped\n";
    
        
        for(int i=0; i< newCardNumber.size(); i++)
    {
        cardNumberS[i]= newCardNumber.at(i)- 48;
        //cout<< "im converted to an int\n";
    }
       
       
        // luhn algorithm thanks to https://youtu.be/A3Kqj2dbgqA
        for (int i = newCardNumber.size() - 1; i>= 0; i--)
        {
            
            int p;
            int num = cardNumberS[i];
            //cout<< num << endl;
            if(i % 2 == 1)
            {
                p = num * 2;
                if(p > 9)
                {
                    p = p - 9;
                }
                evenSum += p;
               // cout<< evenSum << endl;
            }
            else
            {
                p = num;
                oddSum += p;
                //cout<< oddSum<< endl;
            }
            
        }
    // checking to see if the total sum is % 10 with remainder of 0
        sum = evenSum + oddSum;
        
        if (sum % 10 == 0)
        {
            //cout<<"true, valid card\n";
            return true;
        }
        else
        {
            //cout<<"false, invalid luhn!!\n";
           return false;
        }
}

/*
these functions will go through and lay out which transactions are allowed and which arent, it will also print out the transaction list for each card type, using polymorphism the 
program can tell which one to use in which situation. I have several different functions called the same thing, but they will do things differently depending on the card type.
*/
bool GoldCard::AllowTransaction( )
{
    if(newCurrentBalance >= 3000.00)
    {
        newCurrentBalance = newCurrentBalance - purchaseAmmount_;
        return true;
    }
    else
        return false;
}

void GoldCard::DenialSummary()
{
    cout << "your card was denied because: \n";
}

void GoldCard::PrintStatment()
{
   
}

// bool PlatinumCard::AllowTransaction()
// {
//     if(newCurrentBalance >= 5000.00)
//     {
//       newCurrentBalance = newCurrentBalance - purchaseAmmount_;
//         return true;
//     }
//     else if(currentBalance_ >=6000.00)
//     {
//         newCurrentBalance = newCurrentBalance - purchaseAmmount_;
//         return true;
//     }
//     else
//         return false; 
// }

// void PlatinumCard::DenialSummary()
// {
//     cout << "your card was denied because: \n";
// }


// void PlatinumCard::PrintStatment()
// {
    
// }

// bool CorporateCard::AllowTransaction()
// {
//     if(newCurrentBalance >= 10000.00)
//     {
//         newCurrentBalance = newCurrentBalance - purchaseAmmount_;
//         return true;
//     }
//     else if(newCurrentBalance >=15000.00)
//     {
//         newCurrentBalance = newCurrentBalance - purchaseAmmount_;
//         return true;
//     }
//     else
//         return false; 
// }

// void CorporateCard::DenialSummary()
// {
//     cout << "your card was denied because: \n";
// }


// void CorporateCard::PrintStatment()
// {
    
// }

int main()
{
    ifstream accounts("account.txt");
    Account AccountOne;
   
    while(!accounts.eof())
    {
        accounts >> newCardNumber >> newFirstName >> newLastName >> newType >> newCurrentBalance;
    
        if (isValidBin()== true && isValidCard() == true)
        {
            
        }
        else
        {
       
        }
    }
    
    return 0;
}