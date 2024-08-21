#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int T;

void solve() {
    long long n, a, b;
    cin >> n >> a >> b;

    int lsb = 0;
    while ((a & 1) == 0) {
        lsb++;
        a >>= 1;
    }

    cout << n - lsb << '\n';
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}