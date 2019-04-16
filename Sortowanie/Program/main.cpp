//
//  main.cpp
//  Sortowanie
//
//  Created by Przemek W on 10/03/2019.
//  Copyright © 2019 Przemek. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "do_test.hh"
#include "save_in_txt.hh"


using namespace std;

int main(int argc, const char * argv[]) {
  
srand(time(0));
   
    int decision;
    
    cout << "1 - przeprowadz badania dla tablic z elementami " << endl;
    cout << "typu int" << endl;
    cout << "2 - wykonaj test dla poszczegolnego algorytmu" << endl;
    cout << "3 - zamknij program" << endl;
    cout << "Decyzja : " ;
    cin >> decision;
    cout << endl;
    
    if(decision==1)
    {
        saveData<int>();
        return 0;
    }
    
    if(decision==2)
    {
        int size, amount, typeData , inverted, whichAlgorithm;
        float percentage;
        enum sortingAlgorithm SA;
        bool show=1;
        
        cout << "Enum dla rodzaju algorytmu : 1 = quickSort,2 = mergeSort,4 = introsorting " <<endl;
        cout << "Podaj odpowiednio : " << endl;
        cout << "-> rodzaj algorytmu" << endl;
        cout << "-> rozmiar tablicy" << endl;
        cout << "-> ilosc tablic do posortowania" << endl;
        cout << "-> typ elementów tablicy 0 - int , 1 - float " << endl;
        cout << "-> procent posortowania wstepnego tablicy " <<endl;
        cout << "-> czy ma byc odwrocona 0 - nie , 1 - tak " << endl;
    
        cin >> whichAlgorithm;
        
        if(whichAlgorithm==1) SA=quickSort;
        if(whichAlgorithm==2) SA=mergeSort;
        if(whichAlgorithm==4) SA=introSorting;
        
        cin >> size;
        cin >> amount;
        cin >> typeData;
        cin >> percentage;
        cin >> inverted;
        
        switch (SA) {
            
            case 1:{
                
                if(typeData==0)
                {
                    automaticTest<int>(SA, size,amount , percentage, inverted,show);
                }
                
                if(typeData==1)
                {
                    automaticTest<float>(SA, size,amount , percentage, inverted,show);
                }
                
                break;}
                
            case 2:{
                
                if(typeData==0)
                {
                    automaticTest<int>(SA, size,amount , percentage, inverted,show);
                }
                
                if(typeData==1)
                {
                    automaticTest<float>(SA, size,amount , percentage, inverted,show);
                }
                
                break;}
                
            case 4:{
                
                if(typeData==0)
                {
                    automaticTest<int>(SA, size,amount , percentage, inverted,show);
                }
                
                if(typeData==1)
                {
                    automaticTest<float>(SA, size,amount , percentage, inverted,show);
                }
                
                break;}
                
            default:
                break;}
        
        return 0;
    }
    
    
    if(decision==3)
    {
        return 0;
    }
    
    return 0;
}
