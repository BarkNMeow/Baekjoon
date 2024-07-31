#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

// Idea from: https://blog.hoony.me/2023/10/01/find-lis-in-nlogn/

int N;

vector<int> min_elem;

int main() {
    min_elem.push_back(~0x7FFFFFFF);
    cin >> N;

    while (N--) {
        int a;
        cin >> a;

        if (a > min_elem.back())
            min_elem.push_back(a);
        else {
            auto lb = lower_bound(min_elem.begin(), min_elem.end(), a);
            *lb = a;
        }
    }

    cout << min_elem.size() - 1;
}