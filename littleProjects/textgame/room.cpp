#include "room.h"

Room::Room()
: GameObject("UNNAMED ROOM"), description("AN EMPTY ROOM"), northRoom(0), southRoom(0), eastRoom(0), westRoom(0)
{}

Room::Room(string newName, string newDescription)
: GameObject(newName), description(newDescription), northRoom(0), southRoom(0), eastRoom(0), westRoom(0)
{}

Room::Room(string newName, int newGold, string newDescription)
: GameObject(newName, newGold), description(newDescription), northRoom(0), southRoom(0), eastRoom(0), westRoom(0)
{}

void Room::setDescription( string newDescription)
{
	description = newDescription;
}

void Room::setNorthRoom(Room* newNorthRoom)
{
	northRoom = newNorthRoom;
}

void Room::setSouthRoom(Room* newSouthRoom)
{
	southRoom = newSouthRoom;
}

void Room::setEastRoom(Room* newEastRoom)
{
	eastRoom = newEastRoom;
}

void Room::setWestRoom(Room* newWestRoom)
{
	westRoom = newWestRoom;
}

Room* Room::getNorthRoom()
{
	return  northRoom;
}

Room* Room::getSouthRoom()
{
	return  southRoom;
}

Room* Room::getEastRoom()
{
	return  eastRoom;
}

Room* Room::getWestRoom()
{
	return  westRoom;
}

string Room::getDescription()
{
	return description;
}
//void Room::descibe()
//{
	
//}