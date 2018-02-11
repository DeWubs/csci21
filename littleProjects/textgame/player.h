#pragma once

#include "gameobject.h"

class Player : public GameObject
{
	public:
		Player (string newName, int newGold);
};