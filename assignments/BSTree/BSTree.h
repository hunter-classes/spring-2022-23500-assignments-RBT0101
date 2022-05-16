#pragma once
#include <iostream>
#include <stdio.h>


class BSTree{
 private:
  Node *root;

public:
  BSTree();
  int searchr(int value);
  int searchr(int value, Node *node);
  int countLeaves();
  int countHeight();
  int countSum(int level);
  int countSum(Node *node, int level);
  
  void setup();
  void insertr(int value);
  void insertr(int value, Node *node);
  void countHeight(Node *node, int count, int& maxCount);
  bool remove(int value);
};
