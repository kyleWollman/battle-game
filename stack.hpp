/******************************************************************************************
** Program name: stack.hpp
** Author: Kyle Wollman
** Date: 03/05/2017
** Description: This is the header file for the Stack class. It contains a vector of pointers
**		to Creature objects, and an int to track the top of the stack. It can add
**		creature pointers to the top of the stack, print the creatures in the stack
**		by the most recent addition first, and clear all the creatures in the stack. 
*******************************************************************************************/

#ifndef STACK_HPP
#define STACK_HPP
#include "creature.hpp"
#include <vector>

class Stack
{
	private:
		std::vector <Creature*> stack;
		int top;
	public:
		Stack();
		~Stack();
		void addTop(Creature* c);
		void printStack();
		void clearStack();
};

#endif
