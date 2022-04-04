#include <iostream>
#include <filesystem>
#include "headers/TSP.h"
#include "headers/Greedy.h"
#include "headers/Dynamic.h"
#include "headers/Strong.h"

using namespace std;
namespace fs = std::filesystem;

vector<string> getFiles(string path = "./files/") {
  vector<string> files;
  for (const auto & entry : fs::directory_iterator(path)) {
      string file = entry.path().string();
      files.push_back(file);
      cout << file << endl;
  }
  return files;
}
void createFiles(int n, string path = "./files/", int nodes = 8) {
  for (int i = 0; i < n; i++) {
  ofstream f;
  //int random = 2 + (rand() % 10);
  string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string name = path + "graph_" + to_string(i) + ".txt";
  f.open(name);
  f << nodes << endl;
  for (int i = 0; i < nodes - 1; i++) {
    for (int j = i + 1; j < nodes; j++) {
      int value = 1 + (rand() % 100);
      f << alphabet[i] << " " << alphabet[j] << " ";
      f << value << endl;
    }
  }
  f.close();
  }
}

void solveDynamic(string file, double limit = 300000.0) {
  cout << "Dynamic" << endl;
  Solution sol;
  Tsp tsp(file, new Dynamic(), limit);
  //cout << tsp;
  sol = tsp.traverse(tsp,"A","A",1);
  vector<Node> solf = sol.getSolution();
  vector<Node> nodes = tsp.getNodes();
  int ini = find(nodes.begin(), nodes.end(), Node("A")) - nodes.begin();
  Node iniNode(tsp.getNodes()[ini]);
  solf.insert(solf.begin(),iniNode);
  solf.push_back(iniNode);
  cout << "Cost: " << sol.getCost();
  if (sol.getTimeCost() != -1.0) {
    cout << " Time: " << sol.getTimeCost();
  } else {
    cout << " Time: " << "EXCESSIVE";
  }
  cout << " Size: " << nodes.size() << endl;
  for (int i = 0; i < solf.size(); i++) {
    cout << solf[i].getName() << ",";
  }
  cout << endl;
}
void solveGreedy(string file, double limit = 300000.0) {
  cout << "Greedy" << endl;
  Solution sol;
  Tsp tsp(file, new Greedy());
  sol = tsp.traverse(tsp,"A","A",1);
  vector<Node> solf = sol.getSolution();
  vector<Node> nodes = tsp.getNodes();
  int ini = find(nodes.begin(), nodes.end(), Node("A")) - nodes.begin();
  Node iniNode(tsp.getNodes()[ini]);
  solf.push_back(iniNode);
  cout << "Cost: " << sol.getCost() << " Time: " << sol.getTimeCost();
  cout << " Size: " << nodes.size() << endl;
  for (int i = 0; i < solf.size(); i++) {
    cout << solf[i].getName() << ",";
  }
  cout << endl;
}
void solveBrute(string file, double limit = 300000.0) {
  cout << "Brute" << endl;
  Solution sol;
  Tsp tsp(file, new Strong(), limit);
  //cout << tsp;
  sol = tsp.traverse(tsp,"A","A",1);
  vector<Node> solf = sol.getSolution();
  vector<Node> nodes = tsp.getNodes();
  int ini = find(nodes.begin(), nodes.end(), Node("A")) - nodes.begin();
  Node iniNode(tsp.getNodes()[ini]);
  solf.insert(solf.begin(),iniNode);
  solf.push_back(iniNode);
  cout << "Cost: " << sol.getCost();
  if (sol.getTimeCost() != -1.0) {
    cout << " Time: " << sol.getTimeCost();
  } else {
    cout << " Time: " << "EXCESSIVE";
  }
  cout << " Size: " << nodes.size() << endl;
  for (int i = 0; i < solf.size(); i++) {
    cout << solf[i].getName() << ",";
  }
  cout << endl;
}
int main(int argc, char** argv) {
   if (argc < 3) {
     cout << "Please specify the path to file and the limit in ms" << endl;
   } else {
    string path = argv[1];
    double limit = stod(argv[2]);
    string file = "test0.txt";
    createFiles(3,path);
    vector<string> files = getFiles(path);
    for (int i = 0; i < files.size(); i++) {
      file = files[i];
      cout << endl << "Solving " << file << endl;
      solveDynamic(file, limit);
      solveGreedy(file, limit);
      solveBrute(file, limit);
    }
  }
}