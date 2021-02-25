#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <utility> 
#include <sstream>
#include <cmath>
#include <random>

using namespace std; 

// Structure to represent weighted edges
struct edge {
    int source;
    int dest;
    double weight;
};

// Structure to represent sets
struct set {
    int parent;
    int rank;
};

// Limit to decide whether to include edges
bool limit(double num) {
    if (num != 0 && num < pow(2, -(0.6 * log(num)))) {
        return true;
    }
    return false;
};

// Vector of sets
vector<set> sets;

void makeset(int x) {
    set s;
    s.parent = x;
    s.rank = 0;
    sets[x] = s;
};

int find(int x) {
    if(sets[x].parent != x) {
        sets[x].parent = find(sets[x].parent);
    }
    return sets[x].parent;
};

void unionrank (int x, int y) {
    int xroot = find(x);
    int yroot = find(y);

    if (sets[xroot].rank < sets[yroot].rank) {
        sets[xroot].parent = yroot;
    }
    else if (sets[xroot].rank > sets[yroot].rank) {
        sets[yroot].parent = xroot;
    }
    else {
        sets[yroot].parent = xroot;
        sets[xroot].rank++;
    }

};


int main(int argc, char* argv[]) {
    
    // number of vertices
    int n = atoi(argv[2]);

    // number of trials 
    int trials = atoi(argv[3]);

    // number of dimensions - 0, 2, 3, 4
    int dim = atoi(argv[4]);


    //////////////////////////////////////////////////////////////
    // Using Kruskal's
    //////////////////////////////////////////////////////////////

    // Create list of vertices
    double *vertices = new double[n];

    std::vector<edge*> edges;

    // Random numbe generator
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    // to generate a random number do dist(engine)

    // Dimension 0
    // for(i = 0; i<n; i++) {
        // vertices[i] = dist(engine);
    // }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            double num = dist(engine);
            if (limit(num)) {
                edge* e = new edge;
                e -> source = i;
                e -> dest = j;
                e -> weight = num;

                edges.push_back(e);
            }
        }
    }

    cout << "Edges size: " << edges.size() << endl;


 
    // Create V subsets with single elements
    // for (int v = 0; v < n; v++) 
    // {
        // sets[v].parent = v;
        // sets[v].rank = 0;
    // }


    //////////////////////////////////////////////////////////////
}