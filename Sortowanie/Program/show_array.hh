#ifndef show_array_hh
#define show_array_hh
#include <iostream>


// Funkcja z jedna petla wyswietlajaca tablice
// oparta na szablonach


template <typename T>
void show_array (T *array,int size)
{
    for(int i=0;i<size;i++)
    {
        std::cout << array[i];
        std::cout << " ";
    }
        std::cout << "\n";
}

#endif
