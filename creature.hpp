/******************************************************************************************
** Program name: creature.hpp
** Author: Kyle Wollman
** Date: 3/05/2017
** Description: This is the header file for the Creature class object. Creature is an 
**		abstract class that has protected member data representing strength points,
**		name, and armor. It has pure vitrual functions which are overwritten by derived
**		classes. It can return the strength, name, or armor value of a Creature object
**		through the getStrength(), getName(), and getArmor() functions respectively. 
*******************************************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP
#include <string>

class Creature
{
	protected:
		int armor, strength;
		std::string name;
		
	public:
		virtual ~Creature(); 
		virtual int attack() = 0;
		virtual int defense() = 0;
		virtual std::string getType() = 0;
		void restoreStrength();
		int getStrength();
		virtual void setStrength(int);
		int getArmor();
		std::string getName();
};

#endif
		
