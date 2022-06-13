#include "Monster.h"
#include "Color.h"
#include <iostream>
#include <windows.h>

Monster::Monster(const char* name, int strength, int dexterity, int hp, int exp, Monster::Type type, Monster::SpecialPower power) {
	this->name = name;
	this->strength = strength;
	this->dexterity = dexterity;
	this->hp = hp;
	this->exp = exp;
	if(type == Monster::Type::Random) this->type = static_cast<Monster::Type>(rand()%6);
	else this->type = type;
	this->power = power;
	lvl = 0;
}
void Monster::takeDamage(int dmg) {
	hp -= dmg;
	if (hp <= 0) die();
}
void Monster::die() {
	std::cout << name << " died\n";
}

std::ostream& operator<<(std::ostream& std, const Monster& m) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, Color::purple);
	std << m.name;
	SetConsoleTextAttribute(hConsole, Color::white);
	std << std::string(9 - strlen(m.name), ' ');
	std << " - Power: ";
	SetConsoleTextAttribute(hConsole, Color::gold);
	std << m.power.name << std::string(12 - strlen(m.power.name), ' ');
	SetConsoleTextAttribute(hConsole, Color::white);
	std << "str:";
	SetConsoleTextAttribute(hConsole, Color::red);
	std << m.strength;
	SetConsoleTextAttribute(hConsole, Color::white);
	std << " dex:";
	SetConsoleTextAttribute(hConsole, Color::navyBlue);
	std << m.dexterity;
	SetConsoleTextAttribute(hConsole, Color::white);
	std << " hp:";
	SetConsoleTextAttribute(hConsole, Color::paleRed);
	std << m.hp;
	SetConsoleTextAttribute(hConsole, Color::white);
	std << " exp:";
	SetConsoleTextAttribute(hConsole, Color::aqua);
	std << m.exp;
	SetConsoleTextAttribute(hConsole, Color::white);
	std << " Type:";
	SetConsoleTextAttribute(hConsole, Color::gold);
	switch (m.type) {
	case Monster::Type::Water: std << "Water" << "\n"; break;
	case Monster::Type::Earth: std << "Earth" << "\n"; break;
	case Monster::Type::Air: std << "Air" << "\n"; break;
	case Monster::Type::Fire: std << "Fire" << "\n"; break;
	case Monster::Type::Ice: std << "Ice" << "\n"; break;
	case Monster::Type::Steel: std << "Water" << "\n"; break;
	}
	SetConsoleTextAttribute(hConsole, Color::white);
	return std;
}
