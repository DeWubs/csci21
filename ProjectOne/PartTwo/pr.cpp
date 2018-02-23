#include "pr.h"

Transaction::Transaction()
{
    date_ = "00/00/0000";
}

Transaction::Transaction(string newDate)
{
    date_ = newDate;
    transactionNumber_ = 0;
}


Transaction::Transaction(string newDate, int newTransactionNumber)
{
    date_ = newDate;
    transactionNumber_ = newTransactionNumber;
    vendor_ = "no Vendor";
}

Transaction::Transaction(string newDate, int newTransactionNumber, string newVendor)
{
    date_ = newDate;
    transactionNumber_ = newTransactionNumber;
    vendor_ = newVendor;
    purchaseAmmount_ = 0.00;
}

Transaction::Transaction(string newDate, int newTransactionNumber, string newVendor, double newPurchaseAmmount)
{
    date_ = newDate;
    transactionNumber_ = newTransactionNumber;
    vendor_ = newVendor;
    purchaseAmmount_ = newPurchaseAmmount;
}

void Transaction::setDate(string newDate)
{
    date_ = newDate;
}

void Transaction::setTransactionNumber(int newTransactionNumber)
{
    transactionNumber_ = newTransactionNumber;
}

void Transaction::setVendor(string newVendor)
{
    vendor_ = newVendor;
}

void Transaction::setPurchaseAmmount(double newPurchaseAmmount)
{
    purchaseAmmount_ = newPurchaseAmmount;    
}

string Transaction::getDate()
{
    return date_;
}

int Transaction::getTransactionNumber()
{
    return transactionNumber_;
}

string Transaction::getVendor()
{
    return vendor_;
}

double Transaction::getPurchaseAmmount()
{
    return purchaseAmmount_;
}

// void Transaction::Populate()
// {
//      ifstream transactions("trans.txt");
    
//   cout << "hey transaction Populate is working\n";
//     getline(transactions, , ':');
// }

Account::Account()
{
    transactionList.resize(0);
    firstName_ = "no firstname";
    lastName_ = "no Lastname";
    type_ = "no type";
    cardNumber_ = "no card number";
    currentBalance_ = 0.0;
}

Account::Account(string newFirstName)
{
    transactionList.resize(0);
    firstName_ = newFirstName;
    lastName_ = "no Lastname";
     type_ = "no type";
    cardNumber_ = "no card number";
    currentBalance_ = 0.0;
}


Account::Account(string newFirstName, string newLastName)
{
    transactionList.resize(0);
    firstName_ = newFirstName;
    lastName_ = newLastName;
    type_ = "no type";
    cardNumber_ = "no card number";
    currentBalance_ = 0.0;
}

Account::Account(string newFirstName, string newLastName, string newType)
{
    transactionList.resize(0);
    firstName_ = newFirstName;
    lastName_ = newLastName;
    type_ = newType;
    cardNumber_ = "no card number";
     currentBalance_ = 0.0;
}

Account::Account(string newFirstName, string newLastName, string newType, string newCardNumber)
{
    transactionList.resize(0);
    firstName_ = newFirstName;
    lastName_ = newLastName;
    type_ = newType;
    cardNumber_ = newCardNumber;
    currentBalance_ = 0.0;
}

Account::Account(string newFirstName, string newLastName, string newType, string newCardNumber, double newCurrentBalance)
{
    transactionList.resize(0);
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

void Account::setTransaction(Transaction &T)
{
    Transaction newT;
    //cout<<"Vendor "<<T.getVendor()<<" amt: "<<T.getPurchaseAmmount()<<" Date: "<<T.getDate()<<endl;
    newT.setVendor(T.getVendor());
    newT.setPurchaseAmmount(T.getPurchaseAmmount());
    newT.setDate(T.getDate());
    newT.setTransactionNumber(T.getTransactionNumber());
    transactionList.push_back(newT);
}

void Account::getTransaction(){
    cout<<transactionList.size()<<endl;
    for (int i=0;i<transactionList.size(); i++)
    {
        cout<<transactionList[i].getVendor()<<" ";
        cout<<transactionList[i].getPurchaseAmmount()<<endl;
    }
}

void GoldCard::AllowTransaction()
{
    cout << "i am valid, you are within your balance, for the gold card\n";
}

void GoldCard::DenialSummary()
{
     cout << "you dont have enough money in here, for the gold card\n";
}

void PlatinumCard::AllowTransaction()
{
    
    cout << "i am valid, you are within your balance, for the platinum card\n";
}

void PlatinumCard::DenialSummary()
{
     cout << "you dont have enough money in here, for the platinum card\n";
}

void CorporateCard::AllowTransaction()
{
    cout << "i am valid, you are within your balance, for the corperate card\n";
}

void CorporateCard::DenialSummary()
{
     cout << "you dont have enough money in here, for the corperate card\n";
}
/* 
this fuction will take in the card number and check to see if it is a valid card type, one of the four major card types. it will take in the first couple digits of the card number
and process if it is or isnt a valid bin number upon completion it will cout if it is a valid card type and what vendor its from and if it isnt it will say unknown card type.
*/
bool Account::isValidBin(string newCardNumber)
{
    int binNum;
        stringstream sso; 
        if(cardNumber_[0] == '3' && (cardNumber_[1] == '4' || cardNumber_[1] == '7'))
        {
            //cout<<"ae"<<endl;
            return true;
        }
        else if (cardNumber_[0] == '6')
        {
            // use logic to make sure the rest of the integers are valid
           
            
            sso << cardNumber_[0] << cardNumber_[1] << cardNumber_[2] << cardNumber_[3];
            sso >> binNum;
            if(binNum == 6011)
            {
                //cout << "made it here\n";
                //cout<<"discover"<<endl;
                return true;
            }
            
            sso << cardNumber_[0] << cardNumber_[1] << cardNumber_[2] << cardNumber_[3] << cardNumber_[4] << cardNumber_[5];
            sso >> binNum;
             if (binNum >= 622126 && binNum <= 622925)
            {
               // cout<<"discover"<<endl;

                return true;
            }
            
            sso << cardNumber_[0] << cardNumber_[1] << cardNumber_[2];
            sso >> binNum;
             if (binNum >= 644 && binNum <= 649)
            {
               // cout<<"discover"<<endl;
                
                return true;
            }
            sso << cardNumber_[0] << cardNumber_[1];
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
        else if (cardNumber_[0] == '5' )
        {
            sso << cardNumber_[0] << cardNumber_[1];
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
        else if (cardNumber_[0] == '4')
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

bool Account::isValidCard(string cardNumber_)
{
    int cardNumberS[cardNumber_.length() - 1];
   // cout << "got dumped\n";
    

        int sum = 0;
        int evenSum, oddSum = 0;
       // cards >> cardNumber;
        //cout << cardNumber_ << endl;
        // cout << cardNumber<<endl;
        // int cardNumberS[cardNumber.length() - 1];
        // cout << "got dumped\n";
    
        
        for(int i=0; i< cardNumber_.size(); i++)
    {
        cardNumberS[i]= cardNumber_.at(i)- 48;
        //cout<< "im converted to an int\n";
    }
       
       
        // luhn algorithm thanks to https://youtu.be/A3Kqj2dbgqA
        for (int i = cardNumber_.size() - 1; i>= 0; i--)
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

