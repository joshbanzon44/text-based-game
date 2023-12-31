#pragma once
#include <iostream>
#include <string>

using namespace std;

class Item
{
public:
	//Default constructor 
	Item();
	//Parameterized constructor
	//Name, type, description, size, health increase, max health increase, item usuable
	Item(string n, string t, string d, int s, int h, int m, bool canUse = true);

	//Public methods
	void toString();

	//Accessor for find str
	void findStr();
	//Mutator for find str
	void setFindStr(string);

	string name; //Specific name of item
	string type; //Type of item (Ex: sword, bow)
	string desc; //Description of item
	int size;    //Inventory size
	bool isWeapon = false;
	bool canUse = true;

	int healthIncrease;
	int maxHealthIncrease;

private: 
	string find = "";

};
