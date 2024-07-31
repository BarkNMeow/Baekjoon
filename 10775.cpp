#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int G, P;

int parent[100001];

int find_parent(int x) {
    // All gates are filled
    if (x == 0) {
        return -1;
    }

    // Empty spot found
    if (parent[x] == x) {
        return parent[x] = x - 1;
    }

    return parent[x] = find_parent(parent[x]);
}

bool dock_plane(int gate) { return find_parent(gate) != -1; }

int main() {
    cin >> G >> P;
    for (int i = 1; i <= G; i++) parent[i] = i;

    int cnt = 0;
    while (P--) {
        int g;
        cin >> g;
        if (!dock_plane(g)) break;
        cnt++;
    }

    cout << cnt;
}