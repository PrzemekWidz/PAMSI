#include "komputer.hh"

using namespace std;

// Konstruktor
Komputer::Komputer(){ }
// Destruktor
Komputer::~Komputer(){ }

/*Funkcja inicjalizuje gracza komputer.*/

void Komputer::Inicjalizacja(Plansza& plansza){

    GKomputer=-1;
    Gracz=1;
    glebokosc=0;

    rozmiar=plansza.ZwrocRozmiar();
    rzadwygryw=plansza.ZwrocRzadWygryw();
}


/* Funkcja dla algorytmu minimax z cieciami alfa i beta oraz ocena uwzgledniajaca ilosc ruchu
    do zamierzonego rezultatu oraz ocena wybranego pola.*/

Move Komputer::AlphaBetaMiniMax(Plansza& plansza,int alpha,int beta,int gracz,int glebokosc,bool rek){

    int najwynik;
    int iterator=0;

    int wynik=plansza.SprawdzZwyciezce();
    Move ruch;
    vector<Move> ruchy;

    if (rek) glebokosc++;

    if(wynik!=2)
		return (wynik==-1) ? Move(wynik*(-1000)-20*glebokosc) : Move(wynik*(-1000)+20*glebokosc);

    else if(gracz==GKomputer)
    {
        najwynik=alpha;

        for(int i=0;i<plansza.ZwrocRozmiar();i++)
        {
            for(int j=0;j<plansza.ZwrocRozmiar();j++)
            {
                if(plansza.ZwrocZnak(i,j)==0)
                {
                    plansza.UstawZnak(i,j,gracz);

                    ruch.wynik = AlphaBetaMiniMax(plansza,najwynik,beta,Gracz,glebokosc,1).wynik;
                    ruch.w=i;
                    ruch.k=j;
                    ruchy.push_back(ruch);
                    plansza.UstawZnak(i,j,0);

                    if(ruch.wynik>najwynik) najwynik=ruch.wynik;
                    if(beta<=najwynik) i=j=plansza.ZwrocRozmiar();
                }
            }
        }

        najwynik=-10000;

        for(int i=0;i<(int)ruchy.size();i++)
        {
            if(ruchy[i].wynik>najwynik)
            {
                iterator=i;
                najwynik=ruchy[i].wynik;
            }
        }
    }

    else{

        najwynik=beta;

        for(int i=0;i<plansza.ZwrocRozmiar();i++)
        {
            for(int j=0;j<plansza.ZwrocRozmiar();j++)
            {
                if(plansza.ZwrocZnak(i,j)==0)
                {
                    plansza.UstawZnak(i,j,gracz);
                    ruch.wynik = AlphaBetaMiniMax(plansza,alpha,najwynik,GKomputer,glebokosc,1).wynik;
                    ruch.w=i;
                    ruch.k=j;
                    ruchy.push_back(ruch);
                    plansza.UstawZnak(i,j,0);

                    if(ruch.wynik<najwynik) najwynik=ruch.wynik;

                    if(alpha>=najwynik) i=j=plansza.ZwrocRozmiar();
                }
            }
        }

        najwynik=10000;

        for(int i=0;i<(int)ruchy.size();i++)
        {
            if(ruchy[i].wynik<najwynik)
            {
                iterator=i;
                najwynik=ruchy[i].wynik;
            }
        }
    }
    return ruchy[iterator];
}

/* Funkcja obslugujaca ruch komputera*/

void Komputer::RuchKomputera(Plansza& plansza){

	Move najlepszy;
	najlepszy=AlphaBetaMiniMax(plansza,-10000,10000,GKomputer,0,0);

    plansza.UstawZnak(najlepszy.w,najlepszy.k,GKomputer);
}
