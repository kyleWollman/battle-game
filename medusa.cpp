/******************************************************************************************
** Program name: medusa.cpp
** Author: Kyle Wollman
** Date: 03/05/2017
** Description: This is the source file for the Medusa class object. Medusa is derived 
**		from the base class Creature. It contains a Die class object which it uses
**		to attack and defend against attacks. Medusa class objects can attack,
**		defend or return their type to a calling funtion. 
*******************************************************************************************/

#include "medusa.hpp"

/******************************************************************************************
** Description: This constructor creates a Medusa object and sets its armor value to 3 and
**		its strength value to 8. 
*******************************************************************************************/

Medusa::Medusa(std::string n)
{
	name = n;
	armor = 3;
	strength = 8;
}

/*****************************************************************************************
** Description: destructor deletes items going out of scope
*****************************************************************************************/

Medusa::~Medusa() {}

/******************************************************************************************
** Description: Medusa::attack() calls rollDie() function twice simulating rolling two dice.
**		If the accumulated value of the two rolls is 12, then the attack value is 
**		set to 33 which is a strong enough value to overcome the strongest defense
**              from other Creatures plus drain all their strength points. The one exception
**		is a charm defense from a Vampire class object, which would negate this
**		attack. If the accumulated value is something other than 12, that value
**		is returned to the calling function. 
*******************************************************************************************/

int Medusa::attack()
{
	int attack = 0;
	
	for(int i = 0; i < 2; i++)
	{
		attack += die.rollDie();
	}
	
	if(attack == 12)
	{
		attack = 33; //defeating any Creatures defense + armor + strength, except Vampire charm
	}
	
	return attack;
}

/******************************************************************************************
** Description: Medusa::defense() calls the rollDie() function of the Die object and returns
**		that value to the calling function.
*******************************************************************************************/

int Medusa::defense()
{
	return die.rollDie();
}

/******************************************************************************************
** Description: Medusa::getType() returns the string "Medusa" to the calling function.
*******************************************************************************************/

std::string Medusa::getType()
{
	return "Medusa";
}
