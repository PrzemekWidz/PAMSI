#include "komputer.h"

using namespace std;

Komputer::Komputer(){
}
Komputer::~Komputer(){
}
/*Funkcja inicjalizuje gracza komputer.
Wczytuje rozmiar i wygrywajacy rzad.
*/
void Komputer::Inicjalizacja(Plansza& plansza){
    GKomputer=-1;
    Gracz=1;
    glebokosc=0;
    rozmiar=plansza.ZwrocRozmiar();
    rzadwygryw=plansza.ZwrocRzadWygryw();
}


/* Funkcja dla algorytmu minimax z ci�ciami alfa i beta oraz ocen� uwzgl�dniaj�c� ilo�� ruchu
    do zamierzonego rezultatu oraz ocen� wybranego pola.
    Jezeli ruch konczy si� wygrana ktoregos z graczy lub remisem to zwracany jest ruch
    z ocena 1000-punkty za glebokosc dla zwyciestwa komputera i -1000+punkty za glebokosc
    dla zwyciestwa czlowieka.
    Jezeli ruch nie konczy gry to wykonywany jest kolejny ruch i rekurencyjnie wywolywana jest
    ta sama funkcja, tym razem dla drugiego gracza. Po zebraniu kazdego mozliwego ruchu wraz z ich
    ocenami (do oceny ruchu doliczana jest takze ocena wstepna dla wybranego pola) wybierany jest
    ten najkorzystniejszy: Z najnizsza ocena w przypadku ruchu czlowieka i z najwyzsza w przypadku
    ruchu komputera.
    Ciecia alfa i beta pozwalaja ominac symulowania kolejnych ruchow gdy nie maja one wplywu na wybor.
    Dla komputera: Po przeszukaniu jednej ze sciezek, pomija si� przeszukiwanie czesci kolejnej sciezki
    jezeli wiadomo jest ze przeciwnik wybierze w niej ruch dla nas najbardziej niekorzystny, ktory jest
    oceniany slabiej od poprzednio znalezionego. Dla przeciwnika ciecia dzialaja analogicznie.

*/
Move Komputer::AlphaBetaMiniMax(Plansza& plansza,int alpha,int beta,int gracz,int glebokosc,bool rek){
    int i,j,najwynik;
    int iterator=0;
    int wynik=plansza.SprawdzZwyciezce();
    Move ruch;
    vector<Move> ruchy;

    if (rek)
		glebokosc++;
    if(wynik!=2)
		return (wynik==-1) ? Move(wynik*(-1000)-20*glebokosc) : Move(wynik*(-1000)+20*glebokosc);

    else if(gracz==GKomputer){
        najwynik=alpha;
        for(i=0;i<plansza.ZwrocRozmiar();i++){
            for(j=0;j<plansza.ZwrocRozmiar();j++){
                if(plansza.ZwrocZnak(i,j)==0){
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
        for(i=0;i<(int)ruchy.size();i++){
            if(ruchy[i].wynik>najwynik){
                iterator=i;
                najwynik=ruchy[i].wynik;
            }
        }
    }
    else{
        najwynik=beta;
        for(i=0;i<plansza.ZwrocRozmiar();i++){
            for(j=0;j<plansza.ZwrocRozmiar();j++){
                if(plansza.ZwrocZnak(i,j)==0){
                    plansza.UstawZnak(i,j,gracz);
                    ruch.wynik = AlphaBetaMiniMax(plansza,alpha,najwynik,GKomputer,glebokosc,1).wynik;
                    ruch.w=i;
                    ruch.k=j;
                    ruchy.push_back(ruch);
                    plansza.UstawZnak(i,j,0);
                    if(ruch.wynik<najwynik)
						najwynik=ruch.wynik;
                    if(alpha>=najwynik)
						i=j=plansza.ZwrocRozmiar();
                }
            }
        }
        najwynik=10000;
        for(i=0;i<(int)ruchy.size();i++){
            if(ruchy[i].wynik<najwynik){
                iterator=i;
                najwynik=ruchy[i].wynik;
            }
        }
    }
    return ruchy[iterator];
}

/* Funkcja obslugujaca ruch komputera
    Do znalezienia najlepszego ruchu wykorzystywany jest algorytm minimax z cieciami alfa i beta.
*/
void Komputer::RuchKomputera(Plansza& plansza){
	Move najlepszy;
	najlepszy=AlphaBetaMiniMax(plansza,-10000,10000,GKomputer,0,0);
    plansza.UstawZnak(najlepszy.w,najlepszy.k,GKomputer);
}
