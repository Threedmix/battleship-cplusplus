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
        cout << c << ' ';
    }
    cout << endl;
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

bool canPlaceShip(char board[SIZE][SIZE], int row1, int col1, int row2, int col2) {
    int dr;
    int dc;


    if (row1 == row2) {
        dr = 0;
    } else if (row2 > row1) {
        dr = 1;
    } else {
        dr = -1;
    }

    if (col1 == col2) {
        dc = 0;
    } else if (col2 > col1) {
        dc = 1;
    } else {
        dc = -1;
    }

    int len;
    if (abs(row2 - row1) > abs(col2 - col1)) {
        len = abs(row2 - row1) + 1;
    } else {
        len = abs(col2 - col1) + 1;
    }

    int r = row1;
    int c = col1;
    for (int i = 0; i < len; ++i) {
        for (int dr2 = -1; dr2 <= 1; ++dr2) {
            for (int dc2 = -1; dc2 <= 1; ++dc2) {
                int nr = r + dr2;
                int nc = c + dc2;
                if (nr >= 0 && nr < SIZE && nc >= 0 && nc < SIZE) {
                    if (board[nr][nc] == '#') {
                        return false;
                    }
                }
            }
        }
        r += dr;
        c += dc;
    }

    return true;
}

void placeShip(char board[SIZE][SIZE], int row1, int col1, int row2, int col2) {
    int dr;
    int dc;

    if (row1 == row2) {
        dr = 0;
    } else if (row2 > row1) {
        dr = 1;
    } else {
        dr = -1;
    }

    if (col1 == col2) {
        dc = 0;
    } else if (col2 > col1) {
        dc = 1;
    } else {
        dc = -1;
    }

    int len;
    if (abs(row2 - row1) > abs(col2 - col1)) {
        len = abs(row2 - row1) + 1;
    } else {
        len = abs(col2 - col1) + 1;
    }

    int r = row1;
    int c = col1;
    for (int i = 0; i < len; ++i) {
        board[r][c] = '#';
        r += dr;
        c += dc;
    }
}

void clearScreen() {
    system("clear");
}
