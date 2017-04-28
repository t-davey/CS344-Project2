#include <iostream>
#include <cstdlib>
#include "tree.h"

template <class Key, class Element>
Tree<Key, Element>::Tree() {
  root = nullptr;
}

template <class Key, class Element>
Tree<Key, Element>::~Tree() {
  RemoveSubtree(root);
}

template <class Key, class Element>
typename Tree<Key, Element>::Node* Tree<Key, Element>::CreateLeaf(std::pair<Key, Element> key) {
  Node* node   = new Node;
  node->key    = key;
  node->parent = nullptr;
  node->left   = nullptr;
  node->right  = nullptr;

  return node;
}

/* returns a node object from a given key */
template <class Key, class Element>
typename Tree<Key, Element>::Node* Tree<Key, Element>::getNode(Key key) {
  getNodeHelper(key, root);
}

template <class Key, class Element>
typename Tree<Key, Element>::Node* Tree<Key, Element>::getNodeHelper(Key key, Node* node) {
  if (node != nullptr) {
    while (node != nullptr && node->key.first != key) {
      if (key < node->key.first) {
        node = node->left;
      }
      else {
        node = node->right;
      }
    }
    //avoid segfaults
    if (node != nullptr) {
      std::cerr << node->key.first << " was found." << std::endl;
      return node;
    }
    else {
      std::cerr << key << " was not found." << std::endl;
      return nullptr;
    }
  }
  else {
    std::cerr << "The tree is empty." << std::endl;
    return nullptr;
  }
}

template <class Key, class Element>
void Tree<Key, Element>::AddLeaf(std::pair<Key, Element> key) {
  AddLeafHelper(key, root);
}

//key is z
//node was root
/* insert, from notes */
template <class Key, class Element>
void Tree<Key, Element>::AddLeafHelper(std::pair<Key, Element> key, Node* node) {
  if (root == nullptr) {
    root = CreateLeaf(key);
  }
  else {
      bool done = false;
      Node* q = node;

      while(!done) {
        if (key.first < q->key.first) {
          if (q->left == nullptr) {
            q->left = CreateLeaf(key);
            q->left->parent = q; //z->parent = q in psuedocode
            std::cerr << q->key.first << " is " << q->left->key.first << "'s parent" << '\n';
            //std::cerr << q->left->key.first << " is " << q->key.first << "'s parent" << '\n';
            done = true;
          }
          else {
            q = q->left;
          }
        }
        else {
          if (q->right == nullptr) {
            q->right = CreateLeaf(key);
            q->right->parent = q;
            std::cerr << q->key.first << " is " << q->right->key.first << "'s parent" << '\n';
            done = true;
          }
          else {
            q = q->right;
        }
      }
    }
  }
}

template <class Key, class Element>
void Tree<Key,Element>::PrintInOrder() {
  PrintInOrderHelper(root);
}

/* from video */
template <class Key, class Element>
void Tree<Key,Element>::PrintInOrderHelper(Node* node) {
  if (root != nullptr) {
    if (node->left != nullptr) {
      PrintInOrderHelper(node->left);
    }
    std::cerr << node->key.first << " ";
    if (node->right != nullptr) {
      PrintInOrderHelper(node->right);
    }
  }
  else {
    std::cerr << "The tree is empty.\n";
  }
}

template <class Key, class Element>
typename Tree<Key,Element>::Node* Tree<Key,Element>::ReturnNode(Key key) {
  return ReturnNodeHelper(key, root);
}

/* from notes */
template <class Key, class Element>
typename Tree<Key,Element>::Node* Tree<Key,Element>::ReturnNodeHelper(Key key, Node* node) {
  if (node != nullptr) {
    if (node->key.first == key) {
      return node;
    }
    else {
      if (key < node->key.first) {
        return ReturnNodeHelper(key, node->left);
      }
      else {
        return ReturnNodeHelper(key, node->right);
      }
    }
  }
  else {
    return nullptr;
  }
}

template <class Key, class Element>
void Tree<Key, Element>::NodeDebug(Key key) {
  Node* node = getNode(key);

  NodeDebugHelper(key, node);
}

template <class Key, class Element>
void Tree<Key, Element>::NodeDebugHelper(Key key, Node* node) {
  if (node->parent != nullptr) {
    std::cerr << "Parent: " << node->parent->key.first << '\n';
  }
  else {
    std::cerr << "Parent: nullptr" << '\n';
  }

  if (node != nullptr) {
    std::cerr << "Current: " << node->key.first << '\n';
  }
  else {
    std::cerr << "Current: nullptr" << '\n';
  }

  if (node->left != nullptr) {
    std::cerr << "Left: " << node->left->key.first << '\n';
  }
  else {
    std::cerr << "Left: nullptr" << '\n';
  }

  if (node->right != nullptr) {
    std::cerr << "Right: " << node->right->key.first << '\n';
  }
  else {
    std::cerr << "Right: nullptr" << '\n';
  }
  std::cerr << '\n';
}

