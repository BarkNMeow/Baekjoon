#include <functional>
#include <iostream>
#include <queue>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

struct Edge {
    int end;
    short cost;

    bool operator<(const Edge e) const { return this->cost > e.cost; }
} typedef Edge;

int n, m;
bool visited[100001];
vector<pair<int, short>> adj[100001];
priority_queue<Edge> pq;

int main() {
    cin >> n >> m;
    while (m--) {
        int a, b;
        short c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }

    pq.push({1, 0});
    int total_cost = 0, max_cost = 0;

    while (!pq.empty()) {
        Edge e = pq.top();
        pq.pop();

        int end = e.end, cost = e.cost;

        if (visited[end]) continue;

        total_cost += cost;
        max_cost = max(cost, max_cost);
        visited[end] = true;

        for (auto it : adj[end]) {
            if (visited[it.first]) continue;
            pq.push({it.first, it.second});
        }
    }

    cout << total_cost - max_cost;
}