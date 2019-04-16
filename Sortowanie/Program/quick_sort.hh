#ifndef quick_sort_hh
#define quick_sort_hh

/***********************************************************
 *                                                          *
 *  Algorytm sortowania szybkiego na szablonach             *
 *  Zródła :                                                *
 *  -> Ksiazka zaproponowana przez prowadzacego             *
 *  -> https://www.youtube.com/watch?v=82XxdhRCMbI          *
 *     ( film z rozwiazaniem dla zestau kilku liczb         *
 *        krok po kroku )                                   *
 ***********************************************************/

int choosePivot(int left , int right);

template <typename T>
T* changeElements (T* array,int index_1,int index_2)
{
    T tmp = array[index_1];
    array[index_1] = array[index_2];
    array[index_2] = tmp;
    
    return array;
}

template <typename T>
int divideArray (T* array,int left,int right)
{
    int centerElement = choosePivot(left, right);
    int Pivot = array[centerElement];
    
    changeElements(array, centerElement, right);
    
    int aktualPosition = left;
    
    for(int i=left;i<=right-1;i++)
    {
        if(array[i]<Pivot)
        {
              changeElements(array, aktualPosition, i);
              aktualPosition++;
        }
    }
    
    changeElements(array,aktualPosition, right);
    
    return aktualPosition;
}

template <typename T>
T* quick_Sort (T* array,int left,int right)
{
    if(left<right)
    {
        int tmp = divideArray(array, left, right);
        
        quick_Sort(array,left,tmp-1);
        quick_Sort(array,tmp+1,right);
    }
   
        return array;
}


#endif 
