#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);

int n;

int main() {
    bool is_init = true;
    double prev_x = 0, prev_y = 0;
    double init_x = 0, init_y = 0;
    double x, y;
    double area = 0;

    cin >> n;
    while (n--) {
        cin >> x >> y;
        area += (prev_x * y) - (prev_y * x);

        prev_x = x;
        prev_y = y;
        if (is_init) {
            init_x = x;
            init_y = y;
            is_init = false;
        }
    }

    area += (prev_x * init_y) - (prev_y * init_x);
    area /= 2;

    cout << fixed << setprecision(1) << abs(area);
}