#pragma once
#include <iostream>

class Monster
{
	struct SpecialPower
	{
		std::string name;
		std::string instruction;
		bool offensive = true; //false is defensive
		int use = 1; //number of max useages during battle. -1 = unlimited 
		bool passive = false; // false if active

	};
public:
	enum class Type { Water, Earth, Air, Fire, Ice, Steel, Random };
	enum class Name { Slime,Glue,Spider,Tree,Ghost,Mist,Vector,Fenix,Eye,Witch,Cube,Knight,Vampire,Beast,Mirror};
	friend std::ostream& operator<<(std::ostream& std, const SpecialPower&);

private:
	Name nameType;
	std::string name;
	int str;
	int dex;
	int hp;
	int exp;
	Monster::Type type;
	SpecialPower power;
	int lvl = 1;
	int suffer = 0; //amount of dmg taken every turn
public:
	Monster(Name name, int str, int dex, int hp, int exp, Monster::Type type, SpecialPower power);

	bool takeDamage(int dmg, bool canDodge, int& exp);
	void die();
	bool evolve(int& exp); //return true if succed
	bool attack(Monster& monster, int& exp);
	bool special(Monster** arr, const size_t size, int& exp);

	std::string getName();
	std::string checkName();
	int getLvl();
	SpecialPower getPower();
	void sufferDmg(int& exp);
	bool isOffensive();
	bool isPassive();
	bool canUsePower();
	bool isDead();
	bool canMove = true;
	
	friend std::ostream& operator<<(std::ostream& std, const Monster&);
	std::string toString();

	friend Monster** load(bool& succes, int& round, int& difficulty, int& exp);
	void set(int str, int dex, int hp, int exp, int lvl);
};


std::ostream& operator<<(std::ostream& std, const Monster& m);
std::ostream& operator<<(std::ostream& std, const Monster::SpecialPower& m);

