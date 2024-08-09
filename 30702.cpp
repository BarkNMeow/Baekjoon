#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int N, M;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

char A[52][52], B[52][52];

bool search(int x, int y, char color) {
    if (!A[x][y]) return true;

    char current_color = A[x][y];
    A[x][y] = 0;
    if (B[x][y] != color) return false;

    bool possible = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (A[nx][ny] != current_color) continue;

        possible &= search(nx, ny, color);
        if (!possible) break;
    }

    return possible;
}

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) cin >> A[i][j];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) cin >> B[i][j];
    }

    bool possible = true;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            char color = B[i][j];
            possible &= search(i, j, color);

            if (!possible) break;
        }

        if (!possible) break;
    }

    cout << (possible ? "YES" : "NO");
}