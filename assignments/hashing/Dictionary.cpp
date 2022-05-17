#include <iostream>
#include "Dictionary.h"
#include "Node.h"
#include "Person.h"

Dictionary::Dictionary(){
	size = 10;
	for (int i=0; i<getSize(); i++){
		listDictionary[i] = new LinkedList();
	}
}

Dictionary::~Dictionary(){
	try{
		int size = getSize();
		for (int i=0; i<size; i++){
			LinkedList *l = listDictionary[i];
			Node* current = l->getHead();
			while (current != nullptr){
				Node* next = current->getNext();
				delete current;
				current = next;
			}
			
			l->setHead(nullptr);
		}
	}
	catch(...){
		std::cout << "Invalid array size in destructor." << std::endl;
	}
}

int Dictionary::getSize(){
	return size;
}

void Dictionary::insertPerson(Person *&p){
	//Linear Probing
	try{
		std::string fullName = p->get_first_name() + p->get_last_name();
		int hashValue = 0;
		for (auto i=0; i<fullName.length(); i++){
			hashValue += fullName[i];
		}

		//Begin insertion
		//int j = 0;
		int insertionIndex = (hashValue /*+ j*/) % getSize(); 
	/*
		while (listDictionary[insertionIndex] != nullptr){
			//Assume that we are only matching by first and last time
			std::string personName = listDictionary[insertionIndex]->getHead()->getData()->get_first_name() + listDictionary[insertionIndex]->getHead()->getData()->get_last_name();
			if (personName == (p->get_first_name() + p->get_last_name())){
				return;
			}
			else{
				j++;
				insertionIndex = (hashValue + j) % (getSize());
			}
		}
	*/
		std::cout << "Inserting... <<Insertion Complete>>:" << std::endl;
		std::cout << "Insertion Index: " << insertionIndex << std::endl;
		std::cout << "Person's full name: " << p->get_name() << std::endl;
		
		listDictionary[insertionIndex]->insertPerson(p);
	}
	catch(...){
		std::cout << "Error in insertion." << std::endl;
	}
	return;
}

Person* Dictionary::retrievePerson(Person *&p){
	try{
		std::string fullName = p->get_first_name() + p->get_last_name();
		int hashValue = 0;
		for (auto i=0; i<fullName.length(); i++){
			hashValue += fullName[i];
		}
		
		int insertionIndex = (hashValue) % getSize(); 
		Node *node = listDictionary[insertionIndex]->getHead();
		while (node != nullptr){
			std::string searchName = node->getData()->get_first_name() +  node->getData()->get_last_name();
			if (fullName == searchName) return node->getData();
			else node = node->getNext();
		}
	}
	catch(...){
		std::cout << "Error in retrieving Person." << std::endl;
	}
	
	throw std::invalid_argument( "null value" );
}

void Dictionary::runTests(){
	std::cout << "\nRunning Tests..." << std::endl;
	
	//Sine Entry at different index
	std::cout << "Value at Index 7: " << listDictionary[7]->getHead()->getData()->get_name() << std::endl;
	std::cout << "Value at Index 6: " << listDictionary[6]->getHead()->getData()->get_name() << std::endl;
	std::cout << "Value at Index 2: " << listDictionary[7]->getHead()->getData()->get_name() << std::endl;
	
	//Multiple Entries at same index
	std::cout << "Value at Index 8: " << listDictionary[8]->getHead()->getData()->get_name() << std::endl;
	std::cout << "Second Value at Index 8: " << listDictionary[8]->getHead()->getNext()->getData()->get_name() << std::endl;
	std::cout << "\n";
	
	return;
}

std::string Dictionary::getKeys(){
	std::string keys = "\n";
	try{
		int size = getSize();
		for (auto i=0; i<size; i++){
			LinkedList *l = listDictionary[i];
			Node* current = l->getHead();
			//Note that the actual keys do not have a space nor comma between first and last name, this is only for display.
			while (current != nullptr){
				keys = keys + current->getData()->get_name() + "\n";
				current = current->getNext();
			}
		}
	}
	catch(...){
		std::cout << "Invalid attempt to retrieve keys." << std::endl;
	}
	
	return keys;
}
