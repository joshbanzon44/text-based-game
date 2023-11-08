#include "Entity.h"
#include <iostream>
#include <string>

using namespace std;

Entity::Entity()
{
	healthMax = 100;
	healthCurrent = healthMax;
	//cout << "Entity created." << endl;
}

int Entity::getHealth()
{
	return healthCurrent;
}

int Entity::maxHealth()
{
	return healthMax;
}

