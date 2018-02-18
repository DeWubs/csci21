#include "lab_12.h"
Item::Item()
{
    name_ ="item";
}
Item::Item(string newName)
{
    name_ = newName;
    value_ = 0;
}
Item::Item(string newName, int newValue)
{
    name_ = newName;
    value_ = newValue;
}

Item::~Item(){};

void Item::set_name(string newName)
{
    name_ = newName;
}
void Item::set_value(int newValue)
{
    value_ = newValue;
}

string Item::name()
{
    return name_;
}
int Item::value()
{
    return value_;
}


string Item::ToString()
{
   stringstream sso;
   string base;
   sso << name_ <<", $" << value_;
   sso >> base;
   return base;
}
//##################################################################################################################
FoodItem::FoodItem()
{
    name_ = "fooditem";
     
}
FoodItem::FoodItem(string newName)
{
    name_ = newName;
    value_ = 0;
    
}
FoodItem::FoodItem(string newName, int newValue)
{
    name_ = newName;
    value_ = newValue;
    calories_ = 0;
}
FoodItem::FoodItem(string newName, int newValue, int newCalories)
{
    name_ = newName;
    value_ = newValue;
    calories_ = newCalories;
    unit_of_measure_ = "nounits";
}

FoodItem::FoodItem(string newName, int newValue, int newCalories, string newUnit_of_measure)
{
    name_ = newName;
    value_ = newValue;
    calories_ = newCalories;
    unit_of_measure_ = newUnit_of_measure;
    units_ = 0;
}
FoodItem::FoodItem(string newName, int newValue, int newCalories, string newUnit_of_measure, double newUnits)
{
    name_ = newName;
    value_ = newValue;
    calories_ = newCalories;
    unit_of_measure_ = newUnit_of_measure;
    units_ = newUnits;
}
FoodItem::~FoodItem(){};

void FoodItem::set_calories(int newCalories)
{
    calories_ = newCalories;
}
void FoodItem::set_unit_of_measure(string newUnit_of_measure)
{
    unit_of_measure_ = newUnit_of_measure;
}
void FoodItem::set_units(double newUnits)
{
    units_ = newUnits;
}

int FoodItem::calories()
{
    return calories_;
}
string FoodItem::unit_of_measure()
{
    return unit_of_measure_;
}
double FoodItem::units()
{
    return units_;
}

string FoodItem::ToString()
{
    stringstream sso;
    string food;
    sso << name_ << ", $" << value_ << ", " << std::setprecision(2) << units_ << ", " << unit_of_measure << ", " << calories_;
    sso >> food;
    return food;
}
//#####################################################################################################################
MagicItem::MagicItem()
{
     name_ = "magicitem";
}
MagicItem::MagicItem(string newName)
{
    name_ = newName;
    value_ = 0;
}
MagicItem::MagicItem(string newName, int newValue)
{
    name_ = newName;
    value_ = newValue;
    description_ = "no description";
}
MagicItem::MagicItem(string newName, int newValue, string newDescription)
{
    name_ = newName;
    value_ = newValue;
    description_ = newDescription;
    mana_required_ = 0;
}
MagicItem::MagicItem(string newName, int newValue, string newDescription, int newMana_required)
{
    name_ = newName;
    value_ = newValue;
    description_ = newDescription;
    mana_required_ = newMana_required;
}

MagicItem::~MagicItem(){};

void MagicItem::set_description(string newDescription)
{
    description_ = newDescription;
}
void MagicItem::set_mana_required(int newMana_required)
{
    mana_required_ = newMana_required;
}

string MagicItem::description()
{
    return description_;
}
int MagicItem::mana_required()
{
    return mana_required_;
}

string MagicItem::ToString()
{
    stringstream sso;
    string magic;
    sso << name_ << ", $" << value_ << ", " << description_ << ", " << mana_required_;
    sso >> magic
    return magic;
}
//######################################################################################################################