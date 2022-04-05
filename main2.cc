#include <iostream>
#include <filesystem>
#include <iomanip>
#include "headers/TSP.h"
#include "headers/Greedy.h"
#include "headers/Dynamic.h"
#include "headers/Strong.h"

using namespace std;
namespace fs = std::filesystem;

/**
 * @brief Get the Files object from 
 * the given path 
 * @param path path to files
 * @return vector<string> files path
 */
vector<string> getFiles(string path = "./files/") {
  vector<string> files;
  for (const auto & entry : fs::directory_iterator(path)) {
      string file = entry.path().string();
      files.push_back(file);
      cout << file << endl;
  }
  return files;
}

/**
 * @brief Create a Files object with a tsp valid format
 * 
 * @param n number of instance
 * @param path path to store files
 * @param nodes number of nodes for graph
 */
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

/**
 * @brief for every file solve its tsp
 * using dynamic programming
 * @param file graph to be resolved
 * @param limit time limit 
 */
/**
 * @brief for every file solve its tsp
 * using dynamic programming
 * @param file graph to be resolved
 * @param limit time limit 
 */
Solution solveDynamic(string file, double limit = 300000.0) {
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
  sol.setTotal(tsp.getTotal());
  return sol;
}

/**
 * @brief for every file solve its tsp
 * using greedy programming
 * @param file graph to be resolved
 * @param limit time limit
 */
Solution solveGreedy(string file, double limit = 300000.0) {
  cout << "Greedy" << endl;
  Solution sol;
  Tsp tsp(file, new Greedy());
  sol = tsp.traverse(tsp,"A","A",1);
  vector<Node> solf = sol.getSolution();
  vector<Node> nodes = tsp.getNodes();
  int ini = find(nodes.begin(), nodes.end(), Node("A")) - nodes.begin();
  Node iniNode(tsp.getNodes()[ini]);
  solf.push_back(iniNode);
  return sol;
}

/**
 * @brief for every file solve its tsp
 * using brute force programming
 * @param file graph to be resolved
 * @param limit time limit
 */
Solution solveBrute(string file, double limit = 300000.0) {
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
  return sol;
}
int main(int argc, char** argv) {
   if (argc < 3) {
     cout << "Please specify the path to file and the limit in ms" << endl;
   } else {
    string path = argv[1];
    double limit = stod(argv[2]);
    string file = "test0.txt";
    int instances = 3;
    int total = 8;
    createFiles(instances,path);
    vector<int> cost(3);
    vector<vector<int>> costs;
    vector<string> files = getFiles(path);
    for (int i = 0; i < files.size(); i++) {
      int costg = 0;
      int costb = 0;
      file = files[i];
      //cout << endl << "Solving " << file << endl;
      Solution d,g,b;
      int costd = 0;
      d = solveDynamic(file, limit);
      g = solveGreedy(file, limit);
      b = solveBrute(file, limit);
      if (d.getTimeCost() == -1.0) {
        costd += 600000;
      } else {
        costd += d.getTimeCost();
      }
      if (b.getTimeCost() == -1.0) {
        costb += 600000;
      } else {
        costb += b.getTimeCost();
      }
      costg += g.getTimeCost();
      cost[0] = costd;
      cost[1] = costg;
      cost[2] = costb;
    }
    cout << "  " << "Dynamic " << "Greedy" << " Strong" << endl;
    cout << total << setw(4) << cost[0]/instances << setw(8)<< cost[1]/instances << setw(6)<< cost[2]/instances;
  }
}