/******************************************************************************************
** Program name: harryPotter.cpp
** Author: Kyle Wollman
** Date: 03/05/2017
** Description: This is the source file for the HarryPotter class object. HarryPotter is derived 
**		from the base class Creature. It contains a Die class object which it uses
**		to attack and defend against attacks. HarryPotter class objects can attack,
**		defend or return their type to a calling funtion. 
*******************************************************************************************/

#include "harryPotter.hpp"

/******************************************************************************************
** Description: This constructor creates a HarryPotter object and sets its armor value to 0 
**		and its strength value to 10. 
*******************************************************************************************/

HarryPotter::HarryPotter(std::string n)
{
	name = n;
	armor = 0;
	strength = 10;
}

/****************************************************************************************
** Description: destructor deletes items going out of scope
***************************************************************************************/

HarryPotter::~HarryPotter() {}

/******************************************************************************************
** Description: HarryPotter::attack() calls the rollDie() function of the Die object twice
**		and accumulates the value from each roll, simulating rolling 2 dice. It returns
**		the accumulated value to the calling function.
*******************************************************************************************/

int HarryPotter::attack()
{
	int attack = 0;
	
	for(int i = 0; i < 2; i++)
	{
		attack += die.rollDie();
	}
	
	
	return attack;
}

/******************************************************************************************
** Description: HarryPotter::defense() calls the rollDie() function of the Die object twice
**		and accumulates the value from each roll, simulating rolling 2 dice. It returns
**		the accumulated value to the calling function.
*******************************************************************************************/

int HarryPotter::defense()
{
	int defense = 0;
	
	for(int i = 0; i < 2; i++)
	{
		defense += die.rollDie();
	}

	return defense;
}

/******************************************************************************************
** Description: HarryPotter::setStrength() overwrites the setStrength function from the 
**		Creature class. It takes an int as its parameter and subtracts that int
**		from HarryPotter's strength value. It then checks to see if the strength
**		value has reached or gone below zero. If it has, and this is the first time
**		that it has as indicated by lifePoint, then the strength value will be 
**		reset at 20 and the lifePoint will be set to zero, indicating not to reset
**		HarryPotter's strength anymore. 
*******************************************************************************************/

void HarryPotter::setStrength(int s)
{
	strength = strength - s;
	if(strength <= 0 && lifePoint == 1)
	{
		strength = 20;
		lifePoint = 0;
	}
}

/******************************************************************************************
** Description: HarryPotter::getType() returns the string "Harry Potter" to the calling function.
*******************************************************************************************/

std::string HarryPotter::getType()
{
	return "Harry Potter";
}
