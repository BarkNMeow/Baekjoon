#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int N, M, K;
long long tree[1 << 21];  // 2 * 1000 * 1000

void change_sum(int idx, long long num) {
    long long diff = -tree[idx] + num;
    while (idx >= 1) {
        tree[idx] += diff;
        idx >>= 1;
    }
}

long long get_sum(int idx, int s, int e, int l_range, int r_range) {
    if (s > e) return 0;
    if (l_range == s && r_range == e) {
        return tree[idx];
    }

    int mid = (l_range + r_range) / 2;
    int left_end = min(mid, e), right_start = max(mid + 1, s);
    long long left = get_sum(idx * 2, s, left_end, l_range, mid);
    long long right = get_sum(idx * 2 + 1, right_start, e, mid + 1, r_range);

    return left + right;
}

int main() {
    cin >> N >> M >> K;
    int T = 1;
    while (T < N) {
        T <<= 1;
    }

    for (int i = 0; i < N; i++) {
        cin >> tree[T + i];
    }

    // Initialize segment tree
    for (int i = T - 1; i >= 1; i--) {
        int left = i * 2, right = i * 2 + 1;
        tree[i] = tree[left] + tree[right];
    }

    for (int i = 0; i < M + K; i++) {
        int mode;
        cin >> mode;

        if (mode == 1) {
            int idx;
            long num;
            cin >> idx >> num;
            change_sum(T + idx - 1, num);
        } else {
            int a, b;
            cin >> a >> b;
            cout << get_sum(1, a, b, 1, T) << '\n';
        }
    }
}