#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);

int n;
int n_per_size[6];
int t, p;

int main() {
    cin >> n;
    for (int i = 0; i < 6; i++) {
        cin >> n_per_size[i];
    }
    cin >> t >> p;

    int tshirt_bundle = 0;
    for (int i = 0; i < 6; i++) {
        tshirt_bundle += (n_per_size[i] + (t - 1)) / t;
    }

    cout << tshirt_bundle << '\n';
    cout << n / p << ' ' << n % p;
}