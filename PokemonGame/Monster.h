#pragma once
#include <iostream>

class Monster
{
	struct SpecialPower
	{
		const char* name;
	};
public:
	enum class Type { Water, Earth, Air, Fire, Ice, Steel, Random };

private:
	const char* name;
	int strength;
	int dexterity;
	int hp;
	int exp;
	Monster::Type type;
	SpecialPower power;
	int lvl;
public:
	Monster(const char* name, int strength, int dexterity, int hp, int exp, Monster::Type type, SpecialPower power);
	friend std::ostream& operator<<(std::ostream& std, const Monster&);
	void takeDamage(int dmg);
	void die();
	const char* getName() { return name; }
};


std::ostream& operator<<(std::ostream& std, const Monster& m);

