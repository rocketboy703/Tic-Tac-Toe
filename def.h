#define DEF_H
#include <iostream>
#include <string>

using namespace std;

//Define abstract data type - Player
struct Player 
{
  string fullName;
  string firstName;
  string lastName;
  int numWins = 0;
  int move;
};
