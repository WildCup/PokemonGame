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
	Name nameType;		//name of pre-defined monster. Used to identify it
	std::string name;	//name that sould be printed in the console
	int str;			//strangth of the attact
	int dex;			//dexternity * 0.1% = chance to dodge (max dex is set to 9)
	int hp;				//health points
	int exp;			//exp gained by defiting the creature 
	Monster::Type type;	//attribute of the monster. Used to calculate effectiveness of the attack
	SpecialPower power;	//special ability of the monster
	int lvl = 1;
	int suffer = 0;		//amount of dmg taken every turn

public:
	//constructor
	Monster(Name name, int str, int dex, int hp, int exp, Monster::Type type, SpecialPower power);

	bool takeDamage(int dmg, bool canDodge, int& exp);	//returns true if took dmg. Increses attackers exp if died
	void die();											//check if can revive
	bool evolve(int& exp);								//return true if succed (and decrease given exp)
	bool attack(Monster& monster, int& exp);			//return true if succesfully attacked. Check for passive abilities
	bool special(Monster** arr, const size_t size, int& exp); //use special ability. Arr is arr of allies or enemies depending if power is offencive or defensive

	std::string getName();   
	std::string checkName(); //convert enum to string. Returns name
	int getLvl();
	SpecialPower getPower();
	void sufferDmg(int& exp); //take undodgeable dmg depending on suffer variable
	bool isOffensive();
	bool isPassive();
	bool canUsePower();
	bool isDead();
	bool canMove = true;
	
	friend std::ostream& operator<<(std::ostream& std, const Monster&);
	std::string toString();  //return a string that can be saved to file

	friend Monster** load(bool& succes, int& round, int& difficulty, int& exp);
	void set(int str, int dex, int hp, int exp, int lvl); //set paramiters of a monster (after loading from file)
};


std::ostream& operator<<(std::ostream& std, const Monster& m);				//print information about the monster
std::ostream& operator<<(std::ostream& std, const Monster::SpecialPower& m);//print information about its special ability

