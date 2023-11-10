#pragma once
#include "Room.h"
#include <iostream>
#include <string>

using namespace std;

//Constructor
Room::Room(int xCoor, int yCoor)
{
	x = xCoor;
	y = yCoor;
}

//Set room visited to true
void Room::visit()
{
	wasVisited = true;
}

//Get whether room has been visited.
bool Room::hasBeenVisited()
{
	return wasVisited;
}

//Function called when player enters the room
void Room::enter(char directionInput)
{
	direction = directionInput;
	if (direction == 'S')
	{
		directionEnterWord = "South";
		directionFacingWord = "North";
	}
	else if (direction == 'N')
	{
		directionEnterWord = "North";
		directionFacingWord = "South";
	}
	else if (direction == 'E')
	{
		directionEnterWord = "East";
		directionFacingWord = "West";
	}
	else if (direction == 'W')
	{
		directionEnterWord = "West";
		directionFacingWord = "East";
	}
	cout << enterStr << endl;

	if (hasEnemy)
	{
		enemy.findStr();
	}
	if (hasWeapon)
	{
		weapon.findStr();
	}
	if (hasItem)
	{
		item.findStr();
	}

	cout << "\nYou enter from the " << directionEnterWord << " and are facing the " << directionFacingWord << "." << endl;
}

//Returns tuple of ints and char <x,y,c> which are coordinates to next room and direction entered from
tuple <int,int,char> Room::nextRoom(string directionToGo)
{
	//If player came through bottom door
	if (direction == 'S')
	{
		if (directionToGo == "forward")
		{
			nextX = x;
			nextY = y + 1;
			nextDirection = 'S';
		}
		else if (directionToGo == "backward")
		{
			nextX = x;
			nextY = y - 1;
			nextDirection = 'N';
		}
		else if (directionToGo == "left")
		{
			nextX = x - 1;
			nextY = y;
			nextDirection = 'E';
		}
		else if (directionToGo == "right")
		{
			nextX = x + 1;
			nextY = y;
			nextDirection = 'W';
		}
	}
	//If player came through top door
	else if (direction == 'N')
	{
		if (directionToGo == "forward")
		{
			nextX = x;
			nextY = y - 1;
			nextDirection = 'N';
		}
		else if (directionToGo == "backward")
		{
			nextX = x;
			nextY = y + 1;
			nextDirection = 'S';
		}
		else if (directionToGo == "left")
		{
			nextX = x + 1;
			nextY = y;
			nextDirection = 'W';
		}
		else if (directionToGo == "right")
		{
			nextX = x - 1;
			nextY = y;
			nextDirection = 'E';
		}
	}
	//If player came through left door
	else if (direction == 'W')
	{
		if (directionToGo == "forward")
		{
			nextX = x + 1;
			nextY = y;
			nextDirection = 'W';
		}
		else if (directionToGo == "backward")
		{
			nextX = x - 1;
			nextY = y;
			nextDirection = 'E';
		}
		else if (directionToGo == "left")
		{
			nextX = x;
			nextY = y + 1;
			nextDirection = 'S';
		}
		else if (directionToGo == "right")
		{
			nextX = x;
			nextY = y - 1;
			nextDirection = 'N';
		}
	}
	//If player came through right door
	else if (direction == 'E')
	{
		if (directionToGo == "forward")
		{
			nextX = x - 1;
			nextY = y;
			nextDirection = 'E';
		}
		else if (directionToGo == "backward")
		{
			nextX = x + 1;
			nextY = y;
			nextDirection = 'W';
		}
		else if (directionToGo == "left")
		{
			nextX = x;
			nextY = y - 1;
			nextDirection = 'N';
		}
		else if (directionToGo == "right")
		{
			nextX = x;
			nextY = y + 1;
			nextDirection = 'S';
		}
	}

	if (nextX == -1 || nextX == 5 || nextY == -1 || nextY == 4)
	{
		cout << "That way is blocked. Please choose another way. (forward, backward, left, right)" << endl;
		string input;
		cin >> input;
		return nextRoom(input);
	}

	return tuple<int, int, char>(nextX, nextY, nextDirection);
}

//Mutator for X, Y
void Room::setXY(int x, int y)
{

}
int Room::getX() //Return x value
{
	return x;
}
int Room::getY() //Return y value
{
	return y;
}

//Mutator for firstRoom
void Room::setFirstRoom(bool f)
{
	firstRoom = f;
	if (f)
	{
		direction = 'S';
	}
}
bool Room::isFirstRoom()
{
	return firstRoom;
}

//Mutator for enemy
void Room::setEnemy(Enemy e)
{
	enemy = e;
	hasEnemy = true;
}
Enemy Room::getEnemy() //Return room's enemy if not null
{
	return enemy;
}

//Mutator for enemy
void Room::setWeapon(Weapon w)
{
	weapon = w;
	hasWeapon = true;
}
Weapon Room::getWeapon() //Return room's enemy if not null
{
	hasWeapon = false;
	return weapon;
}

//Mutator for item
void Room::setItem(Item i)
{
	item = i;
	hasItem = true;
}
Item Room::getItem() //Return room's item if not null
{
	hasItem = false;
	return item;
}

//Mutator for strings
void Room::setString(string entrance)
{
	enterStr = entrance;
}

//Print entrance string
void Room::entranceStr()
{
	cout << enterStr << endl;
}

void Room::setEnemyFalse()
{
	hasEnemy = false;
}
void Room::setItemFalse()
{
	hasItem = false;
}
void Room::setWeaponFalse()
{
	hasWeapon = false;
}
