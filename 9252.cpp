#include <cmath>
#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int dp[1001][1001];
pair<short, short> last_char[1001][1001];
char a[1001], b[1001];

int main() {
    cin >> a >> b;
    int a_len = 0, b_len = 0;

    for (int i = 0; a[i]; i++) {
        for (int j = 0; b[j]; j++) {
            if (a[i] == b[j]) {
                last_char[i + 1][j + 1] = make_pair(i + 1, j + 1);
                dp[i + 1][j + 1] = 1 + dp[i][j];
            } else {
                if (dp[i + 1][j] > dp[i][j + 1]) {
                    dp[i + 1][j + 1] = dp[i + 1][j];
                    last_char[i + 1][j + 1] = last_char[i + 1][j];
                } else {
                    dp[i + 1][j + 1] = dp[i][j + 1];
                    last_char[i + 1][j + 1] = last_char[i][j + 1];
                }
            }

            b_len = max(b_len, j + 1);
        }
        a_len = max(a_len, i + 1);
    }

    int len = dp[a_len][b_len];
    cout << len;

    if (len == 0) return 0;
    cout << '\n';

    int i = last_char[a_len][b_len].first, j = last_char[a_len][b_len].second;
    int ptr = 0;
    char lcs[1001];

    while (i > 0 && j > 0) {
        lcs[ptr++] = a[i - 1];

        int x = last_char[i - 1][j - 1].first;
        int y = last_char[i - 1][j - 1].second;
        i = x;
        j = y;
    }

    while (ptr) cout << lcs[--ptr];
}