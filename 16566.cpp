#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int N, M, K;

int parent[4000001];

int find(int card) {
    if (parent[card] == card + 1) {
        return parent[card] = card + 2;
    }

    return parent[card] = find(parent[card] - 1);
}

int main() {
    cin >> N >> M >> K;
    int card_max = 0;

    while (M--) {
        int card;
        cin >> card;
        parent[card - 1] = card;

        card_max = max(card_max, card);
    }

    int ptr = card_max - 1, prev = 0;
    while (ptr > 0) {
        if (parent[ptr] && parent[ptr] != prev)
            prev = parent[ptr];
        else
            parent[ptr] = prev;
        ptr--;
    }

    while (K--) {
        int minsu;
        cin >> minsu;
        cout << find(minsu) - 1 << '\n';
    }
}