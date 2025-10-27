#include "../include/board.h"
#include "../include/game.h"

int main() {
    char board1[SIZE][SIZE], board2[SIZE][SIZE];
    initBoard(board1);
    initBoard(board2);

    int fleet[] = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
    int numShips = 10;

    setupPlayer(board1, fleet, numShips, 1);
    setupPlayer(board2, fleet, numShips, 2);

    game(board1, board2);

    return 0;
}
