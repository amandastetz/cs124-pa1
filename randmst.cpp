#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility> 
#include <sstream>

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

    // Create adjacency matrix of size n x n for dim 0
    double adjMatrix[n][n];

    // Fill adjacency matrix for dim 0
    for (int i = 0; i <n; i++) {
        for (int j = 0; j<n; j++) {
            if (i == j) {
                adjMatrix[i][j] = 0;
            }
            else {
                double x = randNum();
                cout << x << " this is x" << endl;
                adjMatrix[i][j] = x;
                adjMatrix[j][i] = x;
            }
        }
    }

    cout << "adjacency matrix" << endl;

    // Print out adjacency matrix for dim 0
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
         cout << adjMatrix[i][j] << " ";
      }
      cout << endl;
   }

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


