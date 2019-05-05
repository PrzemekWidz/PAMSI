#include "list.hh"
#include <iostream>
using namespace std;
#include <fstream>

// Definitions of functions
// that are declared in header
// file

void list::loadListFromFile (){

ifstream plik("dane.txt");

if(plik){

int a1,a2,a3;

plik >> a1;
plik >> a2;
plik >> a3;

this->loadAtributesFromFile(a1,a2,a3);

list **graf;
list *pw;

int m = this->returnEdge();

int x , y ,z;

graf = new list * [returnVertex()];       // Tablica list sąsiedztwa

  for(int i = 0; i < returnVertex(); i++)
  {
    graf[i] = NULL;
  }

  for(int i = 0; i < m; i++)
  {
    plik >> x >> y >> w;           // Odczytujemy krawędź z wagą
    pw = new list;             // Tworzymy element listy sąsiedztwa
    pw->v = y;                    // Wierzchołek docelowy krawędzi
    pw->w = w;                    // Waga krawędzi
    pw->next = graf[x];
    graf[x] = pw;                 // Element dołączamy do listy
  }

}
}
