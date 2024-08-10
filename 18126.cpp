#include <iostream>
#include <vector>

#define LL long long
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

struct Edge {
    short end;
    LL cost;
};

int N;

bool visited[5001];
vector<Edge> adj[5001];

LL search(short x) {
    visited[x] = true;

    LL max_cost = 0;
    for (auto e : adj[x]) {
        if (visited[e.end]) continue;
        max_cost = max(max_cost, e.cost + search(e.end));
    }

    return max_cost;
}

int main() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        short s, e;
        LL cost;
        cin >> s >> e >> cost;

        adj[s].push_back({e, cost});
        adj[e].push_back({s, cost});
    }

    cout << search(1);
}