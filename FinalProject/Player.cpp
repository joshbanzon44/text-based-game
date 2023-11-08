#pragma once
#include "Player.h"
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <algorithm>
#include "Entity.h"
#include "Item.h"
#include "Weapon.h"

using namespace std;

//Default constructor for player
//Will be called at start of program to initialize the Player
Player::Player()
{
	inventoryMax = 100;
	inventoryCurrent = 0;
	inventoryCount = 0;
	//inventory[inventorySize];	//Array initialized at max size of inventory
	cout << "Player created." << endl;
}
void Player::openInventory()
{
	//Print all items in inventory
	cout << "---------------------------------Inventory-----------------------------" << inventoryCurrent << "/" << inventoryMax << endl;
	if (inventoryCount == 0) //If nothing in inventory, end function
	{
		cout << "Your inventory is empty.\n" << endl;
		cout << "----------------------------------------------------------------------------" << endl;
		return;
	}
	cout << "		                                             Health: " << healthCurrent << "/" << healthMax << endl;
	cout << "Weapons: " << endl;
	int i;
	int n = 1;

	if (inventoryWeapon.size() == 0)
	{
		cout << "	--All out of weapons.--" << endl;
	}

	for (i = 0; i < inventoryWeapon.size(); i++)
	{
		cout << n << ". ";
		inventoryWeapon[i].toString();
		n++;
	}

	n = 1;
	cout << "\nItems: " << endl;

	if (inventoryItem.size() == 0)
	{
		cout << "	--All out of items.--" << endl;
	}

	for (i = 0; i < inventoryItem.size(); i++)
	{
		cout << n << ". ";
		inventoryItem[i].toString();
		n++;
	}

	cout << "\nCurrent Weapon: " << endl;
	currentWeapon.toString();
	cout << "----------------------------------------------------------------------------" << endl;

	string input;
	cout << "Options: (change) current weapon / (use) item / (leave) inventory" << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	cin >> input;
	cin.clear();
	cout << "----------------------------------------------------------------------------" << endl;

	if (input.find("quit") != string::npos)
	{
		cout << "Exiting...Thank you for playing!" << endl;
		exit(0);
	}

	while (input.find("exit") == string::npos || input.find("close") == string::npos || input.find("leave") == string::npos) // Inventory loop
	{
		if (input.find("exit") != string::npos || input.find("close") != string::npos || input.find("leave") != string::npos) //Exit inventory choice
		{
			system("cls");
			cout << "----------------------------------------------------------------------------" << endl;
			return;
		}
		else if (input.find("use") != string::npos || input.find("item") != string::npos)			// Use item in inventory
		{
			if (inventoryItem.size() == 0)
			{
				cout << "You don't have any items!" << endl;
				cout << "----------------------------------------------------------------------------" << endl;
				cout << "Options: (change) current weapon / (use) item / (leave) inventory" << endl;
				cout << "----------------------------------------------------------------------------" << endl;
				cin >> input;
				cin.clear();
				cout << "----------------------------------------------------------------------------" << endl;
				continue;
			}

			int inputNum = 0;
			cout << "Enter the number of the item you want to use: ";
			cin >> inputNum;

			if (inputNum > inventoryItem.size() || inputNum < 1)
			{
				cout << "Invalid number!" << endl;
				cout << "----------------------------------------------------------------------------" << endl;
				cout << "Options: (change) current weapon / (use) item / (leave) inventory" << endl;
				cout << "----------------------------------------------------------------------------" << endl;
				cin >> input;
				cin.clear();
				cout << "----------------------------------------------------------------------------" << endl;
				continue;
			}

			if (!inventoryItem[inputNum - 1].canUse)
			{
				cout << "This item isn't usable." << endl;
				cout << "----------------------------------------------------------------------------" << endl;
				cout << "Options: (change) current weapon / (use) item / (leave) inventory" << endl;
				cout << "----------------------------------------------------------------------------" << endl;
				cin >> input;
				cin.clear();
				cout << "----------------------------------------------------------------------------" << endl;
				continue;
			}

			healthMax += inventoryItem[inputNum - 1].maxHealthIncrease;
			healthCurrent = min(healthCurrent+ inventoryItem[inputNum - 1].healthIncrease, healthMax);

			cout << "\n" << inventoryItem[inputNum-1].name << " consumed. Health now: " << healthCurrent << "/" << healthMax << endl;
			dropItem(inputNum);
		}
		else if (input.find("change") != string::npos || input.find("weapon") != string::npos)		// Change current weapon
		{
			if (inventoryWeapon.size() == 0)
			{
				cout << "You don't have any items!" << endl;
				cout << "----------------------------------------------------------------------------" << endl;
				cout << "Options: (change) current weapon / (use) item / (leave) inventory" << endl;
				cout << "----------------------------------------------------------------------------" << endl;
				cin >> input;
				cin.clear();
				cout << "----------------------------------------------------------------------------" << endl;
				continue;
			}
			
			int inputNum = 0;
			cout << "Enter the number of the weapon you want to equip: ";
			cin >> inputNum;

			if (inputNum > inventoryWeapon.size() || inputNum < 1)
			{
				cout << "Invalid number!" << endl;
				continue;
			}

			currentWeapon = inventoryWeapon[inputNum-1];

			cout << "\n" << currentWeapon.name << " equipped." << endl;
		}
		else 
		{
			cout << "Not sure what you meant, try a different wording. " << endl;
		}

		cout << "----------------------------------------------------------------------------" << endl;
		cout << "Options: (change) current weapon / (use) item / (leave) inventory" << endl;
		cout << "----------------------------------------------------------------------------" << endl;
		cin >> input;
		cin.clear();
		cout << "----------------------------------------------------------------------------" << endl;
	}
}

