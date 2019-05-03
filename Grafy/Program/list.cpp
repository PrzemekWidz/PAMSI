#include "list.hh"
#include <iostream>
using namespace std;

// Definitions of functions from header file

void list::loadList(){

   // Attribution of the variables edge and vertex

   this->loadEdgeNumber();
   this->loadVertexNumber();

/* TU ZMIENILEM */
   // Wierzcholek startowy

   int tmp;
   cin >> tmp;

   this->start=tmp;

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

      //wmax = (x > wmax) ? x : wmax;
    //  wmax = (y > wmax) ? y : wmax;

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


// Inne

int list::returnStart(){

int tmp;
tmp = start;


return tmp;
}







// We have to simulate Infinity value

const int MAXINT = 2147483647;

// Typy danych

// A dijikstry algoriyhm for graph
// implemented on list

void dijkstryListAlgorithm(list *Lista){

Lista->loadList();
//Lista->showList();

  Lista->showList();

  int i,j,m,n,v,u,w,x,y,sptr,*d,*p,*S;

// Zbiory Q i S


bool *QS;

list *pw,*rw;

// definicja grafu ale jego juz mamy
// jako liste


m = Lista->returnEdge();


n = Lista->returnVertex();

// wierzcholek startowy

v = Lista->returnStart();

d = new int [n];                // Tablica kosztów dojścia
p = new int [n];                // Tablica poprzedników
QS = new bool [n];              // Zbiory Q i S      // Tablica list sąsiedztwa
S = new int [n];                // Stos
sptr = 0;


// Inicjujemy tablice dynamiczne

 for(i = 0; i < n; i++)
 {
   d[i] = MAXINT;
   p[i] = -1;
   QS[i] = false;
 }

d[v] = 0;                       // Koszt dojścia v j

// Wyznaczamy ścieżki

  for(i = 0; i < n; i++)
  {
    // Szukamy wierzchołka w Q o najmniejszym koszcie d

    for(j = 0; QS[j]; j++);
    for(u = j++; j < n; j++)
      if(!QS[j] && (d[j] < d[u])) u = j;

    // Znaleziony wierzchołek przenosimy do S

    QS[u] = true;
  }

  // Modyfikujemy odpowiednio wszystkich sąsiadów u, którzy są w Q

pw->next = Lista[u].next;
pw-> node = Lista[u].node;
pw-> weight = Lista[u].weight;

      for(pw ; pw; pw = pw->next)
        if(!QS[pw->node] && (d[pw->node] > d[u] + pw->weight))
        {
          d[pw->node] = d[u] + pw->weight;
          p[pw->node] = u;
        }

        // Gotowe, wyświetlamy wyniki

          for(i = 0; i < n; i++)
          {
            cout << i << ": ";

            // Ścieżkę przechodzimy od końca ku początkowi,
            // Zapisując na stosie kolejne wierzchołki

            for(j = i; j > -1; j = p[j]) S[sptr++] = j;

            // Wyświetlamy ścieżkę, pobierając wierzchołki ze stosu

            while(sptr) cout << S[--sptr] << " ";

            // Na końcu ścieżki wypisujemy jej koszt
            cout << "$" << d[i] << endl;


}
  }
