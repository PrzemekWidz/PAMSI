#include "list.hh"
using namespace std;
#include <iostream>

// A function that loads our graph using
// list class

void list::loadList(){

  // Attribution of the variables edge and vertex

  this->loadEdgeNumber();
  this->loadVertexNumber();

  struct listElement *mainList[returnVertex()];

  // Filling nullptr inside mainList elements

     for(int i=0;i<returnVertex();i++)
     {
      mainList[i]->nextElement=nullptr;
     }

  // Filling our graph implemented on list

     int x,y,z;

     for(int i=0;i<returnEdge();i++)
     {
       cin >> x;
       cin >> y;
       cin >> z;

       struct listElement *pointerElement;

       pointerElement = new listElement;

       pointerElement->nextElement=mainList[x-1]->nextElement;
       pointerElement->node=y;
       pointerElement->weight=z;

       mainList[x-1]->nextElement=pointerElement;

     }

     cout << endl;

     struct listElement *pointerElement;

     pointerElement = new listElement;

     for(int i=0;i<returnVertex();i++)
     {
       pointerElement=mainList[i];

       while (pointerElement) {
                  cout << pointerElement->node;
                  cout << "$" << pointerElement->weight << " ";
                  pointerElement=pointerElement->nextElement;
                               }
     }


}

// A function that shows our graph using
// list class

void list::showList(){


 }
