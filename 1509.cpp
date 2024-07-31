#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

// Help from: https://www.acmicpc.net/board/view/20536

char str[2501];
int dp[2501];
bool dp_palindrome[2501][2501];

bool is_palindrome(int s, int e, char str[]) {
    bool result;
    if (e == s)
        result = true;
    else if (e == s + 1)
        result = (str[s] == str[e]);
    else
        result = (str[s] == str[e]) ? dp_palindrome[s + 1][e - 1] : false;

    return dp_palindrome[s][e] = result;
}

int main() {
    cin >> str;
    int n = strlen(str);

    for (int i = 0; i < n; i++) dp[i] = i + 1;

    // Both inclusive
    for (int e = 0; e < n; e++) {
        for (int s = 0; s <= e; s++) {
            if (!is_palindrome(s, e, str)) {
                continue;
            }

            dp[e] = (s == 0 ? 1 : min(dp[e], dp[s - 1] + 1));
        }
    }

    cout << dp[n - 1];
}