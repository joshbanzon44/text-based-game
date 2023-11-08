#pragma once
#include "Weapon.h"
#include <iostream>
#include <string>
#include "Item.h"
#include "Enemy.h"

using namespace std;

//Default constructor
Weapon::Weapon()
{
	name = "Fists";
	type = "hands";
	desc = "nothing but knuckle.";
	size = 0;
	power = 3;
	accuracy = 90;
	isWeapon = true;
	//cout << name << " created." << endl;
}
//Parameterized Constructor
Weapon::Weapon(string n, string t, string d, int s, int p, int a)
{
	name = n;
	type = t;
	desc = d;
	size = s;
	power = p;
	accuracy = a;
	isWeapon = true;
	//cout << name << " weapon created." << endl;
}


void Weapon::toString()
{
	cout << name << "; Type: " << type << " - " << desc << endl;
	cout << "		Size: " << size << "		Power: " << power << "		Accuracy: " << accuracy << endl;
}



