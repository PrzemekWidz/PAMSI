#ifndef generate_array_hh
#define generate_array_hh
#include "generate_numbers.hh"
#include "quick_sort.hh"

// Funkcja generujaca tablice, oparta na szablonach

template <typename T>
T* generate_array (int size,T min,T max,float percentage,int alreadySorted)
{
    T *wsk = nullptr;
    wsk = new T [size];
    
    for(int i=0;i<size;i++)
    {
        T help = random(min,max);
        wsk[i]= help;
    }
    
    if ((percentage!=0.0)&&(alreadySorted==0)&&(percentage!=100.0))
      {
          int tmp = (int)(( size*(percentage/100)));
          wsk=quick_Sort(wsk, 0, tmp);
          
      }
    
    if((percentage==100.0)&&(alreadySorted==1))
      {
           wsk=quick_Sort(wsk, 0, size-1);
          
               for(int i=0;i<(size/2);i++)
              {
                 changeElements(wsk, i, size-1-i);
              }
          
      }
    return wsk;
}

#endif 
