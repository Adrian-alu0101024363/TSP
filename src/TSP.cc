#include "../headers/TSP.h"

using namespace std;

Tsp::Tsp(string file, Traverse* method) {
  read(file);
  method_ = method;
}

void Tsp::read(string file) {
  ifstream f;
  f.open(file);
  f >> nodeNumber_;
  string line;
  getline(f,line);
  while(getline(f,line)) {
    istringstream iss(line);
    string from, to;
    int cost;
    if (!(iss >> from >> to >> cost)) { break; }
    // Check if node (from and to) already in nodes_ if not push it
    if (find(nodes_.begin(), nodes_.end(), Node(from)) == nodes_.end()) nodes_.push_back(Node(from));
    if (find(nodes_.begin(), nodes_.end(), Node(to)) == nodes_.end()) nodes_.push_back(Node(to));
    auto it = find(nodes_.begin(), nodes_.end(), Node(from));
    int index = 0;
    if (it != nodes_.end()) {
      index = it - nodes_.begin();
    } else {
      cout << "Invalid format" << endl;
    }
    // Create transition and push it to node
    Transition trans(from, to, cost);
    nodes_[index].pushTans(trans);
    auto it2 = find(nodes_.begin(), nodes_.end(), Node(to));
    int index2 = 0;
    if (it2 != nodes_.end()) {
      index2 = it2 - nodes_.begin();
    } else {
      cout << "Invalid format" << endl;
    }
    // Create transition and push it to node
    Transition trans2(to, from, cost);
    nodes_[index2].pushTans(trans2);
  }
  f.close();
}

ostream& operator<<(ostream& os, Tsp tsp) {
  os << "Total nodes: " << tsp.getTotal() << endl;
  auto nodes = tsp.getNodes();
  for (int i = 0; i < nodes.size(); i++) {
    //os << nodes[i].getName() << ", ";
    os << nodes[i];
  }
  return os;
}