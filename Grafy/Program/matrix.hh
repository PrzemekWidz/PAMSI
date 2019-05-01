#ifndef MATRIX_HH_INCLUDED
#define MATRIX_HH_INCLUDED

#include "graph.hh"

class matrix : public graph{

private :

    // matrix for our graph

    char ** adjacencyMatrix;

    // matrix for our weights

    int ** graphWeights;

public :

    // definition of constructor

    matrix(){

             adjacencyMatrix=nullptr;
             graphWeights=nullptr;

            }

    // declaration of other functions

    void loadAdjacencyMatrix();
    void showAdjacencyMatrix();
    void showGraphWeights();
};


#endif // MATRIX_HH_INCLUDED
