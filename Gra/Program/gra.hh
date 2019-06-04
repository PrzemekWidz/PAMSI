#ifndef GRA_HH
#define GRA_HH

#include "plansza.hh"
#include "komputer.hh"

using namespace std;

class Gra
{
    private:

        Plansza plansza;
        Komputer GKomputer;
        int gracz;
        int stan;

    public:

        // Konstruktor
        Gra();
        // Destruktor
        virtual ~Gra();

        void Inicjalizacja();
        void Przebieg();
        void RuchGracza();
        void ZmienGracza()
        {
			    (gracz==1) ? gracz=2 : gracz=1;
		    }
};

#endif
