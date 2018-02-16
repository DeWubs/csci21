struct Transaction
{
    string date_;
	int transactionNumber_;
	string vendor_;
	int purchaseAmmount_;
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
        
        string getFirstName();
        string getLastName();
        string getType();
        string getCardNumber();
        double getCurrentBalance();
        
        virtual bool AllowTransaction(){};
        virtual void DenialSummary(){};
        virtual void PrintStatment(){};
};

class GoldCard: public Account
{
   bool AllowTransaction();
   
   void DenialSummary();
    
   void PrintStatment();
};

class PlatinumCard: public Account
{
    bool AllowTransaction();
    
    void DenialSummary();
    
    void PrintStatment();
};

class CorporateCard: public Account
{
    bool AllowTransaction();
    
    void DenialSummary();
    
    void PrintStatment();
    
};