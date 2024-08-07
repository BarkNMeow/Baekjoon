#include <iostream>
#include <queue>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

const int INF = 0x7FFFFFFF - 10;

struct State {
    unsigned short order;
    int distance;

    bool operator<(const State a) const { return this->distance > a.distance; }
};

struct Action {
    int l, r;
    int cost;
};

// permutation <---> number one-to-one
// https://stackoverflow.com/questions/1506078/fast-permutation-number-permutation-mapping-algorithms
int base[] = {1, 2, 6, 24, 120, 720, 5040};
char *lookup[40320];

unsigned short encode(char *str, int n) {
    int result = 0;
    for (int num = 0; num < n - 1; num++) {
        for (int j = 0; j < n && str[j] != num; j++) {
            if (str[j] > num) result += base[n - 2 - num];
        }
    }

    return result;
}

char *decode(unsigned short enc, int n) {
    if (lookup[enc]) return lookup[enc];

    char *str = new char[n];
    for (int i = 0; i < n; i++) str[i] = n - 1;

    int x = enc;
    for (int num = 0; num < n - 1; num++) {
        int pos = x / base[n - 2 - num], ptr = -1;
        do {
            while (str[++ptr] < num);
        } while (pos--);

        str[ptr] = num;
        x %= base[n - 2 - num];
    }

    return lookup[enc] = str;
}

int dist[40320];
Action adj[10];

int N, M;
int arr[8];

int main() {
    cin >> N;
    char *last_perm = new char[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        last_perm[i] = N - 1 - i;
    }
    int P = encode(last_perm, N) + 1;
    delete[] last_perm;

    cin >> M;
    for (int i = 0; i < M; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        adj[i] = {l - 1, r - 1, c};
    }

    for (int i = 1; i < P; i++) {
        dist[i] = INF;
    }

    priority_queue<State> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        State now = pq.top();
        pq.pop();

        if (now.distance > dist[now.order]) continue;

        char *perm = decode(now.order, N);

        for (int i = 0; i < M; i++) {
            auto a = adj[i];
            swap(perm[a.l], perm[a.r]);
            unsigned short dest = encode(perm, N);

            if (dist[dest] > a.cost + dist[now.order]) {
                dist[dest] = a.cost + dist[now.order];
                pq.push({dest, dist[dest]});
            }

            swap(perm[a.l], perm[a.r]);
        }
    }

    int ans = INF;
    for (int i = 0; i < P; i++) {
        char *order = lookup[i];
        if (!order) continue;

        int j = 0;
        for (; j < N - 1; j++) {
            if (arr[order[j]] > arr[order[j + 1]]) break;
        }

        if (j == N - 1) ans = min(ans, dist[i]);
    }

    cout << (ans == INF ? -1 : ans);
}