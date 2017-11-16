/******************************************************************************************
** Program name: combatMenu.cpp
** Author: Kyle Wollman
** Date: 3/05/2017
** Description: This is the source file for the CombatMenu class. CombatMenu contains 2
**		Queue class pointers to hold the two team lineups. It also has 3 creature 
**		pointers to keep track of what creature is being added to the queue, which
**		creature is attacking, and which is defending. It also has a Stack class 
**		pointer to hold the losers of each round. There is a constructor to create
**		a CombatMenu object, and fill the two team Queues, and functions to run the
**		tournament as well as each individaul battle.   
*******************************************************************************************/

#include "combatMenu.hpp"
#include "verify.hpp"
#include <iostream>
#include <ctype.h>

/******************************************************************************************
** Description: This constructor creates a CombatMenu object. It asks the user how many 
**		fighters will be on the first team and then fills the team1 Queue with the
**		appropriate amount of creatures chosen by the user. It then repeats this for
**		team2's Queue. It then calls the tournament function to run the tournament.
**		It repeats this as long as the user indicates they would like another tounrment.
*******************************************************************************************/

CombatMenu::CombatMenu()
{
	
	do
	{
		loserPile = new Stack;
		int fighters = 0;
		
		while(fighters < 1)
		{
			std::cout << "\nHow many fighters will team 1 have? (at least 1)" << std::endl;
			std::cin >> fighters;
			verify(&fighters);
		}
		
		team1 = new Queue(fighters);
		
		std::string name;
		char choice;
		
		//fill team 1's queue
		for(int i = 0; i < fighters; i++)
		{
			bool creatureMade = false;	
			
			do
			{
				std::cout << "\nHere are the Creatures waiting to battle:" 
					  << "\na. Vampire"
					  << "\nb. Barbarian"
					  << "\nc. Blue Men"
					  << "\nd. Medusa"
					  << "\ne. Harry Potter"
					  << "\n\nPlease choose Creature " << i + 1 << "." << std::endl;
							  
				std::cin >> choice;
				verify(&choice);
				
				std::cout << "\nWhat would you like Creature " << i + 1 << "'s name to be?" << std::endl;
				std::cin.clear();
				std::cin.ignore();
				std::getline(std::cin, name);
				
				if(choice == 'a')
				{
					creature = new Vampire(name);
					creatureMade = true;
				}
				
				else if(choice == 'b')
				{
				creature = new Barbarian(name);
					creatureMade = true;
				}
				
				else if(choice == 'c')
				{
					creature = new BlueMen(name);
					creatureMade = true;
				}
				
				else if(choice == 'd')
				{
					creature = new Medusa(name);
					creatureMade = true;
				}
				
				else if(choice == 'e')
				{
				creature = new HarryPotter(name);
				creatureMade = true;
				}
				
				else
				{
					std::cout << "\nERROR.CREATURE NOT MADE. PLEASE CHOOSE A MENU ITEM" << std::endl;
				}
			}while(!creatureMade);
			
			team1 -> addBack(creature);
		}
		
		fighters = 0;
		
		while(fighters < 1)
		{
			std::cout << "\nHow many fighters will team 2 have? (at least 1)" << std::endl;
			std::cin >> fighters;
			verify(&fighters);
		}
		
		team2 = new Queue(fighters);
		
		//fill team 2's queue
		for(int i = 0; i < fighters; i++)
		{
			bool creatureMade = false;	
			do
			{
				std::cout << "\nHere are the Creatures waiting to battle:" 
					  << "\na. Vampire"
				  	  << "\nb. Barbarian"
					  << "\nc. blue men"
					  << "\nd. medusa"
					  << "\ne. harry potter"
					  << "\n\nPlease choose Creature " << i + 1 << "." << std::endl;
						  
				std::cin >> choice;
				verify(&choice);
				
				std::cout << "\nWhat would you like Creature " << i + 1 << "'s name to be?" << std::endl;
				std::cin.clear();
				std::cin.ignore();
				std::getline(std::cin, name);
				
				if(choice == 'a')
				{
					creature = new Vampire(name);
					creatureMade = true;
				}
				
				else if(choice == 'b')
				{
					creature = new Barbarian(name);
					creatureMade = true;
				}
				
				else if(choice == 'c')
				{
				creature = new BlueMen(name);
					creatureMade = true;
				}
				
				else if(choice == 'd')
				{
					creature = new Medusa(name);
					creatureMade = true;
				}
					
				else if(choice == 'e')
				{
					creature = new HarryPotter(name);
					creatureMade = true;
				}
				
				else
				{
					std::cout << "\nERROR. CREATURE NOT MADE. PLEASE CHOOSE A MENU ITEM" << std::endl;
				}
			}while(!creatureMade);
				
			team2 -> addBack(creature);
		}
		
		tournament();
		
		team1 -> clear();
		delete team1;
	
		team2 -> clear();
		delete team2;
		
		loserPile -> clearStack();
		delete loserPile;
		
	} while(again == 'Y');
}

//destructor
CombatMenu::~CombatMenu() {}

/******************************************************************************************
** Description: CombatMenu::tournament() runs the tournament. It calls the battle fuction
**		to do the battling between individual Creatures, and continues the battles
**		going until one of the teams has no Creatures left. It then displays the
**		winner and gives the user the option to see the loser pile and to have 
**		another tournament.
*******************************************************************************************/

