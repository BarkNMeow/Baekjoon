#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int T, n, m;
int A[1000], B[1000];
vector<int> A_sum, B_sum;

void fill_sum(int* arr, int size, vector<int>& vect) {
    for (int s = 0; s < size; s++) {
        int sum = 0;
        for (int e = s; e < size; e++) {
            sum += arr[e];
            vect.push_back(sum);
        }
    }

    sort(vect.begin(), vect.end());
}

int main() {
    cin >> T;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    cin >> m;
    for (int i = 0; i < m; i++) cin >> B[i];

    fill_sum(A, n, A_sum);
    fill_sum(B, m, B_sum);

    long long int ans = 0, prev_cnt = 0;
    int prev_sum = 0x7FFFFFFF;

    for (auto it : A_sum) {
        if (it == prev_sum) {
            ans += prev_cnt;
            continue;
        }

        prev_sum = it;
        prev_cnt = 0;

        int target = T - it;
        auto b_it = lower_bound(B_sum.begin(), B_sum.end(), target);
        while (b_it != B_sum.end() && *b_it == target) {
            ans++;
            prev_cnt++;
            b_it++;
        }
    }

    cout << ans;
}