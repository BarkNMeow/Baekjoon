#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

char str[3000];

int str_to_num(char *start, char *end) {
    int sum = 0;
    while (start < end) {
        if (*start == 0) return -1;
        sum *= 10;
        sum += (*start) - '0';
        start++;
    }

    return sum;
}

int num_len(int x) {
    int digits = 0;
    while (x > 0) {
        x /= 10;
        digits++;
    }

    return digits;
}

int main() {
    cin >> str;

    int start = -1, end = -1;
    for (int len = 1; len <= 3; len++) {
        end = start = str_to_num(str, str + len);

        bool valid = true;
        int ptr = 0;
        while (str[ptr]) {
            int ex_len = num_len(end);
            if (str_to_num(str + ptr, str + ptr + ex_len) != end) {
                valid = false;
                break;
            }

            ptr += ex_len;
            end++;
        }

        if (valid) break;
    }

    cout << start << ' ' << end - 1;
}