#include "Linked_List.h"
#include "Node.h"
#include "Person.h"

LinkedList::LinkedList(){
	head = nullptr;
}

LinkedList::~LinkedList(){
	delete this;
}

void LinkedList::setHead(Node* head){
	this->head = head;
}

void LinkedList::insertPerson(Person *p){
	Node *newNode = new Node(p);
	if (head == nullptr){
		head = newNode;
		return;
	}

	Node *current = head;
	while (current->getNext() != nullptr){
		current = current->getNext();
	}
	current->setNext(newNode);
}

Node* LinkedList::getHead(){
	return head;
}
