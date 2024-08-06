#include <iostream>
#define V_BIT(x) (1 << ((x) - 1))
#define INF (1 << 24)
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int N;
int adj[17][17];

// Last city, cities to visit => cost to return to starting city (1)
int dp[17][1 << 16];
int one_cnt[1 << 16];

int count_one(int x) {
    int cnt = 0;
    for (; x; cnt++) {
        x &= x - 1;
    }

    return cnt;
}

void update_dp(int now, int to_visit) {
    dp[now][to_visit] = INF;
    for (int mid = 2; mid <= N; mid++) {
        if (!(to_visit & V_BIT(mid))) continue;
        if (adj[now][mid] == 0) continue;
        dp[now][to_visit] = min(dp[now][to_visit],
                                adj[now][mid] + dp[mid][to_visit ^ V_BIT(mid)]);
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) cin >> adj[i][j];
    }

    for (int i = 2; i <= N; i++) {
        dp[i][0] = (adj[i][1] ? adj[i][1] : INF);
    }
    for (int i = 1; i < (1 << N); i++) {
        one_cnt[i] = count_one(i);
    }

    for (int left_cnt = 1; left_cnt <= N; left_cnt++) {
        for (int to_visit = 1; to_visit < (1 << N); to_visit++) {
            if (one_cnt[to_visit] != left_cnt) continue;

            for (int now = 1; now <= N; now++) {
                if (to_visit & V_BIT(now)) continue;
                update_dp(now, to_visit);
            }
        }
    }

    cout << dp[1][(~(-1 << N)) ^ 1];
}