/******************************************************************************************
** Program name: barbarian.hpp
** Author: Kyle Wollman
** Date: 03/05/2017
** Description: This is the source file for the Barbarian class object. Barbarian is derived 
**		from the base class Creature. It contains 2 Die class object which it uses
**		to attack and defend against attacks. Barbarian class objects can attack,
**		defend or return their type to a calling funtion. 
*******************************************************************************************/

#include "barbarian.hpp"

/******************************************************************************************
** Description: This constructor creates a Barbarian object and sets its armor value to 0 and
**		its strength value to 12. 
*******************************************************************************************/

Barbarian::Barbarian(std::string n)
{
	name = n;
	armor = 0;
	strength = 12;
}

/******************************************************************************************
** description: destructor deletes item going out of scope 
*******************************************************************************************/

Barbarian::~Barbarian() {}

/******************************************************************************************
** Description: Barbarian::attack() calls the rollDie() function of the Die object twice
**		and accumulates the value from each roll, simulating rolling 2 dice. It returns
**		the accumulated value to the calling function.
*******************************************************************************************/

int Barbarian::attack()
{
	int attack = 0;
	
	for(int i = 0; i < 2; i++)
	{
		attack += die.rollDie();
	}

	return attack;
}

/******************************************************************************************
** Description: Barbarian::defense() calls the rollDie() function of the Die object twice
**		and accumulates the value from each roll, simulating rolling 2 dice. It returns
**		the accumulated value to the calling function.
*******************************************************************************************/

int Barbarian::defense()
{
	int defense = 0;
	
	for(int i = 0; i < 2; i++)
	{
		defense += die.rollDie();
	}
	
	return defense;
}

/******************************************************************************************
** Description: Barbarian::getType() returns the string "Barbarian" to the calling function.
*******************************************************************************************/

std::string Barbarian::getType()
{
	return "Barbarian";
}
