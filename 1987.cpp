#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);

int r, c;
char map[22][22];

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

int search(int x, int y, int visit_alphabet) {
    visit_alphabet |= 1 << (map[x][y] - 'A');

    int max_cnt = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!(visit_alphabet & (1 << (map[nx][ny] - 'A'))) && map[nx][ny] != 0)
            max_cnt = max(max_cnt, search(nx, ny, visit_alphabet));
    }

    return 1 + max_cnt;
}

int main() {
    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> map[i][j];
        }
    }

    cout << search(1, 1, 0);
}