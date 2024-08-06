#include <iostream>
#include <queue>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

struct Coor {
    int x, y;
};

struct State {
    Coor c;
};

int T;
char init_keys[27];
char map[100][100];

vector<Coor> doors[26];
bool visited[100][100];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

void test() {
    queue<Coor> q;
    for (int i = 0; i < 26; i++) doors[i].clear();

    int h, w;
    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c;
            visited[i][j] = false;
            cin >> c;

            if (i == 0 || j == 0 || i == h - 1 || j == w - 1) {
                if ('A' <= c && c <= 'Z')
                    doors[c - 'A'].push_back({i, j});
                else if (c != '*')
                    q.push({i, j});
            }

            map[i][j] = c;
        }
    }

    cin >> init_keys;
    int key_av = 0;
    for (int i = 0; init_keys[i] && init_keys[i] != '0'; i++) {
        key_av |= 1 << (init_keys[i] - 'a');
        for (auto d : doors[init_keys[i] - 'a']) q.push(d);
    }

    int doc_cnt = 0;
    while (true) {
        int new_keys = 0;
        while (!q.empty()) {
            Coor now = q.front();
            q.pop();
            int x = now.x, y = now.y;

            if (visited[x][y]) continue;
            visited[x][y] = true;

            if ('a' <= map[x][y] && map[x][y] <= 'z')
                new_keys |= 1 << (map[x][y] - 'a');
            else if (map[x][y] == '$')
                doc_cnt++;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
                char next = map[nx][ny];

                if ('A' <= next && next <= 'Z' &&
                    !(key_av & (1 << (next - 'A')))) {
                    doors[next - 'A'].push_back({nx, ny});
                } else if (next != '*') {
                    q.push({nx, ny});
                }
            }
        }

        if (new_keys == 0) break;

        for (int i = 0; i < 26; i++) {
            if (!((1 << i) & new_keys)) continue;
            for (auto d : doors[i]) q.push(d);
        }

        key_av |= new_keys;
    }

    cout << doc_cnt << '\n';
}

int main() {
    cin >> T;

    while (T--) {
        test();
    }
}