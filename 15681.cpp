#include <iostream>
#include <vector>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int N, R, Q;
vector<int> edge[100001];
int subsize[100001];

int init_subsize(int root, int parent) {
    int sum = 1;
    for (auto child : edge[root]) {
        if (child == parent) continue;

        sum += init_subsize(child, root);
    }

    return subsize[root] = sum;
}

int main() {
    cin >> N >> R >> Q;

    for (int i = 0; i < N - 1; i++) {
        int start, end;
        cin >> start >> end;
        edge[start].push_back(end);
        edge[end].push_back(start);
    }

    init_subsize(R, 0);

    while (Q--) {
        int query;
        cin >> query;
        cout << subsize[query] << '\n';
    }
}