#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int N, M;

char map[1002][1002];
int group[1002][1002];

int search_group(int x, int y, int group_id) {
    while (map[x][y]) {
        char direction = map[x][y];
        map[x][y] = 0;
        group[x][y] = group_id;

        switch (direction) {
            case 'D':
                x++;
                break;
            case 'L':
                y--;
                break;
            case 'R':
                y++;
                break;
            case 'U':
                x--;
                break;
        }
    }

    if (group[x][y] == group_id || group[x][y] == 0) return 1;
    return 0;
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) cin >> map[i][j];
    }

    int ans = 0;
    int group_id = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (!map[i][j]) continue;
            ans += search_group(i, j, group_id++);
        }
    }

    cout << ans;
}