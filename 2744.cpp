#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

char word[101];

int main() {
    cin >> word;
    for (int i = 0; word[i]; i++) {
        if ('a' <= word[i] && word[i] <= 'z') {
            cout << (char)(word[i] - 'a' + 'A');
        } else {
            cout << char(word[i] - 'A' + 'a');
        }
    }
}