#include <iostream>
#include <filesystem>
#include "headers/TSP.h"
#include "headers/Greedy.h"
#include "headers/Dynamic.h"
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
void solveDynamic(string file) {
  cout << "Dynamic" << endl;
  Solution sol;
  Tsp tsp(file, new Dynamic());
  //cout << tsp;
  sol = tsp.traverse(tsp,"A","A",1);
  sol = tsp.traverse(tsp,"A","A",1);
  vector<Node> solf = sol.getSolution();
  vector<Node> nodes = tsp.getNodes();
  int ini = find(nodes.begin(), nodes.end(), Node("A")) - nodes.begin();
  Node iniNode(tsp.getNodes()[ini]);
  solf.insert(solf.begin(),iniNode);
  solf.push_back(iniNode);
  cout << "Cost: " << sol.getCost() << " Time: " << sol.getTimeCost()<< endl;
  for (int i = 0; i < solf.size(); i++) {
    cout << solf[i].getName() << ",";
  }
  cout << endl;
}
void solveGreedy(string file) {
  cout << "Greedy" << endl;
  Solution sol;
  Tsp tsp(file, new Greedy());
  sol = tsp.traverse(tsp,"A","A",1);
  sol = tsp.traverse(tsp,"A","A",1);
  vector<Node> solf = sol.getSolution();
  vector<Node> nodes = tsp.getNodes();
  int ini = find(nodes.begin(), nodes.end(), Node("A")) - nodes.begin();
  Node iniNode(tsp.getNodes()[ini]);
  solf.push_back(iniNode);
  cout << "Cost: " << sol.getCost() << " Time: " << sol.getTimeCost()<< endl;
  for (int i = 0; i < solf.size(); i++) {
    cout << solf[i].getName() << ",";
  }
  cout << endl;
}

int main() {
  string file = "test.txt";
  vector<string> files = getFiles();
  createFiles();
  for (int i = 0; i < files.size(); i++) {
    file = files[i];
    cout << "Example " << i + 1 << endl;
    solveDynamic(file);
    solveGreedy(file);
  }
  /*
  cout << tsp.traverse(tsp,"B","A") << endl;
  cout << tsp.traverse(tsp,"A","D");*/
}