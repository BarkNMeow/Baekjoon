#include <cmath>
#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);

int n;
short fruit[200001];

int main() {
    int freq[10] = {0};
    int freq_cnt = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> fruit[i];
    }

    int s = 0, e = 0;
    int max_len = 0;

    while (e <= n) {
        if (freq_cnt <= 2) {
            max_len = max(max_len, e - s);

            freq[fruit[e]]++;
            if (freq[fruit[e]] == 1) freq_cnt++;
            e++;
        } else {
            freq[fruit[s]]--;
            if (freq[fruit[s]] == 0) freq_cnt--;
            s++;
        }
    }

    cout << max_len;
}