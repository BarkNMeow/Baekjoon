#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);

int n;
long long int arr[5001];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    long long int min_diff = 0x7FFFFFFFFFFFFFFF;
    int liq_a = -1, liq_b = -1, liq_other = -1;

    for (int i = 0; i < n; i++) {
        int s = (i == 0 ? 1 : 0);
        int e = (i == n - 1 ? n - 2 : n - 1);

        while (s < e) {
            long long int diff = arr[i] + arr[s] + arr[e];
            if (abs(diff) < min_diff) {
                min_diff = abs(diff);
                liq_a = arr[s], liq_b = arr[e], liq_other = arr[i];
            }

            if (diff > 0) {
                do {
                    e--;
                } while (e == i);
            } else {
                do {
                    s++;
                } while (s == i);
            }
        }
    }

    int ans[3] = {liq_a, liq_b, liq_other};
    sort(ans, ans + 3);

    for (auto num : ans) cout << num << ' ';
}