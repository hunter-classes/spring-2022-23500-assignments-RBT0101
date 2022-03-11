#include <iostream>
#include <stdexcept>
#include "List.h"

List::List() {
  head = nullptr;
}


List::~List(){
  Node *trailer;
  std::cerr << "Destructing\n";
  while(head != nullptr){
    trailer = head;
    head = head->getNext();
    delete trailer;
  }
}

void List::insert(int data){
  Node *tmp = new Node(data);
  tmp->setNext(head);
  this->head = tmp;
}

//
// We need a pointer BEFORE
// the insertion point
//
// We use piggybacking
// That is, send a pointer one behind that
// trails the walker.
// When walker points to Node n,
// the trailer points to Node n-1
//
void List::insert(int loc, int data){
  Node *tmp = new Node(data);

  Node *walker = head;
  Node *trailer=nullptr; // this one follows behind walker;
  
  while (walker != nullptr && loc > 0){
    trailer = walker;
    walker = walker->getNext();
    loc = loc - 1;
  }
  // walker is at n, trailer is at the point before the insertion
  // point

  // check to see if we're trying to insert beyond the end
  // Note: we can insert a new last element.

  if (loc > 0){
    throw std::out_of_range("Out of range");
  }

  // inserting at location 0 will have trailer = nullptr
  // so we have to deal with that special case
  if (trailer==nullptr){
    tmp->setNext(head);
    head=tmp;
  } else {
    // and finally the normal insert code
    tmp->setNext(walker);
    trailer->setNext(tmp);
  
  }
}

void List::remove(int loc){

  Node *walker = head;
  Node *trailer=nullptr; // this one follows behind walker;

  while (walker != nullptr && loc > 0){
    trailer = walker;
    walker = walker->getNext();
    loc = loc - 1;
  }

  
  // walker is at n, trailer is at the point before the insertion
  // point

  // check to see if we're trying to delete beyond the end
  // Note: we can insert a new last element.

  if (walker == nullptr){
    throw std::out_of_range("Out of range");
  }

  // delete location 0 will have trailer = nullptr
  // so we have to deal with that special case
  if (trailer==nullptr){
    head = walker->getNext();
    delete walker;
  } else {
    // and finally the normal delete code
    trailer->setNext(walker->getNext());
    delete walker;
  }
}

int List::get(int loc){
  Node *walker = head;

  // using walker as a boolean is
  // the same as writing walker != nullptr
  while (walker && loc > 0){
    walker = walker->getNext();
    loc--;
  }
  if (walker)
    return walker->getData();
  else
    return 0;
    
    
}

int List::length(){
  int l = 0;
  Node *walker = head;
  while (walker){
    l++;
    walker = walker->getNext();
  }
  return l;
}


std::string List::toString(){
  std::string result = "";
  Node *walker = this->head;
  while (walker != nullptr){
    result = result + std::to_string(walker->getData()) + "->";
    walker = walker->getNext();
  }
  result = result + "null";
  return result;
}


OList::OList() {
  head = nullptr;
}


OList::~OList(){
  Node *prev = nullptr;
  
  while (head != nullptr){
  		prev = head;
  		head = head->getNext();
  		delete prev;
	}
}

void OList::insert(int value){
	Node *newNode = new Node(value);
	
	//Length is 0, simply push new node to head.
	if (head == nullptr){
		head = newNode;
		newNode->setNext(nullptr);
	}
	else{
		Node *prevNode = nullptr;
		Node *curNode = head;
		
		while (curNode != nullptr && newNode->getData() > curNode->getData()){
			prevNode = curNode;
			curNode = curNode->getNext();
		}
		
		if (prevNode == nullptr){
			//Location 0 
			newNode->setNext(head);
			head = newNode;
		}
		else{
			//All other locations
			prevNode->setNext(newNode);
			newNode->setNext(curNode);
		}
	}
}

std::string OList::toString(){
  std::string result = "";
  Node *walker = this->head;
  while (walker != nullptr){
    result = result + std::to_string(walker->getData()) + "->";
    walker = walker->getNext();
  }
  result = result + "null";
  return result;
}

void OList::remove(int loc){
	if (loc < 0) return;
	
	Node* prev = nullptr;
	Node* cur = head;
	
	while (cur && loc > 0){
		prev = cur;
		cur = cur->getNext();
		loc--;
	}
	
	//Remove first element (location 0)
	if (prev == nullptr && head){
		head = cur->getNext();
		delete cur;
	}
	else if (cur){
		prev->setNext(cur->getNext());
		delete cur;
	}
}

void OList::reverse(){
	int l = OList::length();
	if (l == 1) return;
	Node *cur = head;
	Node *prev = nullptr;
	Node *next = head;
	if (l == 2){
		next = cur->getNext();
		next->setNext(cur);
		
		head = next;
		cur->setNext(nullptr);
	}
	else{
		while (cur){
			next = next->getNext();
			cur->setNext(prev);
			prev = cur;
			cur = next;
		}
		
		head = prev;
	}
	
}
	
bool OList::contains(int value){
	Node *curr = head;
	while (curr){
		if (curr->getData() == value) return true;
		else curr = curr->getNext();
	}
	
	return false;
}

int OList::get(int loc){
	Node *curNode = head;
	while (curNode && loc > 0){
		curNode = curNode->getNext();
		loc--;
	}
	
	if (curNode == nullptr) return -1;
	return curNode->getData();
}

int OList::length(){
  int l = 0;
  Node *walker = head;
  while (walker){
    l++;
    walker = walker->getNext();
  }
  return l;
}

