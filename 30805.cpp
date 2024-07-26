#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);

int n, m, seq_ptr = 0;
short a[101], b[101], seq[100];

int find_dict_lcs(int a_start, int b_start) {
    char a_marker[101] = {0};
    char b_marker[101] = {0};

    for (int i = a_start; i <= n; i++) {
        if (a_marker[a[i]] == 0) a_marker[a[i]] = i;
    }

    for (int i = b_start; i <= m; i++) {
        if (b_marker[b[i]] == 0) b_marker[b[i]] = i;
    }

    bool is_common = false;
    for (int i = 100; i > 0; i--) {
        if (a_marker[i] && b_marker[i]) {
            a_start = a_marker[i] + 1;
            b_start = b_marker[i] + 1;
            seq[seq_ptr++] = i;
            is_common = true;
            break;
        }
    }

    if (is_common)
        return 1 + find_dict_lcs(a_start, b_start);
    else
        return 0;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    cin >> m;
    for (int i = 1; i <= m; i++) cin >> b[i];

    cout << find_dict_lcs(1, 1) << '\n';
    for (int i = 0; i < seq_ptr; i++) cout << seq[i] << ' ';
}