//Overloaded get function for items or weapons
void Player::get(Item item)
{
	inventoryItem.push_back(item);
	inventoryCount++;
	inventoryCurrent += item.size;
	//cout << item.name << " added to inventory" << endl;
}
void Player::get(Weapon w)
{
	inventoryWeapon.push_back(w);
	inventoryCount++;
	inventoryCurrent += w.size;
	//cout << w.name << " added to inventory" << endl;
}

//Remove item from inventory 
void Player::dropItem(int n)
{
	inventoryCurrent -= inventoryItem[n - 1].size;
	inventoryItem.erase(inventoryItem.begin()+(n-1));
	inventoryCount--;
}

//Fight an enemy
bool Player::fight(Enemy en)
{
	//Initialize variables for fighting mechanic
	string input;
	string summary;
	string winStr = "";
	int random1;
	int random2;
	float playerHealthBar;
	float enemyHealthBar;
	bool fighting = true;
	int win = 0;

	while (fighting)
	{
		system("cls");

		//Interface for fighting
		cout << "*****************************************************************************" << endl;
		cout << "You: " << healthCurrent << "/" << healthMax << string((52-en.name.length()-7), ' ') << en.name << ": " << en.healthCurrent << "/" << en.healthMax << endl;
		playerHealthBar = float(healthCurrent) / float(healthMax);
		playerHealthBar *= 10.0;
		enemyHealthBar = en.healthCurrent / en.healthMax;
		enemyHealthBar *= 10.0;

		string dash = "-";

		cout << "|" << string(int(playerHealthBar), '-') << string((10-int(playerHealthBar)), ' ') << "|					    |" << string(int(enemyHealthBar), '-') << string((10 - int(enemyHealthBar)), ' ') << "|" << endl << endl;
		cout << "|" << string(int(playerHealthBar), '-') << string((10 - int(playerHealthBar)), ' ') << "|					    |" << string(int(enemyHealthBar), '-') << string((10 - int(enemyHealthBar)), ' ') << "|" << endl << endl;
		cout << endl << summary << winStr << endl;
		cout << "*****************************************************************************" << endl;
		cout << "			Options: attack, block" << endl;
		cout << "*****************************************************************************" << endl;

		if (win == 1)
		{
			exit(0);
		}
		else if (win == 2)
		{
			cout << "Enter any number to continue: ";
			cin >> input;
			system("cls");
			return true;
		}

		cin >> input;
		cin.clear();

		random1 = rand() % 101; //Player chance
		random2 = rand() % 101; //Enemy chance

		//Allow quit option
		if (input.find("quit") != string::npos)
		{
			return false;
		}


		if (input.find("attack") != string::npos || input.find("stab") != string::npos || input.find("swing") != string::npos)
		{
			if (random1 <= currentWeapon.accuracy)
			{
				summary = "Your " + currentWeapon.name + " strikes " + en.name + " for " + to_string(currentWeapon.power) + " damage.";
				en.healthCurrent -= currentWeapon.power;
			}
			else
			{
				summary = "Your attack misses.";
			}

			if (random2 <= en.accuracy)
			{
				summary += "\n" + en.name + " strikes you for " + to_string(en.power) + " damage.";
				healthCurrent -= en.power;
			}
			else
			{
				summary += "\n" + en.name + "'s attack misses.";
			}
			
		}
		else if (input.find("block") != string::npos || input.find("parry") != string::npos || input.find("guard") != string::npos)
		{
			if (random1 <= 5) //5% chance to parry and hit back
			{
				summary = "You parry " + en.name + "'s attack and stun them which gives you an opporunity to strike for " + to_string(currentWeapon.power) + " damage.";
				en.healthCurrent -= currentWeapon.power;
			}
			else if (random1 <= 85 && random2 <= en.accuracy) //85% chance to block
			{
				summary = "You block " + en.name + "'s attack and reduce it's damage to " + to_string((currentWeapon.power/2)) + " damage.";
				en.healthCurrent -= (currentWeapon.power/2);
			}
			else if (random2 <= en.accuracy)				//Block fails and enemies attack hits
			{
				summary = "You attempt to block " + en.name + "'s attack, but they best your attempt and hit you for " + to_string(en.power) + " damage.";
				healthCurrent -= en.power;
			}
			else							//Enemy misses and nothing happens
			{
				summary = "You attempt to block " + en.name + "'s attack, but they miss regardless.";
			}
		}
		else
		{
			summary = "Invalid action.";
		}

		//Check if loss or win
		if (healthCurrent <= 0)
		{
			healthCurrent = 0;
			winStr = "\nYou have been slain by " + en.name + ".";
			win = 1;
		}
		else if (en.healthCurrent <= 0)
		{
			en.healthCurrent = 0;
			winStr = "\nYou have defeated " + en.name + ".";
			win = 2;
		}

	}

	return true;
}