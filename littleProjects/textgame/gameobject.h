#pragma once
#include "item.h"
#include <string>
#include <vector>
using namespace std;

class GameObject {
	private:
		string name;
		int gold;
		vector<Item> items;
		


	public:
		GameObject ();
		GameObject (string newName);
		GameObject (string newName, int newGold);

		void setName (string newName);
		string getName ();	

		void addItem(Item anItem);
		Item getItem (int index);
		void removeItem(int index);
		int getItemCount();


		void adjustGold (int amount);
		void setGold (int newGold);
		int getGold ();

		bool hasItem(string itemName);



};