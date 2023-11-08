#pragma once
#include <iostream>
#include <string>

using namespace std;

//Base class for all Entities
class Entity
{
public:
	Entity();		//Default constructor

	int getHealth();
	int maxHealth();
	string name;
	int healthMax;
	int healthCurrent;
	int speed;


};


