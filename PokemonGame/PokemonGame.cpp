// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Monster.h"
#include <windows.h>   //colors


//Monster* m0 = new Monster("Slime", 2, 5, 2, 5, Monster::Water, { "Eat" });
//Monster* m1 = new Monster("Glue", 1, 7, 1, 5, Monster::Water, { "Stop" });
//Monster* m2 = new Monster("Spider", 2, 6, 1, 5, Monster::Earth, { "Poison" });
//Monster* m3 = new Monster("Tree", 2, 3, 4, 5, Monster::Earth, { "Heal" });
//Monster* m4 = new Monster("Ghost", 2, 6, 1, 5, Monster::Air, { "Fear" });
//Monster* m5 = new Monster("Mist", 3, 3, 3, 5, Monster::Air, { "Blind" });
//Monster* m6 = new Monster("Vector", 6, 2, 1, 5, Monster::Fire, { "Ablaze" });
//Monster* m7 = new Monster("Fenix", 3, 3, 3, 5, Monster::Fire, { "Resurrect" });
//Monster* m8 = new Monster("Eye", 5, 2, 2, 5, Monster::Ice, { "Laser" });
//Monster* m9 = new Monster("Witch", 4, 3, 2, 5, Monster::Ice, { "Mirror" });
//Monster* m10 = new Monster("Cube", 2, 1, 5, 4, Monster::Steel, { "Shield" });
//Monster* m11 = new Monster("Knight", 3, 2, 4, 4, Monster::Steel, { "Berserker" });
//Monster* m12 = new Monster("Vampire", 4, 3, 2, 4, Monster::Steel, { "Blood" }); //random type?
//Monster* m13 = new Monster("Vampire", 4, 3, 2, 4, Monster::Steel, { "Blood" }); //random type?
//Monster* m14 = new Monster("Vampire", 4, 3, 2, 4, Monster::Steel, { "Blood" }); //random type?
Monster monsters[]{ 
	{"Slime", 2, 5, 2, 5, Monster::Type::Water, { "Eat" }},
	{"Glue", 1, 7, 1, 5, Monster::Type::Water, { "Stop" }},
	{"Spider", 2, 6, 1, 5, Monster::Type::Earth, { "Poison" }},
	{"Tree", 2, 3, 4, 5, Monster::Type::Earth, { "Heal" }},
	{"Ghost", 2, 6, 1, 5, Monster::Type::Air, { "Fear" }},
	{"Mist", 3, 3, 3, 5, Monster::Type::Air, { "Blind" }},
	{"Vector", 6, 2, 1, 5, Monster::Type::Fire, { "Ablaze" }},
	{"Fenix", 3, 3, 3, 5, Monster::Type::Fire, { "Resurrect" }},
	{"Eye", 5, 2, 2, 5, Monster::Type::Ice, { "Laser" }},
	{"Witch", 4, 3, 2, 5, Monster::Type::Ice, { "Mirror" }},
	{"Cube", 2, 1, 5, 4, Monster::Type::Steel, { "Shield" }},
	{"Knight", 3, 2, 4, 4, Monster::Type::Steel, { "Berserker" }},
	{"Vampire", 4, 3, 2, 4, Monster::Type::Random, { "Blood" }},
	{"Beast", 4, 3, 2, 4, Monster::Type::Random, { "Blood" }},
	{"Mirror", 3, 3, 3, 4, Monster::Type::Random, { "Repeal" }} };

Monster** chooseMonsters() {
	using namespace std;
	cout << "Monster list:\n";
	for (size_t i = 0; i < 10; i++)
		cout << i << ".  " << monsters[i];
	for (size_t i = 10; i < 15; i++)
		cout << i << ". " << monsters[i];

	int a[] = { 0,0,0,0,0,0 };
	bool done = false;
	while (!done) {
		done = true;
		cout << "Choose 6 monsters: ";
		for (int i = 0; i < 6; ++i) {
			cin >> a[i];
			if (cin.fail() || a[i] < 0 || a[i] >= 15) {
				cout << "Incorrect numbers. Type numbers from 0 to 14 separated by space in one line\n";
				done = false;
				cin.clear();
				cin.ignore(123, '\n');
				break;
			}
		}
	}
	cout << "Your monsters: ";
	for (int i = 0; i < 5; ++i) 
		cout << monsters[a[i]].getName() << ", ";
	cout << monsters[a[5]].getName() << "\n\n";

	static Monster* player[6];
	for (int i = 0; i < 6; ++i)
		player[i] = new Monster(monsters[a[i]]);
	return player;
}

Monster** chooseEnemy(){
	static Monster* enemy[4];
	for (int i = 0; i < 4; ++i)
		enemy[i] = new Monster(monsters[rand()%15]);
	return enemy;

}
void print(Monster** arr, size_t size) {
	using namespace std;
	if (size == 6) cout << "--------------------Player's team--------------------" << "\n";
	else		   cout << "--------------------Enemy's  team--------------------" << "\n";
	for (size_t i = 0; i < size; i++)
		cout << i << ". " << **(arr + i);
	cout << "\n";
}

int main()
{
	Monster** player = chooseMonsters();
	Monster** enemy = chooseEnemy();

	print(player, 6);
	print(enemy, 4);

	using namespace std;
	cout << "--------------------MENU--------------------" << "\n";
	cout << "1. Type number to attack with specific monster" << "\n";
	
}

/*---quesitons about the project---
-can we 'change active creature' and then still attack?
-monsters with new or not?
-questions about project on teams?
-distructor will delete my name?
*/