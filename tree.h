class Tree {
  private:
    struct Node {
      int key;
      Node* left;
      Node* right;
    };

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
    void  RemoveSubtree(Node* node);

  public:
    Tree();
    ~Tree();

    void  AddLeaf(int key);
    void  PrintInOrder();
    int   ReturnRootKey();
    void  PrintChildren(int key);
    int   FindSmallest();
    void  RemoveNode(int key);
};