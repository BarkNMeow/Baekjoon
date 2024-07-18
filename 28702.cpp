#include <iostream>
#include <string>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);

bool is_string(string a) {
    return a == "Fizz" || a == "Buzz" || a == "FizzBuzz";
}

string fizzbuzz[3];

int main() {
    for (int i = 0; i < 3; i++) {
        cin >> fizzbuzz[i];
    }

    for (int i = 0; i < 3; i++) {
        if (is_string(fizzbuzz[i])) continue;

        int number = stoi(fizzbuzz[i]) + (3 - i);

        if (number % 3 == 0) {
            if (number % 5 == 0)
                cout << "FizzBuzz";
            else
                cout << "Fizz";
        } else {
            if (number % 5 == 0)
                cout << "Buzz";
            else
                cout << number;
        }

        break;
    }
}