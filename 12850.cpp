#include <iostream>
#define LL long long
#define MOD 1000000007
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int D;
int adj_sample[8][8] = {
    {0, 1, 1, 0, 0, 0, 0, 0}, {1, 0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1, 0}, {0, 0, 0, 1, 1, 0, 0, 1},
    {0, 0, 0, 0, 1, 0, 0, 1}, {0, 0, 0, 0, 0, 1, 1, 0},
};

int** adj;

int** matrix_mul(int** A, int** B) {
    int** result = new int*[8];

    for (int i = 0; i < 8; i++) {
        result[i] = new int[8];
        for (int j = 0; j < 8; j++) {
            LL sum = 0;
            for (int k = 0; k < 8; k++) {
                sum += ((LL)A[i][k] * (LL)B[k][j]) % MOD;
                sum %= MOD;
            }

            result[i][j] = sum;
        }
    }

    return result;
}

int** matrix_pow(int D) {
    if (D == 1) return adj;

    int** result = matrix_pow(D / 2);
    if (D % 2 == 0)
        return matrix_mul(result, result);
    else
        return matrix_mul((int**)adj, matrix_mul(result, result));
}

int main() {
    adj = new int*[8];
    for (int i = 0; i < 8; i++) {
        adj[i] = new int[8];
        for (int j = 0; j < 8; j++) {
            adj[i][j] = adj_sample[i][j];
        }
    }

    cin >> D;
    int** result = matrix_pow(D);
    cout << result[0][0];
}