#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);

int n;
int arr[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int min_diff = 0x7FFFFFFF;
    int liq_a = -1, liq_b = -1;

    for (int start = 0; start < n - 1; start++) {
        int end = start + 1, diff = 0x7FFFFFFF, prev_diff = 0;
        do {
            prev_diff = diff;

            diff = abs(arr[start] + arr[end]);
            if (diff < min_diff) {
                liq_a = arr[start];
                liq_b = arr[end];
                min_diff = diff;
            }

            end++;
        } while (diff < prev_diff && end < n);
    }

    cout << liq_a << ' ' << liq_b;
}