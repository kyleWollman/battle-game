/******************************************************************************************
** Program name: combatMenu.hpp
** Author: Kyle Wollman
** Date: 3/05/2017
** Description: This is the header file for the CombatMenu class. CombatMenu contains 2
**		Queue class pointers to hold the two team lineups. It also has 3 creature 
**		pointers to keep track of what creature is being added to the queue, which
**		creature is attacking, and which is defending. It also has a Stack class 
**		pointer to hold the losers of each round. There is a constructor to create
**		a CombatMenu object, and fill the two team Queues, and functions to run the
**		tournament as well as each individaul battle.   
*******************************************************************************************/

#ifndef COMBATMENU_HPP
#define COMBATMENU_HPP
#include "creature.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "blueMen.hpp"
#include "medusa.hpp"
#include "harryPotter.hpp"
#include "queue.hpp"
#include "stack.hpp"

class CombatMenu
{
	private:
		Queue* team1;
		Queue* team2;
		int team1Score = 0, team2Score = 0;
		Creature* creature = NULL;
		Creature* attacker = NULL;
		Creature* defender = NULL;
		Stack* loserPile;
		char again;
		
	public:
		CombatMenu();
		~CombatMenu();
		void tournament();
		void battle();
		
};

#endif
		
