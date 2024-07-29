#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int N;
int row[501], col[501];
int dp[501][501];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> row[i] >> col[i];
    }

    // Multiply matricies in [s, e] = [s, m] * [m + 1, e]
    // 구간 크기 순으로 돌아야 sub problem이 존재
    for (int len = 1; len < N; len++) {
        for (int s = 1; s + len <= N; s++) {
            int e = s + len;
            dp[s][e] = 0x7FFFFFFF;
            for (int m = s; m < e; m++) {
                int mult_cnt = row[s] * col[m] * col[e];
                dp[s][e] = min(dp[s][e], dp[s][m] + dp[m + 1][e] + mult_cnt);
            }
        }
    }

    cout << dp[1][N];
}