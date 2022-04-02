#include <iostream>
#include <filesystem>
#include "headers/TSP.h"
#include "headers/Greedy.h"
using namespace std;
namespace fs = std::filesystem;

vector<string> getFiles() {
  string path = "./files";
  vector<string> files;
  for (const auto & entry : fs::directory_iterator(path)) {
      string file = entry.path().string();
      files.push_back(file);
      cout << file << endl;
  }
  return files;
}
void createFiles() {
  ofstream kuso;
  kuso.open("./files/kuso.txt");
  kuso << "2" << endl << "A B 25";
  kuso.close();
}

int main() {
  string file = "test.txt";
  vector<string> files = getFiles();
  createFiles();
  for (int i = 0; i < files.size(); i++) {
    file = files[i];
    Solution sol;
    Tsp tsp(file, new Greedy());
    cout << tsp;
    sol = tsp.traverse(tsp,"A","B");
    cout << "Cost: " << sol.getCost() << " Time: " << sol.getTimeCost()<< endl;
    vector<Node> nodes = sol.getSolution();
    for (int i = 0; i < nodes.size(); i++) {
      cout << nodes[i].getName() << ",";
    }
  }
  /*
  cout << tsp.traverse(tsp,"B","A") << endl;
  cout << tsp.traverse(tsp,"A","D");*/
}