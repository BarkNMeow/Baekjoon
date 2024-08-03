#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

// Idea from: https://blog.hoony.me/2023/10/01/find-lis-in-nlogn/

struct Line {
    int start, end;
    bool uncut;
};
bool comp_line(Line a, Line b) { return a.start < b.start; }

struct Element {
    int value;
    int pos;
};
bool comp_elem(Element e, int value) { return e.value < value; }

int N;
Line A[100000];
int prev_elem[100000];
vector<Element> min_elem;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i].start >> A[i].end;
    }
    sort(A, A + N, comp_line);

    min_elem.push_back({~0x7FFFFFFF, -1});
    for (int i = 0; i < N; i++) {
        Element last = min_elem.back();
        if (A[i].end > last.value) {
            min_elem.push_back({A[i].end, i});
            prev_elem[i] = last.pos;
        } else {
            auto lb = lower_bound(min_elem.begin(), min_elem.end(), A[i].end,
                                  comp_elem);
            prev_elem[i] = (*(lb - 1)).pos;
            *lb = {A[i].end, i};
        }
    }

    cout << N - min_elem.size() + 1 << '\n';

    Element longest = min_elem.back();
    int pos = longest.pos;
    while (pos != -1) {
        A[pos].uncut = true;
        pos = prev_elem[pos];
    }

    for (int i = 0; i < N; i++) {
        if (A[i].uncut) continue;
        cout << A[i].start << '\n';
    }
}