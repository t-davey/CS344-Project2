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
typename Tree<Key, Element>::Node* Tree<Key, Element>::CreateLeaf(int key) {
  Node* node   = new Node;
  node->key    = key;
  node->parent = nullptr;
  node->left   = nullptr;
  node->right  = nullptr;

  return node;
}

/* returns a node object from a given key */
template <class Key, class Element>
typename Tree<Key, Element>::Node* Tree<Key, Element>::getNode(int key) {
  getNodeHelper(key, root);
}

template <class Key, class Element>
typename Tree<Key, Element>::Node* Tree<Key, Element>::getNodeHelper(int key, Node* node) {
  if (node != nullptr) {
    while (node != nullptr && node->key != key) {
      if (key < node->key) {
        node = node->left;
      }
      else {
        node = node->right;
      }
    }
    //avoid segfaults
    if (node != nullptr) {
      std::cerr << node->key << " was found." << std::endl;
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
void Tree<Key, Element>::AddLeaf(int key) {
  AddLeafHelper(key, root);
}

//key is z
//node was root
/* insert, from notes */
template <class Key, class Element>
void Tree<Key, Element>::AddLeafHelper(int key, Node* node) {
  if (root == nullptr) {
    root = CreateLeaf(key);
  }
  else {
      bool done = false;
      Node* q = node;

      while(!done) {
        if (key < q->key) {
          if (q->left == nullptr) {
            q->left = CreateLeaf(key);
            q->left->parent = q; //z->parent = q in psuedocode
            std::cerr << q->key << " is " << q->left->key << "'s parent" << '\n';
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
            std::cerr << q->key << " is " << q->right->key << "'s parent" << '\n';
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
    std::cerr << node->key << " ";
    if (node->right != nullptr) {
      PrintInOrderHelper(node->right);
    }
  }
  else {
    std::cerr << "The tree is empty.\n";
  }
}

template <class Key, class Element>
typename Tree<Key,Element>::Node* Tree<Key,Element>::ReturnNode(int key) {
  return ReturnNodeHelper(key, root);
}

/* from notes */
template <class Key, class Element>
typename Tree<Key,Element>::Node* Tree<Key,Element>::ReturnNodeHelper(int key, Node* node) {
  if (node != nullptr) {
    if (node->key == key) {
      return node;
    }
    else {
      if (key < node->key) {
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

/* from video, debug */
template <class Key, class Element>
void Tree<Key,Element>::PrintChildren(int key) {
  Node* node = ReturnNode(key);

  if (node != nullptr) {
    std::cerr << "Parent node = " << node->key << std::endl;

    node->left == nullptr ?
    std::cerr << "Left child = nullptr\n" :
    std::cerr << "Left child = " << node->left->key << std::endl;

    node->right == nullptr ?
    std::cerr << "Right child = nullptr\n" :
    std::cerr << "Right child = " << node->right->key << std::endl;
  }
  else {
    std::cerr << "Key " << key << " is not in the tree.\n";
  }
}

template <class Key, class Element>
int Tree<Key,Element>::FindSmallest() {
  return FindSmallestHelper(root);
}

/* from video, same as notes */
template <class Key, class Element>
int Tree<Key,Element>::FindSmallestHelper(Node* node) {
  if (root == nullptr) {
    std::cerr << "The tree is empty.\n";

    return -1000; //might need to be changed
  }
  else {
    if (node->left != nullptr) {
      return FindSmallestHelper(node->left);
    }
    else {
      return node->key;
    }
  }
}

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
void Tree<Key,Element>::RemoveNode(int key) {

  NodePtr node = getNode(key);

  RemoveNodeHelper(node, root);
}

/* from notes */
template <class Key, class Element>
void Tree<Key,Element>::RemoveNodeHelper(NodePtr& key, NodePtr& node) {
  std::cerr << "Deleting " << key->key << std::endl;

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
void Tree<Key,Element>::ReplaceSubtree(int u, int v) {
  NodePtr a = getNode(u);
  NodePtr b = getNode(v);

  ReplaceSubtreeHelper(a, b, root);
}

//warning look over after sleep
/* from notes */
template <class Key, class Element>
void  Tree<Key,Element>::ReplaceSubtreeHelper(NodePtr& u, NodePtr& v, NodePtr& node) {
  if (u->key == node->key) {
    node = v;
    if (v != nullptr) {
      v->parent = nullptr;
    }
  }
  else {
    Node* q = u->parent;
    if (u->key == q->left->key) {
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

    std::cerr << "Deleting the node containing key " << node->key << std::endl;
    delete node;
    node = nullptr;
  }
}

template <class Key, class Element>
int Tree<Key,Element>::FindNode(int key) {
  return FindNodeHelper(key, root);
}

/* from notes */
template <class Key, class Element>
int Tree<Key,Element>::FindNodeHelper(int key, Node* node) {
  if (node != nullptr) {
    while (node != nullptr && node->key != key) {
      if (key < node->key) {
        node = node->left;
      }
      else {
        node = node->right;
      }
    }
    //avoid segfaults
    if (node != nullptr) {
      std::cerr << node->key << " was found." << std::endl;
      return node->key;
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
