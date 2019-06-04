#ifndef GAME_HH
#define GAME_HH

#include "gameBoard.hh"
#include "ai.hh"

class playGame{

public:

  board mainBoard;
  computer inteligentPlayer;
  int currentPlayer;
  int currentResault;

void loadGame();

};

#endif
