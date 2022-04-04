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
  double elapsed_time_ms = 0.0;
  int index;
  int min_cost = INT_MAX;
  auto t_start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < nodes.size(); i++) {
    auto t_end = std::chrono::high_resolution_clock::now();
    elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end-t_start).count();
    if (elapsed_time_ms > tsp.getLimit()) {
      Solution s(result,min_cost);
      s.setTimeCost(-1.0);
      return s;
    }
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
  auto t_end = std::chrono::high_resolution_clock::now();
  elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end-t_start).count();
  Solution sol(result,min_cost);
  sol.setTimeCost(elapsed_time_ms);
  return sol;
}