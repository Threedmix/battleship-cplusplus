#include <iostream>
#include <limits>
#include "../include/game.h"
using namespace std;

void setupPlayer(char board[SIZE][SIZE], int fleet[], int numShips, int player) {
    clearScreen();
    cout << "Игрок " << player << " расставляет корабли.\n";
    for (int i = 0; i < numShips; ++i) {
        printBoard(board, true);
        string start, end;
        int row1, col1, row2, col2;
        while (true) {
            cout << "Введите координаты корабля длины " << fleet[i] << " (например A0 A3): ";
            cin >> start >> end;
            if (!isValidCoord(start, row1, col1) || !isValidCoord(end, row2, col2)) {
                cout << "Неверный ввод! Попробуйте снова.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            int len = (abs(row2 - row1) > abs(col2 - col1) ? abs(row2 - row1) : abs(col2 - col1)) + 1;
            if (len != fleet[i]) {
                cout << "Длина корабля не соответствует требуемой. Попробуйте снова.\n";
                continue;
            }
            if (row1 != row2 && col1 != col2) {
                cout << "Корабль должен быть горизонтальным или вертикальным.\n";
                continue;
            }
            if (!canPlaceShip(board, row1, col1, row2, col2)) {
                cout << "Нельзя поставить здесь корабль. Попробуйте снова.\n";
                continue;
            }
            break;
        }
        placeShip(board, row1, col1, row2, col2);
        clearScreen();
    }
    cout << "Игрок " << player << " завершил расстановку всех кораблей.\n";
    waitEnter();
    clearScreen();
}

void game(char board1[SIZE][SIZE], char board2[SIZE][SIZE]) {
    bool turn1 = true;
    while (true) {
        clearScreen();
        char (*ownBoard)[SIZE] = (turn1 ? board1 : board2);
        char (*enemyBoard)[SIZE] = (turn1 ? board2 : board1);

        cout << "Ход Игрока " << (turn1 ? 1 : 2) << endl;
        cout << "Ваше поле:\n";
        printBoard(ownBoard, true);
        cout << "\nПоле противника:\n";
        printBoard(enemyBoard, false);

        string shot;
        int row, col;
        while (true) {
            cout << "Введите координату выстрела (например B2): ";
            cin >> shot;
            if (isValidCoord(shot, row, col)) break;
            cout << "Неверный ввод! Попробуйте снова.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        bool sunk = false;
        if (!shoot(enemyBoard, row, col, sunk)) {
            waitEnter();
            continue;
        }

        waitEnter();

        if (enemyBoard[row][col] == 'o') turn1 = !turn1;
        if (allKilled(enemyBoard)) {
            clearScreen();
            cout << "Игрок " << (turn1 ? 1 : 2) << " победил!\n";
            break;
        }
    }
}

bool allKilled(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            if (board[i][j] == '#') return false;
    return true;
}
