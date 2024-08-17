#include <iostream>
#include <string>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

short N, K;
long long dp[1 << 15][100];
short pow_10[51], one_cnt[1 << 15];
short num_len[15], num_remainder[15];
string num[15];

short count_one(int x) {
    short cnt = 0;
    for (; x; cnt++) {
        x &= x - 1;
    }

    return cnt;
}

void update_dp(int perm) {
    for (int i = 0; i < N; i++) {
        if ((perm & (1 << i) == 0)) continue;

        int perm_other = perm ^ (1 << i);
        int re = num_remainder[i];
        for (short re_other = 0; re_other < K; re_other++) {
            short re_dp = (re_other * pow_10[num_len[i]] + re) % K;
            dp[perm][re_dp] += dp[perm_other][re_other] * dp[1 << i][re];
        }
    }
}

long long euclid(long long a, long long b) {
    if (b == 0)
        return a;
    else
        return euclid(b, a % b);
}

int main() {
    long long denom = 1;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
        num_len[i] = num[i].size();
        denom *= (i + 1);
    }
    cin >> K;

    // Calculate remainders for power of 10
    pow_10[0] = 1;
    for (int i = 1; i <= 50; i++) {
        pow_10[i] = (pow_10[i - 1] * 10) % K;
    }

    // Calculate number of ones in binary
    for (int i = 1; i < (1 << N); i++) {
        one_cnt[i] = count_one(i);
    }

    // Convert long(er) numbers to remainders
    for (int i = 0; i < N; i++) {
        string conv = num[i];
        int p = 0;
        long long num = 0;
        while (conv.size() > 0) {
            int len = min(18, (int)conv.size());
            string sub = conv.substr(conv.size() - len);
            long long sub_num = stoll(sub) % (long long)K;
            num = (num + sub_num * pow_10[p]) % K;

            p += len;
            conv = conv.substr(0, conv.size() - len);
        }

        num_remainder[i] = num;
        dp[1 << i][num] += 1;
    }

    for (int num_1 = 2; num_1 <= N; num_1++) {
        for (int perm = 0; perm < (1 << N); perm++) {
            if (one_cnt[perm] != num_1) continue;
            update_dp(perm);
        }
    }

    long long numer = dp[(1 << N) - 1][0];
    long long gcd = euclid(numer, denom);
    cout << numer / gcd << '/' << denom / gcd;
}