#ifndef GAMEBOARD_HH
#define GAMEBOARD_HH

class board
{

public:

  int **board;
  char **boardView;
  int size;
  int winingNumber;
  int stepCounter;
  int last[2];

// Functions declarations

void loadBoard(int size,int winingNumber);
void putCharakter(int row,int col,int charakter,char who);
void showBoard ();
int checkWinner ();

};


#endif
