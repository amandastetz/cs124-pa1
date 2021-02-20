#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility> 
#include <tuple>

using namespace std; 


// Random number generator
// Will produce n random real numbers on interval [0,1]
double randNum() {
  return double(rand()) / (double(RAND_MAX) + 1.0);
}

int main() {

    // number of random numbers
    int n = 5;

    // prints n random numbers --> for graph 1
    srand(static_cast<unsigned int>(clock()));
    for (int i=0; i < n; i++) {
        double x = randNum();
        cout << x << "\n";
    }
    cout << endl; 
    
    // prints n tuples of random numbers --> for graph 2
    srand(static_cast<unsigned int>(clock()));
    for (int i=0; i < n; i++) {
        pair<double, double> PAIR;

        PAIR.first = randNum();
        PAIR.second = randNum();

        cout << PAIR.first << " "; 
        cout << PAIR.second << endl;
    }

    // TODO: generating nums for graphs 3 & 4
    return 0;
}


