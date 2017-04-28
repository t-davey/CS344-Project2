#ifndef TREE_H
#define TREE_H

#include <utility>

template <class Key, class Element>
class Tree {
  private:
    struct Node {
      std::pair<Key, Element> key;
      Node* parent;
      Node* left;
      Node* right;
    };

    typedef Node* NodePtr; //avoids &*/** weirdness - called in RemoveSubtree

    Node* root;

    Node* CreateLeaf(std::pair<Key, Element> key);
    void  AddLeafHelper(std::pair<Key, Element> key, Node* node);
    void  PrintInOrderHelper(Node* node);
    Node* ReturnNodeHelper(Key key, Node* node); //find helper
    void  RemoveNodeHelper(NodePtr& n, NodePtr& node);
    Node* ReturnNode(Key key); //find
    void  RemoveSubtree(NodePtr& node);
    bool  FindNodeHelper(Key key, Node* node);
    int   sizeHelper(Node* node);
    void  ReplaceSubtreeHelper(NodePtr& u, NodePtr& v, NodePtr& node);
    Node* getNodeHelper(Key key, Node* node);
    Node* min(Node* node);
    void  NodeDebugHelper(Key key, Node* node);

  public:
    Tree();
    ~Tree();

    void  NodeDebug(Key key);
    void  AddLeaf(std::pair<Key, Element> key);
    void  PrintInOrder();
    void  RemoveNode(Key key);
    bool  FindNode(Key key);
    void  ReplaceSubtree(Key u, Key v);
    Node* getNode(Key key);
    void  ClearTree();
    int   size();
    bool  isEmpty();
};

#endif
