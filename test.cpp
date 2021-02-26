// Kruskal's algorithm in C++
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
#include <vector>

using namespace std;

#define edge pair<int, int>

class Graph {
   private:
  vector<pair<double, edge> > G;  // graph
  vector<pair<double, edge> > T;  // mst
  int *parent;
  int V;  // number of vertices/nodes in graph
   public:
  Graph(int V);
  void AddWeightedEdge(int u, int v, double w);
  int find_set(int i);
  void union_set(int u, int v);
  void kruskal();
  void print();
};
Graph::Graph(int V) {
  parent = new int[V];

  //i 0 1 2 3 4 5
  //parent[i] 0 1 2 3 4 5
  for (int i = 0; i < V; i++)
    parent[i] = i;

  G.clear();
  T.clear();
}
void Graph::AddWeightedEdge(int u, int v, double w) {
  G.push_back(make_pair(w, edge(u, v)));
}
int Graph::find_set(int i) {
  // If i is the parent of itself
  if (i == parent[i])
    return i;
  else
    // Else if i is not the parent of itself
    // Then i is not the representative of his set,
    // so we recursively call Find on its parent
    return find_set(parent[i]);
}

void Graph::union_set(int u, int v) {
  parent[u] = parent[v];
}
void Graph::kruskal() {
  int i, uRep, vRep;
  sort(G.begin(), G.end());  // increasing weight
  for (i = 0; i < G.size(); i++) {
    uRep = find_set(G[i].second.first);
    vRep = find_set(G[i].second.second);
    if (uRep != vRep) {
      T.push_back(G[i]);  // add to tree
      union_set(uRep, vRep);
    }
  }
}
void Graph::print() {
  double minimumCost = 0;
  // cout << "Edge :"
  //    << " Weight" << endl;
  for (int i = 0; i < T.size(); i++) {
    // cout << T[i].second.first << " - " << T[i].second.second << " : "
    //    << T[i].first;
    // cout << endl;
    minimumCost += T[i].first;
  }
  cout << "Minimum Cost: " << minimumCost << endl;
}
// Limit to decide whether to include edges
bool limit(double num) {
    if (num != 0 && num < pow(2, -(0.6 * log(num)))) {
        return true;
    }
    return false;
};

int main(int argc, char* argv[]) {
    
  // number of vertices
  int n = atoi(argv[2]);

  // number of trials 
  int trials = atoi(argv[3]);

  // number of dimensions - 0, 2, 3, 4
  int dim = atoi(argv[4]);

  Graph g(n);

  std::random_device rd;
  std::mt19937 engine(rd());
  std::uniform_real_distribution<double> dist(0.0, 1.0);

  if (dim == 0) {
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
          double num = dist(engine);
          if (limit(num)) {
            g.AddWeightedEdge(i, j, num);
          }
      }
    }
  }
  else if (dim == 2) {
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
            g.AddWeightedEdge(i, j, num);
          }
      }
    }
  }
  else if (dim == 3) {
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
            g.AddWeightedEdge(i, j, num);
          }
      }
    }
  }
  else if (dim == 4) {
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
            g.AddWeightedEdge(i, j, num);
          }
      }
    }
  }
  else {cout << "Wrong Input" << endl;};


  g.kruskal();
  g.print();
  return 0;
}