#include <iostream>
#include <vector>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int N, K;
int kx, ky;
bool attacked[3][3];

int main() {
    cin >> N >> K;
    cin >> kx >> ky;

    // Cannot move to that position
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int nx = kx + dx, ny = ky + dy;
            attacked[dx + 1][dy + 1] = (nx < 1 || ny < 1 || nx > N || ny > N);
        }
    }

    int qx, qy;
    while (K--) {
        cin >> qx >> qy;

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                int nx = kx + dx, ny = ky + dy;
                attacked[dx + 1][dy + 1] |= (qx == nx) || (qy == ny) ||
                                            (qx + qy == nx + ny) ||
                                            (qx - qy == nx - ny);
            }
        }
    }

    bool empty_adj = false;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int nx = kx + dx, ny = ky + dy;
            if (dx == 0 && dy == 0) continue;
            if (!attacked[dx + 1][dy + 1]) {
                empty_adj = true;
                break;
            }
        }
    }

    if (!attacked[1][1]) {
        cout << (empty_adj ? "NONE" : "STALEMATE");
    } else {
        cout << (empty_adj ? "CHECK" : "CHECKMATE");
    }
}