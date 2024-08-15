#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int N;

int main() {
    cin >> N;
    int a = 1, b = 1;

    while (N > 1) {
        if (b == 1)
            b = a + b, a = 1;
        else
            a++, b--;

        N--;
    }

    cout << b << ' ' << a;
}