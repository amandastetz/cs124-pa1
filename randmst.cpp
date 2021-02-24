#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <utility> 
#include <sstream>
#include <cmath>

using namespace std; 
#define INF 9999999

// #define V n

// Random number generator
// Will produce n random real numbers on interval [0,1]

double randNum() {
return double(rand()) / (double(RAND_MAX) + 1.0);
}

// A utility function to find the vertex with  
// minimum key value, from the set of vertices  
// not yet included in MST  
int minKey(double key[], bool mstSet[], int n) 
{  
    // Initialize min value  
    double min = INT_MAX, min_index;  
  
    for (int v = 0; v < n; v++)  
        if (mstSet[v] == false && key[v] < min)  
            min = key[v], min_index = v;  
  
    return min_index;  
}  

int main(int argc, char* argv[]) {

    cout << "There are " << argc 
         << " argument(s) entered:" << "\n"; 

    for (int i = 0; i < argc; ++i) 
        cout << i << ":" << argv[i] << "\n"; 

    // put something like ./randmst 12 23 34
    // need to have something after ./randmst
    
    // number of vertices
    int n = atoi(argv[2]);

    // number of trials 
    int trials = atoi(argv[3]);

    // number of dimensions - 0, 2, 3, 4
    int dim = atoi(argv[4]);

    // Create adjacency matrix of size n x n
    double adjMatrix[n][n];

    srand(static_cast<unsigned int>(clock()));

    if (dim == 0) {
        //////////////////////////////////////////////////////////////
        // Dimension 0
        //////////////////////////////////////////////////////////////
        for (int k = 0; k<trials; k++) {
        // Fill adjacency matrix for dim 0
            for (int i = 0; i<n; i++) {
                for (int j = 0; j<n; j++) {
                    if (i == j) {
                        // Fill diagonal values with 0
                        adjMatrix[i][j] = 0;
                    }
                    else {
                        // Generate random value as 
                        // edge weight between i and j
                        double x = randNum();
                        adjMatrix[i][j] = x;
                        if (adjMatrix[i][j] == x){
                            adjMatrix[j][i] = x;
                        };
                    }
                }
            }

            // Print out adjacency matrix for dim 0
            cout << "adjacency matrix" << endl;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    cout << adjMatrix[i][j] << " ";
                }
                cout << endl;
            } 
            cout << " " << endl;
        }  
    }
    else if (dim == 2) {

        //////////////////////////////////////////////////////////////
        // Dimension 2 
        //////////////////////////////////////////////////////////////
        for (int k = 0; k<trials; k++) {
            cout << " entering dim 2" << endl;
            // Create coordinates for the n vertices
            // Array holding coordinates in dim 2
            double dim2coords[n][2];
            for (int i=0; i < n; i++) {
                dim2coords[i][0] = randNum();
                dim2coords[i][1] = randNum();
                cout << dim2coords[i][0] << " ";
                cout << dim2coords[i][1] << endl;
            }

            // Adjacency matrix for dim 2
            for (int i = 0; i <n; i++) {
                for (int j = 0; j<n; j++) {
                    if (i == j) {
                        adjMatrix[i][j] = 0;
                    }
                    else {
                        double sqdist = pow((dim2coords[i][0] - dim2coords[j][0]), 2) + 
                                        pow((dim2coords[i][1] - dim2coords[j][1]), 2);
                        double dist = sqrt(sqdist);
                        adjMatrix[i][j] = dist;
                        if (adjMatrix[i][j] == dist){
                            adjMatrix[j][i] = dist;
                        };
                        // adjMatrix[j][i] = x;
                    }
                }
            }
            // Print out adjacency matrix for dim 2
            cout << "adjacency matrix dim 2" << endl;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    cout << adjMatrix[i][j] << " ";
                }
                cout << endl;
            }
            cout << " " << endl;
        }
    }
    else if (dim == 3) {

        //////////////////////////////////////////////////////////////
        // Dimension 3
        //////////////////////////////////////////////////////////////
        for (int k = 0; k<trials; k++) {
            cout << " entering dim 3" << endl;
            // Create coordinates for the n vertices
            // Array holding coordinates in dim 3
            double dim3coords[n][3];
            for (int i=0; i < n; i++) {
                dim3coords[i][0] = randNum();
                dim3coords[i][1] = randNum();
                dim3coords[i][2] = randNum();
                cout << dim3coords[i][0] << " ";
                cout << dim3coords[i][1] << " ";
                cout << dim3coords[i][2] << endl;
            }

            // Adjacency matrix for dim 3
            for (int i = 0; i <n; i++) {
                for (int j = 0; j<n; j++) {
                    if (i == j) {
                        adjMatrix[i][j] = 0;
                    }
                    else {
                        double sqdist = pow((dim3coords[i][0] - dim3coords[j][0]), 2) + 
                                        pow((dim3coords[i][1] - dim3coords[j][1]), 2) + 
                                        pow((dim3coords[i][2] - dim3coords[j][2]), 2);
                        double dist = sqrt(sqdist);
                        adjMatrix[i][j] = dist;
                        if (adjMatrix[i][j] == dist){
                            adjMatrix[j][i] = dist;
                        };
                    }
                }
            }

            // Print out adjacency matrix for dim 3
            cout << "adjacency matrix dim 3" << endl;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    cout << adjMatrix[i][j] << " ";
                }
                cout << endl;
            }
            cout << " " << endl;
        }
    }
    else if (dim == 4) {
        //////////////////////////////////////////////////////////////
        // Dimension 4
        //////////////////////////////////////////////////////////////
        for (int k = 0; k<trials; k++) {
            cout << " entering dim 4" << endl;
            // Create coordinates for the n vertices
            // Array holding coordinates in dim 3
            double dim4coords[n][4];
            for (int i=0; i < n; i++) {
                dim4coords[i][0] = randNum();
                dim4coords[i][1] = randNum();
                dim4coords[i][2] = randNum();
                dim4coords[i][3] = randNum();
                cout << dim4coords[i][0] << " ";
                cout << dim4coords[i][1] << " ";
                cout << dim4coords[i][2] << " ";
                cout << dim4coords[i][3] << endl;
            }

            // Adjacency matrix for dim 2
            for (int i = 0; i <n; i++) {
                for (int j = 0; j<n; j++) {
                    if (i == j) {
                        adjMatrix[i][j] = 0;
                    }
                    else {
                        double sqdist = pow((dim4coords[i][0] - dim4coords[j][0]), 2) + 
                                        pow((dim4coords[i][1] - dim4coords[j][1]), 2) + 
                                        pow((dim4coords[i][2] - dim4coords[j][2]), 2) +
                                        pow((dim4coords[i][3] - dim4coords[j][3]), 2);
                        double dist = sqrt(sqdist);
                        adjMatrix[i][j] = dist;
                        if (adjMatrix[i][j] == dist){
                            adjMatrix[j][i] = dist;
                        };
                    }
                }
            }

            // Print out adjacency matrix for dim 4
            cout << "adjacency matrix dim 4" << endl;
            for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << " " << endl;
        }
    }
    else {cout << "Incorrect number of dimensions inputted!\n" << endl;}

    ///////////////////////////////////
    // G4G Prim's algorithm
    ///////////////////////////////////

    // Array to store constructed MST  
    int parent[n];  
      
    // Key values used to pick minimum weight edge in cut  
    double key[n];  
      
    // To represent set of vertices included in MST  
    bool mstSet[n];  
  
    // Initialize all keys as INFINITE  
    for (int i = 0; i < n; i++)  
        key[i] = INT_MAX, mstSet[i] = false;  
  
    // Always include first 1st vertex in MST.  
    // Make key 0 so that this vertex is picked as first vertex.  
    key[0] = 0;  
    parent[0] = -1; // First node is always root of MST  
  
    // The MST will have n vertices  
    for (int count = 0; count < n - 1; count++) 
    {  
        // Pick the minimum key vertex from the  
        // set of vertices not yet included in MST  
        int u = minKey(key, mstSet, n);  
        cout<<u<< endl;

        for (int i = 0; i < n; i++) 
        cout<<key[i]<< endl;
  
        // Add the picked vertex to the MST Set  
        mstSet[u] = true;  
  
        // Update key value and parent index of  
        // the adjacent vertices of the picked vertex.  
        // Consider only those vertices which are not  
        // yet included in MST  
        for (int v = 0; v < n; v++)  
  
            // graph[u][v] is non zero only for adjacent vertices of m  
            // mstSet[v] is false for vertices not yet included in MST  
            // Update the key only if graph[u][v] is smaller than key[v]  
            if (adjMatrix[u][v] && mstSet[v] == false && adjMatrix[u][v] < key[v])  {
                parent[v] = u, key[v] = adjMatrix[u][v];  
            }
                
    }  
  
    // print the constructed MST  
    cout<<"Edge \tWeight\n";   
    for (int i = 1; i < n; i++)  {
        cout<<parent[i]<<" - "<<i<<" \t"<<adjMatrix[i][parent[i]]<<" \n"; 
    }
    cout << " Key :" << endl;
    for (int i = 1; i < n; i++)  {
        cout<<key[i] << " ";
    }

    cout << endl;

    return 0;
}
