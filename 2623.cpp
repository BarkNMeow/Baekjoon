#include <iostream>
#include <queue>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int N, M;
vector<int> adj[1001];
int in_degree[1001];

int main() {
    cin >> N >> M;
    while (M--) {
        int singer_cnt;
        cin >> singer_cnt;

        int prev = -1, to = -1;
        while (singer_cnt--) {
            cin >> to;

            if (prev != -1) {
                // cout << prev << ' ' << to << '\n';
                adj[prev].push_back(to);
                in_degree[to]++;
            }

            prev = to;
        }
    }

    vector<int> ans;
    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (in_degree[i] > 0) continue;
        q.push(i);
    }

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for (auto next : adj[front]) {
            if (--in_degree[next] == 0) q.push(next);
        }
    }

    if (ans.size() != N)
        cout << 0;
    else {
        for (auto singer : ans) cout << singer << '\n';
    }
}