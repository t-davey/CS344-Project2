#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Map.cpp"

using std::string;
using std::pair;
using std::cout;
using std::endl;

int main(int argc, char **argv) {
  Map<int, string> m;

  srand(time(NULL));

  int testKeys[10] = {1,5,9,7,2,4,1,6,3,7};
  string testElements[10] = {"aa", "bb", "cc", "dd", "ee", "ff", "gg", "hh", "ii", "jj"};
  //"aa" and "dd" should not appear in the map as they will be overwritten

  //insert
  cout << "Testing insert(pair) method:" << endl;
  for (int i = 0; i < 10; i++) {
    m.insert(pair<int, string>(testKeys[i], testElements[i]));
  }
  int nonDupeTestKeys[8] = {1,5,9,7,2,4,6,3};
  for (int i = 0; i < 8; i++) {
   m.printTree(nonDupeTestKeys[i]);
  }

  //erase(key)
  cout << "__________________________________________" << endl;
  cout << "Testing erase(key) on keys 1,7, and 6" << endl;
  m.erase(1);
  m.erase(7);
  m.erase(6);
  m.printTree();

  //find(key)
  cout << "__________________________________________" << endl;
  cout << "Testing find(key) on key 5" << endl;
  //MapItr<int,string> f = m.find(5);

  //empty() and size()
  cout << "__________________________________________" << endl;
  cout << "Testing empty() and size()" << endl;
  if (m.empty()) {
    cout << "Size: " << m.size() << endl;
    cout << "Empty?: Yes" << endl;
  } else {
    cout << "Size: " << m.size() << endl;
    cout << "Empty?: No" << endl;  }

  //clear()
  cout << "__________________________________________" << endl;
  cout << "Testing clear()" << endl;
  m.clear();
  if (m.empty()) {
    cout << "Size: " << m.size() << endl;
    cout << "Empty?: Yes" << endl;
  } else {
    cout << "Size: " << m.size() << endl;
    cout << "Empty?: No" << endl;  }



  // for (int i = 0; i < 10; i++) {
  //    m.printTree(test[i]);
  // }

  //if(m.begin()==m.begin()) {
  //  cout << "True" << endl;
  //}

  return 1;
}
