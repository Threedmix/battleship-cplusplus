#include <iostream>
#include <limits>
#include "../include/ship.h"
#include "../include/board.h"
using namespace std;

bool isValidCoord(string s, int &row, int &col) {
    if (s.length() < 2) return false;

    char letter = toupper(s[0]);
    if (letter < 'A' || letter > 'J') return false;
    col = letter - 'A';

    string num = s.substr(1);

    for (char ch : num) {
        if (!isdigit(ch)) return false;
    }
    row = stoi(num);

    if (row < 0 || row >= SIZE) return false;

    return true;
}

bool shoot(char board[10][10], int row, int col, bool &sunk) {
    sunk = false;
    if (board[row][col] == 'X' || board[row][col] == 'o') {
        cout << "Вы уже стреляли сюда!\n";
        return false;
    }
    if (board[row][col] == '#') {
        board[row][col] = 'X';
        bool alive = false;
        for (int i = 0; i < 10 && !alive; ++i)
            for (int j = 0; j < 10 && !alive; ++j)
                if (board[i][j] == '#') alive = true;

        if (alive) cout << "Попал!\n";
        else { cout << "Потопил!\n"; sunk = true; }
    } else {
        board[row][col] = 'o';
        cout << "Мимо!\n";
        waitEnter();
        clearScreen();
    }
    return true;
}

void waitEnter() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Нажмите Enter";
    cin.get();
}
