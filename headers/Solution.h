#include "Node.h"

using namespace std;

class Solution {
  private:
  vector<Node> sol_;
  int cost_;
  double timeCost_;
  public:
  Solution(){}
  Solution(vector<Node> sol, int cost = 0) {sol_ = sol; cost_ = cost;}
  ~Solution(){}
  vector<Node> getSolution() {return sol_;}
  void setSolution(vector<Node> sol) {sol_ = sol;}
  void setCost(int cost) {cost_ = cost;}
  int getCost() {return cost_;}
  void setTimeCost(double time) {timeCost_ = time;}
  double getTimeCost() {return timeCost_;}
  //method to calculate cost wip
};