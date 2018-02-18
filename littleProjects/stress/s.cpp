#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std; 

class Stress
{
    private:
        int stressLevel;
        int index;
        vector<string> causes;
    public:
        void setStressLevel(int newStressLevel);
        void setIndex(int newIndex);
        
        int getStressLevel();
        int getIndex();
        
};

class List
{
    public:
    vector<Stress> Lists;
};

void Stress::setStressLevel(int newStressLevel)
{
    stressLevel = newStressLevel;
}

void Stress::setIndex(int newIndex)
{
    index = newIndex;
}

int Stress::getStressLevel()
{
    return stressLevel;
}

int Stress::getIndex()
{
    return index;
}

int main()
{
    Stress Stressed;
    List listOne;
    ifstream stressor("stress.txt");
    while(!stressor.eof())
    {
        getline(stressor, listOne);
    }
    for(int i = 0; i<listOne.size(); i++)
    {
        cout listOne[i];
    }
    
    return 0;
}