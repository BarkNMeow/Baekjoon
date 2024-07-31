#include <iostream>
#include <vector>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int N, M;

int map[1002][1002];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

vector<int> group_cnt;

int search(int x, int y, int group_id) {
    map[x][y] = group_id;
    int cnt = 1;
    for (int i = 0; i < 4; i++) {
        int next_x = x + dx[i], next_y = y + dy[i];
        if (map[next_x][next_y]) continue;
        cnt += search(next_x, next_y, group_id);
    }

    return cnt;
}

int get_dest_cnt(int x, int y) {
    int ans = 1;
    for (int i = 0; i < 4; i++) {
        int adj_group = map[x + dx[i]][y + dy[i]];
        if (adj_group == -1) continue;

        bool duplicate = false;
        for (int j = 0; j < i; j++) {
            if (adj_group == map[x + dx[j]][y + dy[j]]) {
                duplicate = true;
                break;
            }
        }

        if (duplicate) continue;
        ans = (ans + group_cnt[adj_group]) % 10;
    }

    return ans;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i <= N + 1; i++) {
        map[i][0] = map[i][M + 1] = -1;
    }

    for (int j = 0; j <= M + 1; j++) {
        map[0][j] = map[N + 1][j] = -1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            char input;
            cin >> input;
            map[i][j] = (input == '1') ? -1 : 0;
        }
    }

    group_cnt.push_back(0);
    int group_id = 1;
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= M; y++) {
            if (map[x][y]) continue;
            group_cnt.push_back(search(x, y, group_id++));
        }
    }

    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= M; y++) {
            if (map[x][y] != -1) {
                cout << 0;
            } else {
                cout << get_dest_cnt(x, y);
            }
        }
        cout << '\n';
    }
}