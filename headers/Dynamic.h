#include "Traverse.h"
#include "TSP.h"
#include <climits>
#include <string>

class Dynamic : public Traverse {
 public:
  Solution traverse(Tsp tsp, string initial, string goal, int mask);
};