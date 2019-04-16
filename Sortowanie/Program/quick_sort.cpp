#include <iostream>
#include <cstdlib>

#include "quick_sort.hh"

// Definicja funkcji wyboru punktu podzialuint choosePivot
// element srodkowy tablicy
// ( jako elementu srodkowego tablicy )

int choosePivot(int left , int right)
{
    div_t result = div((left+(right-1)),2);
    
    return result.quot;
}
