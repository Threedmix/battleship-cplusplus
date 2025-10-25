#ifndef SHIP_H
#define SHIP_H

#include <string>
using namespace std;

bool isValidCoord(string s, int &row, int &col);
bool shoot(char board[10][10], int row, int col, bool &sunk);
void waitEnter();

#endif
