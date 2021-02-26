#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <utility> 
#include <sstream>
#include <cmath>
#include <stdio.h>
#include <random>
#include <algorithm>

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

bool Compare(edge *a, edge *b){
	return a -> weight < b -> weight;
}

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

    // Random number generator
    // To generate a random number do dist(engine)
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);


    if (dim == 0) {
        for (int k = 0; k<trials; k++) {

            double mst_weight = 0.0;

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

                // Step 1: Sort edges
                sort(edges.begin(), edges.end(), Compare);

                cout << "Vector After Sort:\n" << endl;

                for(int i=0; i<edges.size(); i++) {
                    cout <<"Source:  " << edges[i] -> source << endl;
                    cout <<"Dest: " << edges[i] -> dest << endl; 
                    cout <<"Weight: " << edges[i] -> weight << endl; 
                };

                // Step 2: Implement Kruskal's
                for (int i = 0; i < n; i++) {
                    makeset(i);
                }

                for (int u = 0; u < n; u++) {
                    for (int v = u; v < n; v++) {
                        if(find(u) != find(v)) {
                            // sets[]; add the edge to sets
                            mst_weight += edges[v] -> weight;
                            unionrank(find(u), find(v));
                        }
                    }
                }

                edges.clear();
        }
    }
    else if (dim == 2) {
            for (int k = 0; k<trials; k++) {
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
                            edge* e = new edge;
                            e -> source = i;
                            e -> dest = j;
                            e -> weight = num;

                            edges.push_back(e);
                        }
                    }
                }

                edges.clear();
        }
    }
    else if (dim == 3) {
        for (int k = 0; k<trials; k++) {
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
                            edge* e = new edge;
                            e -> source = i;
                            e -> dest = j;
                            e -> weight = num;

                            edges.push_back(e);
                        }
                    }
                }

                edges.clear();
        }
    }
    else if (dim == 4) {
        for (int k = 0; k<trials; k++) {
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
                            edge* e = new edge;
                            e -> source = i;
                            e -> dest = j;
                            e -> weight = num;

                            edges.push_back(e);
                        }
                    }
                }
        }

        edges.clear();
    }
    else {cout << "Incorrect number of dimensions input!\n" << endl;}
    
    cout << "Edges size: " << edges.size() << endl;
    
    
    // Sort edges
   // sort(edges.begin(), edges.end(), [](edge a, edge b){
	 //   return a.weight < b.weight;	
    // });



    // Implement Kruskal's




    //////////////////////////////////////////////////////////////
}