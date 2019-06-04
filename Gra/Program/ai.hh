#ifndef AI_HH
#define AI_HH
#include "gameBoard.hh"

struct Move{

    Move() : moveResoult(0){};
    Move(int x) : moveResoult(x){}

    int row;
    int col;
    int moveResoult;
};

class computer {

public:

int computer;
int opponent;
int howDeep;


// Functions declarations

void set(){

 computer=-1;
 opponent=1;
 howDeep=0;


}

Move AlphaBetaMiniMax(board& playBoard,int alpha,int beta,int player,int howDeep,bool rek);

};

#endif
