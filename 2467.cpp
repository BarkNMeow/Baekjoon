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

    int s = 0, e = n - 1;

    while (s < e) {
        int diff = arr[s] + arr[e];
        if (abs(diff) < min_diff) {
            min_diff = abs(diff);
            liq_a = arr[s], liq_b = arr[e];
        }

        if (diff > 0)
            e--;
        else
            s++;
    }

    cout << liq_a << ' ' << liq_b;
}