#include <cmath>
#include "../include/board.h"

void initBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            board[i][j] = '.';
}

void printBoard(char board[SIZE][SIZE], bool showShips) {
    cout << "  ";
    for (char c = 'A'; c < 'A' + SIZE; ++c) {
        cout << c << ' ' << endl;
    }
    for (int i = 0; i < SIZE; ++i) {
        cout << i << ' ';
        for (int j = 0; j < SIZE; ++j) {
            char c = board[i][j];
            if (!showShips && c == '#') c = '.';
            cout << c << ' ';
        }
        cout << endl;
    }
}
