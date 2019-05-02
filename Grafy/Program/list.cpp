#include "list.hh"
#include <iostream>
using namespace std;

// Definitions of functions from header file

void list::loadList(){

   // Attribution of the variables edge and vertex

   this->loadEdgeNumber();
   this->loadVertexNumber();

   // Variables that we need to remember
   // first and second vertex and weight
   // between them

   int wmax,x,y,z;

   // Two pointers type "list"
   // one for main list , second for
   // adding new elements

   class list *L[returnVertex()],*newElement;

   // Filling nullptr inside main list

   for(int i = 0; i < returnVertex(); i++)
   {
     L[i] = NULL;
   }

   wmax = 0;

  // A proper main list filling in one loop

    for(int i = 0; i < returnEdge(); i++)
    {
      // Reading an edge and weight
      cin >> x >> y >> z;

      wmax = (x > wmax) ? x : wmax;
      wmax = (y > wmax) ? y : wmax;

      newElement = new list;
      newElement->next = L[x];
      newElement->node = y;
      newElement->weight = z;
      L[x] = newElement;
    }


  for(int i = 0; i < returnVertex(); i++)
  {
    cout << i  << ":";
    newElement = L[i];
    while(newElement)
    {
      cout << newElement->node << "#" << newElement->weight << " ";
      newElement = newElement->next;
    }
    cout << endl;
  }

}
