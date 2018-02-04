/*
* this little program is a adress book essentailly. you will be able to show up to 16 of your friends and display their first name last name
* and phone number
*
*
*
*/

#include <iostream>
#include <fstream>

using namespace std;

int getOption();
void showItems(int x);


// main function
int main()
{
    int option;
    
    option = getOption();
    
  
    
    while (option != 4)
    {
        switch(option)
        {
            case 1:
                showItems(1);
                break;
            case 2:
                showItems(2);
                break;
            case 3:
                showItems(3);
                break;
                
        }
        option = getOption();
    }
    
    
    return 0;
}


// get option function
int getOption()
{
    int choice;
    
    cout << "[1] for id numbers 1-5\n";
    cout << "[2] for id numbers 6-11\n";
    cout << "[3] for id numbers 12-16\n";
    cout << "[4] for quit program\n";
    
    cin >> choice;
    return choice;
    
}

// showItems function

void showItems(int x)
{
    ifstream objectFile("objects.txt");
    string firstName;
    string lastName;
    double id;
    double phoneNumber;
    
    if(x==1)
    {
        while(objectFile >> id >> firstName >> lastName >> phoneNumber)
        {
            if(id>=0 && id <= 5)
            {
                cout << id << ' ' << firstName << ' ' << lastName << ' ' << phoneNumber << endl;
            }
        }
    }
    
        if(x==2)
    {
        while(objectFile >> id >> firstName >> lastName >> phoneNumber)
        {
            if(id>=6 && id>=11)
            {
                 cout << id << ' ' << firstName << ' ' << lastName << ' ' << phoneNumber << endl;
            }
        }
    }
    
        if(x==3)
    {
        while(objectFile >> id >> firstName >> lastName >> phoneNumber)
        {
            if(id>=12 && id<=16)
            {
                 cout << id << ' ' << firstName << ' ' << lastName << ' ' << phoneNumber << endl;
            }
        }
    }
}

