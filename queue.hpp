/******************************************************************************************
** Program name: queue.hpp
** Author: Kyle Wollman
** Date: 03/05/2017
** Description: This is the header file for the Queue class. The Queue class has an array
**		of pointers to Creature objects. It can add new Creatures to the array,
**		return the Creature in the front of the array to the calling function, 
**		shift the elements in the array to put a new Creature in the front, remove 
**		the Creature in the front of the array, or remove all of the elements in the
**		array.
*******************************************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "creature.hpp"

class Queue
{
	private:
		Creature** queueArray;
		int queuePosition;
		int capacity;
		
	public: 
		Queue(const int c);
		~Queue();
		void addBack(Creature* c);
		Creature* getFront();
		void moveFront();
		void removeFront();
		void clear();

};

#endif
