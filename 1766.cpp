#include <functional>
#include <iostream>
#include <queue>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int N, M;
short in_degree[32001];
vector<short> adj[32001];
priority_queue<short, vector<short>, greater<short>> pq;

int main() {
    cin >> N >> M;
    while (M--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        in_degree[b]++;
    }

    for (short i = 1; i <= N; i++) {
        if (in_degree[i]) continue;
        pq.push(i);
    }

    while (!pq.empty()) {
        short prob = pq.top();
        cout << prob << ' ';
        pq.pop();

        for (auto next : adj[prob]) {
            if (--in_degree[next] == 0) pq.push(next);
        }
    }
}