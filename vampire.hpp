/******************************************************************************************
** Program name: vampire.hpp
** Author: Kyle Wollman
** Date: 03/05/2017
** Description: This is the header file for the Vampire class object. Vampire is derived 
**		from the base class Creature. It contains 2 Die class objects which it uses
**		to attack and defend against attacks. Vampire class objects can attack,
**		defend or return their type to a calling funtion. 
*******************************************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include "creature.hpp"
#include "die.hpp"
#include <string>

class Vampire: public Creature
{
	private:
		Die attackDie = Die(12);
		Die defenseDie = Die(6);
		
	public:
		Vampire(std::string n);
		virtual ~Vampire();
		int attack();
		int defense();
		std::string getType();
		
};

#endif
