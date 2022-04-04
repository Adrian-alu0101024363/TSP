#include "../headers/Strong.h"

using namespace std;

Solution Strong::traverse(Tsp tsp, string initial, string goal, int mask) {
  vector<Node> nodes = tsp.getNodes();
  vector<Node> result;
  if (nodes.size() == 2) {
    int cost = 2 * nodes[0].getCostTo(nodes[1].getName());
    Solution sol(nodes,cost);
    return sol;
  }
  int origin = find(nodes.begin(), nodes.end(), Node(initial)) - nodes.begin();
  nodes.erase(find(nodes.begin(), nodes.end(), Node(initial)));
  double elapsed_time_ms = 0.0;
  int n = nodes.size();
  int shortest_path = INT_MAX;
  auto t_start = std::chrono::high_resolution_clock::now();
  while(next_permutation(nodes.begin(),nodes.end())) {
    int path_weight = 0;
    auto t_end = std::chrono::high_resolution_clock::now();
    elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end-t_start).count();
    if (elapsed_time_ms > tsp.getLimit()) { //300000 para 5 minutos
      Solution s(result,shortest_path);
      s.setTimeCost(-1.0);
      return s;
    }
    path_weight += tsp.getNodes()[origin].getCostTo(nodes[0].getName());
    for (int i = 1; i < n; i++) {
      path_weight += nodes[i - 1].getCostTo(nodes[i].getName());
    }
    path_weight += nodes[nodes.size() - 1].getCostTo(tsp.getNodes()[origin].getName());
    if (shortest_path > path_weight) {
      shortest_path = path_weight;
      result = nodes;
    }
  }
  auto t_end = std::chrono::high_resolution_clock::now();
  elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end-t_start).count();
  Solution sol(result,shortest_path);
  sol.setTimeCost(elapsed_time_ms);
  return sol;
}