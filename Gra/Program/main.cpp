#include <iostream>
#include "plansza.hh"
#include "komputer.hh"

#define ROZMIAR 5
#define RZAD 3

using namespace std;

int main ()
{

planszaGra nowaGra;

nowaGra.generujPlansze(ROZMIAR);
nowaGra.wyswietlPlansze(ROZMIAR);

int wygrana;
int remis;

while(1){
int x,y;

cin >> x;
cin >> y;
nowaGra.sprawdzRuch(x,y);
nowaGra.wstawRuch('x',x,y);
nowaGra.wyswietlPlansze(ROZMIAR);
wygrana=nowaGra.sprawdzWygrana('x',ROZMIAR,RZAD,x,y);
remis=nowaGra.sprawdzRemis(ROZMIAR);

if(wygrana==1||remis==1) break;


cin >> x;
cin >> y;
nowaGra.sprawdzRuch(x,y);
nowaGra.wstawRuch('o',x,y);
nowaGra.wyswietlPlansze(ROZMIAR);
wygrana=nowaGra.sprawdzWygrana('o',ROZMIAR,RZAD,x,y);
remis=nowaGra.sprawdzRemis(ROZMIAR);

if(wygrana==1||remis==1) break;

};

nowaGra.wyswietlPlansze(ROZMIAR);
cout << "ktos wygral albo remis" << endl;

return 0;

}
