#include <iostream>
#include "matrix.hh"
#include "graph.hh"
#include "list.hh"
#include "dijkstry.hh"

using namespace std;

int main()
{

matrix * newGraph = new matrix;
dijkstryMatrixAlgorithm(newGraph);
cout << endl;
delete newGraph;


    return 0;
}
