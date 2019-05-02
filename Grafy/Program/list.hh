#ifndef LIST_HH_INCLUDED
#define LIST_HH_INCLUDED

#include "graph.hh"

class list : public graph{

private:

// Number of vertex

  int node;

// Value of connection between two vertices

  int weight;

// A pointer we need to add next connections
// between vertices

  class list * next;

public:

// Declaration of functions that are
// in list source file

   void loadList ();

};

#endif // LIST_HH_INCLUDED
