#ifndef plansza_hh
#define plansza_hh

class planszaGra{

public:

char **plansza;
int rozmiar;

void generujPlansze (int rozmiar);
void wyswietlPlansze (int rozmiar);
void wstawRuch (char gracz,int wiersz,int kolumna);

bool sprawdzRuch (int wiersz, int kolumna);
int sprawdzWygrana (char gracz,int rozmiar,int ilosc,int wiersz,int kolumna);
int sprawdzRemis (int rozmiar);

planszaGra()
{
 plansza=nullptr;
 rozmiar=0;
}

};

#endif /* plansza_hpp */
