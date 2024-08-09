#include <iostream>
using namespace std;
// https://www.sciencedirect.com/science/article/pii/B9780080507552500452#formula3
// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

static int x1, y1, x2, y2;
static int x3, y3, x4, y4;

bool denom_test(int denom, int numer) {
    if (denom > 0 && (numer <= 0 || numer >= denom))
        return false;
    else if (denom < 0 && (numer >= 0 || numer <= denom))
        return false;

    return true;
}

int main() {
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    int Ax = x2 - x1, Ay = y2 - y1;
    int Bx = x3 - x4, By = y3 - y4;
    int Cx = x1 - x3, Cy = y1 - y3;

    int denom = Ay * Bx - Ax * By;
    int A_numer = By * Cx - Bx * Cy;

    if (denom == 0) {
        cout << 0;
        return 0;
    }

    bool intersect = denom_test(denom, A_numer);

    if (!intersect) {
        cout << 0;
    } else {
        int B_numer = Ax * Cy - Ay * Cx;
        intersect = denom_test(denom, B_numer);
        cout << (intersect ? 1 : 0);
    }
}