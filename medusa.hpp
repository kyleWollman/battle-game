/******************************************************************************************
** Program name: medusa.hpp
** Author: Kyle Wollman
** Date: 03/05/2017
** Description: This is the header file for the Medusa class object. Medusa is derived 
**		from the base class Creature. It contains a Die class object which it uses
**		to attack and defend against attacks. Medusa class objects can attack,
**		defend or return their type to a calling funtion. 
*******************************************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include "creature.hpp"
#include "die.hpp"
#include <string>

class Medusa: public Creature
{
	private:
		Die die = Die(6);
		
	public:
		Medusa(std::string n);
		virtual ~Medusa();
		int attack();
		int defense();
		std::string getType();
		
};

#endif
