#include "item.h"

Item::Item(string newItemName, string newItemDesription)
{
	itemName = newItemName;
	itemDescription = newItemDesription;
}

void Item::setItemName(string newItemName)
{
	itemName = newItemName;
}

void Item::setItemDescription(string newItemDesription)
{
	itemDescription = newItemDesription;
}

string Item::getItemName()
{
	return itemName;
}

string Item::getItemDescription()
{
	return itemDescription;
}