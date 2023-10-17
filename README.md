# Tic-Tac-Toe
William Swann
Data Structures and Algorithms
Professor Ng
28 August 2023

Program and data structure design

This program runs repeat games of Tic-Tac-Toe. 
1.	Two players can play at a time
2.	The users will input the first and last name of each player separated by a space
3.	Game pieces “x” and “o”
4.	Win by placing three pieces in a row horizontally, vertically, or diagonally
5.	The winning game piece pattern will be uppercased at the end of the game
6.	Program will track and display the number of wins for each player and the number of games played
7.	The player with greater last name starts the first game
8.	The loser of the previous game starts the next game
9.	Option to quit or keep playing after each game
10.	Atypical Tic-Tac-Toe board:

*---*---*---*
| 1 | 2 | 3 |
*---*---*---*
| 8 | 9 | 4 |
*---*---*---*
| 7 | 6 | 5 |
*---*---*---* 

Program components
-	main.cpp
o	Function prototypes
o	Main function
o	Function definitions
-	def.h
o	Player structure

Used local variables for basic game stats such as number of games played, number of moves made, keeping track of what player has the current turn, and the run status of the program.

Used arrays for the player struct, game board, and game pieces. The gameboard is a one dimensional array because it simplifies the algorithms performed on it compared to a two dimensional array. The parallel arrays are used for the player struct and game pieces arrays to 
establish a connection between each player and a game piece.

Nested while loops are used to control the status of the overall program as well as the status of each individual game.

