#include <iomanip>
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
    if (denom > 0 && (numer < 0 || numer > denom))
        return false;
    else if (denom < 0 && (numer > 0 || numer < denom))
        return false;

    return true;
}

void find_meeting_end(long long x1, long long y1, long long x2, long long y2,
                      long long x3, long long y3, long long x4, long long y4) {
    long long l1_min_x, l1_min_y, l1_max_x, l1_max_y;
    long long l2_min_x, l2_min_y, l2_max_x, l2_max_y;

    if (x1 < x2) {
        l1_min_x = x1, l1_min_y = y1;
        l1_max_x = x2, l1_max_y = y2;
    } else {
        l1_min_x = x2, l1_min_y = y2;
        l1_max_x = x1, l1_max_y = y1;
    }

    if (x3 < x4) {
        l2_min_x = x3, l2_min_y = y3;
        l2_max_x = x4, l2_max_y = y4;
    } else {
        l2_min_x = x4, l2_min_y = y4;
        l2_max_x = x3, l2_max_y = y3;
    }

    // all x is same
    if (l1_min_x == l1_max_x) {
        if (min(l1_min_y, l1_max_y) == max(l2_min_y, l2_max_y)) {
            cout << '\n' << l1_min_x << ' ' << min(l1_min_y, l1_max_y);
        } else if (max(l1_min_y, l1_max_y) == min(l2_min_y, l2_max_y)) {
            cout << '\n' << l1_min_x << ' ' << max(l1_min_y, l1_max_y);
        }

        return;
    }

    if (l1_max_x == l2_min_x) {
        cout << '\n' << l1_max_x << ' ' << l1_max_y;
    } else if (l1_min_x == l2_max_x) {
        cout << '\n' << l1_min_x << ' ' << l1_min_y;
    }

    return;
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
        if (A_numer != 0)
            cout << 0;
        else {
            if (max(x1, x2) >= min(x3, x4) && min(x1, x2) <= max(x3, x4) &&
                max(y1, y2) >= min(y3, y4) && min(y1, y2) <= max(y3, y4)) {
                cout << 1;

                find_meeting_end(x1, y1, x2, y2, x3, y3, x4, y4);
            }

            else
                cout << 0;
        }

        return 0;
    }

    bool intersect = denom_test(denom, A_numer);

    if (!intersect) {
        cout << 0;
        return 0;
    } else {
        long long B_numer = Ax * Cy - Ay * Cx;
        intersect = denom_test(denom, B_numer);

        if (!intersect)
            cout << 0;
        else {
            cout << 1 << '\n';
            double section_x = x1 + (double)Ax * A_numer / denom;
            double section_y = y1 + (double)Ay * A_numer / denom;

            cout << fixed << setprecision(16) << section_x << ' ' << section_y;
        }
    }
}