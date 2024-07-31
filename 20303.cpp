#include <iostream>
#include <vector>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int N, M, K;

bool visited[30001];
short children[30001];
int candy_input[30001], candy[30001];
int dp[30001][3001];

vector<short> adj[30001];

void search_group(short c, int ptr) {
    children[ptr]++;
    candy[ptr] += candy_input[c];
    visited[c] = true;

    for (auto fr : adj[c]) {
        if (visited[fr]) continue;
        search_group(fr, ptr);
    }
}

int init_group() {
    int ptr = 1;
    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;
        search_group(i, ptr++);
    }

    ptr--;
    return ptr;
}

int main() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) cin >> candy_input[i];
    while (M--) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int G = init_group();

    for (int i = 1; i <= G; i++) {
        for (int k = 1; k <= K; k++) {
            dp[i][k] = dp[i - 1][k];
            if (k > children[i])
                dp[i][k] = max(dp[i][k], candy[i] + dp[i - 1][k - children[i]]);
        }
    }

    cout << dp[G][K];
}