void CombatMenu::tournament()
{
	do
	{
		battle();
				
		std::string cont;
		std::cout << "Press <ENTER> to continue to the next round" << std::endl;
		std::getline(std::cin, cont);
		
	}while(team1 -> getFront() != NULL && team2 -> getFront() != NULL);
	
	if(team1Score > team2Score)
	{
		std::cout << "\nTeam 1 is the winner of the tournament." 
			  << " They finished with a score of: " << team1Score 
			  << "\nWhile Team 2 had a score of: " << team2Score << std::endl;
	}
	
	else if(team2Score > team1Score)
	{
		std::cout << "\nTeam 2 is the winner of the tournament." 
			  << " They finished with a score of: " << team2Score 
			  << "\nWhile Team 1 had a score of: " << team1Score << std::endl;
	}
	
	else
	{
		std::cout << "\nTournament was a tie. Both teams had a score of: "
			  << team1Score << std::endl;
	}
 
	char pile;
	do
	{
		std::cout << "Would you like to view the loser pile? (Y/N)" << std::endl;
		std::cin >> pile;
		
		pile = toupper(pile);
		
	}while(pile != 'Y' && pile != 'N');
	
	if(pile == 'Y')
	{
		loserPile -> printStack();
	}
		
	//ask user for another tournament
	do
	{
		std::cout << "Would you like to have another tournament? (Y/N)" << std::endl;
		std::cin >> again;
		
		again = toupper(again);
		
	} while( again != 'Y' && again != 'N');
	
}
	
	
/******************************************************************************************
** Description: CombatMenu::battle() runs the battle between the 2 Creature class objects
**		chosen by the user. It first calls their attack functions and compares
**		the values returned to determine be the attacker first and who will be 
**		the defender. It assigns the attacker and defender pointers to the 
**		appropriate creatures. It then starts the battle by calling the attacker's 
**		attack function and the defender's defense function to determine the strength
**		of the attack. The defender's defense value is added to its armor value
**		and the total is subrtacted from the attacker's attack value. The resulting
**		value is deducted from the defender's strength via the setStrength() fucntion.
**		The attacker and defender pointers then switch and point to the other creature
**		and the process is repeated until one of the creatures has a strength value
**		equal to or less than zero. The winner is then moved to the back of its team's 
**		Queue and the loser is added to the loser pile.
*******************************************************************************************/

void CombatMenu::battle()
{
	
	//determine who attacks first
	int tryout1, tryout2;
	
	do
	{
		tryout1 = team1 -> getFront() -> attack();
		tryout2 = team2 -> getFront() -> attack();
		
		if(tryout1 > tryout2)
		{
			attacker = team1 -> getFront();
			defender = team2 -> getFront();
		}
		
		else 
		{
			attacker = team2 -> getFront();
			defender = team1 -> getFront();
		}
		
	} while(tryout1 == tryout2);
	
	int count = 0;
	
	//start battle
	do
	{
		count++;
		
		std::cout << "\n\n\nBattle #" << count << std::endl;
		std::cout << attacker -> getType() << " " << attacker -> getName()
			  << " is now the attacker." << std::endl;
		std::cout << defender -> getType() << " " << defender -> getName() 
			  << " is now the defender." << std::endl;
		
		int attack = 0;
		int defense = 0;
		
		
		attack = attacker -> attack();
		defense = defender -> defense();
		
		std::cout << attacker -> getName() << "'s attack is: " << attack << std::endl;
		std::cout << defender -> getName() << "'s defense is: " << defense << std::endl;
		std::cout << defender -> getName() << "'s armor is: " << defender -> getArmor() << std::endl;
		
		int hitPoint = attack - (defense + defender -> getArmor());
		
		if(hitPoint < 0) //no negative hitPoints
		{
			hitPoint = 0;
		}
		
		std::cout << "Attack damage applied to " << defender -> getName() << " is " << hitPoint << std::endl;
		std::cout << defender -> getName() << "'s strength before the attack is " << defender -> getStrength()
			  << std::endl;
				  
		defender -> setStrength(hitPoint);

		std::cout << defender -> getName() << "'s strength after the attack is " << defender -> getStrength()
			  << std::endl;
				  
		if(defender -> getStrength() > 0)
		{				
			std::swap(attacker, defender); //change attacker to defender and defender to attacker
		}	
		
	} while(team1 -> getFront() -> getStrength() > 0 && team2 -> getFront() -> getStrength() > 0);
	
	//display the winner
	std::cout << "\n\nAfter " << count << " grueling battles " << attacker -> getType() << ": " << attacker -> getName()  
		  << " won the battle against " << defender -> getType() << ": " << defender -> getName() << ".\n"
		  << attacker -> getName() << "'s strength after the battle was "
		  << attacker -> getStrength() << ". \nAnd " << defender -> getName()
		  << "'s strength was " << defender -> getStrength() << std::endl;
	
	Creature* loser = defender;
	
	attacker -> restoreStrength();
	
	loserPile -> addTop(loser);
	
	if(attacker == team1 -> getFront()) //if team1 wins battle
	{
		team2 -> removeFront();
		team1 -> moveFront();
		team1Score ++;
	}
	
	else //if team2 wins battle
	{
		team1 -> removeFront();
		team2 -> moveFront();
		team2Score ++;
	}
}
