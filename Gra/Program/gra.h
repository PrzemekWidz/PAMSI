#ifndef GRA_H
#define GRA_H

#include "plansza.h"
#include "komputer.h"

using namespace std;

class Gra
{
    private:
        Plansza plansza;
        Komputer GKomputer;
        int gracz;         //znacznik gracza: 1 (gracz) lub 2 (komputer)
        int stan;          //-1 wygrana komputera, 1 wygrana gracza
                           //0 - remis, 2 - gra w toku
    public:
        Gra();
        virtual ~Gra();

        void Inicjalizacja();
        void Przebieg();
        void RuchGracza();
        void ZmienGracza(){
			(gracz==1) ? gracz=2 : gracz=1;
		}
};

#endif
