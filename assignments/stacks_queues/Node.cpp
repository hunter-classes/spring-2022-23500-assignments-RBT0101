#include "Node.h"

Node:: Node(){
	data = 0;
	next = nullptr;
}

Node:: Node(int data){
	this->data = data;
	next = nullptr;
}

Node:: Node(int data, Node *next){
	this->data = data;
	this->next = next;
}
		
int Node::getData(){
	return data;
}

Node* Node::getNext(){
	return next;
}
		
void Node:: setData(int data){
	this->data = data;
}

void Node::setNext(Node* next){
	this->next = next;
}
