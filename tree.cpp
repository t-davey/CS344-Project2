#include <iostream>
#include <cstdlib>
#include "tree.h"

Tree::Tree() {
  root = nullptr;
}

Tree::~Tree() {
  RemoveSubtree(root);
}

Tree::Node* Tree::CreateLeaf(int key) {
  Node* node   = new Node;
  node->key    = key;
  node->parent = nullptr;
  node->left   = nullptr;
  node->right  = nullptr;

  return node;
}

/* returns a node object from a given key */
Tree::Node* Tree::getNode(int key) {
  getNodeHelper(key, root);
}

Tree::Node* Tree::getNodeHelper(int key, Node* node) {
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

void Tree::AddLeaf(int key) {
  AddLeafHelper(key, root);
}

//key is z
//node was root
/* insert, from notes */
void Tree::AddLeafHelper(int key, Node* node) {
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


void Tree::PrintInOrder() {
  PrintInOrderHelper(root);
}

/* from video */
void Tree::PrintInOrderHelper(Node* node) {
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

Tree::Node* Tree::ReturnNode(int key) {
  return ReturnNodeHelper(key, root);
}

/* from notes */
Tree::Node* Tree::ReturnNodeHelper(int key, Node* node) {
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
void Tree::PrintChildren(int key) {
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

int Tree::FindSmallest() {
  return FindSmallestHelper(root);
}

/* from video, same as notes */
int Tree::FindSmallestHelper(Node* node) {
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
Tree::Node* Tree::min(Node* node) {
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

void Tree::RemoveNode(int key) {

  NodePtr node = getNode(key);

  RemoveNodeHelper(node, root);
}

/* from notes */
void Tree::RemoveNodeHelper(NodePtr& key, NodePtr& node) {
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

void Tree::ReplaceSubtree(int u, int v) {
  NodePtr a = getNode(u);
  NodePtr b = getNode(v);

  ReplaceSubtreeHelper(a, b, root);
}

//warning look over after sleep
/* from notes */
void  Tree::ReplaceSubtreeHelper(NodePtr& u, NodePtr& v, NodePtr& node) {
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
void Tree::RemoveSubtree(NodePtr& node) {
  if (node != nullptr) {
    RemoveSubtree(node->left);
    RemoveSubtree(node->right);

    std::cerr << "Deleting the node containing key " << node->key << std::endl;
    delete node;
    node = nullptr;
  }
}

int Tree::FindNode(int key) {
  return FindNodeHelper(key, root);
}

/* from notes */
int Tree::FindNodeHelper(int key, Node* node) {
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

void Tree::ClearTree() {
  RemoveSubtree(root);
}

int Tree::size() {
  return sizeHelper(root);
}

int Tree::sizeHelper(Node *node) {
    if (node != nullptr) {
      return (sizeHelper(node->left) + 1 + sizeHelper(node->right));
    }
    else {
      return 0;
    }
}

bool Tree::isEmpty() {
  if (root == nullptr) {
    std::cerr << "The tree is empty." << std::endl;
    return true;
  }
  else {
    std::cerr << "The tree is not empty." << std::endl;
    return false;
  }
}
