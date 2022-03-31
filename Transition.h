#ifndef TRANSITION
#define TRANSITION
#include <iostream>
#include <string>

using namespace std;

class Transition {
 private:
  string from_;
  string to_;
  int cost_;
 public:
  Transition(string from, string to, int value) {from_ = from; to_ = to; cost_ = value;}
  ~Transition(){}
  string getFrom() {return from_;}
  string getTo() {return to_;}
  int getCost() {return cost_;}
  void setFrom(string from) {from_ = from;}
  void setTo(string to) {to_ = to;}
  void setCost(int cost) {cost_ = cost;}
  friend ostream& operator<<(ostream& os, Transition trans) {
    os << "F: " << trans.getFrom() << " To: " << trans.getTo(); 
    os << " Cost: " << trans.getCost() << endl;
    return os;
  }
};
#endif
