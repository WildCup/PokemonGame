// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Monster.h"



int main()
{
	Monster* m1 = new Monster("Slime", 2, 5, 2, 5, Monster::Water, { "Eat" });
	Monster* m2 = new Monster("Glue", 1, 7, 1, 5, Monster::Water, { "Stop" });
	Monster* m3 = new Monster("Spider", 2, 6, 1, 5, Monster::Earth, { "Poison" });
	Monster* m4 = new Monster("Tree", 2, 3, 4, 5, Monster::Earth, { "Heal" });
	Monster* m5 = new Monster("Ghost", 2, 6, 1, 5, Monster::Air, { "Fear" });
	Monster* m6 = new Monster("Mist", 3, 3, 3, 5, Monster::Air, { "Blind" });
	Monster* m7 = new Monster("Vector", 6, 2, 1, 5, Monster::Fire, { "Ablaze" });
	Monster* m8 = new Monster("Fenix", 3, 3, 3, 5, Monster::Fire, { "Resurrect" });
	Monster* m9 = new Monster("Eye", 5, 2, 2, 5, Monster::Ice, { "Laser" });
	Monster* m10 = new Monster("Witch", 4, 3, 2, 5, Monster::Ice, { "Mirror" });
	Monster* m11 = new Monster("Cube", 2, 1, 5, 4, Monster::Steel, { "Shield" });
	Monster* m12 = new Monster("Knight", 3, 2, 4, 4, Monster::Steel, { "Berserker" });
	Monster* m13 = new Monster("Vampire", 4, 3, 2, 4, Monster::Steel, { "Blood" }); //random type?

	std::cout << *m13 << "\n";
	m13->takeDamage(5);
}

