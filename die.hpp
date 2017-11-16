/******************************************************************************************
** Program name: die.hpp
** Author: Kyle Wollman
** Date: 03/05/2017
** Description: This is the header file for the Die class. Die objects only have the data
**		member side, indicating how many sides they have. Die has a constructor and
**		a destructor, and a member function to roll the die.
*******************************************************************************************/

#ifndef DIE_HPP
#define DIE_HPP
#include <iostream>
#include <string>

class Die
{
	private:
		int sides;
		
	public:
		Die(int);
		~Die();
		int rollDie(); 
};

#endif
