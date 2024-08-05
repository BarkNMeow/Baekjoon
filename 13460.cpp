#include <iostream>
#include <queue>

#define R 0
#define B 1

using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

struct State {
    int turn;
    int x[2], y[2];
};

int N, M;
char board[10][10];

queue<State> q;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int RB[2] = {R, B}, BR[2] = {B, R};

int main() {
    State init;
    init.turn = 0;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];

            if (board[i][j] == 'R') {
                init.x[R] = i, init.y[R] = j;
                board[i][j] = '.';
            } else if (board[i][j] == 'B') {
                init.x[B] = i, init.y[B] = j;
                board[i][j] = '.';
            }
        }
    }

    int turn = -1;
    q.push(init);

    while (!q.empty()) {
        State now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            State next;
            for (int c = 0; c < 2; c++)
                next.x[c] = now.x[c], next.y[c] = now.y[c];
            next.turn = now.turn + 1;

            int *order;
            if (dx[i] != 0) {
                order = ((dx[i] > 0) != (now.x[R] > now.x[B]) ? BR : RB);
            } else {
                order = ((dy[i] > 0) != (now.y[R] > now.y[B]) ? BR : RB);
            }

            bool hole_in[2] = {false, false};
            for (int c_i = 0; c_i < 2; c_i++) {
                int c = order[c_i];
                while (true) {
                    next.x[c] += dx[i], next.y[c] += dy[i];

                    if (board[next.x[c]][next.y[c]] != '.' ||
                        (next.x[R] == next.x[B] && next.y[R] == next.y[B])) {
                        if (board[next.x[c]][next.y[c]] == 'O') {
                            hole_in[c] = true;
                            next.x[c] = next.y[c] = -1;
                        } else {
                            next.x[c] -= dx[i], next.y[c] -= dy[i];
                        }

                        break;
                    }
                }
            }

            if (hole_in[B]) {
                continue;
            } else if (hole_in[R]) {
                turn = next.turn;
                break;
            }

            if (next.turn < 10) q.push(next);
        }

        if (turn != -1) break;
    }

    cout << turn;
}
