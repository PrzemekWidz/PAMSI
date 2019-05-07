#ifndef DIJKSTRY_HH_INCLUDED
#define DIJKSTRY_HH_INCLUDED

#include "list.hh"
#include "matrix.hh"

// Declarations of djkstryAlgorithm for
// class list and class matrix

/* FUNCTIONS FOR CLASS MATRIX */

int minimumDist(int dist[], bool Dset[],int vertex);

double dijkstryMatrixAlgorithm(matrix *newGraph);

/* FUNCTIONS FOR CLASS LIST */

double dijkstryListAlgorithm(list *Lista);


#endif // DIJIKSTRY_HH_INCLUDED
