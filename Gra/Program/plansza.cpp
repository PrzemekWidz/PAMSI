#include "plansza.hh"

using namespace std;

int Plansza::ZwrocRozmiar()
{
 return rozmiar;
}


int Plansza::ZwrocZnak(int i, int j)
{
 return plansza[i][j];
};

int Plansza::ZwrocRzadWygryw()
{
return rzadwygryw;
}



/* Funkcja inicjalizuje plansze */

void Plansza::Inicjalizacja(int r,int w){

  rozmiar=r;
	rzadwygryw=w;
	licznikruch=0;

    ostatni[0]=ostatni[1]=rozmiar;

      plansza=new int *[rozmiar];

        for (int i=0;i<rozmiar;i++)
        {
           plansza[i]=new int[rozmiar];

               for (int j=0;j<rozmiar;j++)
               {
                plansza[i][j]=0;
               }
         }
}

/* Funkcja zwracajaca znak przypisany do wskazanego pola */

char Plansza::Znak(int i,int j){

    if(plansza[i][j]==1) return 'x';

    else if(plansza[i][j]==-1) return 'o';

    else return ' ';

}

/* Funkcja wyswietlajaca plansze */
void Plansza::Wyswietl(){

// czyszczenie terminala
system("clear");

    cout << "Rozmiar planszy : "<<rozmiar << endl;
	  cout << "Rzad wygrywajacy : " << rzadwygryw << endl;
    cout << "Przypomnienie : gracz = 'x' , komputer = 'o'"<<endl<<endl;
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

/* Funkcja ustawia znak na wybranym polu */

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

/* Funkcja sprawdzajaca czy gra zostala rozstrzygnieta , sprawdza stan gry */

int Plansza::SprawdzZwyciezce(){

    if(ostatni[0]==rozmiar) return 2;

    int w,k,a,b,znak,licznik;
    znak=licznik=1;

    w=ostatni[0];
    k=ostatni[1];

    znak=plansza[w][k];

    for (int i=-1;i<1;i++)
    {

        for(int j=-1;j<=1;j++){

            if(i>=0 && j>=0){

                if(licznikruch>=rozmiar*rozmiar) return 0;

                else return 2;

            }

            licznik=1;
            a=i;
            b=j;

            while(w+a>=0 && w+a<rozmiar && k+b>=0 && k+b<rozmiar && plansza[w+a][k+b]==znak)
            {
                licznik++;
                a+=i;
                b+=j;
            }

            a=i;
            b=j;

            while(w-a>=0 && w-a<rozmiar && k-b>=0 && k-b<rozmiar && plansza[w-a][k-b]==znak)
            {
                licznik++;
                a+=i;
                b+=j;
            }

            if (licznik>=rzadwygryw) return plansza[w][k];

        }
    }

    return 2;
}
