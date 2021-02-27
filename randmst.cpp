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

// Define class Edges
class Edges {
  public:
  int *parent; // Parent vertex value
  int V; // Vertices in graph
  Edges(int V); // Graph
  void addEdge(int u, int v, double w); // Add a vertex edge pair to the graph
  void unionTake(int u, int v); // Take the union of two sets
  void kruskalAlg(); // Run Kruskal's Alg
  int setSearch(int i); // Look up parents of a vertex
  double calcWeight(); // Calculate total weight of MST
  vector<pair<double, edge> > G;  // Complete Graph
  vector<pair<double, edge> > MST;  // MST
};

// Add a vertex edge pair to the graph
void Edges::addEdge(int u, int v, double d) {
  G.push_back(make_pair(d, edge(u, v)));
}

// Take the union of two sets
void Edges::unionTake(int u, int v) {
  parent[u] = parent[v];
}

// Run Kruskal's Alg
void Edges::kruskalAlg() {
  // Sort graph in order from least to greatest edge weight
  sort(G.begin(), G.end());

  for (int i = 0; i < G.size(); i++) {
    // Check parentage of the vertices
    int comp1 = setSearch(G[i].second.first);
    int comp2 = setSearch(G[i].second.second);
    if (comp1 != comp2) {
      // Add vertex to tree
      MST.push_back(G[i]);
      unionTake(comp1, comp2);
    }
  }
}

// Look up parents of a vertex
int Edges::setSearch(int i) {
  // Check parentage of i
  if (i == parent[i])
    return i;
  else
    return setSearch(parent[i]);
}

// Calculate total weight of MST
double Edges::calcWeight() {
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

// Set up graph
Edges::Edges(int V) {
  parent = new int[V];
  for (int i = 0; i < V; i++){
    parent[i] = i;
  }
  MST.clear();
  G.clear();
}

int main(int argc, char* argv[]) {
    
  // Number of vertices
  int n = atoi(argv[2]);

  // Number of trials 
  int trials = atoi(argv[3]);

  // Number of dimensions - 0, 2, 3, 4
  int dim = atoi(argv[4]);

  // Generate graph with n vertices
  Edges g(n);

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
        g.kruskalAlg();
        double weight = g.calcWeight();
        arr.push_back(weight);
      }
      // Calculate average MST weight
      double sum = accumulate(arr.begin(), arr.end(), 0.0);
      double avg = sum / arr.size();
      // Print average, numpoints, numtrials, dimension
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
      g.kruskalAlg();
      double weight = g.calcWeight();
      arr.push_back(weight);
    }
    // Calculate average MST weight
    double sum = accumulate(arr.begin(), arr.end(), 0.0);
    double avg = sum / arr.size();
    // Print average, numpoints, numtrials, dimension
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
      g.kruskalAlg();
      double weight = g.calcWeight();
      arr.push_back(weight);
    }
    // Calculate average MST weight
    double sum = accumulate(arr.begin(), arr.end(), 0.0);
    double avg = sum / arr.size();
    // Print average, numpoints, numtrials, dimension
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
      g.kruskalAlg();
      double weight = g.calcWeight();
      arr.push_back(weight);
    }
    // Calculate average MST weight
    double sum = accumulate(arr.begin(), arr.end(), 0.0);
    double avg = sum / arr.size();
    // Print average, numpoints, numtrials, dimension
    cout << avg << " " << n << " " << trials << " " << dim << endl;
  }
  // Error Message
  else {cout << "Please input 0, 2, 3 or 4 as the dimension." << endl;};
  return 0;
}