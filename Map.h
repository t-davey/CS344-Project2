#ifndef MAP_H
#define MAP_H

#include "tree.cpp"
#include "MapItr.cpp"
#include <string>
#include <utility>

template <class Key, class Element>
class Map {

private:
  Tree<Key, Element> tree;

public:
  Map();
  Map(const Map & m); //unfinished
  ~Map();

  Element operator[](Key k);

  int size();
  void clear();
  bool empty();
  void swap(); //unfinished
  void insert(std::pair<Key,Element> pair);
  MapItr<Key,Element> begin();
  MapItr<Key,Element> end(); //unfinished
  MapItr<Key,Element> find(Key k);
  void erase(Key k);
  //void erase(itr i); //unfinished
  void printTree(Key k); //TESTING PRINT
  void printTree();
};

#endif
