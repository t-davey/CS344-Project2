#include "MapItr.h"


template <class Key, class Element>
MapItr<Key,Element>::MapItr(){
//  node = nullptr;
}

template <class Key, class Element>
MapItr<Key,Element>::MapItr(Node<Key,Element>* n){
  node = n;
}

template <class Key, class Element>
bool MapItr<Key,Element>::operator==(MapItr<Key,Element> itr){
  return node->key.first == (*itr).first;
}

template <class Key, class Element>
bool MapItr<Key,Element>::operator!=(MapItr<Key,Element> itr){
  return !(node->key.first == (*itr).first);
}

template <class Key, class Element>
Node<Key,Element>* MapItr<Key,Element>::next(Node<Key,Element>* node){
  if (node->right != nullptr){
    return min(node->right);
  } else {
    Node<Key,Element>* parent = node->parent;
    Node<Key,Element>* n = node;
    while(parent != nullptr && parent->right == n){
      n = parent;
      parent = parent->parent;
    }
    return parent;
  }
}


template <class Key, class Element>
Node<Key,Element>* MapItr<Key,Element>::min(Node<Key,Element>* node) {
    while (node->left != nullptr) {
      node = node->left;
    }
    return node;
}

//template <class Key, class Element>
//std::pair<Key,Element> MapItr<Key,Element>::operator*(){
  //return this.getKey();
//}


// template <class Key, class Element>
// bool MapItr<Key,Element>::operator==(MapItr<Key,Element> itr){
//   if ((this->left == itr->left) && (this->right == itr->right)){
//     return true;
//   } else {
//     return false;
//   }
// }
//
// template <class Key, class Element>
// bool MapItr<Key,Element>::operator!=(MapItr<Key,Element> itr){
//   return (!(this==itr));
// }
