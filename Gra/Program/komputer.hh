#ifndef KOMPUTER_HH
#define KOMPUTER_HH

#include <stdio.h>
#include <vector>
#include "plansza.hh"

using namespace std;

struct Move{

    Move() : wynik(0){};
    Move(int s) : wynik(s){}

    int w;
    int k;
    int wynik;
};

class Komputer
{
    private:

        int GKomputer;
        int Gracz;
        int glebokosc;
        int rozmiar;
        int rzadwygryw;

    public:

        // Konstruktor
        Komputer();
        // Destruktor
        virtual ~Komputer();

        // Ladowanie komputera
        void Inicjalizacja(Plansza& plansza);
        // Algorytm zwracajacy najlepszy mozliwy ruch
        Move AlphaBetaMiniMax(Plansza& plansza,int alpha,int beta,int gracz,int glebokosc,bool rek);
        // Funkcja wstawiajaca ruch komputera
        void RuchKomputera(Plansza& plansza);
};


#endif
