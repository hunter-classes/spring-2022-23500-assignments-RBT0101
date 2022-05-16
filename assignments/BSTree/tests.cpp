#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Node.h"
#include "BSTree.h"

TEST_CASE("Testing BSTree Methods"){
	BSTree *tree = new BSTree();
  /*
  		Structure:
  									10 (root node value set in BSTree.cpp)
  								8			20
  							7      15  		25
  						6			14	        30
  													 28
  */
  
  //Initialization
  std::cout << "Initialized 10 nodes for the BST: [10, 8, 20, 7, 15, 25, 6, 14, 30, 28]" << std::endl;
  tree->setup(); //Initializes root node to the value of 10
  tree->insertr(8);
  tree->insertr(7);
  tree->insertr(6);
  tree->insertr(20);
  tree->insertr(15);
  tree->insertr(25);
  tree->insertr(30);
  tree->insertr(28);
  tree->insertr(14);
  
  //Check Level Sum 
  CHECK(tree->countSum(0) == 10);
  CHECK(tree->countSum(1) == 28);
  CHECK(tree->countSum(2) == 47);
  CHECK(tree->countSum(3) == 50);
  CHECK(tree->countSum(4) == 28);
  CHECK(tree->countSum(100) == 0);
  
  //Check Height (Default Value: 1)
  CHECK(tree->countHeight() == 5);
  
  //Search for valid inputs
  CHECK(tree->searchr(8) == 8);
  CHECK(tree->searchr(14) == 14);
  CHECK(tree->searchr(15) == 15);
  CHECK(tree->searchr(1000) == -1);
  
  //Count Leaf Nodes + Above Methods
  CHECK(tree->countLeaves() == 3);
  tree->remove(28);
  CHECK(tree->countHeight() == 4);
  tree->remove(14);
  tree->remove(25);
  CHECK(tree->countLeaves() == 3);
  CHECK(tree->countLeaves() == 3);
}
