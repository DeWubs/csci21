#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Item
{
    private:
        string name_;
        int value_;
    public:
        Item();
        Item(string newName);
        Item(string newName, int newValue);
        virtual ~Item(){};
        
        void set_name(string newName);
        void set_value(int newValue);
        
        string name();
        int value();
        
        string ToString();
};

class FoodItem: public Item
{
    private:
        int calories_;
        string unit_of_measure_;
        double units_;
    public:
        FoodItem();
        FoodItem(string newName);
        FoodItem(string newName, int newValue);
        FoodItem(string newName, int newValue, int newCalories);
        FoodItem(string newName, int newValue, int newCalories, string newUnit_of_measure);
        FoodItem(string newName, int newValue, int newCalories, string newUnit_of_measure, double newUnits);
        virtual ~FoodItem(){};
        
        void set_calories(int newCalories);
        void set_unit_of_measure(string newUnit_of_measure);
        void set_units(double newUnits);
        
        int calories();
        string unit_of_measure();
        double units();
        
        string ToString();
};

class MagicItem: public Item
{
    private:
        string description_;
        int mana_required_;
    public:
        MagicItem();
        MagicItem(string newName);
        MagicItem(string newName, int newValue);
        MagicItem(string newName, int newValue, string newDescription);
        MagicItem(string newName, int newValue, string newDescription, int newMana_required);
        virtual ~MagicItem(){};
        
        void set_description(string newDescription);
        void set_mana_required(int newMana_required);
        
        string description();
        int mana_required();
        
        string ToString();
};