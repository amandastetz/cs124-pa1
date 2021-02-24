#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility> 
#include <sstream>
#include<cmath>

using namespace std; 

// Random number generator
// Will produce n random real numbers on interval [0,1]
double randNum() {
  return double(rand()) / (double(RAND_MAX) + 1.0);
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

    // number of dimensions - 0, 2, 3, 4
    int dim = atoi(argv[3]);

    // number of trials 
    int trials = atoi(argv[4]);

    // Create adjacency matrix of size n x n
    double adjMatrix[n][n];

    // TODO: Create cases per dimension

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
                        //adjMatrix[j][i] = x;
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
    return 0;
}


