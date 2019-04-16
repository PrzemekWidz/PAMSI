#ifndef intro_sort_hh
#define intro_sort_hh
#include <cmath>
#include "insertion_Sort.hh"

/***************************************************************
 *                                                             *
 *  Algorytm sortowania introspektywnego na szablonach         *
 *  Zródła :                                                   *
 *  ->https://pl.wikipedia.org/wiki/Sortowanie_introspektywne  *
 *                                                             *
 **************************************************************/

template <class T>
void introSort (T *array, int size, int M)
{
    int i;
    
    if (M<=0)
    {
        heap_sort(array, size);
        return;
    }
    
    i=divideArray(array,0,size-1);
    if (i>9)
        introSort(array,i,M-1);
    if (size-1-i>9)
        introSort(array+i+1,size-1-i,M-1);
}

template <class T>
void introspectiveSort (T *array, int size)
{
    introSort(array,size,(int)floor(2*log(size)/M_LN2));
    array=insertion_sort(array,size);
}

#endif /* intro_sort_h */
