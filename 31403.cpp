#include <iostream>
#include <string>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << a + b - c << '\n';

    string agg = to_string(a) + to_string(b);
    cout << stoi(agg) - c;
}