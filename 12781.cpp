#include <iostream>
using namespace std;
// https://www.sciencedirect.com/science/article/pii/B9780080507552500452#formula3
// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

static long long x1, y1, x2, y2;
static long long x3, y3, x4, y4;

bool denom_test(long long denom, long long numer) {
    if (denom > 0 && (numer <= 0 || numer >= denom))
        return false;
    else if (denom < 0 && (numer >= 0 || numer <= denom))
        return false;

    return true;
}

int main() {
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    long long Ax = x2 - x1, Ay = y2 - y1;
    long long Bx = x3 - x4, By = y3 - y4;
    long long Cx = x1 - x3, Cy = y1 - y3;

    long long denom = Ay * Bx - Ax * By;
    long long A_numer = By * Cx - Bx * Cy;

    if (denom == 0) {
        cout << 0;
        return 0;
    }

    bool intersect = denom_test(denom, A_numer);

    if (!intersect) {
        cout << 0;
        return 0;
    } else {
        long long B_numer = Ax * Cy - Ay * Cx;
        intersect = denom_test(denom, B_numer);
        cout << (intersect ? 1 : 0);
    }
}