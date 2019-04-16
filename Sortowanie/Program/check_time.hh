#ifndef check_time_hh
#define check_time_hh
#include "enum.hh"
#include <ctime>
#include "do_test.hh"
#include <iostream>
using namespace std;

//
// Funkcja liczaca sredni czas posortowania jednej tablicy
// ( tzn. zwraca zmienna o nazwie calkowity czas ,
// a w funkcji zapisujacej jest ona dzielona przez amount , tj .ilosc tablic )
//

template <typename T>
double chechTime(sortingAlgorithm SA,int amount,float percentage,int alreadySorted,int size,double calkowity_czas,bool show)
{
clock_t poczatek,koniec,czas_trwania;


    T *array = nullptr;
    array = generate_array<T>(size, -200, 200, percentage, alreadySorted);
    
poczatek=clock();
    
    switch (SA) {
        
        case 1:{
            
            if(show==1)
            {
                cout << "Wygląd wygenerowanej tablic :" <<endl;
                show_array(array, size);
                array=quick_Sort(array, 0, size-1);
                cout << "Wygląd posortowanej tablic :" <<endl;
                show_array(array, size);
            }
            
            if(show==0)
            {
                array=quick_Sort(array, 0, size-1);
            }
            
            break;}
            
        case 2:{
            
            T *tmpArray = nullptr;
            tmpArray = new T [size];
        
            if(show==1)
            {
                cout << "Wygląd wygenerowanej tablic :" <<endl;
                show_array(array, size);
                array=mergeRecursion(array, tmpArray, 0, size-1);
                cout << "Wygląd posortowanej tablic :" <<endl;
                show_array(array, size);
            }
            
            if(show==0)
            {
                array=mergeRecursion(array, tmpArray, 0, size-1);
            }
            
            delete [] tmpArray;
            
            break;}
            
        case 3:{
            
            if(show==1)
            {
               heap_sort(array, size);
               show_array(array, size);
            }
            
            if(show==0)
            {
               heap_sort(array, size);
            }
            
            break;}
            
        case 4:{
            
            if(show==1)
            {
                cout << "Wygląd wygenerowanej tablic :" <<endl;
                show_array(array, size);
                introspectiveSort(array, size);
                cout << "Wygląd posortowanej tablic :" <<endl;
                show_array(array, size);
            }
            
            if(show==0)
            {
                introspectiveSort(array, size);
            }
            
            break;}
            
        default:{
            break;}
    }
    
koniec = clock();
    
czas_trwania = koniec-poczatek;

double tmp = (double)czas_trwania / CLOCKS_PER_SEC;
calkowity_czas = calkowity_czas + tmp;
   
delete [] array;
    
return calkowity_czas;
}

#endif /* check_time_h */
