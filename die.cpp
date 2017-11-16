/******************************************************************************************
** Program name: die.cpp
** Author: Kyle Wollman
** Date: 03/05/2017
** Description: This is the source file for the Die class. Die objects only have the data
**		member side, indicating how many sides they have. Die has a constructor and
**		a destructor, and a member function to roll the die.
*******************************************************************************************/

#include "die.hpp"
#include<ctime>
#include<cstdlib>

/******************************************************************************************
** Description: This constructor creates a seed and uses it to see srand(). 
*******************************************************************************************/

Die::Die(int s)
{
	sides = s;
	unsigned seed = time(0);
	srand(seed);
}

/******************************************************************************************
** Description: Die::rollDie() is a virtual function that generates and returns a random 
**		integer between 1 and N, N being the number of sides the Die has.
*******************************************************************************************/

int Die::rollDie()
{
	return rand() % sides + 1;
}

/******************************************************************************************
** Description: This destructor deletes a Die object.  
*******************************************************************************************/

Die::~Die() {}
