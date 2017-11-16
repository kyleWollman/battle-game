/******************************************************************************************
** Program name: blueMen.hpp
** Author: Kyle Wollman
** Date: 03/05/2017
** Description: This is the header file for the BlueMen class object. BlueMen is derived 
**		from the base class Creature. It contains 2 Die class objects which it uses
**		to attack and defend against attacks. BlueMen class objects can attack,
**		defend or return their type to a calling funtion. 
*******************************************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include "creature.hpp"
#include "die.hpp"
#include <string>

class BlueMen: public Creature
{
	private:
		Die attackDie = Die(10);
		Die defenseDie = Die(6);
		
	public:
		BlueMen(std::string n);
		virtual ~BlueMen();
		int attack();
		int defense();
		std::string getType();
		
};

#endif
