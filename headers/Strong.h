#include "Traverse.h"
#include "TSP.h"
#include <climits>

using namespace std;

class Strong : public Traverse {
 public:
  Solution traverse(Tsp tsp, string initial, string goal, int mask);
};