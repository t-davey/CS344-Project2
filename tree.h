#ifndef TREE_H
#define TREE_H

#include <utility>

template <class Key, class Element>
class Node {
public:
  std::pair<Key, Element> key;
  Node<Key,Element>* parent;
  Node<Key,Element>* left;
  Node<Key,Element>* right;
};


template <class Key, class Element>
Node<Key,Element>* next(Node<Key,Element>* node){
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
class Tree {
  private:
    typedef Node<Key,Element>* NodePtr; //avoids &*/** weirdness - called in RemoveSubtree

    Node<Key,Element>* root;

    Node<Key,Element>* CreateLeaf(std::pair<Key, Element> key);
    void  AddLeafHelper(std::pair<Key, Element> key, Node<Key,Element>* node);
    void  PrintInOrderHelper(Node<Key,Element>* node);
    Node<Key,Element>* ReturnNodeHelper(Key key, Node<Key,Element>* node); //find helper
    void  RemoveNodeHelper(NodePtr& n, NodePtr& node);
    Node<Key,Element>* ReturnNode(Key key); //find
    void  RemoveSubtree(NodePtr& node);
    bool  FindNodeHelper(Key key, Node<Key,Element>* node);
    int   sizeHelper(Node<Key,Element>* node);
    void  ReplaceSubtreeHelper(NodePtr& u, NodePtr& v, NodePtr& node);
    Node<Key,Element>* getNodeHelper(Key key, Node<Key,Element>* node);
    void  NodeDebugHelper(Key key, Node<Key,Element>* node);

  public:
    Tree();
    ~Tree();

    void  NodeDebug(Key key);
    void  AddLeaf(std::pair<Key, Element> key);
    void  PrintInOrder();
    void  RemoveNode(Key key);
    bool  FindNode(Key key);
    void  ReplaceSubtree(Key u, Key v);
    Node<Key,Element>* getNode(Key key);
    void  ClearTree();
    int   size();
    bool  isEmpty();
    Node<Key,Element>* min(Node<Key,Element>* node);
    Node<Key,Element>* next(Node<Key,Element>* node);
    Node<Key,Element>* getRoot();

    std::pair<Key,Element> getKey();
};

#endif
