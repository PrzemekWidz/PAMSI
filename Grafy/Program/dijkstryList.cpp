#include "dijkstry.hh"
#include <iostream>
#include <climits>
#include <fstream>
#include <ctime>

using namespace std;

/* Climits used for INT_MAX , there is no infinity value typr */
// We have to simulate Infinity value

const int MAXINT = 2147483647;

// A body of function
// of dijkstry algorithm for the matrix representation

double dijkstryListAlgorithm(list *Lista){

ifstream plik("dane.txt");

clock_t poczatek,koniec,czas_trwania;

fstream plik2;

plik2.open("wynikiList.txt",ios::out|ios::app);


	  int i,j,m,n,v,u,w,x,y,sptr,*d,*p,*S;
	  bool *QS;                       // Zbiory Q i S
	  list **graf;                 // Tablica list sąsiedztwa
	  list *pw,*rw;

	  plik >> m  >> n >> v;             // Węzeł startowy, liczba wierzchołków i krawędzi


	  // Tworzymy tablice dynamiczne

	  d = new int [n];                // Tablica kosztów dojścia
	  p = new int [n];                // Tablica poprzedników
	  QS = new bool [n];              // Zbiory Q i S
	  graf = new list * [n];       // Tablica list sąsiedztwa
	  S = new int [n];                // Stos
	  sptr = 0;                       // Wskaźnik stosu

	  // Inicjujemy tablice dynamiczne

	  for(i = 0; i < n; i++)
	  {
	    d[i] = MAXINT;
	    p[i] = -1;
	    QS[i] = false;
	    graf[i] = NULL;
	  }

	  // Odczytujemy dane wejściowe

	  for(i = 0; i < m; i++)
	  {
	    plik >> x >> y >> w;           // Odczytujemy krawędź z wagą
	    pw = new list;             // Tworzymy element listy sąsiedztwa
	    pw->v = y;                    // Wierzchołek docelowy krawędzi
	    pw->w = w;                    // Waga krawędzi
	    pw->next = graf[x];
	    graf[x] = pw;                 // Element dołączamy do listy
	  }

	  cout << endl;

	  d[v] = 0;                       // Koszt dojścia v jest zerowy

	  // Wyznaczamy ścieżki

poczatek = clock();

	  for(i = 0; i < n; i++)
	  {
	    // Szukamy wierzchołka w Q o najmniejszym koszcie d

	    for(j = 0; QS[j]; j++);
	    for(u = j++; j < n; j++)
	      if(!QS[j] && (d[j] < d[u])) u = j;

	    // Znaleziony wierzchołek przenosimy do S

	    QS[u] = true;

	    // Modyfikujemy odpowiednio wszystkich sąsiadów u, którzy są w Q

	    for(pw = graf[u]; pw; pw = pw->next)
	      if(!QS[pw->v] && (d[pw->v] > d[u] + pw->w))
	      {
	        d[pw->v] = d[u] + pw->w;
	        p[pw->v] = u;
	      }
	  }

koniec = clock();

	  // Gotowe, wyświetlamy wyniki
	plik2 << endl;

	  for(i = 0; i < n; i++)
	  {
	    plik2 << i << ": ";

	    // Ścieżkę przechodzimy od końca ku początkowi,
	    // Zapisując na stosie kolejne wierzchołki

	    for(j = i; j > -1; j = p[j]) S[sptr++] = j;

	    // Wyświetlamy ścieżkę, pobierając wierzchołki ze stosu

	    while(sptr) plik2 << S[--sptr] << " ";

	    // Na końcu ścieżki wypisujemy jej koszt

	    plik2 << "#" << d[i] << endl;
	  }

plik2.close();

czas_trwania = koniec - poczatek;
double tmp = (double)czas_trwania / CLOCKS_PER_SEC;
return tmp;

}
