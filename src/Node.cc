#include "../headers/Node.h"

/**
 * @brief Construct a new Node:: Node object
 * without given transitions
 * @param name node name
 * @param visited visited or not
 */
Node::Node(string name, bool visited) {
  name_ = name;
  visited_ = visited;
}

/**
 * @brief Construct a new Node:: Node object
 * with given transitions
 * @param name node name
 * @param trans transition of node
 * @param visited visited or not
 */
Node::Node(string name, vector<Transition> trans, bool visited) {
  name_ = name;
  visited_ = visited;
  trans_ = trans;
}

/**
 * @brief Get the cost from the current node to the 
 * destination name (by node name)
 * @param destination the name of the dest node
 * @return int the cost
 */
int Node::getCostTo(string destination) {
  for (int i = 0; i < trans_.size(); i++) {
    if (trans_[i].getTo() == destination) {
      return trans_[i].getCost();
    }
  }
  return -1;
}