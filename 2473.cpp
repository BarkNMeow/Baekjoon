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
    int ans[3] = {0};

    for (int s = 0; s < n - 2; s++) {
        int m = s + 1, e = n - 1;

        while (m < e) {
            long long int diff = arr[s] + arr[m] + arr[e];
            if (abs(diff) < min_diff) {
                min_diff = abs(diff);
                ans[0] = arr[s], ans[1] = arr[m], ans[2] = arr[e];
            }

            if (diff > 0) {
                e--;
            } else {
                m++;
            }
        }
    }

    for (auto num : ans) cout << num << ' ';
}