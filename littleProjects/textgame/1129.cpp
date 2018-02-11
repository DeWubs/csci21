/*
 * text based house game
 * walk through a house of mystery and wonder eventually you have to try to escape the house by avoiding / fighting monsters monsters and answering questions?...
 *
 * PROGRAMMER NAME Robert Prouty
 * Date created: 11/27/2017
 *
 * RESOURCES
 * LIST WEBSITES/BOOKS/PEOPLE WHO HELPED YOU WITH YOUR SOLUTION
 */
#include "CinReader.h"
#include <iostream>
#include "room.h"
 #include "player.h"
using namespace std;



void clearScreen ();

int main ()
{
	
	
	Room kitchen("Kitchen",1 , "You see a rather messy kitchen, it seems to have been abandoned for a while but you faintly smell cookies.");
	Room entry("EntryWay",0 , "Where you come in, also the way you get out. A large birdlike bust rests on the door.");
	Room dining("Dining room",5, "A large dusty dining room almost big enough to be a ballroom, sheets cover all the furniture, you can almost see the parties that were held in this room...");
	Room hallway("Grand hallway",0, "strange portraits line the hallway, their eyes almost follow your movment. The moonlight filters through the tattered drapes giving everything an eerie gray glow.");
	Room bedroom("Master bedroom",3, "A room once fit for royalty now stands delapitated, water stains run across the celing, and a previlant musty smell clogs your nose.");
	Room bathroom("Master bathroom",2, "This room is rather impressive despite it's sad state. You somewhat wish you could have used it in it's glory days.");
	
	entry.setEastRoom(&kitchen);
	
	kitchen.setWestRoom(&entry);
	kitchen.setSouthRoom(&dining);
	kitchen.setNorthRoom(&hallway);
	kitchen.addItem(Item("Toilet brush", "a really old toilet brush. You think its rather gross that it would be in the kitchen of all places. Other than that nothing looks out of the ordinary about it."));
	kitchen.addItem(Item("Rusty fork", "An old fork, untold years of exposure has left this once usable fork encrusted in rust."));
	
	dining.setNorthRoom(&kitchen);
	dining.addItem(Item("An old Pillow", "A Pinky pillow that you could imagine once was very expensive."));
	dining.addItem(Item("A golden spork", "The line between trashy and classy has never been thinner"));
	dining.addItem(Item("A mouse trap", "A very old mouse trap with the skeletal remains of its last catch."));
	
	
	hallway.setNorthRoom(&bedroom);
	hallway.setSouthRoom(&kitchen);
	hallway.addItem(Item("Old book", "An old book rests atop a forgotten shelf it's cover covered in dust. Other than its smell there isnt really anything out of the ordinary"));
	hallway.addItem(Item("Strange plant", "You cant quite identify this strange plant growing through the window, maybe its the moonlight giving it it's pale glow..."));

	bedroom.addItem(Item("Dusty Note", "A note written in scrawling script, you hardly make out the writing in the dim light. It says something along the lines of, find the items that look out of place and each coin."));
	bedroom.setSouthRoom(&hallway);
	bedroom.setEastRoom(&bathroom);
	
	bathroom.setWestRoom(&bedroom);

	Room* currentRoom = &bedroom;

	Player thePlayer("Jim", 0);
	
	CinReader reader;
	bool quit = false;
	int itemTaken;
	
	// game loop
	while (quit == false)
	{
		cout << "you are in -> " << currentRoom->getName() << endl << endl;
		cout << "go [N]orth" << endl;
		cout << "go [S]outh" << endl;
		cout << "go [E]ast" << endl;
		cout << "go [W]est" << endl;
		cout << "   [L]ook around" << endl;
		cout << "   [G]rab gold" << endl;
		cout << "   [T]ake item" << endl;
		cout << "   [P]ocket"<< endl;
		cout << "go [Q]uit" << endl;
		cout << "?";
		
		switch(tolower(reader.readChar("NSEWLQPGTnsewlqpgt")))
		{
			case'n':
				clearScreen();
				if(currentRoom->getNorthRoom() != 0)
					currentRoom = currentRoom->getNorthRoom();
				else
					cout << endl << "you ran into a wall and broke your nose." << endl;
			break;
			
			case's':
			clearScreen();
			if(currentRoom->getSouthRoom() != 0)
					currentRoom = currentRoom->getSouthRoom();
				else
					cout << endl << "you ran into a wall and broke your nose, you're really bad at this." << endl;
			break;
			
			case'e':
			clearScreen();
			if(currentRoom->getEastRoom() != 0)
					currentRoom = currentRoom->getEastRoom();
				else
					cout << endl << "you ran into a wall and stubbed your toe." << endl;
			break;
			
			case'w':
			clearScreen();
			if(currentRoom->getWestRoom() != 0)
					currentRoom = currentRoom->getWestRoom();
				else
					cout << endl << "you continue to walk into a wall but your pride wont let you stop." << endl;
			break;
			
			case'l':
				clearScreen();
				cout << endl << currentRoom->getName() << endl;
				cout<< currentRoom->getDescription() << endl << endl;
				if (currentRoom->getGold() > 0)
				{
					cout << "You see " << currentRoom->getGold() << " gold pecie(s)." << endl;
				}
				for (int i = 0; i<currentRoom->getItemCount(); i++)
				{
					cout<< (i + 1) << ": " << currentRoom->getItem(i).getItemName() << ": " << currentRoom->getItem(i).getItemDescription() << endl;
				}
			break;

			case'g':
				clearScreen();
				if (currentRoom->getGold() > 0)
				{
					cout << "You see " << currentRoom->getGold() << " gold pecie(s)." << endl;
					cout << endl << "pick it up? (0 to cancel or ammount to take) ";
					int goldTaken = reader.readInt(0, currentRoom->getGold());
					thePlayer.adjustGold(goldTaken);
					currentRoom->adjustGold(-goldTaken);
				}
				else 
				{
					cout << "there is no gold to take" << endl;
				}
			break;

			case't':
				clearScreen();
				for(int i=0; i<currentRoom->getItemCount(); i++)
				{
					cout << (i + 1) << ": " << currentRoom->getItem(i).getItemName() << endl;
				}
				cout << "take which item? (0 to cancel)";
				itemTaken = reader.readInt(0, currentRoom->getItemCount());
				if (itemTaken > 0)
				{
					itemTaken--;
					Item theItem = currentRoom->getItem(itemTaken);
					thePlayer.addItem(theItem);
					currentRoom->removeItem(itemTaken);

					cout << endl << theItem.getItemName() << " taken." << endl;
				} 
				break;

			
			case'q':
				cout << endl << "bye..." << endl << endl;
				quit = true;
			break;

			case 'p':
				clearScreen();
				cout << "Other than some lint you have:" << thePlayer.getGold() << " gold peices."<< endl;
				for (int i= 0; i<thePlayer.getItemCount(); i++)
				{
					   cout << thePlayer.getItem(i).getItemName() << endl;
				}
			break;

			default:
				cout<< endl << "u wot m8" << endl << endl;
			break;
			
		}
		if (thePlayer.getGold() >= 10 && currentRoom == &entry && thePlayer.hasItem("Toilet brush") && thePlayer.hasItem("An old Pillow") && thePlayer.hasItem("Strange plant"))
		{
			clearScreen();

			cout << "WoW you win" << endl << endl << "Press q to quit and enjoy your victory";
			reader.readChar();

			quit = true;
		}
		
	}
	
	
	return 0;

}

void clearScreen ()
{
	cout << "\x1B[2J\x1B[H";
}