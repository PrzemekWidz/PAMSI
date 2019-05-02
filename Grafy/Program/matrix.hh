#ifndef MATRIX_HH_INCLUDED
#define MATRIX_HH_INCLUDED

#include "graph.hh"

class matrix : public graph{

private:

    // Matrix for our graph
    // that informs us about connection
    // or no connection between two vertexes

    char ** adjacencyMatrix;

    // Matrix for our weights

    int ** graphWeights;

public:

    // Definition of constructor

    matrix(){

             adjacencyMatrix=nullptr;
             graphWeights=nullptr;

            }

    // Declaration of other functions

    void loadAdjacencyMatrix();
    void showAdjacencyMatrix();
    void showGraphWeights();

};


#endif // MATRIX_HH_INCLUDED
