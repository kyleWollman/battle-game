/******************************************************************************************
** Program name: stack.hpp
** Author: Kyle Wollman
** Date: 03/05/2017
** Description: This is the header file for the Stack class. It contains a vector of pointers
**		to Creature objects, and an int to track the top of the stack. It can add
**		creature pointers to the top of the stack, print the creatures in the stack
**		by the most recent addition first, and clear all the creatures in the stack. 
*******************************************************************************************/

#include "stack.hpp"
#include <iostream>

/******************************************************************************************
** Description: This constructor initializes the a Stack class object and sets the top of 
**		the stack to -1 to indicate that the stack is empty.
*******************************************************************************************/

Stack::Stack()
{
	top = -1;
}

/******************************************************************************************
** Description: This destructor deletes all the creatures that were stored during the execution
**		of the program. 
*******************************************************************************************/

Stack::~Stack() 
{
	while(top > -1)
	{
		delete stack.at(top);
		stack.at(top) = NULL;
		top--;
	}
}

/******************************************************************************************
** Description: Stack::addTop takes a Creature pointer as its parameter and adds it to the
**		top of the stack.
*******************************************************************************************/

void Stack::addTop(Creature* c)
{
	stack.push_back(c);
	top++;
}

/******************************************************************************************
** Description: Stack::printStack() displays the contents of the stack in a last in first
**		out order. 
*******************************************************************************************/

void Stack::printStack()
{
	while(top > -1)
	{
		std::cout << stack.at(top) -> getType() << ": " << stack.at(top) -> getName() << std::endl;
		top--;
	}
	
	top = stack.size() - 1;
}

/******************************************************************************************
** Description: Stack::clear() deletes all of the Creatures in the stack leaving it empty.
*******************************************************************************************/

void Stack::clearStack()
{
	while(top > -1)
	{
		delete stack.at(top);
		stack.at(top) = NULL;
		top--;
	}
	
	top = stack.size() - 1;
}
