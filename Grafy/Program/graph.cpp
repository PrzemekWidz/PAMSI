#include <iostream>
#include "graph.hh"

// definition of other functions

int graph::returnVertex(){

   int tmp;
   tmp =vertex;

   return tmp;
}


int graph::returnEdge(){

   int tmp;
   tmp =edge;

   return tmp;
}


void graph::loadVertexNumber(){

   int tmp;
   std::cin >> tmp;
   vertex=tmp;

}

void graph::loadEdgeNumber(){

   int tmp;
   std::cin >> tmp;
   edge=tmp;

}
