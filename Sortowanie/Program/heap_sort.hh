#ifndef heap_sort_h
#define heap_sort_h


/********************************************************************************
 *                                                                               *
 *  Algorytm heap sort na szablonach                                             *
 *  Zródła :                                                                     *
 *  -> Ksiazka zaproponowana przez prowadzacego                                  *
 *  -> https://pl.wikipedia.org/wiki/Sortowanie_przez_kopcowanie                 *
 *  -> https://www.youtube.com/watch?v=M2bKENbdnI4                               *
 *                                                                               *
 *********************************************************************************/


template <typename T>
void checkMaxHeap (T* array,int size,int parentIndex)
{
    int maxIndex = parentIndex;
    int leftIndex = parentIndex * 2 + 1;
    int rightIndex = parentIndex * 2 + 2;
    
    if(leftIndex<size && array[leftIndex]>array[maxIndex])
    {
        maxIndex = leftIndex;
    }
    if(rightIndex<size && array[rightIndex]>array[maxIndex])
    {
        maxIndex = rightIndex;
    }
    if(maxIndex!=parentIndex)
    {
        T tmp = array[maxIndex];
        array[maxIndex]=array[parentIndex];
        array[parentIndex]=tmp;
        checkMaxHeap(array, size, maxIndex);
    }
}

template <typename T>
void heap_sort (T* array,int size)
{
    for(int i=(size/2)-1;i>=0;i--)
    {
        checkMaxHeap(array, size, i);
    }
    
    for(int i=size-1;i>0;i--)
    {
        T tmp = array[0];
        array[0]=array[i];
        array[i]=tmp;
        size --;
        checkMaxHeap(array, size, 0);
    }
    
}


#endif /* heap_sort_h */
