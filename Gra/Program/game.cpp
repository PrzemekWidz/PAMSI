#include "game.hh"
#include <iostream>

using namespace std;

void playGame::loadGame(){



  cout << "Poaj rozmiar planszy " << endl;
  cout << "3 - 5" << endl;

int tmp;
int tmp2;

while(1){

cin >> tmp;

if(tmp>=3&&tmp<=5) break;
  else cout << "Zły rozmiar" << endl;
}

   cout << "Poaj dlugosc wygrywajacego rzedu" << endl;
   cout << "w poprawnym zakresie" << endl;

  while(1){

   cin >> tmp2;

   if(tmp2>=3&&tmp2<=tmp) break;
     else cout << "Zły rozmiar" << endl;
   }

mainBoard.loadBoard(tmp,tmp2);
inteligentPlayer.set();

int tmp3;

  cout << "Kto pierwszy ?" << endl;
  cout << "1-gracz, 2-komputer" << endl;

  while(1){

   cin >> tmp3;

   if(tmp3==1||tmp3==2) break;
     else cout << "ŹLE" << endl;
   }

currentPlayer==tmp;
currentResault=2;

// Now we start real game
/*
           do{

           mainBoard.showBoard();

            if(currentPlayer==1){

                   int tmpRow;
                   int tmpCol;

               again:

               do{
                   cin >> tmpRow;
                   cin >> tmpCol;

                 }while(tmpRow<mainBoard.size&&tmpCol>=0);

                 if(mainBoard.board[tmpRow][tmpCol]!=' ')
                 {
                   cout << "Pole zajete" << endl;
                   goto again;
                 }

                 if(mainBoard.board[tmpRow][tmpCol]==' ')
                 {
                  mainBoard.putCharakter(tmpRow,tmpCol,inteligentPlayer.opponent,'o');
                 }


            }

            if(currentPlayer==-1){

              Move theBest;

              theBest=inteligentPlayer.AlphaBetaMiniMax(mainBoard,-10000,10000,inteligentPlayer.computer,0,0);
              mainBoard.putCharakter(theBest.row,theBest.col,inteligentPlayer.computer,'x');

              currentResault=mainBoard.checkWinner();
              currentPlayer=1;
            }

            mainBoard.showBoard();

            if(currentResault==0) cout << "Remis" << endl;

           else if(currentResault==1) cout << "Wygrana gracza" <<endl;
           else if(currentResault==-1) cout << "Wygrana komputera" <<endl;



         }while(currentResault==2);*/

}
