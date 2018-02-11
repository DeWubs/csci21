#pragma once

#include "gameobject.h"

#include <iostream>
#include <string>
using namespace std;

class Room : public GameObject
{
	private:
		string description;
		Room* northRoom;
		Room* southRoom;
		Room* eastRoom;
		Room* westRoom;
		
	public:
		Room();
		Room(string newName, string newDescription);
		Room(string newName,int newGold, string newDescription);
		
		void setNorthRoom(Room* newNorthRoom);
		void setSouthRoom(Room* newSouthRoom);
		void setEastRoom(Room* newEastRoom);
		void setWestRoom(Room* newWestRoom);
		void setDescription(string newDescription);
	
		
		Room* getNorthRoom();
		Room* getSouthRoom();
		Room* getEastRoom();
		Room* getWestRoom();
		
		string getDescription();
};
