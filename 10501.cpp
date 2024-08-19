#include <iostream>
#include <string>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int len[101];

int main() {
    string input;
    int n = 0, max_len = 0;

    while (getline(cin, input)) {
        max_len = max(max_len, (int)input.size());
        len[n++] = input.size();
    }

    int ragged = 0;
    for (int i = 0; i < n - 1; i++) {
        ragged += (max_len - len[i]) * (max_len - len[i]);
    }

    cout << ragged;
}