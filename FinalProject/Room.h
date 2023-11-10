#pragma once
#include <string>
#include <tuple>
#include "Enemy.h"
#include "Item.h"
#include "Weapon.h"

using namespace std;

class Room
{
public:
	//Accessor and mutator for X and Y coordinates
	void setXY(int, int);
	int getX();
	int getY();

	//Accessor and mutator for firstRoom
	void setFirstRoom(bool);
	bool isFirstRoom();

	//Accessor and mutator for enemy
	void setEnemy(Enemy);
	Enemy getEnemy();

	//Accessor and mutator for item
	void setItem(Item);
	Item getItem();

	//Accessor and mutator for weapon
	void setWeapon(Weapon);
	Weapon getWeapon();

	//Accessor and mutator for visited
	bool hasBeenVisited();
	void visit();

	//Mutator for strings
	void setString(string entrance);

	//Print entrance string
	void entranceStr();

	//Functions for movement in/within/out of room
	void enter(char);
	tuple<int,int,char> nextRoom(string);

	//Public variable
	bool hasEnemy = false;
	bool hasItem = false;
	bool hasWeapon = false;

	void setEnemyFalse();
	void setItemFalse();
	void setWeaponFalse();

	//Constructor (X, Y)
	Room(int xCoor = 0, int yCoor = 0);

private:
	//Coordinates for room
	int x;
	int y;

	//Bool if it is the first room
	bool firstRoom = false;

	//If the room has been visited
	bool wasVisited = false;

	//Coordinates and direction for next room
	int nextX = 0;
	int nextY = 0;
	char nextDirection = 'N'; //N for top, S for bottom, E for right, W for left 

	//Direction that player enters room from
	char direction = 'S';
	string directionEnterWord; //North, East, South, or West
	string directionFacingWord; //North, East, South, or West

	//Objects in room
	Enemy enemy;
	Item item;
	Weapon weapon;

	//Strings to print
	string enterStr;
};

