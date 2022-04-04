#include "../headers/TSP.h"

using namespace std;

/**
 * @brief Construct a new Tsp:: Tsp object
 * read from the file convert to a tsp 
 * @param file file to be readed
 * @param method the method for traverse tsp
 * @param limit the time limit in ms
 */
Tsp::Tsp(string file, Traverse* method, double limit) {
  read(file);
  method_ = method;
  limit_ = limit;
}

/**
 * @brief read a tsp from file with the format
 * numbernodes
 * from to cost
 * ...
 * @param file the file to be read
 */
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

/**
 * @brief true if all nodes of tsp are visited
 * false if not all
 * @return true 
 * @return false 
 */
bool Tsp::allVisited() {
  for (int i = 0; i < nodes_.size(); i++) {
    if (!nodes_[i].getVisited()) return false;
  }
  return true;
}

/**
 * @brief set all nodes to the given state
 * 
 * @param state 
 */
void Tsp::setAll(bool state) {
  for (int i = 0; i < nodes_.size(); i++) {
    nodes_[i].setVisited(state);
  }
}

/**
 * @brief ostream the tsp specification/description
 * 
 * @param os 
 * @param tsp 
 * @return ostream& 
 */
ostream& operator<<(ostream& os, Tsp tsp) {
  os << "Total nodes: " << tsp.getTotal() << endl;
  auto nodes = tsp.getNodes();
  for (int i = 0; i < nodes.size(); i++) {
    //os << nodes[i].getName() << ", ";
    os << nodes[i];
  }
  return os;
}