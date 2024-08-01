#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int N;
bool possible[10][10];
int col_occupy = 0;

int fill_bishop(int row) {
    if (row == 2 * N - 1) return 0;

    int ans = 0;
    bool put_once = false;

    for (int i = max(row - N + 1, 0); i <= min(N - 1, row); i++) {
        int j = row - i;

        if (!possible[i][j] || col_occupy & (1 << (i - j + N))) continue;
        put_once = true;

        col_occupy ^= (1 << (i - j + N));
        ans = max(ans, 1 + fill_bishop(row + 1));
        col_occupy ^= (1 << (i - j + N));
    }

    // Case when you can't put one
    if (!put_once) ans = max(ans, fill_bishop(row + 1));

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int input;
            cin >> input;
            possible[i][j] = !!input;
        }
    }

    cout << fill_bishop(0);
}