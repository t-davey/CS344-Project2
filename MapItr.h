#ifndef MAPITR_H
#define MAPITR_H

#include <utility>
#include "Tree.cpp"

template <class Key, class Element>
class MapItr {

private:
  struct Node {
    std::pair<Key, Element> key;
    Node* parent;
    Node* left;
    Node* right;
  };

  typedef Node* NodePtr;
  Node* node;

  MapItr<Key,Element> operator++(int i);
  std::pair<Key,Element> operator*();
  //friend bool operator==(MapItr<Key,Element> itr);
  //friend bool operator!=(MapItr<Key,Element> itr);

public:
  MapItr();
  MapItr(NodePtr& n);


};

#endif
