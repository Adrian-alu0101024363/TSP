#include "../headers/Dynamic.h"
#include <set>

using namespace std;

Solution Dynamic::traverse(Tsp tsp, string initial, string goal, int mask) {
  vector<Node> result;
  auto nodes = tsp.getNodes();
  int all = (1 << nodes.size())- 1;
  int origin = find(nodes.begin(), nodes.end(), Node(goal)) - nodes.begin();
  Node actual(tsp.getNodes()[origin]);
  vector<Transition> trans = actual.getTrans();
  if (mask == all) {
    int cost = actual.getCostTo(initial);
    Solution solution(result, cost);
    return solution;
  }
  string to,dest;
  int index;
  int min_cost = INT_MAX;
  set<string> set;
  for (int i = 0; i < nodes.size(); i++) {
    if ((mask&(1<<i)) == 0) {
      //cout << "visiting " << nodes[i].getName() << " with min: " << min_cost << endl;
      Solution s = traverse(tsp,initial,nodes[i].getName(),mask|(1<<i));
      int aux = s.getCost();
      //cout << "coste: " << aux << endl;
      int cost = actual.getCostTo(nodes[i].getName()) + aux;
      //min_cost = min(min_cost,cost);
      if (min_cost > cost) {
        min_cost = cost;
        result = s.getSolution();
        result.push_back(nodes[i]);
        //cout << "path: " << nodes[i].getName();
      }
    }
  }
  Solution sol(result,min_cost);
  return sol;
}