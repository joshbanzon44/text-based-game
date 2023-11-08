#pragma once
#include <vector>
#include "Entity.h"
#include "Item.h"
#include "Weapon.h"

using namespace std;

//Derived class from Entity, Player class that will be controlled by user
class Player : public Entity
{
public:
	

	//Default constructor for player
	//Will be called at start of program to initialize the Player
	Player();
	
	//Player functions
	void openInventory();
	void get(Item item);
	void get(Weapon w);
	void dropItem(int);

	//Fight an enemy. Returns true if fight won
	bool fight(Enemy en);
	
private:
	int inventoryMax;		//Max inventory allowed
	int inventoryCurrent;	//Amount of inventory space currently used
	int inventoryCount;		//Number of items in inventory
	vector<Item> inventoryItem;		//Array of all items in inventory
	vector<Weapon> inventoryWeapon;
	Weapon currentWeapon;


};

