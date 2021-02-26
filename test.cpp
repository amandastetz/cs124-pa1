#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <utility> 
#include <sstream>
#include <cmath>
#include <stdio.h>
#include <random>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
#define edge pair<int, int>

class Graph {
  public:
  int *parent;
  int V; // Vertices in graph
  Graph(int V);
  void addEdge(int u, int v, double w);
  void unionTake(int u, int v);
  void kruskal();
  int setSearch(int i);
  double calcWeight();
  vector<pair<double, edge> > G;  // Complete Graph
  vector<pair<double, edge> > MST;  // MST
};

Graph::Graph(int V) {
  parent = new int[V];
  for (int i = 0; i < V; i++){
    parent[i] = i;
  }
  G.clear();
  MST.clear();
}

void Graph::addEdge(int u, int v, double w) {
  G.push_back(make_pair(w, edge(u, v)));
}

void Graph::unionTake(int u, int v) {
  parent[u] = parent[v];
}

void Graph::kruskal() {
  int i, comp1, comp2;

  // Sort graph in order from least to greatest edge weight
  sort(G.begin(), G.end());

  for (i = 0; i < G.size(); i++) {
    comp1 = setSearch(G[i].second.first);
    comp2 = setSearch(G[i].second.second);
    if (comp1 != comp2) {
      // Add vertex to tree
      MST.push_back(G[i]);
      unionTake(comp1, comp2);
    }
  }
}

int Graph::setSearch(int i) {
  // Check parentage of i
  if (i == parent[i])
    return i;
  else
    return setSearch(parent[i]);
}

double Graph::calcWeight() {
  double minimumCost = 0;
  for (int i = 0; i < MST.size(); i++) {
    minimumCost += MST[i].first;
  }
  return minimumCost;
}

// Limit to decide whether to include edges
bool limit(double num) {
    if (num != 0 && num < pow(2, -(0.6 * log(num)))) {
        return true;
    }
    return false;
};

int main(int argc, char* argv[]) {
    
  // Number of vertices
  int n = atoi(argv[2]);

  // Number of trials 
  int trials = atoi(argv[3]);

  // Number of dimensions - 0, 2, 3, 4
  int dim = atoi(argv[4]);

  // Generate graph with n vertices
  Graph g(n);

  // Hold MST weights
  std::vector< double > arr;

  // Generate random double between 0 and 1
  std::random_device rd;
  std::mt19937 engine(rd());
  std::uniform_real_distribution<double> dist(0.0, 1.0);

  // Dimension 0
  if (dim == 0) {
    for (int k = 0; k < trials; k++) {
        for (int i = 0; i < n; i++) {
          for (int j = i+1; j < n; j++) {
              double num = dist(engine);
              if (limit(num)) {
                g.addEdge(i, j, num);
              }
          }
        }
      g.kruskal();
      }
      double weight = g.calcWeight();
      arr.push_back(weight);
      double sum = accumulate(arr.begin(), arr.end(), 0.0);
      double avg = sum / arr.size();
      cout << avg << " " << n << " " << trials << " " << dim << endl;
  }
  // Dimension 2
  else if (dim == 2) {
    for (int k = 0; k < trials; k++) {
    double dim2coords[n][2];
          for (int i=0; i < n; i++) {
              dim2coords[i][0] = dist(engine);
              dim2coords[i][1] = dist(engine);
          }
      for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            double sqdist = pow((dim2coords[i][0] - dim2coords[j][0]), 2) + 
                            pow((dim2coords[i][1] - dim2coords[j][1]), 2);
            double num = sqrt(sqdist);
            if (limit(num)) {
              g.addEdge(i, j, num);
            }
        }
      }
    g.kruskal();
    }
    double weight = g.calcWeight();
    arr.push_back(weight);
    double sum = accumulate(arr.begin(), arr.end(), 0.0);
    double avg = sum / arr.size();
    cout << avg << " " << n << " " << trials << " " << dim << endl;
  }
  // Dimension 3
  else if (dim == 3) {
    for (int k = 0; k < trials; k++) {
      double dim3coords[n][3];
        for (int i=0; i < n; i++) {
          dim3coords[i][0] = dist(engine);
          dim3coords[i][1] = dist(engine);
          dim3coords[i][2] = dist(engine);
        }
      for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            double sqdist = pow((dim3coords[i][0] - dim3coords[j][0]), 2) + 
                            pow((dim3coords[i][1] - dim3coords[j][1]), 2) +
                            pow((dim3coords[i][2] - dim3coords[j][2]), 2);
            double num = sqrt(sqdist);
            if (limit(num)) {
              g.addEdge(i, j, num);
            }
        }
      }
    g.kruskal();
    }
    double weight = g.calcWeight();
    arr.push_back(weight);
    double sum = accumulate(arr.begin(), arr.end(), 0.0);
    double avg = sum / arr.size();
    cout << avg << " " << n << " " << trials << " " << dim << endl;
  }
  // Dimension 4
  else if (dim == 4) {
    for (int k = 0; k < trials; k++) {
      double dim4coords[n][4];
        for (int i=0; i < n; i++) {
          dim4coords[i][0] = dist(engine);
          dim4coords[i][1] = dist(engine);
          dim4coords[i][2] = dist(engine);
          dim4coords[i][3] = dist(engine);
        }
      for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            double sqdist = pow((dim4coords[i][0] - dim4coords[j][0]), 2) + 
                            pow((dim4coords[i][1] - dim4coords[j][1]), 2) +
                            pow((dim4coords[i][2] - dim4coords[j][2]), 2) +
                            pow((dim4coords[i][3] - dim4coords[j][3]), 2);
            double num = sqrt(sqdist);
            if (limit(num)) {
              g.addEdge(i, j, num);
            }
        }
      }
    g.kruskal();
  }
    double weight = g.calcWeight();
    arr.push_back(weight);
    double sum = accumulate(arr.begin(), arr.end(), 0.0);
    double avg = sum / arr.size();
    cout << avg << " " << n << " " << trials << " " << dim << endl;
  }
  // Error Message
  else {cout << "Please input 0, 2, 3 or 4 as the dimension." << endl;};

  return 0;
}