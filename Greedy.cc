#include "Greedy.h"

using namespace std;

int Greedy::traverse(Tsp tsp, string initial, string goal) {
  cout << "Greedy" << endl;
  string to, dest;
  int min_path = INT_MAX;
  int cost = 0;
  vector<Node> result;
  auto nodes = tsp.getNodes();
  int origin = find(nodes.begin(), nodes.end(), Node(initial)) - nodes.begin();
  Node actual(tsp.getNodes()[origin]);
  nodes[origin].setVisited(true);
  result.push_back(actual);
  while(actual.getName() != goal) {
    min_path = INT_MAX;
    vector<Transition> trans = actual.getTrans();
    actual.setVisited(true);
    int index;
    for (int i = 0; i < trans.size(); i++) {
      to = trans[i].getTo();
      index = find(nodes.begin(), nodes.end(), Node(to)) - nodes.begin();
      if (trans[i].getCost() < min_path && !nodes[index].getVisited()) {
        min_path = trans[i].getCost();
        dest = trans[i].getTo();
      }
    }
    index = find(nodes.begin(), nodes.end(), Node(dest)) - nodes.begin();
    cost += min_path;
    actual = tsp.getNode(index);
    result.push_back(actual);
    nodes[index].setVisited(true);
  }
  for (int j = 0; j < result.size(); j++) cout << result[j].getName();
  cout << endl;
  return cost;
}
