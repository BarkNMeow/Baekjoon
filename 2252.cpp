#include <cstdint>
#include <iostream>
#include <queue>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int N, M;
vector<uint16_t> adj[32001];
int in_degree[32001];

int main() {
    cin >> N >> M;
    while (M--) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        in_degree[B]++;
    }

    queue<uint16_t> q;
    for (int i = 1; i <= N; i++) {
        if (in_degree[i] > 0) continue;
        q.push(i);
    }

    while (!q.empty()) {
        uint16_t node = q.front();
        q.pop();

        cout << node << ' ';
        for (auto dest : adj[node]) {
            in_degree[dest]--;
            if (in_degree[dest] == 0) q.push(dest);
        }
    }
}