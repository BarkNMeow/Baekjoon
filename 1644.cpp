#include <iostream>
#include <vector>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int N;
bool eratos[4000001];
vector<int> prime;

int main() {
    cin >> N;

    // finding primes
    for (long long int i = 2; i <= N; i++) {
        if (eratos[i]) continue;

        prime.push_back(i);

        for (long long int j = i * i; j <= N; j += i) {
            eratos[j] = true;
        }
    }

    // Checking sum via 2 ptr algorithm
    int sum = 0, cnt = 0;
    auto s = prime.begin(), e = prime.begin();

    while (true) {
        if (sum < N) {
            if (e == prime.end()) break;
            sum += *e;
            e++;
        } else {
            if (sum == N) cnt++;
            sum -= *s;
            s++;
        }
    }

    cout << cnt;
}