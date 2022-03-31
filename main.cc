#include <iostream>
#include "TSP.h"
#include "Greedy.h"

int main() {
  string file = "test.txt";

  Tsp tsp(file, new Greedy());
  cout << tsp;
  cout << tsp.traverse(tsp,"A","B") << endl;
  cout << tsp.traverse(tsp,"B","A") << endl;
  cout << tsp.traverse(tsp,"A","D");
}