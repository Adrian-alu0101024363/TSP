#include "Traverse.h"
#include "TSP.h"
#include <climits>
#include <string>

class Greedy : public Traverse {
 public:
  int traverse(Tsp tsp, string initial, string goal);
};