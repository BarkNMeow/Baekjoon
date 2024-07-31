#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

long long N, M;

int main() {
    cin >> N >> M;
    if (N >= M)
        cout << N - M;
    else
        cout << M - N;
}