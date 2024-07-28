#include <cmath>
#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int N, M;
int memory[101], cost[101];
int dp[101][10001];

int main() {
    cin >> N >> M;

    int cost_sum = 0;
    for (int i = 1; i <= N; i++) cin >> memory[i];
    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
        cost_sum += cost[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int c = 0; c <= cost_sum; c++) {
            dp[i][c] = dp[i - 1][c];
            if (c >= cost[i])
                dp[i][c] = max(dp[i][c], memory[i] + dp[i - 1][c - cost[i]]);
        }
    }

    for (int c = 0; c <= cost_sum; c++) {
        if (dp[N][c] >= M) {
            cout << c;
            break;
        }
    }
}