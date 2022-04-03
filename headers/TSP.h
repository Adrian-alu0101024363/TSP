#ifndef TSP
#define TSP
#include <iostream>
#include <string>
#include <vector>
#include "Node.h"
#include "Transition.h"
#include "Traverse.h"
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class Tsp {
 private:
  vector<Node> nodes_;
  Traverse* method_;
  int nodeNumber_;
 public:
  Tsp(string file, Traverse* method);
  ~Tsp(){}
  int getTotal() {return nodeNumber_;}
  vector<Node> getNodes() {return nodes_;}
  Node getNode(int index) {return nodes_[index];}
  void setVisited(int index) {nodes_[index].setVisited(1);}
  void read(string file);
  bool allVisited();
  void setAll(bool state);
  Solution traverse(Tsp tsp, string initial, string goal, int mask) {return method_->traverse(*this,initial,goal, mask);}
  friend ostream& operator<<(ostream& os, Tsp tsp);
};
#endif