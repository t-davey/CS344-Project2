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
  Node* node  = new Node;
  node->key   = key;
  node->left  = nullptr;
  node->right = nullptr;

  return node;
}

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
      std::cout << node->key << " was found." << std::endl;
      return node;
    }
    else {
      std::cout << key << " was not found." << std::endl;
      return nullptr;
    }
  }
  else {
    std::cout << "The tree is empty." << std::endl;
    return nullptr;
  }
}

void Tree::AddLeaf(int key) {
  AddLeafHelper(key, root);
}

//key is z
//node was root
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
            std::cout << q->key << " is " << q->left->key << "'s parent" << '\n';
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
            std::cout << q->key << " is " << q->right->key << "'s parent" << '\n';
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

void Tree::PrintInOrderHelper(Node* node) {
  if (root != nullptr) {
    if (node->left != nullptr) {
      PrintInOrderHelper(node->left);
    }
    std::cout << node->key << " ";
    if (node->right != nullptr) {
      PrintInOrderHelper(node->right);
    }
  }
  else {
    std::cout << "The tree is empty.\n";
  }
}

Tree::Node* Tree::ReturnNode(int key) {
  return ReturnNodeHelper(key, root);
}

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

int Tree::ReturnRootKey() {
  if (root != nullptr) {
    return root->key;
  }
  else {
    return -1000; //might have to change
  }
}

void Tree::PrintChildren(int key) {
  Node* node = ReturnNode(key);

  if (node != nullptr) {
    std::cout << "Parent node = " << node->key << std::endl;

    node->left == nullptr ?
    std::cout << "Left child = nullptr\n" :
    std::cout << "Left child = " << node->left->key << std::endl;

    node->right == nullptr ?
    std::cout << "Right child = nullptr\n" :
    std::cout << "Right child = " << node->right->key << std::endl;
  }
  else {
    std::cout << "Key " << key << " is not in the tree.\n";
  }
}

int Tree::FindSmallest() {
  return FindSmallestHelper(root);
}

int Tree::FindSmallestHelper(Node* node) {
  if (root == nullptr) {
    std::cout << "The tree is empty.\n";

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

Tree::Node* Tree::min(Node* node) {
  if (root == nullptr) {
    std::cout << "The tree is empty.\n";

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

void Tree::RemoveNodeHelper(NodePtr& key, NodePtr& node) {
  std::cout << "Deleting " << key->key << std::endl;
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

/*
void Tree::RemoveRootMatch() {
  if (root != nullptr) {
    Node* delNode = root;
    int   rootKey = root->key;
    int   smallestInRightSubTree;

    // Case 1 - 0 children
    if (root->left == nullptr && root->right == nullptr) {
      root = nullptr;
      delete delNode;
    }

    // Case 2 - 1 child
    else if (root->left == nullptr && root->right != nullptr) {
      root = root->right;

      delNode->right = nullptr;
      delete delNode;

      std::cout << "The root node with key "
                << rootKey << " was deleted. "
                << "The new root contains key "
                << root->key << std::endl;
    }
    else if (root->left != nullptr && root->right == nullptr) {
      root = root->left;

      delNode->left = nullptr;
      delete delNode;

      std::cout << "The root node with key "
                << rootKey << " was deleted. "
                << "The new root contains key "
                << root->key << std::endl;
    }

    // Case 3 - 2 children
    else {
      smallestInRightSubTree = FindSmallestHelper(root->right);
      RemoveNodeHelper(smallestInRightSubTree, root);
      root->key = smallestInRightSubTree;

      std::cout << "The root key containing key "
                << rootKey << " was overwritten with key "
                << root->key << std::endl;
    }
  }
  else {
    std::cout << "Cannot remove root. The tree is empty.\n";
  }
}
*/

/*
void Tree::RemoveMatch(Node* parent, Node* match, bool isLeft) {
  if (root != nullptr) {
    Node* delNode;
    int   matchKey = match->key;
    int   smallestInRightSubtree;

    // Case 1 - 0 children
    if (match->left == nullptr && match->right == nullptr) {
      delNode = match;
      if (isLeft == true) {
        parent->left = nullptr;
      }
      else {
        parent->right = nullptr;
      }

      delete delNode;
      std::cout << "The node containing key " << matchKey
                << " was removed.\n";
    }

    // Case 2 - 1 child
    else if (match->left == nullptr && match->right != nullptr) {
      if (isLeft == true) {
        parent->left = match->right;
      }
      else {
        parent->right = match->right;
      }

      match->right = nullptr;
      delNode = match;

      delete delNode;
      std::cout << "The node containing key " << matchKey
                << " was removed.\n";
    }
    else if (match->left != nullptr && match->right == nullptr) {
      if (isLeft == true) {
        parent->left = match->left;
      }
      else {
        parent->right = match->left;
      }

      match->right = nullptr;
      delNode = match;

      delete delNode;
      std::cout << "The node containing key " << matchKey
                << " was removed.\n";
    }
      // Case 3 - 2 children
    else {
      smallestInRightSubtree = FindSmallestHelper(match->right);
      RemoveNodeHelper(smallestInRightSubtree, match);
      match->key = smallestInRightSubtree;
    }
  }
  else {
    std::cout << "Cannot remove root. The tree is empty.\n";
  }
}*/

void Tree::RemoveSubtree(NodePtr& node) {
  if (node != nullptr) {
    RemoveSubtree(node->left);
    RemoveSubtree(node->right);

    std::cout << "Deleting the node containing key " << node->key << std::endl;
    delete node;
    node = nullptr;
  }
}

int Tree::FindNode(int key) {
  return FindNodeHelper(key, root);
}

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
      std::cout << node->key << " was found." << std::endl;
      return node->key;
    }
    else {
      std::cout << key << " was not found." << std::endl;
      return -1000; //might need to be changed
    }
  }
  else {
    std::cout << "The tree is empty." << std::endl;
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
    std::cout << "The tree is empty." << std::endl;
    return true;
  }
  else {
    std::cout << "The tree is not empty." << std::endl;
    return false;
  }
}
