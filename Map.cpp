#include "Map.h"

//default constructor
template <class Key, class Element>
Map<Key,Element>::Map(){
  tree = Tree<Key,Element>();
}

//default destructor
template <class Key, class Element>
Map<Key,Element>::~Map(){
  clear();
}

//copy constructor
template <class Key, class Element>
Map<Key,Element>::Map(const Map & m){
  for (auto itr = m.begin(); itr != m.end(); itr++){
    tree.AddLeaf((*itr));
  }
}


//clears map's tree
template <class Key, class Element>
void Map<Key,Element>::clear() {
  tree.ClearTree();
  //need to set begin and end itr to null
}

//returns size of map's tree
template <class Key, class Element>
int Map<Key,Element>::size() {
  return tree.size();
}

//currently unimplemented map swap

/*
Map::swap(Map b) {
  final version should copy trees and itrs of "this" map to map b and the inverse
}
*/

//returns true if map's tree is empty
template <class Key, class Element>
bool Map<Key,Element>::empty() {
  return tree.isEmpty();
}

//returns the element that corresponds to given key
//inserting a node that doesn't exist in tree is unfinished
template <class Key, class Element>
Element Map<Key,Element>::operator[](Key k){
    if (tree.FindNode(k)){
      return tree.getNode(k)->key->second;
    } else {
      std::cout << "Node with key " << k << " was not found.\n" << "Insertion from [] operator"
        << " is currently unfinished." << std::endl;

    }

}

//inserts given pair into map's tree
template <class Key, class Element>
void Map<Key,Element>::insert(std::pair<Key,Element> pair) {
  tree.AddLeaf(pair);
}

//removes node with Key k from tree
template <class Key, class Element>
void Map<Key,Element>::erase(Key k) {
  tree.RemoveNode(k);
}

//removes node at itr i
template <class Key, class Element>
void Map<Key,Element>::erase(MapItr<Key,Element> i) {
  tree.RemoveNode(((*i).first));
}

//testing function to check map's tree's nodes are correct
template <class Key, class Element>
void Map<Key,Element>::printTree(Key k) {
  tree.NodeDebug(k);
}


template <class Key, class Element>
void Map<Key,Element>::printTree() {
  tree.PrintInOrder();
}

//returns an iterator pointing to the first node
template <class Key, class Element>
MapItr<Key,Element> Map<Key,Element>::begin() {
  Node<Key,Element>* min = tree.min(tree.getRoot());

  return MapItr<Key,Element>(min);
}

//returns an iterator pointing past the last node
template <class Key, class Element>
MapItr<Key,Element> Map<Key,Element>::end(){
  return MapItr<Key,Element>(nullptr);
}

//returns an iterator pointing to the found node, or end() if not found
template <class Key, class Element>
MapItr<Key,Element> Map<Key,Element>::find(Key k){

}
