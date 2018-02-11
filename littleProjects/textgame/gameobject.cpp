#include "gameobject.h"

GameObject::GameObject ()
: name("GAMEOBJECT") {
}

GameObject::GameObject (string newName, int newGold)
: name(newName), gold(newGold) {
}

GameObject::GameObject(string newName)
: name(newName){}

void GameObject::setName (string newName) {
	name = newName;
}

string GameObject::getName () {
	return name;
}

void GameObject::adjustGold(int amount)
{
	gold += amount;
}

void GameObject::setGold(int newGold)
{
	gold = newGold;
}

int GameObject::getGold()
{
	return gold;
}

void GameObject::addItem(Item anItem)
{
	items.push_back(anItem);
}

void GameObject::removeItem(int itemIndex)
{
	items.erase(items.begin() + itemIndex);
}

int GameObject::getItemCount()
{
	return items.size();
}
Item GameObject::getItem (int index)
{
	return items[index];
}

bool GameObject::hasItem(string itemName)
{
	bool foundTheItem = false;

	for (int i=0; i < items.size(); i++)
	{
		if (items[i].getItemName() == itemName)
		{
			foundTheItem = true;
			break;
		}
	}
	return foundTheItem;
}