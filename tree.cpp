#include <vector>
#include <utility>
#include <iostream>

struct Tree {
  char data;
  Tree *parent;
	Tree *left;
	Tree *right;
};

Tree* find(struct Tree *node, char key) {
	if (node == NULL) {
    return node;
  }

	if (node->data == key) {
    return node;
  }
	else {
	  if(node->data < key) {
      return find(node->right, key);
    }
	  else {
		  return find(node->left, key);
    }
	}
}

struct Tree *add(int data) {
	Tree *node = new Tree;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;

	return node;
}

struct Tree* insert(struct Tree *node, int data) {
	static Tree *p;
	Tree *retNode;

	if (node == NULL) {
	    retNode = add(data);
	    retNode->parent = p;
	    return retNode;
	}
	if (data <= node->data) {
	    p = node;
	    node->left = insert(node->left,data);
	}
	else {
	    p = node;
	    node->right = insert(node->right,data);
	}
	return node;
}

int size(struct Tree *node)
{
	if (node == NULL) {
    return 0;
  }
	else {
	  return size(node->left) + 1 + size(node->right);
  }
}

void clear(struct Tree *node) {
	if (node != NULL) {
	    clear(node->left);
	    clear(node->right);
	    delete node;
	}
}

int main(int argc, char **argv) {
	char ch, ch1, ch2;
	Tree *found;
	Tree *succ;
	Tree *pred;
	Tree *ancestor;
	char charArr[9]
	    = {'A','B','C','D','E','F','G','H','I'};

	Tree *root = add('F');
	insert(root,'B');
	insert(root,'A');
	insert(root,'D');
	insert(root,'C');
	insert(root,'E');
	insert(root,'G');
	insert(root,'I');
	insert(root,'H');

	clear(root);

	return 0;
}
