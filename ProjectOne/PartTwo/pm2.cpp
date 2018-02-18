#include "pr.h"

int main()
{  
    Transaction transOne;
    Account accountOne;
    GoldCard goldOne;
    PlatinumCard platOne;
    CorporateCard coorpOne;
    
    ifstream accounts("account.txt");
    // transOne.Populate();
    
    // ifstream transactions("trans.txt");

    // getline(transactions, accountOne.transactionList[], ':');
    
    /*
    *   this function is going through the account text file and doing logic to see which function it is doing on which card
    * if it is a gold card it will do the functions for the corrisponding gold functions 
    * if it is platunum it will do the functions for the corrisponding platinum functions
    * and likewise for corperate
    *
    *
    *
    */
    //accountOne.populate();
    while(accounts.eof())
    {
        // getline(accounts, accountOne.getCardNumber(), ' ');
        // getline(accounts, accountOne.getFirstName(), ' ');
        // getline(accounts, accountOne.getLastName(), ' ');
        // getline(accounts, accountOne.getType(), ' ');
        // getline(accounts, accountOne.getCurrentBalance(), ' ');
        
             accountOne.populate();
        
            if (accountOne.isValidBin(accountOne.getCardNumber())== true && accountOne.isValidCard(accountOne.getCardNumber()) == true)
            {
                cout << "hey hey i am valid card\n";
                if(accountOne.getType() == "Gold")
                {
                    if(accountOne.getCurrentBalance() <= 3000.00)
                    {
                        goldOne.AllowTransaction();
                    }
                    else if (accountOne.getCurrentBalance() >= 3000.00)
                    {
                        goldOne.DenialSummary();
                    }
                }
                else if(accountOne.getType() == "Platinum")
                {
                    if(accountOne.getCurrentBalance() <= 4000.00)
                    {
                        platOne.AllowTransaction();
                    }
                    else if(accountOne.getCurrentBalance() >= 4000.01 && accountOne.getCurrentBalance() <= 5000.00)
                    {
                         platOne.AllowTransaction();
                         cout << "you have overdrawn\n";
                    }
                    else if(accountOne.getCurrentBalance() >= 5000.00)
                    {
                        platOne.DenialSummary();
                    }
                }
                else if(accountOne.getType() == "Corporate")
                {
                    if(accountOne.getCurrentBalance() <= 10000.00)
                    {
                        coorpOne.AllowTransaction();
                    }
                    else if(accountOne.getCurrentBalance() >= 10000.01 && accountOne.getCurrentBalance() <= 15000.00)
                    {
                         coorpOne.AllowTransaction();
                         cout << "you have overdrawn\n";
                    }
                    else if (accountOne.getCurrentBalance() >= 15000.00)
                    {
                        coorpOne.DenialSummary();
                    }
                }
                else
                cout << "invalid card Type\n";
            }
            else
                {
                    cout << "hey dumbo im not valid\n";
                }
            
    }
    
    return 0;
}