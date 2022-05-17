#pragma once
#include "Node.h"
#include "Person.h"

class LinkedList{
	private:
		Node* head;
	public:
		LinkedList();
		~LinkedList();
		Node* getHead();
		void setHead(Node* head);
		void insertPerson(Person *p);
};
