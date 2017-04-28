#include <iostream>
#include <cstdlib>
#include "tree.cpp"

using std::string;
using std::pair;

int main(int argc, char **argv) {
  Tree<int,string> tree;
  int input;

  tree.FindNode(1);

  tree.isEmpty();
  std::cerr << "The tree has " << tree.size() << " nodes.\n";

  pair<int, string> p0(5,"5");
  pair<int, string> p1(55,"5");

  tree.AddLeaf(p0);
  std::cerr << "The tree has " << tree.size() << " nodes.\n";

  tree.AddLeaf(p1);
  std::cerr << "The tree has " << tree.size() << " nodes.\n";

  tree.PrintInOrder();
  std::cerr << '\n';


  tree.AddLeaf(p1);

  std::cerr << "The tree has " << tree.size() << " nodes.\n";

  tree.PrintInOrder();
  std::cerr << '\n';

  tree.FindNode(5);

  tree.ReplaceSubtree(5, 55);

  tree.RemoveNode(55);

  tree.getNode(5);

  tree.size();

  tree.ClearTree();


  return 0;
}
