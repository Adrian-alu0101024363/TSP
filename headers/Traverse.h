#include <string>
#include <chrono>
#ifndef TRAVERSE
#define TRAVERSE
#include "Solution.h"

using namespace std;

class Tsp;

class Traverse {
 public:
  virtual Solution traverse(Tsp tsp, string initial, string goal, int mask) = 0;
};
#endif