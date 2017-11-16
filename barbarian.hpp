/******************************************************************************************
** Program name: barbarian.hpp
** Author: Kyle Wollman
** Date: 03/05/2017
** Description: This is the header file for the Barbarian class object. Barbarian is derived 
**		from the base class Creature. It contains a Die class object which it uses
**		to attack and defend against attacks. Barbarian class objects can attack,
**		defend or return their type to a calling funtion. 
*******************************************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "creature.hpp"
#include "die.hpp"
#include <string>

class Barbarian: public Creature
{
	private:
		Die die = Die(6);
		
	public:
		Barbarian(std::string n);
		virtual ~Barbarian();
		int attack();
		int defense();
		std::string getType();
		
};

#endif
