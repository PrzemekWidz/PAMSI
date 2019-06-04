#include "gra.h"

using namespace std;

Gra::Gra(){
}

Gra::~Gra(){
}

/* Funkcja inicjalizujaca gre
    Pozwala wprowadzic rozmiar pola, dlugosc rzedu wygrywajacego i rozpoczynajacego gracza.
    Inicjalizuje plansze i gracza komputer.
*/
void Gra::Inicjalizacja(){
    int rozmiar,rzadwygryw;
    stan=2;            
    rozmiar=rzadwygryw=0;

    cout<<"Podaj rozmiar planszy od 3 do 9:"<<endl;
    while(1){
        while (!(cin>>rozmiar)){
			cout<<"Zly wybor"<<endl;
			cout<<"Podaj rozmiar planszy od 3 do 9."<<endl;
            cin.clear();
            cin.sync();
        }
		if (rozmiar>2 && rozmiar<10)
			break;
		else
			cout<<"Zly rozmiar."<<endl; 
			cout<<"Podaj rozmiar planszy od 3 do 9."<<endl;
    }

    cout<<"Podaj dlugosc wygrywajacego rzedu od 3 do rozmiaru planszy:"<<endl;
    while(1) {
        while (!(cin>>rzadwygryw)){
            cout<<"Zly wybor."<<endl;
			cout<<"Podaj dlugosc wygrywajacego rzedu od 3 do rozmiaru planszy:"<<endl;
            cin.clear();
            cin.sync();
        }
        if(rzadwygryw>2 && rzadwygryw<=rozmiar) 
			break;
        else 
			cout<<"Zly rozmiar."<<endl;
			cout<<"Podaj dlugosc wygrywajacego rzedu od 3 do rozmiaru planszy:"<<endl;
    }
    plansza.Inicjalizacja(rozmiar,rzadwygryw);
	GKomputer.Inicjalizacja(plansza);
 
    cout<<"Kto zaczyna? 1 - Gracz (x), 2 - Komputer (o)."<<endl;
    while(1) {
        while (!(cin>>gracz)) {
            cout<<"Zly wybor."<<endl;
			cout<<"Kto zaczyna? 1 - Gracz (x), 2 - Komputer (o)."<<endl;
            cin.clear();
            cin.sync();
        }
        if(gracz==1 || gracz==2) 
			break;
        else 
			cout<<"Zly wybor."<<endl;
			cout<<"Kto zaczyna? 1 - Gracz (x), 2 - Komputer (o)."<<endl;
    }
}

/* Funkcja kontrolujaca przebieg gry
    Wywoluje funkcje inicjalizujaca, wyswietla plansze, umozliwia wykonanie ruchu,
    sprawdza stan gry po kazdym ruchu i zmienia graczy.
    Po zakonczeniu gry umozliwia ponowna gre.
*/
void Gra::Przebieg(){

    while(1){
        Inicjalizacja();
        while(stan==2){
            plansza.Wyswietl();
            if(gracz==1) 
				RuchGracza();
            else 
				GKomputer.RuchKomputera(plansza);
            stan=plansza.SprawdzZwyciezce();
			ZmienGracza();
        }
        plansza.Wyswietl();
        if(stan==0) 
			cout<<"Remis!"<<endl;
        else if(stan==1) 
			cout<<"Wygrales!"<<endl;
		else if(stan==-1)
			cout<<"Wygral komputer"<<endl;

        cout<<"Nowa gra? 1 - tak, 0 - koniec."<<endl;
        while(1) {
            while (!(cin>>stan)){
                cout<<"Zly wybor. 1 - tak, 0 - koniec."<<endl;
                cin.clear();
                cin.sync();
            }
            if(stan==1) 
				break;
            if(stan==0) 
				return;
            else 
				cout<<"Zly wybor. 1 - tak, 0 - koniec."<<endl;
        }
    }
}

/* Funkcja obslugujaca ruch gracza
    Pozwala na wybranie pola, sprawdza poprawnosc wprowadzonych danych.
*/
void Gra::RuchGracza(){
    int w,k;
    bool zmiana=0;
    cout<<"Twoj ruch. Najpierw wpisz wiersz, nastepnie kolumne.";
    while (!zmiana){
        while (!(cin>>w)){
            cout<<"Zly wybor. Najpierw wpisz wiersz, nastepnie kolumne."<<endl;
            cin.clear();
            cin.sync();
        }
        while (!(cin>>k)){
            cout<<"Zly wybor. Najpierw wpisz wiersz, nastepnie kolumne."<<endl;
            cin.clear();
            cin.sync();
        }
        if(w>=0 && w<plansza.ZwrocRozmiar() && k>=0 && k<plansza.ZwrocRozmiar())
            if(plansza.ZwrocZnak(w,k)==0) {
                plansza.UstawZnak(w,k,1);
                zmiana=1;
            }
            else 
				cout<<"Pole zajete. Wybierz nowe. Najpierw wpisz wiersz, nastepnie kolumne."<<endl;
        else 
			cout<<"Pole spoza planszy. Wybierz nowe. Najpierw wpisz wiersz, nastepnie kolumne."<<endl;
    }
}