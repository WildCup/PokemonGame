#include "Monster.h"

#include <iostream>

Monster::Monster(const char* name, int strength, int dexterity, int hp, int exp, Type type, SpecialPower power) {
	this->name = name;
	this->strength = strength;
	this->dexterity = dexterity;
	this->hp = hp;
	this->exp = exp;
	this->type = type;
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
	return std << m.name << " - Power: " << m.power.name << "\n" <<
		"strength:" << m.strength << " dexterity:" << m.dexterity << " hp:" << m.hp << " exp:" << m.exp << "\n";
}
