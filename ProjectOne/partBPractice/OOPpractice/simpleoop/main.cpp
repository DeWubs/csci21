/*
this is a simple oop that makes a monster, you can put in a name and age and it will cout that information
*/

#include <iostream>

using namespace std;

class Monster
{
    private:
        string name;
        int age;
    public:
        Monster();
        Monster(string newName);
        Monster(string newName, int age);
        
        string getName();
        int getAge();
        
        void setName(string newName);
        void setAge(int newAge);
        
        
        void monsterName();
        void monsterAge();
        void describe();
};

Monster::Monster()
{
    name = "no name";
    
}

Monster::Monster(string newName)
{
    name = newName;
    age = 0;
}

Monster::Monster(string newName, int newAge)
{
    name = newName;
    age = newAge;
}


string Monster::getName()
{
    return name;
}

int Monster::getAge()
{
    return age;
}


void Monster::setName(string newName)
{
    name = newName;
}

void Monster::setAge(int newAge)
{
    age = newAge;
}

void Monster::monsterName()
{
    cout << "enter a name for your monster.\n";
    cin >> name;
}

void Monster::monsterAge()
{
    cout <<"enter an age for your monster\n";
    cin >> age;
}

void Monster::describe()
{
    cout << "your monster's name is "<< name << endl;
    cout << "they are "<< age << " years old." << endl;
}

int main()
{
    Monster monsterOne;
    monsterOne.monsterName();
    monsterOne.monsterAge();
    monsterOne.describe();
    
    
    
    
    return 0;
}