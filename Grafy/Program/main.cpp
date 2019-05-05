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


list *newList = new list;

dijkstryListAlgorithm(newList);

delete newList;

    return 0;
}

/*
0 6 9
0 1 3
0 4 3
1 2 1
2 3 3
2 5 1
3 1 3
3 5 2
5 0 6
5 3 1 */
