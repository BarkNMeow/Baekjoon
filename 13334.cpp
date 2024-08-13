#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

struct Path {
    int left, right;
    bool operator<(const Path p) const { return this->left > p.left; };
};

bool comp_sort(const Path a, const Path b) { return a.right < b.right; };

Path p[100000];
int N, d;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int h, o;
        cin >> h >> o;
        p[i].left = min(h, o), p[i].right = max(h, o);
    }

    cin >> d;

    sort(p, p + N, comp_sort);

    priority_queue<Path> pq;
    int ptr = 0, max_cnt = 0;

    while (ptr < N) {
        do {
            pq.push(p[ptr]);
            ptr++;
        } while (ptr < N && p[ptr].right == p[ptr - 1].right);

        while (pq.top().left < p[ptr - 1].right - d && !pq.empty()) pq.pop();
        max_cnt = max(max_cnt, (int)pq.size());
    }

    cout << max_cnt;
}