#include "../headers/Greedy.h"

using namespace std;

Solution Greedy::traverse(Tsp tsp, string initial, string goal, int mask) {
  //cout << "Greedy" << endl;
  Timer t;
  t.start();
  string to, dest;
  int min_path = INT_MAX;
  int cost = 0;
  vector<Node> result;
  auto nodes = tsp.getNodes();
  int origin = find(nodes.begin(), nodes.end(), Node(initial)) - nodes.begin();
  Node actual(tsp.getNodes()[origin]);
  tsp.setVisited(origin);
  nodes[origin].setVisited(true);
  result.push_back(actual);
  do {
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
    tsp.setVisited(index);
  } while(!tsp.allVisited());
  vector<Transition> trans = actual.getTrans();
  for (int i = 0; i < trans.size(); i++) {
    if (trans[i].getTo() == initial) {
      cost += trans[i].getCost();
      break;
    }
  }
  t.finish();
  Solution solution(result, cost);
  solution.setTimeCost(t.getCpuTime());
  return solution;
}

/*
Solution Greedy::traverse(Tsp tsp, string initial, string goal) {
  int sum = 0;
  int counter = 0;
  int j= 0, i = 0;
  int min = INT_MAX;
  map<Node,int> visitedRoute;

}*/
