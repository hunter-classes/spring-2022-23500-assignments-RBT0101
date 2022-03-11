#include <iostream>
#include "List.h"

int main(int args, char*argv[])
{
	OList *list = new OList();
	
	std::cout << "Inserting numbers: 1, 0, 3, 2 to the list, sorted in ascending order" << std::endl;
	list->insert(1);	//Insert first element
	list->insert(0);//Insert at location 0
	list->insert(3);//Insert after last element
	list->insert(2);//Insert between 1 and 3
	std::cout << list->toString() << std::endl;
	std::cout << "\n";
	
	//All should return true
	std::cout << "Checking if numbers 1, 0, 3, 2 are all contained within the list" << std::endl;
	std::cout << list->contains(1) << std::endl;
	std::cout << list->contains(0) << std::endl;
	std::cout << list->contains(3) << std::endl;
	std::cout << list->contains(2) << std::endl;
	std::cout << "\n";
	
	//All should return false
	std::cout << "Checking if numbers -1, 5, and 3000 are all contained within the list" << std::endl;
	std::cout << list->contains(-1) << std::endl;	
	std::cout << list->contains(5) << std::endl;
	std::cout << list->contains(3000) << std::endl;
	std::cout << "\n";
	
	
	//Get values at each location
	std::cout << "Get the values at position 0, 1, 2, 3, and 4 (null). -1 if the value is not in the list" << std::endl;
	std::cout << list->get(0) << std::endl;
	std::cout << list->get(1) << std::endl;
	std::cout << list->get(2) << std::endl;
	std::cout << list->get(3) << std::endl;
	std::cout << list->get(4) << std::endl;
	std::cout << "\n";
	
	//Reverse list
	std::cout << "Reversing list" << std::endl;
	list->reverse();
	std::cout << list->toString() << std::endl;
	std::cout << "\n";
	
	std::cout << "Reversing list again (back to original)" << std::endl;
	list->reverse();
	std::cout << list->toString() << std::endl;
	std::cout << "\n";
	
	//Remove values
	std::cout << "Removing values at position: -4, 0, 2, and 1000." << std::endl;
	list->remove(-4);
	list->remove(0);
	list->remove(2);
	list->remove(1000);
	std::cout << list->toString() << std::endl;
	std::cout << "\n";
	

	
	return 0;
}	
