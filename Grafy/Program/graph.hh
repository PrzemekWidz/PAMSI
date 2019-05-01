#ifndef GRAPH_HH_INCLUDED
#define GRAPH_HH_INCLUDED

class graph {

private :

    // vertexes and edges of the graph

    int vertex;
    int edge;

public :

    // definition of the constructor

    graph(){

      vertex = 0;
      edge   = 0;

           }

    // declaration of the other functions

    void loadVertexNumber ();
    void loadEdgeNumber   ();

    int  returnVertex     ();
    int  returnEdge       ();
};



#endif // GRAPH_HH_INCLUDED
