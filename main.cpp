#include <iostream>
#include <string>
#include "def.h"

using namespace std;

/*-----------------------------------------------------------------------
CSC310-01 Data Structures and Algorithm Analysis (Fall 2023) Assignment 1
Due Date: Friday, August 25, 2023
Write a program to play the 3 by 3 “Tic-Tac-Toe” board game

William Swann 8/25/23
------------------------------------------------------------------------*/

const int NUMPLAYERS = 2;

int winCheck(char gameBoard[]);
void finishBoard(int turn, char (&gameBoard)[9], char gamePieces[]);
void gameStats(int numGames, Player players[]);
void getMove(int turn, Player players[]);
void intro(char gamePieces[], Player players[]);
void playQuit(string &programStatus);
void printBoard(char gameBoard[]);
void resetGame(char (&gameBoard)[9], int &numMoves);
void sortPlayers(Player players[]);
void switchTurn(int &turn);
void updateBoard(int turn, char gamePieces[], char (&gameBoard)[9], Player players[]);
void updateScore(int turn, Player players[], char (&gameBoard)[9]);

/*-----------------------------------------------------------------------
This is the main function.

This function organizes the pocesses of the Tic-Tac-Toe game by calling
predefined fucntions, defining variables and arrays, and utilizing while
loops.
------------------------------------------------------------------------*/
int main() 
{
  int numGames = 0;
  int numMoves = 0;
  int turn = 0;
  string programStatus = "PLAY";

  Player players[NUMPLAYERS];
  char gameBoard[9] = {'1','2','3','4','5','6','7','8','9'};
  char gamePieces[NUMPLAYERS] = {'x','o'};
  
  intro(gamePieces, players);
  
  while (programStatus == "PLAY") 
  {
    while (winCheck(gameBoard) == 0 && numMoves < 9)
    {
      printBoard(gameBoard);
      getMove(turn, players);
      updateBoard(turn, gamePieces, gameBoard, players);
      updateScore(turn, players, gameBoard);
      switchTurn(turn);

      numMoves++;
    }
    
    numGames++;
    finishBoard(turn, gameBoard, gamePieces);
    printBoard(gameBoard);
    gameStats(numGames, players);
    playQuit(programStatus);
    resetGame(gameBoard, numMoves);
  }
}

/*-----------------------------------------------------------------------
This function sorts the players in the array alphabetically by last name
------------------------------------------------------------------------*/
void sortPlayers(Player players[])
{
  Player temp;
  
  if (players[1].lastName > players[0].lastName) 
  {
    temp = players[0];
    players[0] = players[1];
    players[1] = temp;
  }
}

/*-----------------------------------------------------------------------
This function prints out introductory statements and retrieves the 
players first and last names
------------------------------------------------------------------------*/
void intro(char gamePieces[], Player players[])
{
  cout << "Welcome to Tic-Tac-Toe." << endl << endl;

  for (int index = 0; index < NUMPLAYERS; index++)
  {
    cout << "Enter the first and last name of player " << index + 1 << ": ";
    cin >> players[index].firstName;
    cin >> players[index].lastName;
    players[index].fullName = players[index].firstName + " " + players[index].lastName;
    cout << endl;
  }
  
  sortPlayers(players);

  for (int index = 0; index < NUMPLAYERS; index++)
  {
    cout << players[index].fullName << " will be using game piece " << gamePieces[index];
    cout << endl;
  }
  cout << endl;
}

/*-----------------------------------------------------------------------
This function changes the value of the variable that correlates to which 
player currently holds the turn
------------------------------------------------------------------------*/
void switchTurn(int &turn) 
{
  if (turn == 0)
  {
    turn++;
  } 
  else if(turn == 1)
  {
    turn--;
  }
}

/*-----------------------------------------------------------------------
This function asks the user for his/her next move and stores the value in 
an integer variable
------------------------------------------------------------------------*/
void getMove(int turn, Player players[])
{
  cout << players[turn].firstName << " enter your move: ";
  cin >> players[turn].move;
}

/*-----------------------------------------------------------------------
This function prints the current state of the gameboard
------------------------------------------------------------------------*/
void printBoard(char gameBoard[])
{
  cout << "*---*---*---*" << endl;
  cout << "| " << gameBoard[0] << " | " << gameBoard[1] << " | " << gameBoard[2] << " |" << endl;
  cout << "*---*---*---*" << endl;
  cout << "| " << gameBoard[7] << " | " << gameBoard[8] << " | " << gameBoard[3] << " |" << endl;
  cout << "*---*---*---*" << endl;
  cout << "| " << gameBoard[6] << " | " << gameBoard[5] << " | " << gameBoard[4] << " |" << endl;
  cout << "*---*---*---*" << endl;
  cout << endl;
}

