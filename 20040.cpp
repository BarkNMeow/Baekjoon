#include <cmath>
#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int N, M;
int parent[500000];

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) parent[i] = i;

    for (int turn = 1; turn <= M; turn++) {
        int a, b;
        cin >> a >> b;

        a = find(a), b = find(b);

        if (a == b) {
            cout << turn;
            return 0;
        }

        parent[a] = b;
    }

    cout << 0;
}