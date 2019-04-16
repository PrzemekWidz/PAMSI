#ifndef save_in_txt_hh
#define save_in_txt_hh
#include "do_test.hh"
#include <iostream>
#include <fstream>
#include "enum.hh"

using namespace std;

//
// Funkcja zapisujaca sredni czas sortowania tablicy do pliku .txt 
//

void saveData(sortingAlgorithm SA,int amount,float percentage,int alreadySorted,int size,double calkowity_czas)
{
    fstream plik;
    
    plik.open("wyniki_sortowania.txt",ios::out|ios::app);
    
      if(plik.good()==true)
      {
        plik << endl;
          plik << "Algorytm => ";
          
          switch (SA) {
              
              case 1:
                  
                  plik << " SORTOWANIA SZYBKIEGO " << endl;
                  
                  break;
                  
              case 2 :
                  
                  plik << " SORTOWANIA PRZEZ SCALANIE " << endl;
                  
                  break;
                  
              case 3 :
                  
                  plik << " SORTOWANIA PRZEZ KOPCOWANIE " << endl;
                  
                  break;
                  
              case 4 :
                  
                  plik << " SORTOWANIA INTROSPEKTYWNEGO  " << endl;
                  
                  break;
                  
              default:
                  break;
          }
          
          
        plik << "Czas sortowania " << amount << " tablic " <<endl;
        plik << "o rozmiarze "     << size   << endl;
        plik << "Posortowanych w : "<<percentage <<" % " << endl;
        plik << "WYNOSI (średnia dla jednej tablicy) -> " << (double)(calkowity_czas/amount) << endl;
        
        plik << endl;
        plik.close();
     }
}

#endif /* save_in_txt_h */
