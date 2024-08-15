#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int N, M;
int value[100000], tree[1 << 18];  // 256 * 1000

int min_idx(int a, int b) {
    if (value[a] < value[b]) return a;
    if (value[a] > value[b]) return b;
    return min(a, b);
}

void change_min(int val_idx, int tree_idx, long long num) {
    value[val_idx] = num;
    tree_idx >>= 1;
    while (tree_idx >= 1) {
        int left = tree_idx * 2, right = tree_idx * 2 + 1;
        if (tree[right] == -1)
            tree[tree_idx] = tree[left];
        else
            tree[tree_idx] = min_idx(tree[left], tree[right]);
        tree_idx >>= 1;
    }
}

int get_min(int idx, int s, int e, int l_range, int r_range) {
    if (s > e) return -1;
    if (l_range == s && r_range == e) {
        return tree[idx];
    }

    int mid = (l_range + r_range) / 2;
    int left_end = min(mid, e), right_start = max(mid + 1, s);
    int left = get_min(idx * 2, s, left_end, l_range, mid);
    int right = get_min(idx * 2 + 1, right_start, e, mid + 1, r_range);

    if (left == -1)
        return right;
    else if (right == -1)
        return left;

    return min_idx(left, right);
}

int main() {
    cin >> N;
    int T = 1;
    while (T < N) {
        T <<= 1;
    }

    {
        int i;
        for (i = 0; i < N; i++) {
            cin >> value[i];
            tree[T + i] = i;
        }

        while (i < T) {
            tree[T + i] = -1;
            i++;
        }
    }

    cin >> M;

    // Initialize segment tree
    for (int i = T - 1; i >= 1; i--) {
        int left = i * 2, right = i * 2 + 1;
        if (tree[right] == -1)
            tree[i] = tree[left];
        else
            tree[i] = min_idx(tree[left], tree[right]);
    }

    while (M--) {
        int mode;
        cin >> mode;

        if (mode == 1) {
            int idx, num;
            cin >> idx >> num;
            change_min(idx - 1, T + idx - 1, num);
        } else {
            int a, b;
            cin >> a >> b;
            cout << get_min(1, a, b, 1, T) + 1 << '\n';
        }
    }
}