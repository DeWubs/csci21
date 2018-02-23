/*
* NAME                : PROJECT 1 PART b
* CREATOR             : ROBERT PROUTY
* DATE CREATED        : 2-17-18
* PROJECT DESCRIPTION : this project will take in two files, an account file and a trans file, with the account file it will take in each part
*                       and use the different information to preform what needs to be done the most important parts being card number and card
*                       type. the second one will stored in a vector and used to make the transaction lists, it will store purchases it will then
*                       deduct the transaction ammount from the balance and make sure it doesnt exceed it. in the end it will print a report.
*
*
*
*                       ACCEPTED CARD TYPES:        BIN PREFIX:
*                       AMERICAN EXTRESS   :         34 | 37 
*                       DISCOVER           :         6011 | 622126 – 622925 | 644 – 649 | 65
*                       MASTER CARD        :         51 – 55
*                       VISA               :         4
*                       ANY CARD WITH A BIN NUMBER OUTSIDE OF THESE WILL NOT BE A VALID CARD
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

class Transaction
{
    private:
    
    string date_;
	int transactionNumber_;
	string vendor_;
	double purchaseAmmount_;
	
	public:
	Transaction();
	Transaction(string newDate);
	Transaction(string newDate, int newTransactionNumber);
    Transaction(string newDate, int newTransactionNumber, string newVendor);
	Transaction(string newDate, int newTransactionNumber, string newVendor, double newPurchaseAmmount);
	
	void setDate(string newDate);
	void setTransactionNumber(int newTransactionNumber);
	void setVendor(string newTransactionNumber);
	void setPurchaseAmmount(double newPurchaseAmmount);
	
	void Populate();
	
	string getDate();
	int getTransactionNumber();
	string getVendor();
	double getPurchaseAmmount();
};

class Account
{
    private:
        string firstName_;
        string lastName_;
        string type_;
        string cardNumber_; 
        double currentBalance_;
        vector<Transaction> transactionList;
    public:
        Account();
        Account(string newFirstName);
        Account(string newFirstName, string newLastName);
        Account(string newFirstName, string newLastName, string newType);
        Account(string newFirstName, string newLastName, string newType, string newCardNumber);
        Account(string newFirstName, string newLastName, string newType, string newCardNumber, double newCurrentBalance);
        
        bool isValidBin(string newCardNumber);
        bool isValidCard(string newCardNumber);
        
        void setFirstName(string newFirstName);
        void setLastName(string newLastName);
        void setType(string newType);
        void setCardNumber(string newCardNumber);
        void setCurrentBalance(double newCurrentBalance);
        void setTransaction(Transaction &T);
        
        void getTransaction();
        string getFirstName();
        string getLastName();
        string getType();
        string getCardNumber();
        double getCurrentBalance();
        
        virtual void AllowTransaction(){};
        virtual void DenialSummary(){};
        //virtual void PrintStatment(){};
};

class GoldCard: public Account
{
    public:
    void AllowTransaction();
   
    void DenialSummary();
    
    //void PrintStatment();
};

class PlatinumCard: public Account
{
    public:
    void AllowTransaction();
    
    void DenialSummary();
    
   // void PrintStatment();
};

class CorporateCard: public Account
{
    public:
    void AllowTransaction();
    
    void DenialSummary();
    
    //void PrintStatment();
    
};