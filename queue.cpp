/******************************************************************************************
** Program name: queue.cpp
** Author: Kyle Wollman
** Date: 03/05/2017
** Description: This is the source file for the Queue class. The Queue class has an array
**		of pointers to Creature objects. It can add new Creatures to the array,
**		return the Creature in the front of the array to the calling function, 
**		shift the elements in the array to put a new Creature in the front, remove 
**		the Creature in the front of the array, or remove all of the elements in the
**		array.
*******************************************************************************************/

#include "queue.hpp"
#include <iostream>

/******************************************************************************************
** Description: This constructor initializes the a Queue class object and creates an array
**		of Creature pointers of the size specified by the user. It then points all
**		of the elements in the array to NULL and sets queuePosistion to zero.
*******************************************************************************************/

Queue::Queue(const int c)
{
	capacity = c;
	queueArray = new Creature* [c];
	
	for(int i = 0; i < c; i++)
	{
		queueArray[i] = NULL;
	}
	
	queuePosition = 0;
}

/******************************************************************************************
** Description: This destructor deletes all the Creatures that were stored during the execution
**		of the program. 
*******************************************************************************************/

Queue::~Queue()
{
	for(int i = 0; i < capacity; i++)
	{
		if(queueArray[i] != NULL)
		{
			delete queueArray[i];
			queueArray[i] = NULL;
		}
	}

	delete queueArray;

	queueArray = NULL;
}

/******************************************************************************************
** Description: Queue::addBack takes a Creature pointer as its parameter. It scans the 
**		array for the first empty element and points that to the Creature pointer.
*******************************************************************************************/

void Queue::addBack(Creature* c)
{
	while(queueArray[queuePosition] != NULL)
	{
		queuePosition++;
	}
	
	queueArray[queuePosition] = c;
	
}

/******************************************************************************************
** Description: Queue::getFront() returns the Creature pointer stored in the front node of 
**		the Queue.if the front node is empty it will return NULL.
*******************************************************************************************/

Creature* Queue::getFront()
{
	return queueArray[0];
}

/******************************************************************************************
** Description: Queue::moveFront() stores the first element in the queueArray in a temp
**				Creature pointer and shifts the rest of the elements in the array forward
**				by one position. The element that was in the front of the array is then put
**				in the last position. 
*******************************************************************************************/

void Queue::moveFront()
{
	Creature* temp = queueArray[0];
	
	for(int i = 0; i < queuePosition; i++)
	{
		queueArray[i] = queueArray[i + 1];
	}
	
	queueArray[queuePosition] = temp;
}

/******************************************************************************************
** Description: Queue::removeFront() moves the array elements up one position and sets the
**		last element in the array equal to NULL
*******************************************************************************************/

void Queue::removeFront()
{
	for(int i = 0; i < queuePosition; i++)
	{
		queueArray[i] = queueArray[i + 1];
	}
	
	queueArray[queuePosition] = NULL;
	
	queuePosition--;
	
}

/******************************************************************************************
** Description: Queue::clear() scans the array. Any elements not set to NULL are deleted and
**			set to NULL; 
*******************************************************************************************/

void Queue::clear()
{
	for(int i = 0; i < capacity; i++)
	{
		if(queueArray[i] != NULL)
		{
			delete queueArray[i];
			queueArray[i] = NULL;
		}
	}
}
