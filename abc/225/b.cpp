#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {

    int n; cin >> n;
    map<int, set<int>> tree;
    rep(i, n-1) {
        int a, b; cin >> a >> b;
        tree[a].insert(b);
        tree[b].insert(a);
    }
    for (auto p : tree) {
        if (p.second.size() == n - 1) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}