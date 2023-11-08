#pragma once
#include <iostream>
#include <string>
#include "Item.h"
#include "Enemy.h"

using namespace std;

//Derived class from Item
class Weapon : public Item
{
public:
	//Default constructor
	Weapon();
	//Parameterized Constructor
	Weapon(string n, string t, string d, int s, int p, int a);

	//Public methods
	void toString();

	int power;		//Damage that the weapon deals
	int accuracy;	//Chance to hit attack, 1-100

	
};
