#include "tree.h"
#include <string>

class Map {

private:
  Tree t;

public:
  Map();
  Map(const Map & m);
  ~Map();

  std::string operator[](int i); //int i will need to be generic

  int size();
  void clear();
  bool empty();
  //itr begin()
  //itr end()
  std::string find(int key); //int key will need to be generic
  void erase(int key);
  //void erase(itr i);
};
