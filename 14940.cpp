#include <iostream>
#include <queue>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);

int n, m;
int map[1002][1002], result[1002][1002];

struct space {
    int x, y;
    int distance;
} typedef space;

int main() {
    queue<space> q;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];

            if (map[i][j] == 2) q.push({i, j, 0});

            if (map[i][j] != 0) result[i][j] = -1;
        }
    }

    while (!q.empty()) {
        auto head = q.front();
        q.pop();

        int x = head.x, y = head.y;
        if (map[x][y] == 0) continue;

        map[x][y] = 0;
        result[x][y] = head.distance;

        q.push({x + 1, y, head.distance + 1});
        q.push({x - 1, y, head.distance + 1});
        q.push({x, y + 1, head.distance + 1});
        q.push({x, y - 1, head.distance + 1});
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << result[i][j];
            cout << ((j == m) ? '\n' : ' ');
        }
    }
}