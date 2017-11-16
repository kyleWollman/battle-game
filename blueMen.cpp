/******************************************************************************************
** Program name: blueMen.cpp
** Author: Kyle Wollman
** Date: 03/05/2017
** Description: This is the source file for the BlueMen class object. BlueMen is derived 
**		from the base class Creature. It contains 2 Die class objects which it uses
**		to attack and defend against attacks. BlueMen class objects can attack,
**		defend or return their type to a calling funtion. 
*******************************************************************************************/

#include "blueMen.hpp"

/******************************************************************************************
** Description: This constructor creates a BlueMen object and sets its armor value to 3 and
**		its strength value to 12. 
*******************************************************************************************/

BlueMen::BlueMen(std::string n)
{
	name = n;
	armor = 3;
	strength = 12;
}

/******************************************************************************************
** description: destructor deletes item going out of scope 
*******************************************************************************************/

BlueMen::~BlueMen() {}

/******************************************************************************************
** Description: BlueMen::attack() calls the rollDie() function of the Die object twice
**		and accumulates the value from each roll, simulating rolling 2 dice. It returns
**		the accumulated value to the calling function.
*******************************************************************************************/

int BlueMen::attack()
{
	int attack = 0;
	
	for(int i = 0; i < 2; i++)
	{
		attack += attackDie.rollDie();
	}
	
	return attack;
}

/******************************************************************************************
** Description: BlueMen::defense() calls the rollDie() function of the Die object 3 times 
**		if BlueMen's strength value is 9 - 12, twice if the strength value is 
**		5 - 8, and once if the strength value is 4 or less. This simulates rolling
**		3 die, 2 die, and 1 die respectively. It returns the value retrieved from
**		the rollDie calls and their accumulation to the calling function.
*******************************************************************************************/

int BlueMen::defense()
{
	int defense = 0;
	
	if(getStrength() > 8)
	{
		for(int i = 0; i < 3; i++)
		{
			defense += defenseDie.rollDie();
		}
	}
	
	else if(getStrength() > 4)
	{
		for(int i = 0; i < 2; i++)
		{
			defense += defenseDie.rollDie();
		}
	}
	
	else 
	{
		defense = defenseDie.rollDie();
	}
	
	return defense;
}

/******************************************************************************************
** Description: BlueMen::getType() returns the string "Blue Men" to the calling function.
*******************************************************************************************/

std::string BlueMen::getType()
{
	return "Blue Men";
}
