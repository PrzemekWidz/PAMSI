#ifndef GRAPH_HH_INCLUDED
#define GRAPH_HH_INCLUDED


class graph {

private:

    // Vertexes and edges of the graph

    int vertex;
    int edge;

public:

    // Definition of the default class constructor

    graph(){

      vertex = 0;
      edge   = 0;

           }

    // Declaration of the other functions
    // that are in sourse file ["graph.cpp"]

    void loadVertexNumber ();
    void loadEdgeNumber   ();

    int  returnVertex     ();
    int  returnEdge       ();
};


#endif // GRAPH_HH_INCLUDED
