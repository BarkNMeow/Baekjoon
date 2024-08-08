#include <iostream>

#define MERGE (1 << 31)
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int N;
int board[20][20];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

void copy_board(int src[20][20], int dst[20][20]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dst[i][j] = src[i][j];
        }
    }
}

int move_block(int di) {
    int max_block = -1;
    for (int _i = 0; _i < N; _i++) {
        int i = (dx[di] > 0 ? N - 1 - _i : _i);
        for (int _j = 0; _j < N; _j++) {
            int j = (dy[di] > 0 ? N - 1 - _j : _j);

            if (board[i][j] == 0) continue;

            int num = board[i][j];
            int x = i, y = j;
            board[i][j] = 0;

            while (true) {
                int nx = x + dx[di], ny = y + dy[di];
                if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
                    board[x][y] = num;
                    break;
                }

                if (board[nx][ny] != 0) {
                    if (board[nx][ny] == num) {
                        num = (board[nx][ny] << 1) | MERGE;
                        x = nx, y = ny;
                    }

                    board[x][y] = num;
                    break;
                }

                x = nx, y = ny;
            }

            max_block = max(max_block, num ^ MERGE);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] &= ~MERGE;
        }
    }

    return max_block;
}

int play(int turn, int max_block) {
    if (turn == 5) {
        return max_block;
    }

    int max_total = max_block;
    int original[20][20];
    copy_board(board, original);

    for (int i = 0; i < 4; i++) {
        int new_block = move_block(i);
        max_total = max(max_total, play(turn + 1, new_block));
        copy_board(original, board);
    }

    return max_total;
}

int main() {
    cin >> N;

    int max_block = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            max_block = max(max_block, board[i][j]);
        }
    }

    cout << play(0, max_block);
}