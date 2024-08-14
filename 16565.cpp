#include <iostream>
#define MOD 10007
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int N;
int memo[53][53];

int C(int n, int k) {
    if (n == k || k == 0)
        return 1;
    else if (memo[n][k])
        return memo[n][k];
    else
        return memo[n][k] = (C(n - 1, k) + C(n - 1, k - 1)) % MOD;
}

int main() {
    cin >> N;
    int sum = 0, sign = 1, k = 1;
    while (k <= min(13, N / 4)) {
        int delta = (C(13, k) * C(52 - 4 * k, N - k * 4)) % MOD;
        sum = (sum + sign * delta + MOD) % MOD;
        k++;
        sign *= -1;
    }

    cout << sum;
}