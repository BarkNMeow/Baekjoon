#include <iostream>
#include <queue>
#define INF (1 << 20);
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int N;
vector<int> adj[1000001];
int edge_cnt[1000001];

// 0: Root is EA
// 1: Root is not EA
int dp[1000001][2];

int main() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
        edge_cnt[u]++, edge_cnt[v]++;
    }

    // Push leaf nodes
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (edge_cnt[i] == 1) q.push(i);
    }

    int root = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (edge_cnt[node] == -1) continue;
        root = node;
        edge_cnt[node] = -1;

        int parent = 0;
        dp[node][0] = 1;

        for (auto child : adj[node]) {
            if (edge_cnt[child] != -1) {
                parent = child;
                continue;
            }

            dp[node][0] += min(dp[child][0], dp[child][1]);
            dp[node][1] += dp[child][0];
        }

        --edge_cnt[parent];
        if (edge_cnt[parent] == 0 || edge_cnt[parent] == 1) q.push(parent);
    }

    cout << min(dp[root][0], dp[root][1]);
}