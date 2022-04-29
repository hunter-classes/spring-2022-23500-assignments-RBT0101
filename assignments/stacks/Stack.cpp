#include <iostream>
#include <stdexcept>
#include "Stack.h"

Stack::Stack(){
	head = nullptr;
	size = 0;
}

Stack::~Stack(){
	Node *node = head;
	Node *tmp = node;
	
	while (node != nullptr){
		tmp = node->getNext();
		delete node;
		setSize(getSize() - 1);
		node = tmp;
	}
	
	head = nullptr;
}

//pushes new node to top
void Stack::push(int data){
	Node* newNode = new Node(data);
	if (getSize() > 0) newNode->setNext(head);	//Set the new Node's "next" to the top level node
	head = newNode; //Set top level Node to the new Node
	setSize(getSize() + 1); 	//Increase stack size by one
}

void Stack::setSize(int newSize){
	if (newSize >= 0) size = newSize;
}

//remove and return top item
int Stack::pop(){
	//Handle Exceptions 
	try{
		if (getSize() <= 0) throw new std::runtime_error("Pop() Failed! Cannot remove from an empty stack!");
	} catch(...){
		std::cout << "Pop() Failed! Cannot remove from an empty stack!" << "\n";
		return -1; 
	}
	
	Node *tmp = head;
	int val = tmp->getData();
	head = head->getNext();
	delete tmp;
		
	setSize(getSize() - 1);
	return val;
}

//return but do not remove top item
int Stack::top(){
	//Handle Exceptions 
	try{
		if (getSize() <= 0) throw new std::runtime_error("Top() Failed! Cannot retrieve data value from an empty stack!");
	} catch(...){
		std::cout << "Top() Failed! Cannot remove data value from an empty stack!" << "\n";
		return -1; 
	}
	return head->getData();
}

int Stack::getSize(){
	return size;
}

//return true if empty, false otherwise
bool Stack::is_empty(){
	return (size == 0);
}

std::string Stack::to_string(){
	std::string output = "";
	Node *node = head;
	while (node != nullptr){
		output = output + std::to_string(node->getData()) + " ";
		node = node->getNext();
	}
	
	output = output + "null";
	return output;
}