/*-----------------------------------------------------------------------
This function takes the user’s selected move and places his or her 
character on the board by modifying the gameboard array
------------------------------------------------------------------------*/
void updateBoard(int turn, char gamePieces[], char (&gameBoard)[9], Player players[])
{
  for (int index = 0; index < 10; index ++) 
  {
    if (players[turn].move == (index + 1))
    {
      gameBoard[index] = gamePieces[turn];
    }
  }
}

/*
-----------------------------------------------------------------------
This function checks the game board for either a winning pattern of 
letter x or letter o and returns a number that correlates to a specific 
win scenerio
------------------------------------------------------------------------
*/
int winCheck(char gameBoard[])
{
  if (gameBoard[0] == gameBoard[1] && gameBoard[0] == gameBoard[2]) 
  {
    return 1;
  } 
  else if (gameBoard[7] == gameBoard[8] && gameBoard[7] == gameBoard[3])
  {
    return 2;
  } 
  else if (gameBoard[6] == gameBoard[5] && gameBoard[6] == gameBoard[4]) 
  {
    return 3;
  } 
  else if (gameBoard[0] == gameBoard[7] && gameBoard[0] == gameBoard[6])
  {
    return 4;
  }
  else if (gameBoard[1] == gameBoard[8] && gameBoard[1] == gameBoard[5])
  {
    return 5;
  }
  else if (gameBoard[2] == gameBoard[3] && gameBoard[2] == gameBoard[4])
  {
    return 6;
  }
  else if (gameBoard[0] == gameBoard[8] && gameBoard[0] == gameBoard[4])
  {
    return 7;
  }
  else if (gameBoard[2] == gameBoard[8] && gameBoard[2] == gameBoard[6]) 
  {
    return 8;
  }
  else return 0;
}

/*-----------------------------------------------------------------------
This function resets the game board and number of moves to their original 
values
------------------------------------------------------------------------*/
void resetGame(char (&gameBoard)[9], int &numMoves)
{
  char originalBoard[9] = {'1','2','3','4','5','6','7','8','9'};
  
  for (int index = 0; index < 10; index++) 
  {
    gameBoard[index] = originalBoard[index];
  }
  numMoves = 0;
}

/*-----------------------------------------------------------------------
This function adds 1 to the last user’s score if the game board result is 
a win
------------------------------------------------------------------------*/
void updateScore(int turn, Player players[], char (&gameBoard)[9])
{
  if (winCheck(gameBoard) != 0)
  {
    players[turn].numWins++;
  }
}

/*-----------------------------------------------------------------------
This function takes the winning pattern of letters and changes them from 
lowercase to uppercase
------------------------------------------------------------------------*/
void finishBoard(int turn, char (&gameBoard)[9], char gamePieces[])
{
  switchTurn(turn);
  char uppercasePiece = toupper(gamePieces[turn]);

  switch (winCheck(gameBoard)) 
  {
    case 1:
      gameBoard[0] = e;
      gameBoard[1] = e;
      gameBoard[2] = e;
      break;
    
    case 2:
      gameBoard[7] = e;
      gameBoard[8] = e;
      gameBoard[3] = e;
      break;

    case 3:
      gameBoard[6] = e;
      gameBoard[5] = e;
      gameBoard[4] = e;
      break;

    case 4:
      gameBoard[0] = e;
      gameBoard[7] = e;
      gameBoard[6] = e;
      break;

    case 5:
      gameBoard[1] = e;
      gameBoard[8] = e;
      gameBoard[5] = e;
      break;

    case 6:
      gameBoard[2] = e;
      gameBoard[3] = e;
      gameBoard[4] = e;
      break;

    case 7:
      gameBoard[0] = e;
      gameBoard[8] = e;
      gameBoard[4] = e;
      break;
    
    case 8:
      gameBoard[2] = e;
      gameBoard[8] = e;
      gameBoard[6] = e;
      break;
  }
}

/*-----------------------------------------------------------------------
This function prints out the game stats: games played and number of wins 
for each player
------------------------------------------------------------------------*/
void gameStats(int numGames, Player players[])
{
  cout << endl << endl;
  cout << "Number of games played: ";
  cout << numGames << endl << endl;
  
  for (int index = 0; index <NUMPLAYERS; index++)
  {
    cout << players[index].fullName;
    cout << " number of wins: ";
    cout << players[index].numWins;
    cout << endl;
  }
  cout << endl;
}

/*-----------------------------------------------------------------------
This function updates the run status of the program by asking the user to 
type “PLAY” or “END” and storing the input in a string variable
------------------------------------------------------------------------*/
void playQuit(string &programStatus)
{
  cout << "Type 'PLAY' to continue playing." << endl;
  cout << "TYPE 'QUIT' to end the game." << endl;
  cout << endl;
  cin >> programStatus;
}
