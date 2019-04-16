#ifndef merge_sort_hh
#define merge_sort_hh


/********************************************************************************
 *                                                                               *
 *  Algorytm merge sort na szablonach                                            *
 *  Zródła :                                                                     *
 *  -> Ksiazka zaproponowana przez prowadzacego                                  *
 *  -> https://pl.wikipedia.org/wiki/Sortowanie_przez_scalanie                   *
 *  -> https://www.youtube.com/watch?v=iJyUFvvdfUg                               *
 *                                                                               *
 *********************************************************************************/

template < typename T >
void copyArrays (T* array,T* tmpArray,int left ,int right,int leftIndex,int middleIndex,int rightIndex,int k)
{
    
    if(leftIndex <= middleIndex)
    {
        while (leftIndex <= middleIndex)
        {
            tmpArray[k] = array[leftIndex];
            leftIndex++;
            k++;
        }
    }
    
    else
    {
        while (rightIndex <= right)
        {
            tmpArray[k] = array[rightIndex];
            rightIndex++;
            k++;
        }
    }
    
    for (leftIndex = 0; leftIndex <= right-left; leftIndex++)
    {
        array[left+leftIndex] = tmpArray[leftIndex];
     }

}

template < typename T >
void mergeAlgorithm (T* array,T* tmpArray,int left , int right)
{

    int middleIndex = (left+right)/2;
    int leftIndex = left;
    int rightIndex = middleIndex+1;
    int k=0;
    
    while((leftIndex <= middleIndex) && (rightIndex <= right))
    {
        if(array[rightIndex]<array[leftIndex])
        {
          tmpArray[k]=array[rightIndex];
          rightIndex++;
        }
        
        else
        {
            tmpArray[k]=array[leftIndex];
            leftIndex++;
        }
        k++;
    }
    
    copyArrays(array, tmpArray, left, right, leftIndex, middleIndex, rightIndex, k);
    
}


template < typename T >
T* mergeRecursion (T* array,T* tmpArray,int left, int right)
{
    if(left>=right)
    {
        return array;
    }
    
    else{
    
        int middle = ( left + right )/2;
        mergeRecursion(array,tmpArray ,left, middle);
        mergeRecursion(array,tmpArray ,middle+1, right);
        mergeAlgorithm(array,tmpArray ,left,right);
    }
    
    return array;
}



#endif /* merge_sort_h */
