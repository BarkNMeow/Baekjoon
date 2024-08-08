#include <iostream>

#define LL long long
#define MOD 1000000007
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int N, M, K;
long long tree[1 << 21];  // 2 * 1000 * 1000

void change_mul(int idx, long long num) {
    tree[idx] = num;
    idx >>= 1;

    while (idx >= 1) {
        int left = idx * 2, right = idx * 2 + 1;
        if (tree[right] == -1) {
            tree[idx] = tree[left];
        } else {
            tree[idx] = (tree[left] * tree[right]) % MOD;
        }

        idx >>= 1;
    }
}

long long get_mul(int idx, int s, int e, int l_range, int r_range) {
    if (s > e) return -1;
    if (l_range == s && r_range == e) {
        return tree[idx];
    }

    int mid = (l_range + r_range) / 2;
    int left_end = min(mid, e), right_start = max(mid + 1, s);
    long long left = get_mul(idx * 2, s, left_end, l_range, mid);
    long long right = get_mul(idx * 2 + 1, right_start, e, mid + 1, r_range);

    if (left == -1)
        return right;
    else if (right == -1)
        return left;
    return (left * right) % MOD;
}

int main() {
    cin >> N >> M >> K;
    int T = 1;
    while (T < N) {
        T <<= 1;
    }

    int i;
    for (i = 0; i < N; i++) {
        cin >> tree[T + i];
    }
    for (; i < T; i++) {
        tree[T + i] = -1;
    }

    // Initialize segment tree
    for (int i = T - 1; i >= 1; i--) {
        int left = i * 2, right = i * 2 + 1;

        if (tree[right] == -1) {
            tree[i] = tree[left];
        } else {
            tree[i] = (tree[left] * tree[right]) % MOD;
        }
    }

    for (int i = 0; i < M + K; i++) {
        int mode;
        cin >> mode;

        if (mode == 1) {
            int idx;
            long num;
            cin >> idx >> num;
            change_mul(T + idx - 1, num);
        } else {
            int a, b;
            cin >> a >> b;
            cout << get_mul(1, a, b, 1, T) << '\n';
        }
    }
}