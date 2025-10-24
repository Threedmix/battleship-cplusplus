#include "../include/board.h"

int main() {
    char board1[SIZE][SIZE], board2[SIZE][SIZE];
    initBoard(board1);
    initBoard(board2);

    printBoard(board1, false);

    return 0;
}
