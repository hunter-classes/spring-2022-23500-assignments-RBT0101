#pragma once
#include <iostream>
#include "Node.h"
#include "Person.h"
#include "Linked_List.h"

class Dictionary{
	private:
		LinkedList* listDictionary[10];
		int size;
	public:
		Dictionary();
		~Dictionary();
		void insertPerson(Person *&p);
		void runTests();
		int getSize();
		Person* retrievePerson(Person *&p);
		std::string getKeys();
};
