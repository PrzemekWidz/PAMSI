#ifndef GRAPH_HH_INCLUDED
#define GRAPH_HH_INCLUDED

class graph {

private :

    // vertexes and edges of the graph

    int vertex;
    int edge;

public :

    // constructor

    graph();

    // declaration of other functions
    void loadVertexNumber ();
    void loadEdgeNumber   ();

    int  returnVertex     ();
    int  returnEdge       ();
};

// definition of constructor

graph::graph(){

  vertex = 0;
  edge   = 0;

}

// definition of other functions

int graph::returnVertex(){

   int tmp;
   tmp =vertex;

   return tmp;
};


int graph::returnEdge(){

   int tmp;
   tmp =edge;

   return tmp;
};


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

#endif // GRAPH_HH_INCLUDED
