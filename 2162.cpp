#include <iostream>
#include <vector>
using namespace std;
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy1__ = cin.tie(NULL);
auto __dummy2__ = cout.tie(NULL);

struct Segment {
    int x1, y1;
    int x2, y2;
};

int N;
int parent[3001];
int seg_cnt[3001];
Segment s[3001];

int find(int idx) {
    if (parent[idx] == idx) return idx;
    return parent[idx] = find(parent[idx]);
}

int merge(int a, int b) {
    int a_root = find(a);
    int b_root = find(b);

    if (a_root == b_root) return -1;

    parent[a] = parent[b] = min(a_root, b_root);
    return parent[a];
}

bool denom_test(int denom, int numer) {
    if (denom > 0 && (numer < 0 || numer > denom))
        return false;
    else if (denom < 0 && (numer > 0 || numer < denom))
        return false;

    return true;
}

bool intersect(Segment a, Segment b) {
    int Ax = a.x2 - a.x1, Ay = a.y2 - a.y1;
    int Bx = b.x1 - b.x2, By = b.y1 - b.y2;
    int Cx = a.x1 - b.x1, Cy = a.y1 - b.y1;

    int denom = Ay * Bx - Ax * By;
    int A_numer = By * Cx - Bx * Cy;

    if (denom == 0) {
        if (A_numer != 0)
            return false;
        else {
            return (max(a.x1, a.x2) >= min(b.x1, b.x2) &&
                    min(a.x1, a.x2) <= max(b.x1, b.x2) &&
                    max(a.y1, a.y2) >= min(b.y1, b.y2) &&
                    min(a.y1, a.y2) <= max(b.y1, b.y2));
        }
    }

    bool intersect = denom_test(denom, A_numer);

    if (!intersect) {
        return false;
    } else {
        long long B_numer = Ax * Cy - Ay * Cx;
        return denom_test(denom, B_numer);
    }
}

int main() {
    cin >> N;
    int group_cnt = 0;
    for (int i = 1; i <= N; i++) {
        cin >> s[i].x1 >> s[i].y1 >> s[i].x2 >> s[i].y2;
        parent[i] = i;
        group_cnt++;

        vector<int> merge_list;
        for (int j = 1; j < i; j++) {
            if (intersect(s[i], s[j])) merge_list.push_back(j);
        }

        int target = i;
        for (auto other : merge_list) {
            int result = merge(target, find(other));
            if (result == -1) continue;

            target = result;
            group_cnt--;
        }
    }

    int max_seg = -1;
    for (int i = 1; i <= N; i++) {
        int ancestor = find(i);
        seg_cnt[ancestor]++;
        max_seg = max(max_seg, seg_cnt[ancestor]);
    }

    cout << group_cnt << '\n' << max_seg;
}