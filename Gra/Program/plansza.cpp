#include "plansza.h"

using namespace std;

Plansza::Plansza(){
}

Plansza::~Plansza(){
    delete [] plansza;
    plansza=NULL;
}

/* Funkcja inicjalizuje plansze poprzez wpisanie do kazdego pustego pola - 0 */
void Plansza::Inicjalizacja(int r,int w){
	rozmiar=r;
	rzadwygryw=w;
	licznikruch=0;
    ostatni[0]=ostatni[1]=rozmiar;

    plansza=new int *[rozmiar];
    for (int i=0;i<rozmiar;i++){
        plansza[i]=new int[rozmiar];
        for (int j=0;j<rozmiar;j++){
            plansza[i][j]=0;
        }
    }
}

/* Funkcja zwracajaca znak przypisany do wskazanego pola
    1 - pole wybrane przez gracza (x), -1 - pole wybrane przez komputer (o), 0 - pole puste */
char Plansza::Znak(int i,int j){
    if(plansza[i][j]==1)
		return 'x';
    else if(plansza[i][j]==-1)
		return 'o';
    else
		return ' ';
}

/* Funkcja wyswietlajaca plansze */
void Plansza::Wyswietl(){

system("clear");

    cout<<"    Gra kolko i krzyzyk "<<rozmiar<<"x"<<rozmiar<<endl;
	cout <<"   Aby wygrac uloz " << rzadwygryw << " w rzedzie" << endl;;
    cout<<"Gracz - x     |     Komputer - o"<<endl<<endl;

    cout << "  " ;

     for(int i=0;i<this->rozmiar;i++) cout << " " << i;

      cout << endl;

         for(int i=0;i<this->rozmiar;i++)
          {
            cout << i << " ";

              for(int j=0;j<this->rozmiar;j++)
               {
                cout << "|" << Znak(i,j);
               }
               cout << "|" <<endl;

           if(i!=this->rozmiar-1)
             {
             cout << "  +";
             for(int k=0;k<this->rozmiar-1;k++) cout << "-+";
             cout << "-+" << endl;
             }
           }

  cout << endl;
}

/* Funkcja ustawia znak na wybranym polu
    1 - pole wybrane przez gracza (x), -1 - pole wybrane przez komputer (o), 0 - pole puste
    Przy przypisywaniu pola dolicza ruch do licznika ruchow i zapisuje wspolrzedne tego ruchu do tablicy ostatni
    Przy zwalnianiu pola (znak=0) odlicza ruch od liczby wykonanych ruchow i resetuje wspolrzedne ostatniego ruchu
*/
void Plansza::UstawZnak(int i,int j,int znak){
    plansza[i][j]=znak;
    if(znak==0){
        licznikruch--;
        ostatni[0]=ostatni[1]=rozmiar;
    }
    else{
        licznikruch++;
        ostatni[0]=i;
        ostatni[1]=j;
    }
}

/* Funkcja sprawdzajaca czy gra zostala rozstrzygnieta
    2 - gra w toku, 1 - wygrana gracza , -1 - wygrana komputera, 0 - remis
    Jesli wspolrzedne ostatniego ruchu = szerokosci pola (reset) to zwraca 2.
    Kiedy znajdzie rzad wygrywajacy to zwraca -1 lub 1.
    Jezeli liczba ruchow rowna sie szerokosci pola do kwadratu to zwraca 0.
	Jezeli zaden z warunkow nie zostanie spelniony zwraca 2.
*/
int Plansza::SprawdzZwyciezce(){
    if(ostatni[0]==rozmiar)
		return 2;

    int i,j,w,k,a,b,znak,licznik;
    znak=licznik=1;
    w=ostatni[0];
    k=ostatni[1];
    znak=plansza[w][k];

    for (i=-1;i<1;i++){
        for(j=-1;j<=1;j++){
            if(i>=0 && j>=0){
                if(licznikruch>=rozmiar*rozmiar)
					return 0;
                else
					return 2;
            }
            licznik=1;
            a=i;
            b=j;
            while(w+a>=0 && w+a<rozmiar && k+b>=0 && k+b<rozmiar && plansza[w+a][k+b]==znak){
                licznik++;
                a+=i;
                b+=j;
            }
            a=i;
            b=j;
            while(w-a>=0 && w-a<rozmiar && k-b>=0 && k-b<rozmiar && plansza[w-a][k-b]==znak){
                licznik++;
                a+=i;
                b+=j;
            }
            if (licznik>=rzadwygryw)
				return plansza[w][k];
        }
    }
    return 2;
}
