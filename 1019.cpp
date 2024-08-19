#include <iostream>
#define LL long long
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

LL cnt[10];
LL N;

int main() {
    cin >> N;
    LL added = 1, digit = 1;
    while (added * 10 <= N) {
        added *= 10;
        digit++;
    }

    while (digit > 0) {
        LL i;
        for (i = 0; i < (N / added); i++) {
            cnt[i] += added;

            for (LL j = 0; j < 10; j++) {
                cnt[j] += (added / 10) * (digit - 1);
            }
        }

        cnt[0] -= added;
        N %= added;
        cnt[i] += N + 1;
        added /= 10;
        digit--;
    }

    for (int i = 0; i < 10; i++) {
        cout << cnt[i] << ' ';
    }
}