#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "ship.h"

void setupPlayer(char board[SIZE][SIZE], int fleet[], int numShips, int player);
void game(char board1[SIZE][SIZE], char board2[SIZE][SIZE]);
bool allKilled(char board[SIZE][SIZE]);

#endif
