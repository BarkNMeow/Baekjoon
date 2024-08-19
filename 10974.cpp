#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int N;
int num_list[8];
bool selected[8];

void choose_num(int n, int pnt, int max_pnt) {
    selected[n] = true;
    num_list[pnt] = n;

    if (pnt == max_pnt - 1) {
        for (int i = 0; i < max_pnt; i++) cout << num_list[i] << ' ';
        cout << '\n';
    } else {
        for (int i = 1; i <= max_pnt; i++) {
            if (selected[i]) continue;

            choose_num(i, pnt + 1, max_pnt);
        }
    }

    selected[n] = false;
    num_list[pnt] = 0;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) choose_num(i, 0, N);
}