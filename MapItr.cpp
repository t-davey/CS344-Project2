#include "MapItr.h"


template <class Key, class Element>
MapItr<Key,Element>::MapItr(){
  node = nullptr;
}

template <class Key, class Element>
MapItr<Key,Element>::MapItr(NodePtr& n){
  node = n;
}


template <class Key, class Element>
std::pair<Key,Element> MapItr<Key,Element>::operator*(){
  return node->key;
}

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
