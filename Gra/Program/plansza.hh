#ifndef PLANSZA_HH
#define PLANSZA_HH

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Plansza
{
    private:

        int **plansza;
        int rozmiar;
        int rzadwygryw;
        int licznikruch;
        int ostatni[2];

    public:

        // Konstruktor
        Plansza(){

        }

        // Destruktor
        virtual ~Plansza(){
        delete [] plansza;
        plansza=NULL;
        }

        // Ładowanie planszy
        void Inicjalizacja(int r,int w);
        // Potrzebna do funkcji wyswietl
        char Znak(int i,int j);
        // Wyswietlanie planszy
        void Wyswietl();
        // Wstawinie znaku
        void UstawZnak(int i,int j,int znak);
        // Sprwdzanie zwyciezcy
	     	int SprawdzZwyciezce();

        int ZwrocRozmiar();
		    int ZwrocZnak(int i, int j);
		    int ZwrocRzadWygryw();
};

#endif
