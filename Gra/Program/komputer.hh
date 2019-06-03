#ifndef komputer_hh
#define komputer_hh
#include "plansza.hh"

struct Move{

int row;
int column;

};

class komputer: public planszaGra{

public:

char przeciwnik = 'o';

int evaluate ();

};


#endif /* pkomputer_hpp */
