#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

struct Node {
    int min_val, max_val;
};

int N, M;
Node tree[1 << 18];  // 256 * 1000

Node find_min_max(int idx, int s, int e, int l_range, int r_range) {
    if (s > e) return {0, 0};
    if (l_range == s && r_range == e) {
        return tree[idx];
    }

    int mid = (l_range + r_range) / 2;
    int left_end = min(mid, e), right_start = max(mid + 1, s);
    Node left = find_min_max(idx * 2, s, left_end, l_range, mid);
    Node right = find_min_max(idx * 2 + 1, right_start, e, mid + 1, r_range);

    if (left.min_val == 0)
        return right;
    else if (right.min_val == 0)
        return left;

    int min_val = min(left.min_val, right.min_val);
    int max_val = max(left.max_val, right.max_val);

    return {min_val, max_val};
}

int main() {
    cin >> N >> M;
    int T = 1;
    while (T < N) {
        T <<= 1;
    }

    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        tree[T + i].min_val = tree[T + i].max_val = val;
    }

    // Initialize segment tree
    for (int i = T - 1; i >= 1; i--) {
        int left = i * 2, right = i * 2 + 1;
        if (tree[right].min_val == 0) {
            if (tree[left].min_val != 0) {
                tree[i].min_val = tree[left].min_val;
                tree[i].max_val = tree[left].max_val;
            }
        } else {
            tree[i].min_val = min(tree[left].min_val, tree[right].min_val);
            tree[i].max_val = max(tree[left].max_val, tree[right].max_val);
        }
    }

    while (M--) {
        int a, b;
        cin >> a >> b;

        Node result = find_min_max(1, a, b, 1, T);
        cout << result.min_val << ' ' << result.max_val << '\n';
    }
}