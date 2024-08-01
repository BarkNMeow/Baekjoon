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

int N;

struct {
    int value;
    int pos;
} typedef Element;

bool comp(Element e, int value) { return e.value < value; }

vector<Element> min_elem;
int A[1000001], prev_elem[1000001];

int main() {
    min_elem.push_back({~0x7FFFFFFF, -1});
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];

        Element last = min_elem.back();
        if (A[i] > last.value) {
            min_elem.push_back({A[i], i});
            prev_elem[i] = last.pos;
        } else {
            auto lb = lower_bound(min_elem.begin(), min_elem.end(), A[i], comp);
            prev_elem[i] = (*(lb - 1)).pos;
            *lb = {A[i], i};
        }
    }

    cout << min_elem.size() - 1 << '\n';

    stack<int> output;
    Element longest = min_elem.back();
    int pos = longest.pos;
    while (pos != -1) {
        output.push(A[pos]);
        pos = prev_elem[pos];
    }

    while (!output.empty()) {
        cout << output.top() << ' ';
        output.pop();
    }
}