#include <iostream>
#include <cstdlib>
#include <vector>
#include "gameBoard.hh"

using namespace std;

// Functions definitions

/************************************************
*                                               *
*   Function that loads our game board          *
*                                               *
*                                               *
************************************************/

void board::loadBoard(int SIZE,int WINNINGNUMBER){

size = SIZE;
winingNumber=WINNINGNUMBER;
stepCounter=0;

last[0]=last[1]=size;

board = new int *[size];
boardView = new char *[size];


// Putting zeros inside our int board
for (int i=0;i<size;i++){

      board[i]=new int[size];

      for (int j=0;j<size;j++)
      {
       board[i][j]=0;
      }

   }

// Putting 'spaces' inside our char board

for (int i=0;i<size;i++){

      boardView[i]=new char[size];

      for (int j=0;j<size;j++)
      {
       boardView[i][j]=' ';
      }

   }
}

/************************************************
*                                               *
*  Function that puts the 'x' or 'o' in board   *
*                                               *
*                                               *
************************************************/

void board::putCharakter(int row,int col,int charakter,char who){

board[row][col]=charakter;

if(charakter==0)
 {
   stepCounter--;
   last[0]=last[1]=size;
 }

 else{

     stepCounter++;
     last[0]=row;
     last[1]=col;
 }

boardView[row][col]=who;

}

/************************************************
*                                               *
*  Function that shows our game board           *
*                                               *
*                                               *
************************************************/

void board::showBoard (){

  cout << "  " ;

   for(int i=0;i<this->size;i++) cout << " " << i;

    cout << endl;

       for(int i=0;i<this->size;i++)
        {
          cout << i << " ";

            for(int j=0;j<this->size;j++)
             {
              cout << "|" << boardView[i][j];
             }
             cout << "|" <<endl;

         if(i!=this->size-1)
           {
           cout << "  +";
           for(int k=0;k<this->size-1;k++) cout << "-+";
           cout << "-+" << endl;
           }
         }

    cout << endl;

}

/************************************************
*                                               *
*  Function that checks the winner              *
*                                               *
*                                               *
************************************************/

int board::checkWinner(){

if(last[0]==size) return 2;

    int sign;
    int counter;

    int row=last[0];
    int col=last[1];

    sign=counter=1;

    sign=board[row][col];

    for (int i=-1;i<1;i++)
      {

        for(int j=-1;j<=1;j++){

            if(i>=0 && j>=0){
                              if(stepCounter>=size*size) return 0;
                              else return 2;
                            }
            counter=1;

            int a=i;
            int b=j;

            while(row+a>=0 && row+a<size && col+b>=0 && col+b<size && board[row+a][col+b]==sign){

                counter++;
                a+=i;
                b+=j;
            }

            a=i;
            b=j;

            while(row-a>=0 && row-a<size && col-b>=0 && col-b<size && board[row-a][col-b]==sign){

                counter++;
                a+=i;
                b+=j;
            }

            if (counter>=winingNumber)

        return board[row][col];

        }
    }

    return 2;
}

/* FIRST TRY OF FUNCTION CHECK WINNER (po polsku,bo tak zacalem pisac,potem zmienione na ang)

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

*/
