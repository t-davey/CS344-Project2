class Tree {
  private:
    struct Node {
      int key;
      Node* parent;
      Node* left;
      Node* right;
    };

    typedef Node* NodePtr; //avoids *&/** weirdness - called in RemoveSubtree

    Node* root;

    Node* CreateLeaf(int key);
    void  AddLeafHelper(int key, Node* node);
    void  PrintInOrderHelper(Node* node);
    Node* ReturnNodeHelper(int key, Node* node); //find helper
    int   FindSmallestHelper(Node* node);
    void  RemoveNodeHelper(NodePtr& n, NodePtr& node);
    void  RemoveRootMatch();
    void  RemoveMatch(Node* parent, Node* match, bool isLeft);
    Node* ReturnNode(int key); //find
    void  RemoveSubtree(NodePtr& node);
    int   FindNodeHelper(int key, Node* node);
    void  SwapNodes(int key, int swap, Node* node); //not implemented
    int   sizeHelper(Node* node);
    void  ReplaceSubtreeHelper(NodePtr& u, NodePtr& v, NodePtr& node);
    Node* getNodeHelper(int key, Node* node);
    Node* min(Node* node);

  public:
    Tree();
    ~Tree();

    void  AddLeaf(int key);
    void  PrintInOrder();
    int   ReturnRootKey();
    void  PrintChildren(int key);
    int   FindSmallest();
    void  RemoveNode(int key);
    int   FindNode(int key);
    void  SwapNodes(int key, int swap); //not implemented
    void  ReplaceSubtree(int u, int v);
    Node* getNode(int key);
    void  ClearTree();
    int   size();
    bool  isEmpty();
    void  begin(); //not implemented
    void  end();   //not implemented
};
