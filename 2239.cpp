#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

short sudoku[9][9];

void find_possible(int x, int y, bool possible[10]) {
    for (int i = 1; i < 10; i++) possible[i] = true;

    // check row and column
    for (int i = 0; i < 9; i++) possible[sudoku[x][i]] = false;
    for (int i = 0; i < 9; i++) possible[sudoku[i][y]] = false;

    // check square
    int sq_x = x / 3 * 3, sq_y = y / 3 * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            possible[sudoku[sq_x + i][sq_y + j]] = false;
    }
}

bool fill_sudoku(int x, int y) {
    if (x >= 9) return true;

    int next_x, next_y;
    if (y == 8) {
        next_x = x + 1;
        next_y = 0;
    } else {
        next_x = x;
        next_y = y + 1;
    }

    if (sudoku[x][y] != 0) {
        return fill_sudoku(next_x, next_y);
    }

    bool possible[10];
    find_possible(x, y, possible);

    for (int num = 1; num <= 9; num++) {
        if (!possible[num]) continue;
        sudoku[x][y] = num;
        if (fill_sudoku(next_x, next_y)) {
            return true;
        }
    }

    sudoku[x][y] = 0;
    return false;
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char c;
            cin >> c;
            sudoku[i][j] = c - '0';
        }
    }

    fill_sudoku(0, 0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j];
        }
        cout << '\n';
    }
}