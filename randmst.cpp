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

int main(int argc, char **argv) {

    cout << "There are " << argc 
         << " argument(s) entered:" << "\n"; 
  
    for (int i = 0; i < argc; ++i) 
        cout << i << ":" << argv[i] << "\n"; 

    // put something like ./randmst 12 23 34
    // need to have something after ./randmst
    
    // convert char to int
    for(int i = 1; i < argc; i++) {
        cout << atoi(argv[i]) << endl;
    }

    // number of random numbers
    int n = 5;

    // Create adjacency matrix of size n x n
    double adjMatrix[n][n];

    // TODO: Create cases per dimension

    //////////////////////////////////////////////////////////////
    // Dimension 0
    //////////////////////////////////////////////////////////////

    // Fill adjacency matrix for dim 0
    for (int i = 0; i <n; i++) {
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
    //////////////////////////////////////////////////////////////
    // Dimension 2 
    //////////////////////////////////////////////////////////////
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
                double sqdist = pow((dim2coords[i][0] - dim2coords[j][0]), 2) + pow((dim2coords[i][1] - dim2coords[j][1]), 2);
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

    //////////////////////////////////////////////////////////////

    // prints n random numbers --> for graph 1, dimension 0
    srand(static_cast<unsigned int>(clock()));
    for (int i=0; i < n; i++) {
        double x = randNum();
        cout << x << "\n";
    }
    cout << endl; 
    
    // prints n tuples of random numbers --> for graph 2
    srand(static_cast<unsigned int>(clock()));
    for (int i=0; i < n; i++) {
        double arr [2] = {randNum(), randNum()};

        cout << arr [0] << " ";
        cout << arr [1] << endl;
    }
    cout << endl;

    // TODO: generating nums for graphs 3 & 4
    srand(static_cast<unsigned int>(clock()));
    for (int i=0; i < n; i++) {

        double tpl [3] = {randNum(), randNum(), randNum()};

        cout << tpl [0] << " ";
        cout << tpl [1] << " ";
        cout << tpl [2] << endl;
    }
    cout << endl;

    // TODO: generating nums for graphs 3 & 4
    srand(static_cast<unsigned int>(clock()));
    for (int i=0; i < n; i++) {

        double tpl [4] = {randNum(), randNum(), randNum(), randNum()};

        cout << tpl [0] << " ";
        cout << tpl [1] << " ";
        cout << tpl [2] << " ";
        cout << tpl [3] << endl;
    }

    return 0;
}


