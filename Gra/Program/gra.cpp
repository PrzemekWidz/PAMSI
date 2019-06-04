#include "gra.hh"
#include <iostream>
#include <cstdlib>

using namespace std;

// Konstruktor
Gra::Gra(){ }

// Destruktor
Gra::~Gra(){ }

/* Funkcja ladujaca gre */

void Gra::Inicjalizacja(){

    int rozmiar;
    int rzadwygryw;

    stan=2;
    rozmiar=rzadwygryw=0;

// Podawanie rozmiaru planszy i ilosci znakow w rzedzie przez uzytkownika
// programu

// ROZMIAR PLANSZY
    cout<< "Podaj rozmiar:"<< endl;
    cout<< "3-5" << endl;

    while(1)
    {
        while (!(cin>>rozmiar)){ cout<<"Źle, podaj jeszcze raz"<<endl; }

		if (rozmiar>=3 && rozmiar<10) break;

		else
			cout<<"Źle, podaj jeszcze raz"<<endl;

    }
// WYGRYWAJACY CIAG

    cout<<"Podaj dlugosc wygrywajacego ciagu:"<<endl;

    while(1)
    {
        while (!(cin>>rzadwygryw))
        {
        cout<<"Źle, podaj jeszcze raz"<<endl;
        }
        if(rzadwygryw>=3 && rzadwygryw<=rozmiar) break;

      else
			cout<<"Źle, podaj jeszcze raz"<<endl;

    }

// LADOWANIE PLANSZY
// I OBIEKTU KOMPUTER

  plansza.Inicjalizacja(rozmiar,rzadwygryw);
	GKomputer.Inicjalizacja(plansza);

    cout << "Wcisnij 1 , zaczniesz gre Ty" << endl;
    cout << "Wcisnij 2 , zacznie gre komputer" << endl;

// WYBOR KTO ZACZYNA

    while(1)
    {
        while (!(cin>>gracz))
        {
        cout<<"Źle, podaj jeszcze raz"<<endl;
        }

        if(gracz==1 || gracz==2) break;

        else
	          cout<<"Źle, podaj jeszcze raz"<<endl;
    }
}

/* Funkcja kontrolujaca przebieg gry*/
void Gra::Przebieg(){

    while(1){

Inicjalizacja();

while(stan==2)
{
  plansza.Wyswietl();

  if(gracz==1) RuchGracza();

   else

    GKomputer.RuchKomputera(plansza);
      stan=plansza.SprawdzZwyciezce();
			 ZmienGracza();
}
    plansza.Wyswietl();

      if(stan==0)
      {
        cout<<"REMIS"<<endl;
        break;
      }

       else if(stan==1)
        {
         cout<<"WYGRALES"<<endl;
         break;
        }

		     else if(stan==-1)
         {
           cout<<"WYGRAL KOMPUTER"<<endl;
           break;
         }
 }

}

/* Funkcja obslugujaca ruch gracza */
void Gra::RuchGracza(){

    int w,k;
    bool zmiana=0;

    cout << "TWOJ RUCH" << endl;
    cout << "Wpisz go w postaci: WIERSZ (SPACJA) KOLUMNA" << endl;

    while (!zmiana)
    {
        while (!(cin>>w)){
            cout<<"Źle, podaj jeszcze raz"<<endl;
        }

        while (!(cin>>k)){
            cout<<"Źle, podaj jeszcze raz"<<endl;
        }

        if(w>=0 && w<plansza.ZwrocRozmiar() && k>=0 && k<plansza.ZwrocRozmiar())

            if(plansza.ZwrocZnak(w,k)==0)
            {
                plansza.UstawZnak(w,k,1);
                zmiana=1;
            }

            else

				cout<<"Pole zajete"<< endl;

        else

			cout<<"Pole spoza planszy" << endl;
    }
}
