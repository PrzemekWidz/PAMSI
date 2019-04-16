#ifndef insertion_Sort_hh
#define insertion_Sort_hh

/***********************************************************
 *                                                          *
 *  Algorytm sortowania przez wstawianie na szablonach      *
 *  Zródła :                                                *
 *  -> Ksiazka zaproponowana przez prowadzacego             *
 *  -> https://www.youtube.com/watch?v=8RkE7MbqVl8          *
 *                                                          *
 ***********************************************************/

template <typename T>
T* insertion_sort (T *array ,int size)
{
    for(int i=1;i<size;i++)
    {
        T tmp = array[i];
        
        while( (array[i-1]>tmp) && ((i-1)>=0) )
        {
            array[i]=array[i-1];
            i--;
        }
        array[i]=tmp;
    }
    
    return array;
}

#endif /* insertion_Sort_h */
