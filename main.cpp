#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tree.cpp"

using std::string;
using std::pair;

int main(int argc, char **argv) {
  Tree<int, int> tree;
  srand(time(NULL));

  tree.FindNode(1);

  tree.isEmpty();
  std::cerr << "The tree has " << tree.size() << " nodes.\n";

  int a[10];
  for (int i = 0; i < 10; i++) {
    a[i] = rand() % 100;
  }

  for (int i = 0; i < 10; i++) {
    std::cerr << a[i] << '\n';
  }

  for (int i = 0; i < 10; i++) {
    tree.AddLeaf(pair<int, int>(a[i], i));
  }

  for (int i = 0; i < 10; i++) {
    tree.NodeDebug(a[i]);
  }

  return 0;
}
