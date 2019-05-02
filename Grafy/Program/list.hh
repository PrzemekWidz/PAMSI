#ifndef LIST_HH_INCLUDED
#define LIST_HH_INCLUDED

#include "graph.hh"

// A structure listElement that will have
// information about nodes and weights
// in our graph

   struct listElement {

   struct listElement *nextElement; // Pointer
   // for the  next elements in our list
   int node;     // Number of node
   int weight;   // The walue of weight

   };

// Class list that will use element type
// listElement [look up] in some areas

class list : public graph{

private :

/* A pointers that will allow us to implement
   a graph on list  and add next  elements     */

  // struct listElement *mainList;

struct listElement *L,*p;

public :

// Constructor of our class

   /*list()
   {
     mainList->node=0;
     mainList->weight=0;
     mainList->nextElement = nullptr;
   }*/

// Declaration of other functions

   void loadList ();
   void showList ();

};


#endif // LIST_HH_INCLUDED
