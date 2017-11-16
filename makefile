
# Author: Kyle Wollman
# Date: 3/05/2017
# Project 4 makefile
  
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS +=  -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
OBJS = $(SRCS:.cpp=.o)
SRCS = creature.cpp vampire.cpp barbarian.cpp blueMen.cpp medusa.cpp harryPotter.cpp die.cpp stack.cpp queue.cpp combatMenu.cpp project4Main.cpp 
HEADERS = creature.hpp vampire.hpp barbarian.hpp blueMen.hpp medusa.hpp harryPotter.hpp die.hpp verify.hpp stack.hpp queue.hpp combatMenu.hpp 

all : $(OBJS)
	$(CXX) $(OBJS)  -o battle 

$(OBJS) : $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $(SRCS)
	
clean: 
	rm -f *.o battle 
