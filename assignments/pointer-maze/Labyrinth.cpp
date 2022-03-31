#include "Labyrinth.h"
#include <iostream>

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
	//Potion, Spell, Wand counts
   int itemsFound [3] = {0, 0, 0};
   Item item = start->whatsHere;
   
   //Check item at starting position
   if (item == Item::SPELLBOOK) itemsFound[1] += 1;
   if (item == Item::POTION) itemsFound[0] += 1;
   if (item == Item::WAND) itemsFound[2] += 1;
   
   for (int i=0; i<moves.length(); i++){
   	char move = moves[i];
   	std::cout << "Current Move = " << move << std::endl;
   	if (move == 'N') start = start->north;
   	else if (move == 'S') start = start->south;
   	else if (move == 'E') start = start->east;
   	else if (move == 'W') start = start->west;
   	
		if (start == nullptr) return false;
		else{
			//We moved to a new cell, check for any item.
			item = start->whatsHere;
			if (item == Item::SPELLBOOK){	
				itemsFound[1] += 1;
				std::cout << "Found Spellbook" << std::endl;
			}
			if (item == Item::POTION){
				itemsFound[0] += 1;
				std::cout << "Found Potion" << std::endl;
			}
			if (item == Item::WAND) {
				itemsFound[2] += 1;
				std::cout << "Found Wand" << std::endl;
			}
		}
   }
   
   std::cout << "VALID PATH" << std::endl;
   for (int i=0; i<sizeof(itemsFound)/sizeof(itemsFound[0]); i++){
   	if (itemsFound[i] < 1) return false;
	}
	
	return true;
}
