#include <iostream>
#include <cstdlib>
#include "tree.h"

Tree::Tree() {
  root = NULL;
}

Tree::~Tree() {
  RemoveSubtree(root);
}

Tree::Node* Tree::CreateLeaf(int key) {
  Node* node  = new Node;
  node->key   = key;
  node->left  = NULL;
  node->right = NULL;

  return node;
}

void Tree::AddLeaf(int key) {
  AddLeafHelper(key, root);
}

void Tree::AddLeafHelper(int key, Node* node) {
  if (root == NULL) {
    root = CreateLeaf(key);
  }
  else if (key < node->key) {
    if (node->left != NULL) {
      AddLeafHelper(key, node->left);
    }
    else {
       node->left = CreateLeaf(key);
    }
  }
  else if (key > node->key) {
    if (node->right != NULL) {
      AddLeafHelper(key, node->right);
    }
    else {
       node->right = CreateLeaf(key);
    }
  }
  else {
    std::cout << "The key " 
              << key 
              << " has already been added to the tree.\n";
  }
}

void Tree::PrintInOrder() {
  PrintInOrderHelper(root);
}

void Tree::PrintInOrderHelper(Node* node) {
  if (root != NULL) {
    if (node->left != NULL) {
      PrintInOrderHelper(node->left);
    }
    std::cout << node->key << " ";
    if (node->right != NULL) {
      PrintInOrderHelper(node->right);
    }
  }
  else {
    std::cout << "The tree is empty.\n";
  }
}

/* find */
Tree::Node* Tree::ReturnNode(int key) {
  return ReturnNodeHelper(key, root);
}

/* find helper */
Tree::Node* Tree::ReturnNodeHelper(int key, Node* node) {
  if (node != NULL) {
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
    return NULL;
  }
}

int Tree::ReturnRootKey() {
  if (root != NULL) {
    return root->key;
  }
  else {
    return -1000; //might have to change
  }
}

void Tree::PrintChildren(int key) {
  Node* node = ReturnNode(key);

  if (node != NULL) {
    std::cout << "Parent node = " << node->key << std::endl;

    node->left == NULL ?
    std::cout << "Left child = NULL\n" :
    std::cout << "Left child = " << node->left->key << std::endl;
    
    node->right == NULL ?
    std::cout << "Right child = NULL\n" :
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
  if (root == NULL) {
    std::cout << "The tree is empty.\n";

    return -1000; //might need to be changed
  }
  else {
    if (node->left != NULL) {
      return FindSmallestHelper(node->left);
    }
    else {
      return node->key;
    }
  }
}

void Tree::RemoveNode(int key) {
  RemoveNodeHelper(key, root);
}

void Tree::RemoveNodeHelper(int key, Node* parent) {
  if (root != NULL) {
    if (root->key == key) {
      RemoveRootMatch();
    }
    else {
      if (key < parent->key && parent->left != NULL) {
        if (parent->left->key == key) {
          RemoveMatch(parent, parent->left, true);
        }
        else {
          RemoveNodeHelper(key, parent->left);
        }
      }
      else if (key > parent->key && parent->right != NULL) {
        if (parent->right->key == key) {
          RemoveMatch(parent, parent->right, false);
        }
        else {
          RemoveNodeHelper(key, parent->right);
        }
      }
      else {
        std::cout << "The key " << key << " was not found in the tree.\n";
      }
    }
  }
  else {
    std::cout << "The tree is empty.\n";
  }
}

void Tree::RemoveRootMatch() {
  if (root != NULL) {
    Node* delNode = root;
    int   rootKey = root->key;
    int   smallestInRightSubTree;

    // Case 1 - 0 children
    if (root->left == NULL && root->right == NULL) {
      root = NULL;
      delete delNode;
    }

    // Case 2 - 1 child
    else if (root->left == NULL && root->right != NULL) {
      root = root->right;

      delNode->right = NULL;
      delete delNode;

      std::cout << "The root node with key " 
                << rootKey << " was deleted. "
                << "The new root contains key "
                << root->key << std::endl;
    }
    else if (root->left != NULL && root->right == NULL) {
      root = root->left;

      delNode->left = NULL;
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

void Tree::RemoveMatch(Node* parent, Node* match, bool isLeft) {
  if (root != NULL) {
    Node* delNode;
    int   matchKey = match->key;
    int   smallestInRightSubtree;

    // Case 1 - 0 children
    if (match->left == NULL && match->right == NULL) {
      delNode = match;
      if (isLeft == true) {
        parent->left = NULL;
      }
      else {
        parent->right = NULL;
      }

      delete delNode;
      std::cout << "The node containing key " << matchKey
                << " was removed.\n";
    }

    // Case 2 - 1 child
    else if (match->left == NULL && match->right != NULL) {
      if (isLeft == true) {
        parent->left = match->right;
      }
      else {
        parent->right = match->right;
      }

      match->right = NULL;
      delNode = match;

      delete delNode;
      std::cout << "The node containing key " << matchKey
                << " was removed.\n";
    }
    else if (match->left != NULL && match->right == NULL) {
      if (isLeft == true) {
        parent->left = match->left;
      }
      else {
        parent->right = match->left;
      }

      match->right = NULL;
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
}

void Tree::RemoveSubtree(Node* node) {
  if (node != NULL) {
    if (node->left != NULL) {
      RemoveSubtree(node->left);
    }
    if (node->right != NULL) {
      RemoveSubtree(node->right);
    }

    std::cout << "Deleting the node containing key " << node->key << std::endl;
    delete node;
  }
  else {

  }
}