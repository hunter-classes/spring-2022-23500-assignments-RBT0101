#pragma once
#include "Node.h"

class List{
	private:
	Node *head;

	public:
	List();
	~List();
	void insert(int data);
	void insert(int loc, int data);
	void remove(int loc);
	
	int length();
	
	int get(int loc);
	std::string toString();
};

class OList{
	private:
	Node *head;

	public:
	OList();
	~OList();
	void insert(int data);
	void remove(int loc);
	void reverse();
	
	bool contains(int value);
	int get(int loc);
	int length();
	
	std::string toString();
};

