#include <algorithm>
#include <iostream>
#define LL long long
#define MOD 1000000007
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int N;
int arr[300000];
int agg_sum[300000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);
    int agg = 0;
    for (int i = 0; i < N; i++) {
        agg = (agg + (arr[i] % MOD)) % MOD;
        agg_sum[i] = agg;
    }

    int sum = 0;
    int pow = 1;

    for (int len = 0; len < N - 1; len++) {
        long long end_agg = (agg_sum[N - 1] - agg_sum[len] + MOD) % MOD;
        long long start_agg = agg_sum[N - len - 2];
        long long len_sum = (LL)pow * (LL)((end_agg - start_agg + MOD) % MOD);

        sum = (sum + (len_sum % MOD)) % MOD;
        pow = (pow * 2) % MOD;
    }

    cout << sum;
}