#include <iostream>
#include <queue>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

struct Coor {
    int x, y;
    int turn;
};

int N;
int dx[] = {-2, -2, 0, 0, 2, 2}, dy[] = {-1, 1, -2, 2, -1, 1};
bool visited[200][200];

int main() {
    int s_x, s_y, e_x, e_y;
    cin >> N;
    cin >> s_x >> s_y >> e_x >> e_y;

    queue<Coor> q;
    int ans = -1;
    q.push({s_x, s_y, 0});

    while (!q.empty()) {
        Coor now = q.front();
        q.pop();

        if (now.x == e_x && now.y == e_y) {
            ans = now.turn;
            break;
        }

        if (visited[now.x][now.y]) continue;
        visited[now.x][now.y] = true;

        for (int i = 0; i < 6; i++) {
            int n_x = now.x + dx[i], n_y = now.y + dy[i];

            if (n_x < 0 || n_y < 0 || n_x >= N || n_y >= N) continue;
            q.push({n_x, n_y, now.turn + 1});
        }
    }

    cout << ans;
}