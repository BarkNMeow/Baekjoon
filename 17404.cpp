#include <cmath>
#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int N;
short cost[1001][3];
int dp[1001][3][3];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) cin >> cost[i][j];
    }

    for (int start = 0; start < 3; start++) {
        for (int color = 0; color < 3; color++)
            if (start == color)
                dp[1][color][start] = cost[1][color];
            else
                dp[1][color][start] = 1000 * 1000 + 1;
    }

    for (int start = 0; start < 3; start++) {
        for (int i = 2; i <= N; i++) {
            dp[i][0][start] =
                cost[i][0] + min(dp[i - 1][1][start], dp[i - 1][2][start]);
            dp[i][1][start] =
                cost[i][1] + min(dp[i - 1][0][start], dp[i - 1][2][start]);
            dp[i][2][start] =
                cost[i][2] + min(dp[i - 1][1][start], dp[i - 1][0][start]);
        }
    }

    int min_cost = 1000 * 1000 + 1;
    for (int start = 0; start < 3; start++) {
        for (int end = 0; end < 3; end++) {
            if (start == end) continue;
            min_cost = min(dp[N][end][start], min_cost);
        }
    }

    cout << min_cost;
}