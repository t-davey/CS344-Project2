#ifndef TREE_H
#define TREE_H

#include <utility>

template <class Key, class Element>
class Tree {
  private:
    struct Node {
      int key;
      Node* parent;
      Node* left;
      Node* right;
    };

    typedef Node* NodePtr; //avoids &*/** weirdness - called in RemoveSubtree

    Node* root;

    Node* CreateLeaf(int key);
    void  AddLeafHelper(int key, Node* node);
    void  PrintInOrderHelper(Node* node);
    Node* ReturnNodeHelper(int key, Node* node); //find helper
    int   FindSmallestHelper(Node* node);
    void  RemoveNodeHelper(NodePtr& n, NodePtr& node);
    Node* ReturnNode(int key); //find
    void  RemoveSubtree(NodePtr& node);
    int   FindNodeHelper(int key, Node* node);
    int   sizeHelper(Node* node);
    void  ReplaceSubtreeHelper(NodePtr& u, NodePtr& v, NodePtr& node);
    Node* getNodeHelper(int key, Node* node);
    Node* min(Node* node);

  public:
    Tree();
    ~Tree();

    void  AddLeaf(int key);
    void  PrintInOrder();
    void  PrintChildren(int key);
    int   FindSmallest();
    void  RemoveNode(int key);
    int   FindNode(int key);
    void  ReplaceSubtree(int u, int v);
    Node* getNode(int key);
    void  ClearTree();
    int   size();
    bool  isEmpty();
};

#endif
