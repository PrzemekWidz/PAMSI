#include <iostream>
#include "matrix.hh"

using namespace std;

int main()
{

matrix * newGraph = new matrix;

newGraph->loadAdjacencyMatrix();
newGraph->showAdjacencyMatrix();
cout << endl;
newGraph->showGraphWeights();
cout << endl;

delete newGraph;

    return 0;
}
