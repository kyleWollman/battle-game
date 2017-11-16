/******************************************************************************************
** Program name: vampire.cpp
** Author: Kyle Wollman
** Date: 03/05/2017
** Description: This is the source file for the Vampire class object. Vampire is derived 
**		from the base class Creature. It contains 2 Die class objects which it uses
**		to attack and defend against attacks. Vampire class objects can attack,
**		defend or return their type to a calling funtion. 
*******************************************************************************************/

#include "vampire.hpp"

/******************************************************************************************
** Description: This constructor creates a Vampire object and sets its armor value to 1 and
**		its strength value to 18. 
*******************************************************************************************/
Vampire::Vampire(std::string n)
{
	name = n;
	armor = 1;
	strength = 18;
}

/******************************************************************************************
** Description: destructor delets items going out of scope
*******************************************************************************************/
 
Vampire::~Vampire() {}

/******************************************************************************************
** Description: Vampire::attack() calls the rollDie() function of the Die object and returns
**		that value to the calling function.
*******************************************************************************************/

int Vampire::attack()
{
	return attackDie.rollDie();
}

/******************************************************************************************
** Description: Vampire::defense() uses the rollDie() function to generate a random number
**		called charm. For half the values of charm defense() will return a value
**		from defenseDie's rollDie() function. The other half of the time, it 
**		will return 32, which is a high enough defense to nullify the strongest
**		possible attack from any other creature in the game.
*******************************************************************************************/

int Vampire::defense()
{
	int charm = defenseDie.rollDie(); //to determine if Vampire will use charm defense
	
	if(charm >= 1 && charm <= 3)
	{
		return defenseDie.rollDie();
	}
	
	else
	{
		return 33; //negate largest attack possible from any creature
	}
}

/******************************************************************************************
** Description: Vampire::getType() returns the string "Vampire" to the calling function.
*******************************************************************************************/

std::string Vampire::getType()
{
	return "Vampire";
}
