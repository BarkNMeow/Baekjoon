#include <algorithm>
#include <cstring>
#include <functional>
#include <iostream>
#include <queue>
using namespace std;
// Key Idea: Optimal edge = between adjacent points on the axis

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

struct Edge {
    int end;
    int cost;

    bool operator<(const Edge e) const { return this->cost > e.cost; }
};

int N;
Edge adj[100000][6];
int coor[3][100000];
int ord[100000];

function<bool(int, int)> comp_sort(int i) {
    return [i](int a, int b) { return coor[i][a] < coor[i][b]; };
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> coor[j][i];
        }

        ord[i] = i;
    }

    for (int i = 0; i < 3; i++) {
        sort(ord, ord + N, comp_sort(i));
        for (int j = 0; j < N - 1; j++) {
            int start = ord[j], end = ord[j + 1];
            int cost = abs(coor[i][start] - coor[i][end]);
            adj[start][i * 2] = {end, cost};
            adj[end][i * 2 + 1] = {start, cost};
        }
    }

    memset(ord, 0, sizeof(ord));
    priority_queue<Edge> pq;
    pq.push({0, 0});
    int *visited = ord;

    long long cost = 0;
    while (!pq.empty()) {
        Edge e = pq.top();
        pq.pop();
        if (visited[e.end]) continue;

        cost += (long long)e.cost;
        visited[e.end] = true;

        for (auto e : adj[e.end]) {
            pq.push(e);
        }
    }

    cout << cost;
}