#include <iostream>
#include <map>
#include <string>
using namespace std;

// Dummy variable to prevent misinterpretation
bool __dummy__ = ios::sync_with_stdio(false);
auto __dummy2__ = cin.tie(NULL);
auto __dummy3__ = cout.tie(NULL);

struct Node {
    map<string, int> children;
};

int N;
int tree_ptr = 1;
Node tree[15001];

void traverse(int ptr, int depth) {
    auto node_tree = tree[ptr].children;
    for (auto it : node_tree) {
        for (int i = 0; i < depth; i++) cout << "--";
        cout << it.first << '\n';
        traverse(it.second, depth + 1);
    }
}

int main() {
    cin >> N;
    while (N--) {
        int K;
        cin >> K;

        int ptr = 0;
        while (K--) {
            string name;
            cin >> name;

            auto &node_tree = tree[ptr].children;
            auto next_iter = node_tree.find(name);

            if (next_iter == tree[ptr].children.end()) {
                node_tree.insert({name, tree_ptr});
                ptr = tree_ptr++;
            } else {
                ptr = next_iter->second;
            }
        }
    }

    traverse(0, 0);
}