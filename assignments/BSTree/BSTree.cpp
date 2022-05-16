#include <iostream>
#include <vector>
#include "Node.h"
#include "BSTree.h"

BSTree::BSTree(){
  root = new Node(5);
}

void BSTree::setup(){
  /*
  		Structure:
  									10
  								8			20
  							7      15  		25
  						6			14	       30
  												  28
  */	
  root = new Node(10);
}

int BSTree::searchr(int value, Node *node){
	if (node != nullptr){
		int data = node->getData();
		if (data == value) return data;
		
		if (node->getLeft() != nullptr){
			int left = searchr(value, node->getLeft());
			if (left == value) return left;
		}
		
		if (node->getRight() != nullptr){
			int right = searchr(value, node->getRight());
			if (right == value) return right;
		}
	}
	
	return -1;
}

//returns the value if it is found, otherwise return -1
int BSTree::searchr(int value){
	int searchedData = searchr(value, root);
	if (searchedData == value) return searchedData;
	return -1;
}

void BSTree::insertr(int value, Node *node){
		int data = node->getData();
		Node *left = node->getLeft();
		Node *right = node->getRight();
		
		if (value <= data){
			if (left == nullptr){
				node->setLeft(new Node(value));
				return;
			}
			else{
				insertr(value, node->getLeft());
			}
		}
		else{
			if (right == nullptr){
				node->setRight(new Node(value));
				return;
			}
			else{
				insertr(value, node->getRight());
			}
		}
}

void BSTree::insertr(int value){
		if (root == nullptr){
			root = new Node(value);
			return;
		}
		else{
			insertr(value, root);
			return;
		}
}

int BSTree::countLeaves(){
	Node *node = root;
	int count = 0;
	
	if (node == nullptr) return 0;
	else{
		std::vector<Node*> bfs;
		bfs.push_back(node);
		
		while (bfs.size() != 0){
			Node *front = bfs.front();
			bfs.erase(bfs.begin());
			
			if ((front->getLeft() == nullptr) && (front->getRight() == nullptr)){
				count++;
			}
			
			if (front->getLeft() != nullptr){
				bfs.push_back(front->getLeft());
			}	
			if (front->getRight() != nullptr){
				bfs.push_back(front->getRight());
			}
		}
	}
	return count;
}

//Height Default: 1
void BSTree::countHeight(Node *node, int count, int& maxCount){
	if (node == nullptr){
		//nullptr does not contribute to the count
		if (count-1 > maxCount) maxCount = count-1;
	}
	else{
		countHeight(node->getLeft(), count+1, maxCount);
		countHeight(node->getRight(), count+1, maxCount);
	}
}

int BSTree::countHeight(){
	if (root == nullptr) return 1;
	else{
		int maxCount = 1;
		countHeight(root, 1, maxCount);
		
		return maxCount;
	}
}

int BSTree::countSum(Node *node, int level){
	if (node == nullptr) return 0;
	if (level == 0) return node->getData();
	else{
		return countSum(node->getLeft(), level-1) + countSum(node->getRight(), level-1);
	}
}

int BSTree::countSum(int level){
	if (root == nullptr) return 0;
	else{
		return countSum(root, level);
	}
}

//Source: http://www.algolist.net/Data_structures/Binary_search_tree/Removal
bool BSTree::remove(int value) {
      if (root == nullptr)
            return false;
      else {
            if (root->getData() == value) {
                  Node auxRoot(0);
                  auxRoot.setLeft(root);
                  Node* removedNode = root->remove(value, &auxRoot);
                  root = auxRoot.getLeft();
                  if (removedNode != nullptr) {
                        delete removedNode;
                        return true;
                  } else
                        return false;
            } else {
                  Node* removedNode = root->remove(value, nullptr);
                  if (removedNode != nullptr) {
                        delete removedNode;
                        return true;
                  } else
                        return false;
            }
      }
}

