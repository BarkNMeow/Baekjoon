#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

// N, min, max, start
int N;
int dp[101][10][10][10];

int sum_mod(int a, int b) { return (a + b) % 1000000000; }

void update_stairnum(int n) {
    for (int min_num = 0; min_num < 10; min_num++) {
        for (int max_num = min_num + 1; max_num < 10; max_num++) {
            for (int start = min_num; start <= max_num; start++) {
                int& target = dp[n][min_num][max_num][start];

                if (start > 0) {
                    if (start == max_num) {
                        // max range is expanded
                        target = sum_mod(
                            target, dp[n - 1][min_num][start - 1][start - 1]);
                    }

                    // or same
                    target =
                        sum_mod(target, dp[n - 1][min_num][max_num][start - 1]);
                }

                if (start < 9) {
                    if (start == min_num) {
                        // min range is expanded
                        target = sum_mod(
                            target, dp[n - 1][start + 1][max_num][start + 1]);
                    }

                    // or same
                    target =
                        sum_mod(target, dp[n - 1][min_num][max_num][start + 1]);
                }
            }
        }
    }
}

int get_cnt(int n) {
    int sum = 0;
    for (int start = 1; start < 10; start++)
        sum = sum_mod(sum, dp[n][0][9][start]);

    return sum;
}

int main() {
    cin >> N;

    for (int i = 0; i < 10; i++) {
        dp[1][i][i][i] = 1;
    }

    for (int n = 2; n <= N; n++) {
        update_stairnum(n);
    }

    cout << get_cnt(N);
}