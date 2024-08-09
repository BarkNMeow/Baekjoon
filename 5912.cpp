#include <algorithm>
#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int N, K;
short hay[1000001];

int main() {
    cin >> N >> K;
    while (K--) {
        int s, e;
        cin >> s >> e;
        hay[s]++, hay[e + 1]--;
    }

    short hay_cnt = 0;
    for (int i = 1; i <= N; i++) {
        hay_cnt += hay[i];
        hay[i] = hay_cnt;
    }

    sort(hay + 1, hay + N + 1);
    cout << hay[(N + 1) / 2];
}