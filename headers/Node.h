#include <iostream>
#include <string>
#include <vector>
#include "Transition.h"
#ifndef NODE
#define NODE

using namespace std;

class Node {
 private:
  string name_;
  bool visited_;
  vector<Transition> trans_;
 public:
  Node(string name, bool visited = 0) {name_ = name;visited_ = visited;}
  Node(string name, vector<Transition> trans, bool visited = 0) {name_ = name;visited_ = visited;trans_ = trans;}
  ~Node(){}
  bool operator==(Node comp) {return comp.getName() == getName();}
  string getName() {return name_;}
  bool getVisited() {return visited_;}
  void setVisited(bool visited) {visited_ = visited;}
  vector<Transition> getTrans() {return trans_;}
  int getCostTo(string destination) {
    for (int i = 0; i < trans_.size(); i++) {
      if (trans_[i].getTo() == destination) {
        return trans_[i].getCost();
      }
    }
    return -1;
  }
  void setName(string name) {name_ = name;}
  void pushTans(Transition tran) {trans_.push_back(tran);}
  friend ostream& operator<<(ostream& os, Node node) { for(Transition t : node.getTrans()) os << t;return os;}
};
#endif
