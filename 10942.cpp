#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int N, M;

int seq[2001];
bool dp[2001][2001];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> seq[i];

    for (int i = 1; i <= N; i++) dp[i][i - 1] = dp[i][i] = true;

    for (int len = 1; len <= N; len++) {
        for (int s = 1; s + len <= N; s++) {
            int e = s + len;
            if (seq[s] == seq[e])
                dp[s][e] = dp[s + 1][e - 1];
            else
                dp[s][e] = false;
        }
    }

    cin >> M;
    while (M--) {
        int s, e;
        cin >> s >> e;
        cout << (int)dp[s][e] << '\n';
    }
}