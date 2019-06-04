#include "ai.hh"
#include <stdio.h>
#include <vector>

using namespace std;

// Functions definitions

/************************************************
*                                               *
*  Function that checks the best move to make   *
*                                               *
*                                               *
************************************************/


Move computer::AlphaBetaMiniMax(board& gameBoard,int alpha,int beta,int player,int howDeep,bool rek){

  int maxResault;

      int iterator=0;

      int resault=gameBoard.checkWinner();

      Move step;
      vector<Move> steps;

      if (rek) howDeep++;

      if(resault!=2)

  		return (resault==-1) ? Move(resault*(-1000)-20*howDeep) : Move(resault*(-1000)+20*howDeep);

      else if(player==computer){

          maxResault=alpha;

          for(int i=0;i<gameBoard.size;i++)
          {
              for(int j=0;j<gameBoard.size;j++)
              {

                  if(gameBoard.board[i][j]==0)
                  {
                      gameBoard.board[i][j]=player;
                      if (!rek) printf("|");
                      step.moveResoult = AlphaBetaMiniMax(gameBoard,maxResault,beta,player,howDeep,1).moveResoult;

                      step.row=i;
                      step.col=j;

                      steps.push_back(step);
                      gameBoard.board[i][j]==0;

                      if(step.moveResoult>maxResault) maxResault=step.moveResoult;
                      if(beta<=maxResault) i=j=gameBoard.size;
                  }
              }
          }

          maxResault=-10000;
          for(int i=0;i<(int)steps.size();i++)
          {
              if(steps[i].moveResoult>maxResault)
              {
                  iterator=i;
                  maxResault=steps[i].moveResoult;
              }
          }
      }

      else{
          maxResault=beta;

          for(int i=0;i<gameBoard.size;i++)
          {
              for(int j=0;j<gameBoard.size;j++)
              {
                  if(gameBoard.board[i][j]==0)
                  {
                      gameBoard.board[i][j]=player;

                      step.moveResoult = AlphaBetaMiniMax(gameBoard,alpha,maxResault,computer,howDeep,1).moveResoult;
                      step.row=i;
                      step.col=j;
                      steps.push_back(step);

                      gameBoard.board[i][j]=0;

                      if(step.moveResoult<maxResault) maxResault=step.moveResoult;

                      if(alpha>=maxResault) i=j=gameBoard.size;
                  }
              }
          }

          maxResault=10000;

          for(int i=0;i<(int)steps.size();i++)
          {
              if(steps[i].moveResoult<maxResault)
              {
                  iterator=i;
                  maxResault=steps[i].moveResoult;
              }
          }
      }

      return steps[iterator];

}
