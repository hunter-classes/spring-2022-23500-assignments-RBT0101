#include "Node.h"

Node::Node() {
  data = 0;
  left = nullptr;
  right = nullptr;
}

Node::Node(int data){
  this->data = data;
  left = nullptr;
  right = nullptr;
}

Node::Node(int data, Node *l, Node *r){
  this->data = data;
  left = l;
  right = r;
}

int Node::getData(){
  return data;
}

Node * Node::getLeft(){
  return left;
}

Node * Node::getRight(){
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


//Source: http://www.algolist.net/Data_structures/Binary_search_tree/Removal
Node* Node::remove(int value, Node *parent) {
      if (value < this->data) {
            if (left != nullptr)
                  return left->remove(value, this);
            else
                  return nullptr;
      } else if (value > this->data) {
            if (right != nullptr)
                  return right->remove(value, this);
            else
                  return nullptr;
      } else {
            if (left != nullptr && right != nullptr) {
                  this->data = right->minValue();
                  return right->remove(this->data, this);
            } else if (parent->left == this) {
                  parent->left = (left != nullptr) ? left : right;
                  return this;
            } else{
                  parent->right = (left != nullptr) ? left : right;
                  return this;
            }
      }
} 

int Node::minValue() {
      if (left == nullptr)
            return false;
      else
            return left->minValue();
}

