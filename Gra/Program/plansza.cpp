#include <iostream>
#include "plansza.hh"
using namespace std;

void planszaGra::generujPlansze(int rozmiar){

  plansza = new char * [rozmiar];

    for(int i=0;i<rozmiar;i++) plansza[i] = new char [rozmiar];

      for(int i=0;i<rozmiar;i++)
      {
        for(int k=0;k<rozmiar;k++)
        {
         plansza[i][k]=' ';
         }
      }
}

void planszaGra::wyswietlPlansze(int rozmiar){

cout << "  " ;

 for(int i=0;i<rozmiar;i++) cout << " " << i;

  cout << endl;

     for(int i=0;i<rozmiar;i++)
      {
        cout << i << " ";

          for(int j=0;j<rozmiar;j++)
           {
            cout << "|" << plansza[i][j];
           }
           cout << "|" <<endl;

       if(i!=rozmiar-1)
         {
         cout << "  +";
         for(int k=0;k<rozmiar-1;k++) cout << "-+";
         cout << "-+" << endl;
         }
       }

  cout << endl;

}

void planszaGra::wstawRuch (char gracz,int wiersz,int kolumna){

this->plansza[wiersz][kolumna]=gracz;

}

bool planszaGra::sprawdzRuch (int wiersz, int kolumna){

if(this->plansza[wiersz][kolumna]==' ') return true;
else return false;

}

int planszaGra::sprawdzRemis (int rozmiar){

int licznik = 0;

for(int i=0;i<rozmiar;i++)
{
  for(int k=0;k<rozmiar;k++)
  {
    if(this->plansza[i][k]=='x'||this->plansza[i][k]=='o')
    licznik=licznik+1;
    if(licznik==rozmiar*rozmiar)return 1;
  }
}
return 0;
}

/*
bool planszaGra::sprawdzWygrana (char gracz,int rozmiar,int ilosc){


// w poziomie

for(int i=0;i<rozmiar;i++)
{
  for(int k=0;k<=rozmiar-ilosc;k++)
  {
    int help=0;

     for(int j=0;j<ilosc;j++)
     {
       if(this->plansza[i][k+j]==gracz) help++;
     }

    if(help==ilosc) return true;
    else return false;
  }
}

// w pionie

for(int i=0;i<rozmiar;i++)
{
  for(int k=0;k<=rozmiar-ilosc;k++)
  {
    int help=0;

     for(int j=0;j<ilosc;j++)
     {
       if(this->plansza[k+j][i]==gracz) help++;
     }

    if(help==ilosc) return true;
    else return false;
  }
}

// inne

for(int i=0;i<=rozmiar-ilosc;i++)
{
  for(int k=0;k<=rozmiar-ilosc;k++)
  {
    for(int j=0;j<ilosc;j++)
    {
      if(this->plansza[i+k][k+i]!=gracz) return false;
      else return true;
    }
  }
}

}
*/
int planszaGra::sprawdzWygrana (char gracz,int rozmiar,int ilosc,int wiersz,int kolumna){

int licznik;

// w prawo
licznik = 0;

for(int i=kolumna;i<rozmiar;i++)
{
  if(this->plansza[wiersz][i]==gracz) licznik=licznik+1;
  if(licznik==ilosc) return 1;
}


// w lewo
licznik = 0;

for(int i=kolumna;i>=0;i--)
{
  if(this->plansza[wiersz][i]==gracz) licznik++;
  if(licznik==ilosc) return 1;
}


// w dol
licznik = 0;

for(int i=wiersz;i<rozmiar;i++)
{
  if(this->plansza[i][kolumna]==gracz) licznik++;
  if(licznik==ilosc) return 1;
}


// w gore ( przy sprawdzaniu isc w dol )
licznik = 0;

for(int i=wiersz;i>=0;i--)
{
  if(this->plansza[i][kolumna]==gracz) licznik++;
  if(licznik==ilosc) return 1;

}

int tmpk, tmpw;

tmpk = kolumna;
tmpw = wiersz;
// po przekatnych
licznik = 0;
int i=0;
// od prawego dolnego rogu
while((tmpw<rozmiar)&&(tmpk<rozmiar))
{
  if(this->plansza[tmpw][tmpk]==gracz) licznik++;

    if(licznik==ilosc) return 1;

    tmpk++;
    tmpw++;
}


// od lewego gorneo
tmpk = kolumna;
tmpw = wiersz;

licznik = 0;
i=0;

while(tmpw>=0&&tmpk>=0)
{
  if(this->plansza[tmpw][tmpk]==gracz) licznik++;


    if(licznik==ilosc) return 1;

 tmpw--;
 tmpk--;

}

// inny przypadek ...

tmpk = kolumna;
tmpw = wiersz;
// po przekatnych
licznik = 0;
i=0;
// od prawego dolnego rogu
while((tmpw>=0)&&(tmpk<rozmiar))
{
  if(this->plansza[tmpw][tmpk]==gracz) licznik++;

    if(licznik==ilosc) return 1;

    tmpk++;
    tmpw--;
}

// jeszcze jeden

tmpk = kolumna;
tmpw = wiersz;
// po przekatnych
licznik = 0;
i=0;
// od prawego dolnego rogu
while((tmpw<rozmiar)&&(tmpk>=0))
{
  if(this->plansza[tmpw][tmpk]==gracz) licznik++;

    if(licznik==ilosc) return 1;

    tmpk--;
    tmpw++;
}


return 0;

}
