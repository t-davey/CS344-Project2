#ifndef MAPITR_H
#define MAPITR_H

#include <utility>
#include "tree.cpp"

template <class Key, class Element>
class MapItr {

private:
  Node<Key,Element>* next(Node<Key,Element>* node);

public:
  MapItr();
  MapItr(Node<Key,Element>* n);
  std::pair<Key,Element> & operator*();
  MapItr<Key,Element> operator++(int);
  Node<Key,Element>* min(Node<Key,Element>* node);
  bool operator==(MapItr<Key,Element> itr);
  bool operator!=(MapItr<Key,Element> itr);
  Node<Key,Element>* node;
};

template <class Key, class Element>
inline std::pair<Key,Element> & MapItr<Key,Element>::operator*() {
 return node->key;
}

template <class Key, class Element>
MapItr<Key,Element> MapItr<Key,Element>::operator++(int) {
  node = next(node);
  return node;
}
#endif
