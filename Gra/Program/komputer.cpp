#include <iostream>
#include "komputer.hh"

using namespace std;

int komputer::evaluate(){

int zwroc;
planszaGra tmp;
tmp = *this;

zwroc=tmp.sprawdzRemis(this->rozmiar);
if(zwroc==1) return 0;



}
