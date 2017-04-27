#include <iostream>
#include <cstdlib>
#include "tree.cpp"

int main(int argc, char **argv) {
  int treeKeys[16] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};
  Tree tree;
  int input;

  tree.isEmpty();

  std::cout << "Printing the tree in order.\nBefore adding numbers.\n";

  tree.PrintInOrder();

  for (int i = 0; i < 16; i++) {
    tree.AddLeaf(treeKeys[i]);
  }

  tree.isEmpty();

  std::cout << "Printing the tree in order.\nAfter adding numbers.\n";

  tree.PrintInOrder();

  std::cout << std::endl;

  //print each node's children debug
  for (int i = 0; i < 16; i++) {
    tree.PrintChildren(treeKeys[i]);
    std::cout << std::endl;
  }

  std::cout << "The smallest value ion the tree is "
            << tree.FindSmallest() << std::endl;

  tree.FindNode(1);
  tree.FindNode(52);
  std:: cout << "The tree has " << tree.size()
             << " nodes." <<std::endl;
  //tree.ClearTree();

  tree.RemoveNode(50);
  //tree.ReplaceSubtree(76, 64);

  for (int i = 0; i < 16; i++) {
    tree.PrintChildren(treeKeys[i]);
    std::cout << std::endl;
  }

  //tree.PrintInOrder();


  /*
  //delete nodes test
  while (input != -1) {
    std::cout << "Delete node: ";
    std::cin  >> input;
    {
      if (input != -1) {
        std::cout << std::endl;
        tree.RemoveNode(input);
        tree.PrintInOrder();
        std::cout << std::endl;
      }
    }
  }
  */

  return 0;
}
