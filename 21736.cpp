#include <cstring>
#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);

int n, m;
char map[602][602];

int search(int x, int y) {
    if (map[x][y] == 'X') return 0;

    int sum = 0;

    if (map[x][y] == 'P') sum += 1;
    map[x][y] = 'X';

    sum += search(x - 1, y);
    sum += search(x + 1, y);
    sum += search(x, y - 1);
    sum += search(x, y + 1);

    return sum;
}

int main() {
    memset(map, 'X', 602 * 602);
    cin >> n >> m;

    int s_x = 0, s_y = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];

            if (map[i][j] == 'I') {
                s_x = i;
                s_y = j;
            }
        }
    }

    int people = search(s_x, s_y);
    if (people == 0)
        cout << "TT";
    else
        cout << people;
}