#pragma once
#include "Enemy.h"
#include <iostream>
#include <string>

using namespace std;

Enemy::Enemy(string n, string t, int h, int p, int a)
{
	name = n;
	type = t;
	healthMax = h;
	healthCurrent = healthMax;
	power = p;
	accuracy = a;
	//cout << type << " enemy created" << endl;
}

void Enemy::setFindStr(string s)
{
	find = s;
}
void Enemy::findStr()
{
	cout << endl << find << endl;
}

