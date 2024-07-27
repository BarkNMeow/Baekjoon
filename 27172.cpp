#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int n;
int number[100001];
int score[100001];
int number_player[1000001];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> number[i];
        number_player[number[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        if (number_player[1]) {
            score[number_player[1]]++;
            score[i]--;
        }

        for (int q = 2; q * q <= number[i]; q++) {
            if (number[i] % q != 0) continue;

            if (number_player[q]) {
                score[number_player[q]]++;
                score[i]--;
            }

            int pair_q = number[i] / q;
            if (pair_q != q && number_player[pair_q]) {
                score[number_player[pair_q]]++;
                score[i]--;
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << score[i] << ' ';
}