class Tree {
  private:
    struct Node {
      int key;
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
    void  RemoveNodeHelper(int key, Node* parent);
    void  RemoveRootMatch();
    void  RemoveMatch(Node* parent, Node* match, bool isLeft);
    Node* ReturnNode(int key); //find
    void  RemoveSubtree(NodePtr& node);
    int   FindNodeHelper(int key, Node* node);
    void  SwapNodes(int key, int swap, Node* node); //not implemented
    int   sizeHelper(Node* node);

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
    void  ClearTree();
    int   size();
    bool  isEmpty();
    void  begin(); //not implemented
    void  end();   //not implemented
};