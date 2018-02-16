
/*
* NAME                : PROJECT 1 PART A
* CREATOR             : ROBERT PROUTY
* DATE CREATED        : 2-1-18
* PROJECT DESCRIPTION :     THIS PROGRAM WILL TAKE A FILE AND PREFORM LUHN'S ALGORTIHM ON IT TO SEE IF IT IS A VALID CARD AND
*                       TO TELL YOU WHAT CARD COMPANY IT IS FROM. IT WILL NOT ACCEPT ANY CARD IT DOES NOT RECOGNIZE THE BIN
*                       NUMBER TO AND OUTPUT UNKOWN CARD TYPE... HOPFULLY
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

using namespace std;
/*
    THE FUNCTION BELOW WILL TAKE IN A FILE FILLED WITH CARD NUMBERS AND TAKE THE BIN NUMBER AND SEE IF ITS VALID BY USING AN ASSORTMENT OF LOGIC IF ITS VALIT IT WILL 
RETURN TRUE, IF NOT IT WILL RETURN FALSE
*/


bool isValidBin(string cardNumber)
{
    
        int binNum;
        stringstream sso; 
        if(cardNumber[0] == '3' && (cardNumber[1] == '4' || cardNumber[1] == '7'))
        {
            cout<<"ae"<<endl;
            return true;
        }
        else if (cardNumber[0] == '6')
        {
            // use logic to make sure the rest of the integers are valid
           
            
            sso << cardNumber[0] << cardNumber[1] << cardNumber[2] << cardNumber[3];
            sso >> binNum;
            if(binNum == 6011)
            {
                //cout << "made it here\n";
                cout<<"discover"<<endl;
                return true;
            }
            
            sso << cardNumber[0] << cardNumber[1] << cardNumber[2] << cardNumber[3] << cardNumber[4] << cardNumber[5];
            sso >> binNum;
             if (binNum >= 622126 && binNum <= 622925)
            {
                cout<<"discover"<<endl;

                return true;
            }
            
            sso << cardNumber[0] << cardNumber[1] << cardNumber[2];
            sso >> binNum;
             if (binNum >= 644 && binNum <= 649)
            {
                cout<<"discover"<<endl;
                
                return true;
            }
            sso << cardNumber[0] << cardNumber[1];
            sso >> binNum;
             if (binNum == 65)
            {
                cout<<"discover"<<endl;

                return true;
            }
            else 
            {
                cout << "Unknown card type!\n";
                return false;
            }
        }
        else if (cardNumber[0] == '5' )
        {
            sso << cardNumber[0] << cardNumber[1];
            sso >> binNum;
            if(binNum >= 51 && binNum <= 55)
            {
                cout<<"master"<<endl;
                return true;
            }
            else
            {
                cout << "Unknown card type! (master)\n";
                return false;
            }
        }
        else if (cardNumber[0] == '4')
        {
            cout<<"visa"<<endl;
            return true;
        }
        else
        {
            cout << "Unknown card type! (visa)\n";
            return false;
        }
}
/*
    THE FUNCTION BELOW WILL TAKE IN A FILE FILLED WITH CARD NUMBERS AND TAKE THE WHOLE BIN NUMBER AND PREFORM LUHN'S ALGORITHM ON IT TO DETERMINE IF IT IS VALID
*/

bool isValidCard(string cardNumber)
{
    
    int cardNumberS[cardNumber.length() - 1];
   // cout << "got dumped\n";
    

        int sum = 0;
        int evenSum, oddSum = 0;
       // cards >> cardNumber;
        cout << cardNumber << endl;
        // cout << cardNumber<<endl;
        // int cardNumberS[cardNumber.length() - 1];
        // cout << "got dumped\n";
    
        
        for(int i=0; i< cardNumber.size(); i++)
    {
        cardNumberS[i]= cardNumber.at(i)- 48;
        //cout<< "im converted to an int\n";
    }
       
       
        // luhn algorithm thanks to https://youtu.be/A3Kqj2dbgqA
        for (int i = cardNumber.size() - 1; i>= 0; i--)
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
            cout<<"true, valid card\n";
            return true;
        }
        else
        {
            cout<<"false, invalid luhn!!\n";
           return false;
        }
}

int main()
{
    ifstream cards("account.txt");
    string cardNumber;
   
    while(!cards.eof())
    {
        cards >> cardNumber;
    
    //isValidBin();
         if (isValidBin(cardNumber)== true)
        {
            //cout<<"is valid"<<endl;;
            isValidCard(cardNumber);
         }
        else
        {
            cout<<"Not valid"<<endl;
            cout << "unknown card type!!\n";
        }
    }
    
    
    return 0;
}