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

int main(int argc, char** argv) {

    cout << "There are " << argc 
         << " argument(s) entered:" << "\n"; 
  
    for (int i = 0; i < argc; ++i) 
        cout << i << ":" << argv[i] << "\n"; 

    // put something like ./randmst 12 23 34
    // need to have something after ./randmst
    char* num1 = argv[1];
    
    cout << num1 << "\n";


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
    srand(static_cast<unsigned int>(clock()));
    for (int i=0; i < n; i++) {
        //tuple<double, double, double> tpl;
        
        //tuple<int,char> fifth (10,'a');  

        //auto tpl = make_tuple(5.5, 10.0, 15.5); 

        //get<0>(tpl) = randNum();
        //get<1>(tpl) = randNum();
        //get<2>(tpl) = randNum();


        //cout << get<0>(tpl) << " ";
        //cout << get<1>(tpl) << " "; 
        //cout << get<2>(tpl) << endl; 

        int tpl [3] = {randNum(), randNum(), randNum()};

        //tpl [0] = randNum();
        //tpl [1] = randNum();
        //tpl [2] = randNum();

        cout << tpl [0] << " ";
        cout << tpl [1] << " ";
        cout << tpl [2] << endl;
    }

    return 0;
}


