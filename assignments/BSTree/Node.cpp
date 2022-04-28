#include "Node.h"

Node::Node(){
	data = 0;
	left = nullptr;
	right = nullptr;
}

Node::Node(int data){
	this->data = data;
	left = nullptr;
	right = nullptr;
}

Node::Node(int data, Node *left, Node *right){
	this->data = data;
	this->left = left;
	this->right = right;
}	

int Node::getData(){
	return data;
}	

Node *Node::getLeft(){
	return left;
}

Node *Node::getRight(){
	return right;
}

void Node::setData(int d){
	data = d;
}

void Node::setLeft(Node *l){
	left = l;
}

void Node::setRight(Node *r){
	right = r;
}
