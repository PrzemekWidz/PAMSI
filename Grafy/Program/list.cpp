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

   this->next= new class list [returnVertex()];
   class list *newElement;

   // Filling nullptr inside main list

   for(int i = 0; i < returnVertex(); i++)
   {
     next[i].next = NULL;
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
      newElement->next = next[x].next;
      newElement->node = y;
      newElement->weight = z;
      next[x].next = newElement;
    }
}
// Function that shows our list

void list::showList () {

class list *newElement;

  for(int i = 0; i < returnVertex(); i++)
    {
    cout << i  << ":";
    newElement = next[i].next;
    while(newElement)
    {
      cout << newElement->node << "#" << newElement->weight << " ";
      newElement = newElement->next;
    }
    cout << endl;
   }

}

// Dijkstry alrogithm dor lists

void list::dijkstryListAlgorithm(){




}
