#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);

int n, m;
unsigned int adj[101][101];
const unsigned int INF = 0x7FFFFFFF;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = (i == j) ? 0 : INF;
        }
    }

    int a, b;
    while (m--) {
        cin >> a >> b;
        adj[a][b] = adj[b][a] = 1;
    }

    for (int mid = 1; mid <= n; mid++) {
        for (int s = 1; s <= n; s++) {
            for (int e = 1; e <= n; e++) {
                if (adj[s][mid] + adj[mid][e] < adj[s][e]) {
                    adj[s][e] = adj[s][mid] + adj[mid][e];
                }
            }
        }
    }

    int ans = -1, ans_bacon = 0;
    for (int i = 1; i <= n; i++) {
        int bacon = 0;
        for (int j = 1; j <= n; j++) {
            if (adj[i][j] != INF) bacon += adj[i][j];
        }

        if (ans == -1 || ans_bacon > bacon) {
            ans = i;
            ans_bacon = bacon;
        }
    }

    cout << ans;
}