/*
template <class Key, class Element>
Key Tree<Key,Element>::FindSmallest() {
  return FindSmallestHelper(root);
}
*/

/* from video, same as notes */
/*
template <class Key, class Element>
Key Tree<Key,Element>::FindSmallestHelper(Node* node) {
  if (root == nullptr) {
    std::cerr << "The tree is empty.\n";

    return -1000; //might need to be changed
  }
  else {
    if (node->left != nullptr) {
      return FindSmallestHelper(node->left);
    }
    else {
      return node->key.first;
    }
  }
}
*/

/* from notes */
template <class Key, class Element>
typename Tree<Key,Element>::Node* Tree<Key,Element>::min(Node* node) {
  if (root == nullptr) {
    std::cerr << "The tree is empty.\n";

    return nullptr;
  }
  else {
    while (node->left != nullptr) {
      node = node->left;
    }
    return node;
  }
}


template <class Key, class Element>
void Tree<Key,Element>::RemoveNode(Key key) {

  NodePtr node = getNode(key);

  RemoveNodeHelper(node, root);
}

/* from notes */
template <class Key, class Element>
void Tree<Key,Element>::RemoveNodeHelper(NodePtr& key, NodePtr& node) {
  std::cerr << "Deleting " << key->key.first << std::endl;

  if (key->left == nullptr) {
    ReplaceSubtreeHelper(key, key->right, node);
  }
  else if (key->right == nullptr) {
    ReplaceSubtreeHelper(key, key->left, node);
  }
  else {
    Node* y = min(key->right);

    if (y != key->right) {
      ReplaceSubtreeHelper(y, y->right, node);
      y->right = key->right;
      y->right->parent = y;
    }
    ReplaceSubtreeHelper(key, y, node);
    y->left = key->left;
    y->left->parent = y;
  }
  key->left = key->right = nullptr;
}

template <class Key, class Element>
void Tree<Key,Element>::ReplaceSubtree(Key u, Key v) {
  NodePtr a = getNode(u);
  NodePtr b = getNode(v);

  ReplaceSubtreeHelper(a, b, root);
}

//warning look over after sleep
/* from notes */
template <class Key, class Element>
void  Tree<Key,Element>::ReplaceSubtreeHelper(NodePtr& u, NodePtr& v, NodePtr& node) {
  if (u->key.first == node->key.first) {
    node = v;
    if (v != nullptr) {
      v->parent = nullptr;
    }
  }
  else {
    Node* q = u->parent;
    if (u->key.first == q->left->key.first) {
      q->left = v;
    }
    else {
      q->right = v;
    }
    if (v != nullptr) {
      v->parent = q;
    }
    u->parent = nullptr;
  }
}

/* modified from the video to work with ClearTree() and ~Tree */
template <class Key, class Element>
void Tree<Key,Element>::RemoveSubtree(NodePtr& node) {
  if (node != nullptr) {
    RemoveSubtree(node->left);
    RemoveSubtree(node->right);

    std::cerr << "Deleting the node containing key " << node->key.first << std::endl;
    delete node;
    node = nullptr;
  }
}

template <class Key, class Element>
Key Tree<Key,Element>::FindNode(Key key) {
  return FindNodeHelper(key, root);
}

/* from notes */
template <class Key, class Element>
Key Tree<Key,Element>::FindNodeHelper(Key key, Node* node) {
  if (node != nullptr) {
    while (node != nullptr && node->key.first != key) {
      if (key < node->key.first) {
        node = node->left;
      }
      else {
        node = node->right;
      }
    }
    //avoid segfaults
    if (node != nullptr) {
      std::cerr << node->key.first << " was found." << std::endl;
      return node->key.first;
    }
    else {
      std::cerr << key << " was not found." << std::endl;
      return -1000; //might need to be changed
    }
  }
  else {
    std::cerr << "The tree is empty." << std::endl;
    return -1000; //might need to be changed
  }
}

template <class Key, class Element>
void Tree<Key,Element>::ClearTree() {
  RemoveSubtree(root);
}

template <class Key, class Element>
int Tree<Key,Element>::size() {
  return sizeHelper(root);
}

template <class Key, class Element>
int Tree<Key,Element>::sizeHelper(Node *node) {
    if (node != nullptr) {
      return (sizeHelper(node->left) + 1 + sizeHelper(node->right));
    }
    else {
      return 0;
    }
}

template <class Key, class Element>
bool Tree<Key,Element>::isEmpty() {
  if (root == nullptr) {
    std::cerr << "The tree is empty." << std::endl;
    return true;
  }
  else {
    std::cerr << "The tree is not empty." << std::endl;
    return false;
  }
}
