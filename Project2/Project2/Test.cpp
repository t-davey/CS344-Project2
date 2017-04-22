#include <iostream>
#include <string>

#include "Node.h"

using namespace std;

int main() {
	Node n = Node();
	Node n2 = Node(1, "Hi", nullptr, nullptr);

	cout << "Key: " << n.key << "\nValue: " << n.value << endl;

	cout << "Key: " << n2.key << "\nValue: " << n2.value << endl;

	system("pause");
}