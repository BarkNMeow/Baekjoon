#include <iostream>
#include <string>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);

int main() {
    string str;
    int index;

    cin >> str;
    cin >> index;
    cout << str[index - 1];
}