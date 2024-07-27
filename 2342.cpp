#include <cmath>
#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int INF = 0x7FFFFFFF - 8;
int seq[100001];
int dp[100001][2][5];

int trans_cost[5][5] = {
    {0, 2, 2, 2, 2}, {2, 1, 3, 4, 3}, {2, 3, 1, 3, 4},
    {2, 4, 3, 1, 3}, {2, 3, 4, 3, 1},
};

void update_dp(int i, int lr, int other) {
    // Invalid case
    if (seq[i] == other) {
        dp[i][lr][other] = INF;
        return;
    }

    // Moving the same foot as before
    int prev_lr = seq[i - 1];
    dp[i][lr][other] =
        min(trans_cost[prev_lr][seq[i]] + dp[i - 1][lr][other], INF);

    if (other != seq[i - 1]) return;

    // Moving the different foot
    for (int prev_other = 0; prev_other < 5; prev_other++) {
        dp[i][lr][other] =
            min(dp[i][lr][other],
                trans_cost[prev_other][seq[i]] + dp[i - 1][!lr][prev_other]);
    }
}

int main() {
    int n = 1;
    while (true) {
        cin >> seq[n++];

        if (seq[n - 1] == 0) {
            break;
        }
    }

    n -= 2;
    // cout << n << endl;

    for (int f = 0; f < 5; f++) {
        dp[0][0][f] = dp[0][1][f] = INF;
    }

    dp[0][0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int lr = 0; lr < 2; lr++)
            for (int other = 0; other < 5; other++) {
                update_dp(i, lr, other);
            }
    }

    int min_cost = INF;
    for (int lr = 0; lr < 2; lr++) {
        for (int other = 0; other < 5; other++) {
            min_cost = min(min_cost, dp[n][lr][other]);
        }
    }

    cout << min_cost;
}