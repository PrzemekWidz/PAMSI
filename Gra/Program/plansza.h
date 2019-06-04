#ifndef PLANSZA_H
#define PLANSZA_H

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Plansza
{
    private:
        int **plansza;		
        int rozmiar;		//rozmiar planszy
        int rzadwygryw;     //dlugosc wygrywajacego rzedu
        int licznikruch;   //licznik wykonanych ruchow
        int ostatni[2];    //wspolrzedne ostatniego ruchu
    public:
        Plansza();
        virtual ~Plansza();

        void Inicjalizacja(int r,int w);
        char Znak(int i,int j);
        void Wyswietl();
        void UstawZnak(int i,int j,int znak);
		int SprawdzZwyciezce();
        int ZwrocRozmiar(){
			return rozmiar;
		}
		int ZwrocZnak(int i, int j){
			return plansza[i][j];
		};
		int ZwrocRzadWygryw(){
			return rzadwygryw;
		}
};

#endif
