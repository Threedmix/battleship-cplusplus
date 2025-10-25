#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
using namespace std;

#define SIZE 10

void initBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE], bool showShips);
bool canPlaceShip(char board[SIZE][SIZE], int row1, int col1, int row2, int col2);
void placeShip(char board[SIZE][SIZE], int row1, int col1, int row2, int col2);
void clearScreen();

#endif
