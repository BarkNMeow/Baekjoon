#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

long long A, B;

long long binary_digit(long long x) {
    long long digit = 0;
    while (x > 0) {
        digit++;
        x >>= 1;
    }

    return digit;
}

long long count_ones(long long x) {
    long long ans = 0;
    long long digit = binary_digit(x);

    while (digit > 0) {
        // 0~01111...111
        if (digit > 1) ans += (1LL << (digit - 2)) * (digit - 1);

        // "1"~~~~~~~~
        x ^= (1LL << (digit - 1));
        ans += x + 1;
        digit = binary_digit(x);
    }

    return ans;
}

int main() {
    cin >> A >> B;
    cout << count_ones(B) - count_ones(A - 1);
}