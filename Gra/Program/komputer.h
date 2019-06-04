#ifndef KOMPUTER_H
#define KOMPUTER_H

#include <stdio.h>
#include <vector>
#include "plansza.h"

using namespace std;

struct Move{
    Move() : wynik(0){};
    Move(int s) : wynik(s){}
    int w;				//wiersz
    int k;				//kolumna
    int wynik;			//ocena ruchu
};

class Komputer
{
    private:
        int GKomputer;               //identyfikator dla komputera (-1)
        int Gracz;					 //identyfikator dla gracza (1)
        int glebokosc;               //glebokosc rekurencji algorytmu minimax
        int rozmiar;                 //rozmiar planszy
        int rzadwygryw;              //dlugosc wygrywajacego rzedu

    public:
        Komputer();
        virtual ~Komputer();

        void Inicjalizacja(Plansza& plansza);
        Move AlphaBetaMiniMax(Plansza& plansza,int alpha,int beta,int gracz,int glebokosc,bool rek);
        void RuchKomputera(Plansza& plansza);
};


#endif 
