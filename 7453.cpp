#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int n;
int A[4000], B[4000], C[4000], D[4000];

vector<int> ABsum, CDsum;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ABsum.push_back(A[i] + B[j]);
            CDsum.push_back(C[i] + D[j]);
        }
    }

    sort(ABsum.begin(), ABsum.end());
    sort(CDsum.begin(), CDsum.end());

    long long ans = 0;
    int prev_ab = 0x7FFFFFFF, prev_cnt = 0;
    for (auto ab : ABsum) {
        if (prev_ab == ab) {
            ans += prev_cnt;
            continue;
        }

        prev_ab = ab;
        prev_cnt = upper_bound(CDsum.begin(), CDsum.end(), -ab) -
                   lower_bound(CDsum.begin(), CDsum.end(), -ab);

        ans += prev_cnt;
    }

    cout << ans;
}