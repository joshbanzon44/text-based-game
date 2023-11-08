#pragma once
#include "Item.h"
#include <iostream>
#include <string>

using namespace std;

//Default constructor 
Item::Item()
{
	//cout << "Item created." << endl;
	size = 1;
}

//Parameterized constructor
Item::Item(string n, string t, string d, int s, int h, int m, bool u)
{
	name = n;
	type = t;
	desc = d;
	size = s;
	healthIncrease = h;
	maxHealthIncrease = m;
	canUse = false;
	cout << "Item created." << endl;
}

void Item::toString()
{
	cout << name << "; Type: " << type << " - " << desc << endl;
	cout << "		Size: " << size << "		Health increase : " << healthIncrease << "		Max Health Increase : " << maxHealthIncrease << endl << endl;
}

void Item::setFindStr(string s)
{
	find = s;
}
void Item::findStr()
{
	cout << endl << find << endl;
}


