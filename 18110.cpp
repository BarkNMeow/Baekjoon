#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);

int n;
short difficulty[300000];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) cin >> difficulty[i];

    if (n == 0) {
        cout << 0;
        return 0;
    }

    int cutoff = (int)round((float)n * 0.15);
    sort(difficulty, difficulty + n);

    int sum = 0;
    for (int i = cutoff; i < n - cutoff; i++) {
        sum += difficulty[i];
    }

    cout << (int)round((float)sum / (n - 2 * cutoff));
}