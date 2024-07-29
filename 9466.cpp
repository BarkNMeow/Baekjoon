#include <cstring>
#include <iostream>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

int T;

int find_cycle(int node, int *pick, char *visited) {
    int cycle_start = node;
    while (!visited[cycle_start]) {
        visited[cycle_start] = 1;
        cycle_start = pick[cycle_start];
    }

    int cnt = 0;
    if (visited[cycle_start] == 1) {
        int ptr = cycle_start;
        do {
            ptr = pick[ptr];
            cnt++;
        } while (ptr != cycle_start);
    }

    while (visited[node] != 2) {
        visited[node] = 2;
        node = pick[node];
    }

    return cnt;
}

void find_noteam(int *pick, int n) {
    char *visited = (char *)malloc(sizeof(char) * (n + 1));
    memset(visited, 0, sizeof(char) * (n + 1));

    int student_left = n;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        student_left -= find_cycle(i, pick, visited);
    }

    cout << student_left << '\n';
    free(visited);
}

int main() {
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        int *pick = (int *)malloc(sizeof(int) * (n + 1));

        for (int i = 1; i <= n; i++) cin >> pick[i];

        find_noteam(pick, n);
        free(pick);
    }
}