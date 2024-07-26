#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int N, S;
short seq[100001];

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) cin >> seq[i];

    int min_len = N + 1;
    int s = 0, e = 0, sum = 0;
    while (e <= N) {
        if (sum < S) {
            sum += seq[e++];
        } else {
            min_len = min(min_len, e - s);
            sum -= seq[s++];
        }
    }

    cout << (min_len == N + 1 ? 0 : min_len);
}