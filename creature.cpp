/******************************************************************************************
** Program name: creature.cpp
** Author: Kyle Wollman
** Date: 3/05/2017
** Description: This is the source file for the Creature class object. Creature is an 
**		abstract class that has protected member data representing strength points,
**		name, and armor. It has pure vitrual functions which are overwritten by derived
**		classes. It can return the strength, name, or armor value of a Creature object
**		through the getStrength(), getName(), and getArmor() functions respectively. 
*******************************************************************************************/

#include "creature.hpp"

/******************************************************************************************
** Description: destructor destroys items going out of scope
******************************************************************************************/
		
Creature::~Creature() {}

/******************************************************************************************
** Description: Creature::getStrength() returns the current strength value of the Creature
**		object. 
*******************************************************************************************/

int Creature::getStrength()
{
	return strength;
}

/******************************************************************************************
** Description: Creature::restoreStrength() restores some of the Creature's current strength
*******************************************************************************************/

void Creature::restoreStrength()
{
	strength += strength * .5;
}

/******************************************************************************************
** Description: Creature::getArmor() returns the armor value of the Creature object. 
*******************************************************************************************/

int Creature::getArmor()
{
	return armor;
}

/******************************************************************************************
** Description: Creature::setStrength() takes an int as its parameter and duducts that 
**		value from the Creature object's current strength value. setStrength()
**		is a virtual function that is overwritten by HarryPotter class objects
**		to modify it. Other derived classes use this function directly. 
*******************************************************************************************/

void Creature::setStrength(int val)
{
	strength = strength - val;
}

/******************************************************************************************
** Description: Creature::getName() returns the name of the Creature object. 
*******************************************************************************************/

std::string Creature::getName()
{
	return name;
}


