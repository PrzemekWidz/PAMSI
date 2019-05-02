#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
#include "matrix.hh"


// Definition of other functions

/* Function that loads a matrix */

void matrix::loadAdjacencyMatrix(){

   // Attribution of the variables edge and vertex

   this->loadEdgeNumber();
   this->loadVertexNumber();

   // 1.Creating a new matrix for graph edges
   // and another one for graph weights depending on
   // the number of Vertexes and Edges which we already know
   // 2.Creating a dynamic table structure which consists of tables
   // [one type int] , [second type char]

   adjacencyMatrix = new char * [returnVertex()];
   graphWeights= new int * [returnVertex()];

   for(int i=0;i<returnVertex();i++)
   {
    adjacencyMatrix[i]=new char [returnVertex()];
    graphWeights[i]=new int[returnVertex()];
   }

   // Filling zeros inside our matrix of graph and weights

   for(int i=0;i<returnVertex();i++){

          for(int j=0;j<returnVertex();j++)
            {
            adjacencyMatrix[i][j]=0;
            graphWeights[i][j]=0;
            }
                                    }
    // ...and a proper filling graph with weights and connections

   int weight;
    int v1;
     int v2;

     for(int i=0;i<returnEdge();i++)
     {
       std::cin >> v1;
       std::cin >> v2;
       std::cin >> weight;


       adjacencyMatrix[v1][v2]=1;
       graphWeights[v1][v2]=weight;

     }

}

// Function that shows our adjacencyMatrix

void matrix::showAdjacencyMatrix(){

    for(int i=0;i<returnVertex();i++)
    {
      for(int j=0;j<returnVertex();j++)
      {
          cout << setw(3) << (int)adjacencyMatrix[i][j];
      }
      cout << '\n';
    }
}

// Function that shows our graph weights between connections

void matrix::showGraphWeights(){

    for(int i=0;i<returnVertex();i++)
    {
      for(int j=0;j<returnVertex();j++)
      {
          cout << setw(3) << graphWeights[i][j];
      }
                cout << '\n';
    }
}
