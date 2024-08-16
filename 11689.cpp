#include <iostream>
#define LL long long
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

bool is_prime(LL n) {
    for (LL i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }

    return true;
}

LL n;
int main() {
    cin >> n;

    LL ans = n;
    for (LL prime = 2; prime * prime <= n; prime++) {
        if (!is_prime(prime)) continue;
        if (ans % prime != 0) continue;

        ans = ans / prime * (prime - 1);
        while (n % prime == 0) {
            n /= prime;
        }
    }

    if (n > 1) ans = ans / n * (n - 1);
    cout << ans;
}