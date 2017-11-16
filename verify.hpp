/******************************************************************************************
** Program name: verify.hpp
** Author: Kyle Wollman
** Date: 03/05/2017
** Description: Verify recieves a variable by reference and confirms that it is the right 
**				type of input that the calling function is asking for. It uses a template
**				in order to receive mutliple types of data to verify.
*******************************************************************************************/

#ifndef VERIFY_HPP
#define VERIFY_HPP
#include <iostream>

template <class input>
inline void verify(input* i)
{
	while(std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Invalid input. Please reenter: " << std::endl;
		std::cin >> *i;	
	}
}

#endif