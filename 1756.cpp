#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int D, N;
int stove[300001];

int main() {
    cin >> D >> N;

    stove[0] = 0x7fffffff;
    for (int i = 1; i <= D; i++) {
        int radius;
        cin >> radius;
        stove[i] = min(stove[i - 1], radius);
    }

    int ptr = D + 1, pizza;
    while (N--) {
        cin >> pizza;
        do {
            ptr--;
        } while (ptr > 0 && stove[ptr] < pizza);
    }

    cout << max(0, ptr);
}