#ifndef NODE_H
#define NODE_H


#include <utility>
#include <string>

using std::pair;
using std::string;

class Node //needs to be generic
{
public:

	Node() : key(0), value(), left(nullptr), right(nullptr) {}
	Node(const int & k, const string & v, Node * left0, Node * right0) :
		key(k), value(v), left(left0), right(right0) {}
	//~Node();


//private: commented out for testing
	int key;
	string value;
	Node * left;
	Node * right;

};

#endif
