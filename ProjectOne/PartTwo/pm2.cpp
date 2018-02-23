#include "pr.h"

int main()
{  
    Transaction transOne;
    Account accountOne;
    GoldCard goldOne;
    PlatinumCard platOne;
    CorporateCard coorpOne;
    
//###########################################################################################################################
        
    ifstream transactions("trans.txt");

    string d;
    string cnub;
    string dates;
    int nub;
    string ven;
    double amm;

    while(!transactions.eof())
    {
        getline(transactions, d);
        
        stringstream ss;
        replace(d.begin(), d.end(), ':', ' ');
       // cout << d << endl;
        ss << d;
        ss >> cnub;
        
        ss >> dates;
        ss >> nub;
        ss >> ven;
        ss >> amm;
      
        accountOne.setCardNumber(cnub);
        transOne.setDate(dates);
        transOne.setTransactionNumber(nub);
        transOne.setVendor(ven);
        transOne.setPurchaseAmmount(amm);
        //cout<<"Vendor "<<transOne.getVendor()<<" amount: "<<transOne.getPurchaseAmmount()<<endl;
        accountOne.setTransaction(transOne);
        
        accountOne.getTransaction();
        //transactions.ignore(1);
    }
    
//###########################################################################################################################
    
    ifstream accounts("account.txt");
    /*
    *   this function is going through the account text file and doing logic to see which function it is doing on which card
    * if it is a gold card it will do the functions for the corrisponding gold functions 
    * if it is platunum it will do the functions for the corrisponding platinum functions
    * and likewise for corperate
    *
    *
    *
    */


    string number;
    string fName;
    string lName;
    string cType;
    double cBal;
    while(!accounts.eof())
    {
       
        accounts >> number;
        accounts >> fName;
        accounts >> lName;
        accounts >> cType;
        accounts >> cBal;
        
        accountOne.setCardNumber(number);
        accountOne.setFirstName(fName);
        accountOne.setLastName(lName);
        accountOne.setType(cType);
        accountOne.setCurrentBalance(cBal);
        
        
            if (accountOne.isValidBin(accountOne.getCardNumber())== true && accountOne.isValidCard(accountOne.getCardNumber()) == true)
            {
                //cout << "hey hey i am valid card\n";
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
    //accounts.close();
    
//     ifstream transactions("trans.txt");

//     string d;
//     string cnub;
//     string dates;
//     int nub;
//     string ven;
//     double amm;
//     stringstream ss;
//     while(!transactions.eof())
//     {
//         getline(transactions, d);
        
        
//         replace(d.begin(), d.end(), ':', ' ');
//         cout << d << endl;
//         ss << cnub;
//         ss << d;
//         ss >> dates;
//         ss >> nub;
//         ss >> ven;
//         ss >> amm;
      
//         accountOne.setCardNumber(cnub);
//         transOne.setDate(dates);
//         transOne.setTransactionNumber(nub);
//         transOne.setVendor(ven);
//         transOne.setPurchaseAmmount(amm);
//         accountOne.setTransaction(transOne);
        
        
        
    
// //      cout<<transOne.getDate()<<" "<<transOne.getTransactionNumber()<<" "<<transOne.getVendor()<<" "<<transOne.getPurchaseAmmount()<<endl;
        
//     }
    
  


    
    
    
    return 0;
}