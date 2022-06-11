#pragma once
#include <iostream>

class Monster
{
	struct SpecialPower
	{
		const char* name;
	};
public:
	enum Type { Water, Earth, Air, Fire, Ice, Steel };

private:
	const char* name;
	int strength;
	int dexterity;
	int hp;
	int exp;
	Type type;
	SpecialPower power;
	int lvl;
public:
	Monster(const char* name, int strength, int dexterity, int hp, int exp, Type type, SpecialPower power);
	friend std::ostream& operator<<(std::ostream& std, const Monster&);
	void takeDamage(int dmg);
	void die();
};


std::ostream& operator<<(std::ostream& std, const Monster& m);

