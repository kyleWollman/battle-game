/******************************************************************************************
** Program name: harryPotter.hpp
** Author: Kyle Wollman
** Date: 03/05/2017
** Description: This is the header file for the HarryPotter class object. HarryPotter is derived 
**		from the base class Creature. It contains a Die class object which it uses
**		to attack and defend against attacks. HarryPotter class objects can attack,
**		defend or return their type to a calling funtion. 
*******************************************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include "creature.hpp"
#include "die.hpp"
#include <string>

class HarryPotter: public Creature
{
	private:
		Die die = Die(6);
		int lifePoint = 1;
		
	public:
		HarryPotter(std::string n);
		virtual ~HarryPotter();
		int attack();
		int defense();
		void setStrength(int);
		std::string getType();

};

#endif
