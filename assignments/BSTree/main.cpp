#include <iostream>
#include "Node.h"
#include "BSTree.h"
int main()
{

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

  //Level Sum
  std::cout << "Calculating sum at level 0/1/2/3/4/100 of the tree respectively below" << std::endl;
  std::cout << "Level 0 Sum: " << tree->countSum(0) << std::endl;
  std::cout << "Level 1 Sum: " << tree->countSum(1) << std::endl;
  std::cout << "Level 2 Sum: " << tree->countSum(2) << std::endl;
  std::cout << "Level 3 Sum: " << tree->countSum(3) << std::endl;
  std::cout << "Level 4 Sum: " << tree->countSum(4) << std::endl;
  std::cout << "Level 100 Sum: " << tree->countSum(100) << std::endl;
  std::cout << "\n";
  
  //Height (Default value: 1)
  std::cout << "Tree height (default value of 1): " << tree->countHeight() << std::endl;
  std::cout << "\n";
  
  //Search
  std::cout << "Attempting to find input: 8 (or -1 if it does not exist):" << tree->searchr(8) << std::endl;
  std::cout << "Attempting to find input: 14 (or -1 if it does not exist):" << tree->searchr(14) << std::endl;
  std::cout << "Attempting to find input: 15 (or -1 if it does not exist):" << tree->searchr(15) << std::endl;
  std::cout << "Attempting to find input: 1000 (or -1 if it does not exist):" << tree->searchr(1000) << std::endl;
  std::cout << "\n";
  
  //Count number of leaves and Deletion
  std::cout << "Current nunber of leaf nodes after removing node value 28: " << tree->countLeaves() << std::endl;
  tree->remove(28);
  std::cout << "Tree height (default value of 1): " << tree->countHeight() << std::endl;
  std::cout << "\n";
    
  std::cout << "Current nunber of leaf nodes after removing node value 14: " << tree->countLeaves() << std::endl;
  tree->remove(14);
  
  std::cout << "Current nunber of leaf nodes after removing node value 25: " << tree->countLeaves() << std::endl;
  tree->remove(25);
   std::cout << "\n";
  return 0;
}

