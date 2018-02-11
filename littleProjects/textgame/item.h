#pragma once
#include <string>
using namespace std;
class Item
{
	private:
	
	string itemName;
	string itemDescription;
	public:
	
	Item(string newItemName, string newItemDesription);
	
	void setItemName(string newItemName);
	void setItemDescription (string newItemDesription);
	
	string getItemName();
	string getItemDescription();

	
};