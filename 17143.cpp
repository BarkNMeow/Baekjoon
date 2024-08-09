#include <cassert>
#include <cstring>
#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

struct Shark {
    bool alive;
    short x, y;
    short speed;
    short di;
    short size;
};

int R, C, M;

int dx[] = {0, -1, 1, 0, 0}, dy[] = {0, 0, 0, 1, -1};
short map[101][101];
Shark sk[10001];

short f(int x, int period) {
    int mod = (period - 1) * 2;
    x %= mod;
    if (x < -period + 2) x += mod;
    if (x > period) x -= mod;
    return abs(x - 1) + 1;
}

void move_shark(int shark_id) {
    assert(R >= 2 && C >= 2);
    Shark &s = sk[shark_id];
    short nx = s.x + dx[s.di] * s.speed;
    short ny = s.y + dy[s.di] * s.speed;

    // Invert direction
    if (nx < 1 || nx > R || ny < 1 || ny > C) {
        int collision = 0;
        if (nx < 1)
            collision += -nx / (R - 1) + 1;
        else if (nx > R)
            collision += (nx - 2) / (R - 1);
        if (ny < 1)
            collision += -ny / (C - 1) + 1;
        else if (ny > C)
            collision += (ny - 2) / (C - 1);

        if (collision & 1) {
            s.di += (s.di & 1 ? 1 : -1);
        }
    }

    nx = f(nx, R), ny = f(ny, C);

    if (map[nx][ny] != 0) {
        Shark &foe = sk[map[nx][ny]];
        if (foe.size > s.size) {
            s.alive = false;
            return;
        } else {
            foe.alive = false;
        }
    }

    map[nx][ny] = shark_id;
    s.x = nx, s.y = ny;
}

int main() {
    cin >> R >> C >> M;
    for (int i = 1; i <= M; i++) {
        cin >> sk[i].x >> sk[i].y;
        cin >> sk[i].speed >> sk[i].di >> sk[i].size;

        map[sk[i].x][sk[i].y] = i;
        sk[i].alive = true;
    }

    int sum = 0;
    for (int king = 1; king <= C; king++) {
        // find nearest shark in the column
        for (int i = 1; i <= R; i++) {
            if (map[i][king] == 0) continue;

            int shark_id = map[i][king];
            sum += sk[shark_id].size;
            sk[shark_id].alive = false;
            break;
        }

        // Move shark
        memset(map, 0, sizeof(map));
        for (int i = 1; i <= M; i++) {
            if (!sk[i].alive) continue;
            move_shark(i);
        }
    }

    cout << sum;
}