#include <iostream>
#include "matrix.hh"

using namespace std;

int main()
{

matrix * newGraph = new matrix;

newGraph->loadAdjacencyMatrix();
newGraph->showAdjacencyMatrix();
newGraph->showGraphWeights();


delete newGraph;

    return 0;
}
