#include <string>
#ifndef TRAVERSE
#define TRAVERSE

using namespace std;

class Tsp;

class Traverse {
 public:
  virtual int traverse(Tsp tsp, string initial, string goal) = 0;
};
#endif