#pragma once
#include "Node.h"

class Stack{
	private:
	Node *head;
	int size;
	
	public:
	Stack();
	~Stack();
	void push(int data); //pushes new node to top
	void setSize(int newSize);
	int pop(); //remove and return top item
	int top(); //return but do not remove the top item
	int getSize();
	bool is_empty(); //return true if empty, false otherwise
	std::string to_string();
};
