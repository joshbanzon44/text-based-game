#pragma once
#include "Entity.h"
#include <string>
#include <iostream>

using namespace std;

//Derived class from Entity, Class for all enemies the player will fight
class Enemy : public Entity
{
public:
	Enemy(string n = "", string t = "", int h = 5, int p = 1, int a = 50);
	string type;	//Type of enemy (Ex: zombie, troll, skeleton)

	//Accessor for find str
	void findStr();
	//Mutator for find str
	void setFindStr(string);

	int power;
	int accuracy;
	string find = "";

};

